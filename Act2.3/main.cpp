#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "LinkedList.h"

using namespace std;

int main(){
	LinkedList<string> pila;
	ifstream in("bitacora.txt");
	
	string mes;
	string dia;
	string hora;
	string ip;
	string razon;
	
	int size = 0;
	
	string ipInicial;
	string ipFinal;
	
	cout<<"Bienvenido! Favor de esperar a que se termine el ordenamiento"<<endl;
	if(in != NULL)
	{
		while(in >> mes)
		{
			in>>dia>>hora>>ip;
			getline(in, razon);
			pila.create(mes,dia,hora,ip,razon);
			size++;
		}
	}
	pila.beginMerge();
	
	cout<<"Ingresar el valor inicial de ip que desea buscar en formato exacto y que sea menor que el ip segundo Ej: #.#.#:#### : "<<endl;
	cin>>ipInicial;
	cout<<"Ingresar el valor final de ip que desea buscar: "<<endl;
	cin>>ipFinal;
	
	in.close();

	pila.printRange(ipInicial, ipFinal);
	
	pila.printAll();
}
