#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <iostream>
# include <ctime>
# include <sstream>


/*********************** For displaying info ************************/

class	IMonitorDisplay {

	public:
		~IMonitorDisplay(){}
		virtual void DrawStaticData() = 0;

	protected:

};

#endif


