#pragma once
#include <list>
#include "../Prenda/Prenda.h"
class Tienda
{
private:
	char* m_nombre;
	char* m_direccion;
	std::list<Prenda> l_prendas;

};
