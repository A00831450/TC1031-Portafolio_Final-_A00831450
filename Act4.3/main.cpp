#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Grafo.h"
#include "Arista.h"

using namespace std;

int main()
{
	ifstream in("bitacoraACT4_3.txt");
	int nIps,nAristas = 0;
	in>>nIps>>nAristas;
	vector<string> vertices;
	
	string ip;
	string mes,dia,hora,ipOrigen,ipDestino,razon;
	int count = nAristas;

	while(nIps > 0)
	{
		in>>ip;
		vertices.push_back(ip);
		//cout<<vertices[vertices.size()-1]<<endl;
		nIps--;
	}
	Grafo<string> grafo(vertices);
	cout<<"Favor de esperar a que termine el procesamiento"<<endl;
	while(nAristas > 0)
	{
		in>>mes>>dia>>hora>>ipOrigen>>ipDestino;
		getline(in,razon);
		for(int i = 0; i < 6;i++)
		{
			if(ipOrigen[ipOrigen.size()-1] != ':')
			{
				ipOrigen.pop_back();
			}
		}
		ipOrigen.pop_back();
		if(count % 1000 == 0 || count % 10000 == 0)
		{	
			cout<<count<<endl;
			
		}
		for(int i = 0; i < 6;i++)
		{
			if(ipDestino[ipDestino.size()-1] != ':')
			{
				ipDestino.pop_back();
			}
		}
		ipDestino.pop_back();
		grafo.insert(Arista<string>(mes,dia,hora,ipOrigen,ipDestino,razon));
		nAristas--;
		count--;
	}	
	grafo.loadGraph(nIps,nAristas);
	grafo.mayorCinco();
	grafo.bootMaster();
}
