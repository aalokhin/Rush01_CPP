# include "NCurses.hpp"

NcursesOut::NcursesOut(RAM &ram, Time &time, Host &host_info, OS &os_info, NET &net_info, CPU &cpu_info) 
{
	this->_ram = ram;
	this->_time = time;
	this->_host_info = host_info;
	this->_os_info = os_info;
	this->_net_info = net_info;
	this->_cpu_info = cpu_info;

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
	_win = newwin(this->y_wmax - 1, 75, 0, 0);


	
	DrawStaticData();
	drawLines();
	//wrefresh(_win);

};

void				NcursesOut::drawLines()
{


	wattron(_win, COLOR_PAIR(133));

	wborder(_win, 42, 42, 42, 42, 42, 42, 42, 42);



	// wattron(_win, COLOR_PAIR(133));
	// mvwvline(_win, 0, 70, 42, this->y_wmax);
	
}


void 				NcursesOut::DrawStaticData()
{
	std::string tmpStr;

	this->_host_info.refresh();
	this->_os_info.refresh();

	tmpStr = this->_host_info.getHost();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 9, 1, "Host: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 9, 15, tmpStr.c_str());

	tmpStr = this->_host_info.getUser();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 11, 1, "User: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 11, 15, tmpStr.c_str());

	tmpStr = this->_os_info.getOS();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 13, 1, "OS: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 13, 18, tmpStr.c_str());

	tmpStr = this->_os_info.getType();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 14, 1, "Kernel: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 14, 18, tmpStr.c_str());

	tmpStr = this->_os_info.getVersion();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 15, 1, "Kernel Version: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 15, 18, tmpStr.c_str());




	tmpStr = this->_os_info.getOSname();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 17, 1, "OS name: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 17, 15, tmpStr.c_str());

	tmpStr = this->_os_info.getOSver();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 18, 1, "OS version: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 18, 15, tmpStr.c_str());

	tmpStr = this->_os_info.getOSbuild();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 19, 1, "OS build: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 19, 15, tmpStr.c_str());


	tmpStr = this->_cpu_info.getModel();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 23, 1, "Processor: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 23, 15, tmpStr.c_str());


	tmpStr = this->_cpu_info.getHwMachine();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 24, 1, "Hardware Machine: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 24, 19, tmpStr.c_str());
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 25, 1, "Cores number: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 25, 19, "%i", this->_cpu_info.GetNCPU());



	


/*
std::string getModel() const;
std::string getHwMachine() const;
std::string getHwModel() const;
*/

}


void 	NcursesOut::displayKoteyka()
{
	// if ()
	time_t t ; 
	struct tm *tmp ; 
	char current_time[20]; 
	time( &t ); 
	tmp = localtime(&t);
	strftime(current_time, sizeof(current_time), "%S", tmp);
	int k = atoi(current_time);

	if (k % 7 == 0)
		wattron(_win, COLOR_PAIR(105));
	else if (k % 7 == 1)
		wattron(_win, COLOR_PAIR(106));
	else if (k % 7 == 2)
		wattron(_win, COLOR_PAIR(107));
	else if (k % 7 == 3)
		wattron(_win, COLOR_PAIR(133));
	else if (k % 7 == 4)
		wattron(_win, COLOR_PAIR(104));
	else if (k % 7 == 5)
		wattron(_win, COLOR_PAIR(1));
	else
		wattron(_win, COLOR_PAIR(111));


	mvwprintw(_win, 40, 3, "    _                ___       _.--.");
	mvwprintw(_win, 41, 3, "    \\`.|\\..----...-'`   `-._.-'_.-'`");
	mvwprintw(_win, 42, 3, "    /  ' `         ,       __.--'   ");
	mvwprintw(_win, 43, 3, "    )/' _/     \\   `-_,   /         ");
	mvwprintw(_win, 44, 3, "    `-\'\" `\"\\_  ,_.-;_.-\\_ ',      ");
	mvwprintw(_win, 45, 3, "        _.-'_./   {_.'   ; /        ");
	mvwprintw(_win, 46, 3, "       {_.-``-'         {_/         ");

}

