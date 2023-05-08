#include "Bitacora.h"

Bitacora::Bitacora()
{
	this->mes = " ";
	this->dia = 0;
	this->hora = " ";
	this->ip = " ";
	this->razon = " ";
	this->orden = 0; 
}

Bitacora::Bitacora(string m, int d, string h, string i, string r, int o)
{
	this->mes = m;
	this->dia = d;
	this->hora = h;
	this->ip = i;
	this->razon = r;
	multiOrden();
}

void Bitacora::multiOrden()
{
	this->tempHora = hora;
	this->tempHora.erase(remove(this->tempHora.begin(), this->tempHora.end(), ':'), this->tempHora.end());
	if(mes == "Jan")
	{
		orden = 1 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if( mes == "Feb")
	{
		orden = 2 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Mar")
	{
		orden = 3 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Apr")
	{
		orden = 4 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "May")
	{
		orden = 5 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Jun")
	{
		orden = 6 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Jul")
	{
		orden = 7 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Aug")
	{
		orden = 8 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Sep")
	{
		orden = 9 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Oct")
	{
		orden = 10 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Nov")
	{
		orden = 11 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
	else if(mes == "Dec")
	{
		orden = 12 * 100000000;
		orden += dia*1000000;
		orden += stoi(tempHora);
	}
}

Bitacora::~Bitacora()
{
}
