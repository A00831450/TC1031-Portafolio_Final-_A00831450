#ifndef IPACCESS_H
#define IPACCESS_H
#include <iostream>
#include <string>

using namespace std;

class ipAccess
{
	public:
		ipAccess()
		{
			access = 0;
			tempIp = " ";
			ip = " ";
		}
		ipAccess(int access, string tempIp, string ip)
		{
			this->access = access;
			this->tempIp = tempIp;
			this->ip = ip;
		}
		
		int access;
		string tempIp;
		string ip;
		
		int getAccess()
		{
			return access;
		}
		string getIp()
		{
			return ip;
		}
		string getTempIp()
		{
			return tempIp;
		}
		
		void setAccess(int access)
		{
			this->access = this->access+access;
		}
		void setAccessBts(int access)
		{
			this->access = access;
		}
		void setIp(string ip)
		{
			this->ip = ip;
		}
};

#endif
