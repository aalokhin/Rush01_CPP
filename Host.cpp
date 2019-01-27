#include "Host.hpp"


void Host::refresh()
{
	char host_intfo[_POSIX_HOST_NAME_MAX];

	gethostname(host_intfo, _POSIX_HOST_NAME_MAX );
	
	this->_user = std::string(getlogin());

	this->_host = std::string(host_intfo);

}


/******************************** COPLIEN ****************************/

Host::Host(void) {return;}

Host::Host(const Host& copy) {	*this = copy;}

Host::~Host(void) {	return;}

Host & Host::operator=(const Host&) {return *this;}

/******************************** GETTERS ****************************/

std::string Host::getHost() {return this->_host;}
std::string Host::getUser() {return this->_user;}