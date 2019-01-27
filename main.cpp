/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:34:36 by aalokhin          #+#    #+#             */
/*   Updated: 2019/01/27 20:34:37 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CPU.hpp"
#include "RAM.hpp"
#include "NET.hpp"
#include "Time.hpp"
# include "NCurses.hpp"
#include "OS.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <iostream>

#include <sys/param.h>
#include <sys/sysctl.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define GREEN1 "\033[0;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

# include <ncurses.h>

int 				main()
{

	std::cout << GREEN1 << ".............  we created a display ........................\n";

	RAM ram;
	Time time;
	NET net_info;
	Host host_info;
	OS	 os_info;
	CPU  cpu_info;
 /*
 	this->_host_info.refresh();
	this->_os_info.refresh();
	

	std::cout << GREEN1 << "Host: " << _host_info.getHost() <<  std::endl << std::endl;
	std::cout << GREEN1 << "User: " << _host_info.getUser() <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS() <<  std::endl << std::endl;
	std::cout << GREEN1 << "Kernel: " << _os_info.getType() <<  std::endl << std::endl;
	std::cout << GREEN1 << "Kernel Version: " << _os_info.getVersion() <<  std::endl << std::endl;
	
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	std::cout << GREEN1 << "OS: " << _os_info.getOS(); <<  std::endl << std::endl;
	*/


	NcursesOut 	visualMode(ram, time, host_info, os_info, net_info, cpu_info);

	visualMode.printOutput();
	//std::cout << "===>" << net_info.getNetworkInfo() << std::endl;



	return 0;
}
