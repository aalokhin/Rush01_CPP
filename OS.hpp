#ifndef OS_HPP
#define OS_HPP
#include "IMonitorModule.hpp"

class OS: public IMonitorModule {
	public:
		OS(void);
		OS(const OS& copy);
		~OS(void);
		OS& operator=(const OS&);	

		std::string getOS() const;
		std::string getVersion() const;
		std::string getType() const;
		std::string getDetails() const;
		int GetRelease() const;



		std::string getOSname() const;
		std::string getOSver() const;
		std::string getOSbuild() const;

		void refresh();

	private:
		std::string _os;
		std::string _version;
		std::string _type;
		int _release_date;


		std::string _details;

		std::string findOS();
		std::string versionDisplay();
		void 	split_string(const std::string & str, const std::string & delimiter); 

		std::string _OSname;
		std::string _OSver;
		std::string _OSbuild;

};

#endif