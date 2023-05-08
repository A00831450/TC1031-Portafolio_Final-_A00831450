#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

string erasePort(string);

int main()
{
	ifstream in("bitacoraACT5_2.txt");
	
	string mes, dia, hora, ip, razon;
	int count = 91910;
	string tempIp;
	
	string ipBuscar;
	
    string info;

	unordered_map<string, vector<string>> umap;
	
	while(count != 0)
	{
		in>>mes>>dia>>hora>>ip;
		getline(in,razon);

            info = mes + " " + dia + " " + hora + " " + ip + " "+ razon;
            tempIp = ip;
            
            tempIp = erasePort(tempIp);
            if(umap.count(tempIp) == 0){
                vector<string> pr = {info};
                pair<string,vector<string>> pr2= {tempIp,pr};
                umap.insert(pr2);
            }
            else{
                umap[tempIp].push_back(info);
            }
            count--;
            cout << count << endl;
	}
	
	cout<<"\nIngresar el Ip a Buscar: ";
	cin>>ipBuscar;
	ipBuscar.erase(remove(ipBuscar.begin(), ipBuscar.end(),'.'), ipBuscar.end());

  for(int i = 0; i < umap[ipBuscar].size(); i++){ 
      cout << umap[ipBuscar][i] << endl;
  }

}

string erasePort(string ip){
    ip.erase(remove(ip.begin(), ip.end()-5,'.'), ip.end());
    return ip;
}
