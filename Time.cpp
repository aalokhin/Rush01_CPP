#include "Time.hpp"

void	Time::refresh()
{
    time_t t ; 
	struct tm *tmp ; 
    char current_time[20]; 
    time( &t ); 
    tmp = localtime(&t);
    strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", tmp);

    this->_time_date =  std::string(current_time);

}

std::string 	Time::getCurrentTime() const
{
	return this->_time_date;
}

/******************************** COPLIEN ****************************/


Time::Time(void) {return;}

Time::Time(const Time& copy) {	*this = copy;}

Time::~Time(void) {	return;}

Time & Time::operator=(const Time&) {return *this;}
