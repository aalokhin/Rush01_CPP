#include "CPU.hpp"

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>





void CPU::refresh()
{
	this->_cpu_usage = GetAllUsage();

	this->_load_av =  LdAv();

	

}

float CPU::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalSinceLast;

  totalSinceLast = totalTicks - _previousTotal;

  unsigned long long idleSinceLast;

  idleSinceLast  = idleTicks - _previousIdle;


  float idle= static_cast<float>(idleSinceLast);

  float ret = 1.0f-((totalSinceLast > 0) ? idle/totalSinceLast : 0);
  
  _previousTotal = totalTicks;
  _previousIdle  = idleTicks;

  return ret;
}


std::string CPU::LdAv()
{
	FILE* popOp;
 	char tmpBuf[256];
 	

 	std::string tmp;
 	popOp = popen("uptime | sed -n 's/.*averages://p'", "r");
 	

 	fgets(tmpBuf, sizeof(tmpBuf), popOp);
 	tmp = std::string(tmpBuf);	
 	


 	tmp.erase(0, 1);
 	tmp.erase(tmp.end() - 1, tmp.end());

 	pclose(popOp);
 	return (std::string(tmp));
}


float CPU::GetAllUsage()
{
	unsigned long long totalTicks;
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count;



	int i;

	count = HOST_CPU_LOAD_INFO_COUNT;


	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		totalTicks = 0;
		i = 0;

		while (i < CPU_STATE_MAX)
		{
			totalTicks += cpuinfo.cpu_ticks[i];
			i++;
		}
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else
		return -1.0f;
 
}




/******************************** Getters ********************************/

std::string CPU::getModel() const {return this->_cpuModel;}

std::string CPU::getHwMachine() const {return this->_hw_machine;}

int CPU::GetNCPU()const {return this->_number_cpu;}

float	CPU::GetCpuUsg() const {return this->_cpu_usage;}

std::string CPU::GetLoadAv() const{return this->_load_av;}

/******************************** COPLIEN ****************************/

CPU::CPU(void) : _previousTotal(0), _previousIdle(0){

	char brand_string[1024];
	size_t size = 1024;
	sysctlbyname("machdep.cpu.brand_string", &brand_string, &size, NULL, 0);
	this->_cpuModel = std::string(brand_string);
	memset(brand_string, 0, sizeof(brand_string));

	sysctlbyname("hw.machine", &brand_string, &size, NULL, 0);
	this->_hw_machine = std::string(brand_string);
	memset(brand_string, 0, sizeof(brand_string));

	this->_number_cpu = sysconf(_SC_NPROCESSORS_ONLN);

}

CPU::CPU(const CPU & copy) { *this = copy; }

CPU::~CPU(void) {}

CPU& CPU::operator=(const CPU&) {return *this;}