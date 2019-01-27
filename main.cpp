// #include "User.hpp"
// #include "Time.hpp"
// #include "OS.hpp"
//#include "CPU.hpp"
#include "RAM.hpp"
// #include "Network.hpp"


# include "NCurses.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <iostream>

#include <sys/param.h>
#include <sys/sysctl.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define GREEN1 "\033[0;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"
# include <ncurses.h>

int 				main()
{
	pid_t			get_info;

	if ((get_info = fork()) == 0)
	{
		system("system_profiler -detailLevel mini > all_info.txt");
		return (0);
	}
	std::cout << GREEN1 << ".............  we created all_info.txt file ........................\n";
	// int sysctlbyname( char *sname,
 //                  void *oldp,
 //                  size_t *oldlenp,
 //                  void * newp,
 //                  size_t newlen );

	
	//std::vector<double> _loadAVG;
	//sysctlbyname("hw.ncpu", &coreNum, &size, NULL, 0);



	// sysctlbyname("hw.ncpu", &coreNum, &size, NULL, 0);
	
	// this->_cores.push_back(coreNum);

	// this->_loadAVG.clear();
	// double avg[3];
 //    getloadavg(avg, 3);
	// this->_loadAVG.push_back(avg[0]);
	// this->_loadAVG.push_back(avg[1]);
	// this->_loadAVG.push_back(avg[2]);

	RAM ram;
	NcursesOut 	visualMode(ram);

	visualMode.printOutput();


	// int coreNum;


	// sysctlbyname("hw.ncpu", &coreNum, &size, NULL, 0);

	// std::cout << GREEN << coreNum  << std::endl;

	return 0;
}