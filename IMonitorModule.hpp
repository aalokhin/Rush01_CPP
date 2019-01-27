#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <unistd.h>
#include <sys/sysctl.h>
#include <time.h>
#include <sstream>
#include <mach/mach_host.h>
#include <mach/processor_info.h>
#include <vector>
#include <numeric>
#include <iomanip>
#include <ncurses.h>

/*********************** Colects info on modules ************************/

class	IMonitorModule {

	public:
		virtual ~IMonitorModule() {}
		virtual void refresh() = 0;		


};

#endif