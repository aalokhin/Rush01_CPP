#ifndef CPU_HPP
#define CPU_HPP

#include "IMonitorModule.hpp"

class CPU: public IMonitorModule
{

	public:
		CPU();
		CPU(const CPU& copy);
		~CPU();
		CPU& operator=(const CPU&);

		void refresh();

		std::string getModel() const;
		std::string getHwMachine() const;
		int GetNCPU()const;
		std::string GetLoadAv() const;
		
		float GetCpuUsg()const ;
		//std::string getModel() const;




	private:
		std::string _cpuModel;
		std::string	_hw_machine;

		std::string _load_av;

		int 	_number_cpu;
		float 	_cpu_usage;



		float GetAllUsage();
		float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);

		unsigned long long _previousTotal;
		unsigned long long _previousIdle;

		std::string LdAv();


};

#endif


/*

Second level name          Type          Changeable
HW_MACHINE                 string        no
HW_MODEL                   string        no
HW_NCPU                    integer       no
HW_BYTEORDER               integer       no
HW_PHYSMEM                 integer       no
HW_USERMEM                 integer       no
HW_PAGESIZE                integer       no
HW_FLOATINGPOINT           integer       no
HW_MACHINE_ARCH            string        no

*/