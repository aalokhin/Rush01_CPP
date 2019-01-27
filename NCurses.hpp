#ifndef NCURSES_HPP
# define NCURSES_HPP





# include <iostream>
# include <ctime>
# include <sstream>

# include <string>
# include <vector>
# include <ncurses.h>
# include "RAM.hpp"

# include "IMonitorDisplay.hpp"

/*********************** Colects info on modules ************************/

class RAM;

class	NcursesOut : public IMonitorDisplay {

	public:
		NcursesOut(RAM &ram);

		~NcursesOut();
		void 	printOutput();
	private:
		int			y_wmax;
		int 		x_wmax;
		WINDOW*		_win;

		RAM		_ram;

		void	initColorPairs();


		void 	drawRAM();
		
};

#endif


