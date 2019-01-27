#ifndef NCURSES_HPP
# define NCURSES_HPP





# include <iostream>
# include <ctime>
# include <sstream>

# include <string>
# include <vector>
# include <ncurses.h>
#include "Time.hpp"
# include "RAM.hpp"

# include "IMonitorDisplay.hpp"

/*********************** Colects info on modules ************************/

class RAM;

class Time;

class	NcursesOut : public IMonitorDisplay {

	public:
		NcursesOut(RAM &ram, Time &time);

		~NcursesOut();
		void 	printOutput();
	private:
		int			y_wmax;
		int 		x_wmax;
		WINDOW*		_win;

		RAM		_ram;
		Time   	_time;

		void	initColorPairs();


		void 	drawRAM();
		
};

#endif


