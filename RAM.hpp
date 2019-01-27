#ifndef RAM_HPP
#define RAM_HPP
#include "IMonitorModule.hpp"

class RAM: public IMonitorModule {
	public:
		RAM();
		RAM(const RAM &copy);
		~RAM();
		RAM& operator=(const RAM&);
		void refresh(void);

		/************* Getters *************/

		unsigned long long getTotal(void) const;
		unsigned long long getUsed(void) const;
		unsigned long long getFree(void) const;

	private:
		unsigned long long _total;
		unsigned long long _used;
		unsigned long long _free;


};

#endif