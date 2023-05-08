#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "ipAccess.h"
#include "BST.h"

using namespace std;

int main()
{
	BST tree;
	ifstream in("bitacora2.txt");
	string mes, dia, hora, ip, razon;
	int size;
	vector<ipAccess> lista;
	bool check = false;
	
	if(in != NULL)
	{
		while(in >> mes)
		{
			in>>dia>>hora>>ip;
			getline(in, razon);
			
			string tempIp = ip;
			tempIp.erase(remove(tempIp.begin(), tempIp.end()-5,'.'), tempIp.end());
			
			if(lista.size() == 0)
			{
				lista.push_back(ipAccess(1,tempIp,ip));
			}
			else
			{
				for(int i = 0; i < lista.size(); i++)
				{
					if(lista[i].getTempIp().compare(tempIp) == 0)
					{
						lista[i].setAccess(1);
						check = false;
						break;
					}
					else
					{
						check = true;
					}
				}
				if(check)
				{
					lista.push_back(ipAccess(1,tempIp,ip));
				}
			}
			size++;
		}
	}
	
	for(int i = 0; i < lista.size(); i++)
	{
		//cout<<lista[i].getIp()<<"  "<<lista[i].getAccess()<<" "<<lista[i].getTempIp()<<endl;
		tree.insert(lista[i].getAccess(),lista[i].getIp());
	}
	
	cout<<"====================================================================================="<<endl;
	tree.beginInorden();
	cout<<"===================================================================================="<<endl;
	tree.printListaCinco();
	
	return 0;
}
