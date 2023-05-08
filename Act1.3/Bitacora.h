#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Bitacora
{
	public:
		Bitacora();
		~Bitacora();
		Bitacora(string mes, int dia, string hora, string ip, string razon, int orden);
		string mes;
		int dia;
		string hora;
		string ip;
		string razon;
		int orden;
		string tempHora;
		
		void printBitacora()
		{
			cout<<mes<<" "<<dia<<" "<<hora<<" "<<ip<<" "<<razon<<endl;
		};
		
		bool operator>(Bitacora bitacora){return orden > bitacora.orden;};
		
		int regionOrden()
		{
			this->tempHora = hora;
			this->tempHora.erase(remove(this->tempHora.begin(), this->tempHora.end(), ':'), this->tempHora.end());
			return (stoi(tempHora));
		}
		
		void multiOrden();
};

#endif
