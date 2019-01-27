#include "OS.hpp"

//kern.version
//kern.ostype
#include <cassert> 
#include <string> 
void OS::refresh()

{


	char buffer[256];
	size_t size = sizeof(buffer);

	sysctlbyname("kern.osrelease", buffer, &size, NULL, 0);
	this->_version = std::string(buffer);
	memset(buffer, 0, sizeof(buffer));

	sysctlbyname("kern.ostype", buffer, &size, NULL, 0);
	this->_type = std::string(buffer);
	memset(buffer, 0, sizeof(buffer));


	this->_release_date = sysctlbyname("kern.osreldate", buffer, &size, NULL, 0);

	this->_os = std::string(findOS());

	this->_details =  std::string(versionDisplay());



	

} 


void OS::split_string(const std::string & str, const std::string & delimiter)
{
	
	std::string::size_type pos = 0;
	std::string::size_type prev = 0;

	

	

	pos = str.find(delimiter, prev);
	std::string arr1(str.substr(prev, pos - prev));
	prev = pos + 1;

	pos = str.find(delimiter, prev);
	std::string arr2(str.substr(prev, pos - prev));
	prev = pos + 1;
	std::string arr3(str.substr(prev));
	
	arr1.erase(0, 13);
	arr2.erase(0, 16);
	arr3.erase(0, 14);

	this->_OSname = std::string(arr1);
	this->_OSver = std::string(arr2);
	this->_OSbuild = std::string(arr3);
}


std::string OS::versionDisplay()
{
	char buf[1024];
	unsigned buflen = 0;
	char line[256];
	FILE *sw_vers = popen("sw_vers", "r");
	while (fgets(line, sizeof(line), sw_vers) != NULL)
	{
		int l = snprintf(buf + buflen, sizeof(buf) - buflen, "%s", line);
		buflen += l;
		assert(buflen < sizeof(buf));
	}
	pclose(sw_vers);
	std::string ret(buf);
	split_string(ret, "\n");

	return (ret);
}

std::string OS::findOS()
{

	#ifdef _WIN32
		return "Windows 32-bit";
	#elif _WIN64
		return "Windows 64-bit";
	#elif __unix || __unix__
		return "Unix";
	#elif __APPLE__ || __MACH__
		return "Mac OS X";
	#elif __linux__
		return "Linux";
	#elif __FreeBSD__
		return "FreeBSD";
	#else
		return "Other";
	#endif
					
}



std::string OS::getOS() const{return this->_os;}
std::string OS::getVersion() const{return this->_version;}
std::string OS::getType() const{return this->_type;}
int OS::GetRelease()const {return this->_release_date;} 

std::string OS::getDetails() const{return this->_details;}


std::string OS::getOSname() const{return this->_OSname;}
std::string OS::getOSver() const{return this->_OSver;}
std::string OS::getOSbuild() const{return this->_OSbuild;}

/******************************** COPLIEN ****************************/

OS::OS(void) {return;}

OS::OS(const OS& copy) {	*this = copy;}

OS::~OS(void) {	return;}

OS & OS::operator=(const OS&) {return *this;}
