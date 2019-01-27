#ifndef TIME_HPP
# define TIME_HPP


# include "IMonitorModule.hpp"


class Time : public IMonitorModule
{

	public:
		Time();
		~Time();
		Time(Time const & toCopy);

		Time &operator=(Time const & rhs);
		
		std::string 	getCurrentTime() const;
		void			refresh();
 
	protected:
		std::string		 _time_date;


};

#endif