void	NcursesOut::initColorPairs()
{
	// init_color(1, 0, 500, 0);
	//init_color(2, 255, 102, 0);
	// init_color(3, 0, 500, 0);
	// init_color(4, 0, 500, 0);
	// init_color(5, 0, 500, 0);
	// init_color(6, 0, 500, 0);
	//	init_color(6, 0, 500, 0);



	 init_color(104, 500, 100, 500);
	 init_color(105, 900, 500, 500);
	 init_color(106, 500, 500, 800);
	 init_color(107, 500, 300, 500);
	 init_color(111, 100, 300, 500);
	
	init_pair(102, 102, COLOR_BLACK);
	init_pair(104, 104, COLOR_BLACK);
	init_pair(105, 105, COLOR_BLACK);
	init_pair(106, 106, COLOR_BLACK);
	init_pair(107, 107, COLOR_BLACK);
	init_pair(111, 111, COLOR_BLACK);


	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_RED);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_CYAN, COLOR_CYAN);
	init_pair(22, COLOR_BLACK, COLOR_BLUE);
	init_pair(33, COLOR_BLACK, COLOR_RED);
	init_pair(44, COLOR_BLACK, COLOR_CYAN);
	init_pair(55, COLOR_BLACK, COLOR_WHITE);
	init_pair(133, COLOR_CYAN, COLOR_BLACK);
	init_pair(134, COLOR_BLUE, COLOR_BLUE);
	//init_pair(134, COLOR_YELLOW, COLOR_YELLOW);

	//init_pair(13, COLOR_ORANGE, COLOR_BLACK);	

}

void	NcursesOut::printOutput()
{


	while(true)
	{
		this->_ram.refresh();
		this->_time.refresh();
		this->_net_info.refresh();
		this->_cpu_info.refresh();

		drawRAM();

		displayKoteyka();
		DrawStaticData();
		drawLines();
		
		//usleep(100000);

	}

}


void					NcursesOut::drawRAM()
{



	int bars = 0;
	int i = 0;
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 1, 1, "Total memory: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 1, 15, "%llu MB", this->_ram.getTotal());
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 3, 1, "Used memory:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 3, 15, "%llu MB", this->_ram.getUsed());

	// std::cout << ">>>>>>>>>>" << this->_ram.getUsed() % 40 << std::endl;
	// exit(1);
	bars = this->_ram.getUsed() % 40;
	if (bars < 15)
		bars = 15;
	wattron(_win, COLOR_PAIR(134));
	//mvwprintw(_win, 4, 73, ":");
	mvwprintw(_win, 4, 1, ":");
	
	while (i < bars)
	{
		mvwprintw(_win, 4, 2 + i, "=");
		// wattron(_win, COLOR_PAIR(133));
		// mvwprintw(_win, 4, 70, "%c", 42);
		// wattroff(_win, COLOR_PAIR(133));
		// wattron(_win, COLOR_PAIR(1));
		i++;
	}



	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 5, 1, "Free memory:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 5, 15, "%llu MB", this->_ram.getFree());



	bars = this->_ram.getFree() % 40;
	wattron(_win, COLOR_PAIR(134));
	//mvwprintw(_win, 6, 73, ":");
	mvwprintw(_win, 6, 1, ":");
	i = 0;
	while (i < bars)
	{
		mvwprintw(_win, 6, 2 + i, "=");
		// wattron(_win, COLOR_PAIR(133));
		// mvwprintw(_win, 6, 70, "%c", 42);
		// wattroff(_win, COLOR_PAIR(133));
		// wattron(_win, COLOR_PAIR(1));
		i++;
	}

	std::string tmpStr = this->_time.getCurrentTime();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 7, 1, "Current date and time: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 7, 24, tmpStr.c_str());

	tmpStr = this->_net_info.getNetworkInfo();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 21, 1, "Network info: ");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 21, 15, tmpStr.c_str());


	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 26, 1, "CPU Usage:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 26, 16, "%f", this->_cpu_info.GetCpuUsg());
	

	bars = (this->_cpu_info.GetCpuUsg()) * 30;
	wattron(_win, COLOR_PAIR(134));
	//mvwprintw(_win, 27, 73, ":");
	mvwprintw(_win, 27, 1, ":");
	// mvwprintw(_win, 28, 1, "%d", bars);
	i = 0;
	while (i < bars)
	{
		mvwprintw(_win, 27, 2 + i, "=");
		// wattron(_win, COLOR_PAIR(133));
		// mvwprintw(_win, 27, 70, "%c", 42);
		// wattroff(_win, COLOR_PAIR(133));
		// wattron(_win, COLOR_PAIR(1));
		i++;
	}

	tmpStr = this->_cpu_info.GetLoadAv();
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 29, 1, "Load Averages:");
	wattroff(_win, COLOR_PAIR(1));
	mvwprintw(_win, 29, 16, tmpStr.c_str());




	wrefresh(_win);
	werase(_win);

}



NcursesOut::~NcursesOut()
{
	delwin(_win);
	endwin();
}
