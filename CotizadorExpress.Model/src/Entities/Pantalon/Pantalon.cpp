
#include "Pantalon.h"
#include <string>



Pantalon::~Pantalon()
{
}

std::string Pantalon::MostrarTipoDePrenda()
{
	std::string tipo;
	tipo.append(this->m_nombre + ' ' + std::to_string(this->m_pantalonTipo));
	return tipo;
}
