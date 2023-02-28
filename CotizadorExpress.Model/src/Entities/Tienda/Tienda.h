#pragma once
#include <list>
#include "../Prenda/Prenda.h"

class PrendaCotizacionStrategy;
class Tienda
{
private:
	std::string m_nombre;
	std::string m_direccion;
	std::list<Prenda*> l_prendasStock;
public:
	Tienda(std::string nombre, std::string direccion);
	~Tienda();
	Prenda* BuscarPrenda(Prenda* prenda);
	std::string GetNombre();
	std::string GetDireccion();
	PrendaCotizacionStrategy* GetPoliticaDeCotizacion(std::string nombreDePrenda);
};


