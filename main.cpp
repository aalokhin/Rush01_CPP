// #include "User.hpp"
// #include "Time.hpp"
// #include "OS.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
// #include "Network.hpp"
#include "NET.hpp"
#include "Time.hpp"
# include "NCurses.hpp"
#include "OS.hpp"

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

	RAM ram;
	Time time;
	NET net_info;
	Host host_info;
	OS	 os_info;
	CPU  cpu_info;


	NcursesOut 	visualMode(ram, time, host_info, os_info, net_info, cpu_info);

	visualMode.printOutput();
	//std::cout << "===>" << net_info.getNetworkInfo() << std::endl;



	return 0;
}