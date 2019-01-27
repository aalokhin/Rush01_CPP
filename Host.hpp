#ifndef HOST_HPP
#define HOST_HPP

#include "IMonitorModule.hpp"


class Host : public IMonitorModule
{
	public:
		Host();
		~Host();
		Host(const Host &other);
		Host &operator = (const Host &other);

		std::string getUser();

		std::string getHost();

		void refresh();
	private:
		std::string _user;
		std::string _host;
};

#endif