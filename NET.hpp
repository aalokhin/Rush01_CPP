#ifndef NET_HPP
#define NET_HPP

#include "IMonitorModule.hpp"

class NET: public IMonitorModule
{

	public:
		NET();
		NET(const NET& copy);
		~NET();
		NET& operator=(const NET&);

		void refresh();

		std::string getNetworkInfo() const;

	private:
		std::string _network_info;


};

#endif