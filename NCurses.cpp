# include "NCurses.hpp"

NcursesOut::NcursesOut(RAM &ram){
	this->_ram = ram;


	initscr(); 
	cbreak(); 
	noecho(); 
	curs_set(0);
	start_color();
	keypad(stdscr, TRUE); 
	nodelay(stdscr, TRUE); 
	scrollok(stdscr, FALSE);
	getmaxyx(stdscr, this->y_wmax, this->x_wmax);


	initColorPairs();
	getmaxyx(stdscr, this->y_wmax, this->x_wmax);
	_win = newwin(this->y_wmax - 1, this->x_wmax/2, 0, 0);


	wattron(_win, COLOR_PAIR(133));
	wborder(_win, 42, 42, 42, 42, 42, 42, 42, 42);

	mvwvline(_win, 0, 50, 42, this->y_wmax);
	mvwvline(_win, 0, 100, 42, this->y_wmax);
	mvwvline(_win, 0, 150, 42, this->y_wmax);
	wrefresh(_win);

};

void	NcursesOut::initColorPairs()
{
	init_color(COLOR_GREEN, 0, 500, 0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_RED);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_CYAN, COLOR_CYAN);
	init_pair(22, COLOR_BLACK, COLOR_BLUE);
	init_pair(33, COLOR_BLACK, COLOR_RED);
	init_pair(44, COLOR_BLACK, COLOR_CYAN);
	init_pair(55, COLOR_BLACK, COLOR_WHITE);
	init_pair(133, COLOR_CYAN, COLOR_BLACK);	

}

void	NcursesOut::printOutput()
{


	while(true)
	{
		this->_ram.refresh();
		drawRAM();

	}


}


void					NcursesOut::drawRAM()
{

	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 1, 1, "Total memory: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 1, 15, "%llu MB", this->_ram.getTotal());
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 3, 1, "Used memory:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 3, 15, "%llu MB", this->_ram.getUsed());
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 5, 1, "Free memory:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 5, 15, "%llu MB", this->_ram.getFree());
	wrefresh(_win);
}


NcursesOut::~NcursesOut()
{
	delwin(_win);
	endwin();
}
