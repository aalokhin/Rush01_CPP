#include "NET.hpp"

void NET::refresh()
{
	this->_network_info.clear();
	

	FILE* popOp;
 	char tmpBuf[256];
 	std::string tmp;
 	popOp = popen("top -l 1 | grep Network", "r");
 	fgets(tmpBuf, sizeof(tmpBuf), popOp);
 	tmp = std::string(tmpBuf);
 	
 	this->_network_info = std::string(tmp);
 	this->_network_info.erase(this->_network_info.end() - 1, this->_network_info.end());
 	this->_network_info.erase (0, 10);

 	pclose(popOp);

}



/******************************** Getters ********************************/

std::string NET::getNetworkInfo() const{return this->_network_info;} 

/******************************** COPLIEN ****************************/

NET::NET(void) {}

NET::NET(const NET & copy) { *this = copy; }

NET::~NET(void) {}

NET& NET::operator=(const NET&) {return *this;}