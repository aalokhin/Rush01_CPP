#ifndef NCURSES_HPP
# define NCURSES_HPP
# include <iostream>
# include <ctime>
# include <sstream>

# include <string>
# include <vector>
# include <ncurses.h>

#include "Time.hpp"

#include "NET.hpp"
# include "RAM.hpp"
#include "Host.hpp"
#include "OS.hpp"

#include "CPU.hpp"
# include "IMonitorDisplay.hpp"

/*********************** Colects info on modules ************************/

class RAM;

class Time;

class	NcursesOut : public IMonitorDisplay {

	public:
		NcursesOut(RAM &ram, Time &time, Host & host_info, OS & os_info, NET & net_info, CPU & cpu_info);

		~NcursesOut();
		void 	printOutput();
	private:
		int			y_wmax;
		int 		x_wmax;
		WINDOW*		_win;

		RAM		_ram;
		Time   	_time;
		Host	_host_info;
		OS 		_os_info;
		NET		_net_info;
		CPU 	_cpu_info;

		void	initColorPairs();
		void 	drawLines();
		void 	DrawStaticData();

		void 	drawRAM();
		
};

#endif


