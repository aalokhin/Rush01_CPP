#include "RAM.hpp"


void RAM::refresh(void)
{
	unsigned long long mem1;
	int mem2;

	size_t size_uint = sizeof(unsigned long long);
	size_t size_int = sizeof(int);
	
	sysctlbyname("hw.memsize", &mem1, &size_uint, NULL, 0);
	sysctlbyname("vm.page_free_count", &mem2, &size_int, NULL, 0);

	this->_used = (this->_total =  mem1 / (1024 * 1024)) - (this->_free = mem2 * 4096 / 1024/1024);
}







/******************************** COPLIEN ****************************/

RAM::RAM(void) {}

RAM::RAM(const RAM& copy) { *this = copy; }

RAM::~RAM(void) {}

RAM& RAM::operator=(const RAM&) {return *this;}


/******************************** Getters ********************************/

unsigned long long RAM::getTotal(void) const {return this->_total;}
unsigned long long RAM::getUsed(void) const {return this->_used;}
unsigned long long RAM::getFree(void) const {return this->_free;}
