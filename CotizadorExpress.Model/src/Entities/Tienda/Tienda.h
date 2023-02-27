#pragma once
#include <list>
#include "../Prenda/Prenda.h"
#include "../../Strategies/Prendas/PrendaCotizacionStrategy.h"


class Tienda
{
private:
	std::string m_nombre;
	std::string m_direccion;
	std::list<Prenda*> l_prendasStock;
public:
	Tienda(std::string nombre, std::string direccion);
	~Tienda();
	Prenda* BuscarPrenda(std::string nombre);
	std::string GetNombre();
	std::string GetDireccion();
	std::list<PrendaCotizacionStrategy*> GetPoliticasDeCotizacion();
};


