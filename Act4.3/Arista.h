#ifndef ARISTA_H
#define ARISTA_H

template <class T>
class Arista
{
	public:
		T mes;
		T dia;
		T hora;
		T origen;
	    T destino;
	    T razon;
	    Arista();
	    Arista(T mes, T dia, T hora, T origen, T destino, T razon);
	    
	    T getOrigen()
	    {
	    	return this->origen;
		}
		
		T getDestino()
		{
			return this->destino;
		}
};

template<class T>
Arista<T>::Arista()
{
	this->mes = " ";
	this->dia = " ";
	this->hora = " ";
	this->origen = " ";
	this->destino = " ";
	this->razon = " ";
}

template<class T>
Arista<T>::Arista(T mes, T dia, T hora, T origen, T destino, T razon) 
{
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->origen = origen;
    this->destino = destino;
    this->razon = razon;
}


#endif
