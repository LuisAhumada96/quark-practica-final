
#include "Pantalon.h"
#include <string>



Pantalon::Pantalon()
{
}

Pantalon::~Pantalon()
{
}

std::string Pantalon::GetCaracteristicasDePrenda()
{
	std::string tipo;
	tipo.append(this->m_nombre + ' ' + std::to_string(this->m_pantalonTipo));
	return tipo;
}

std::string Pantalon::GetNombreDePrenda()
{
	return m_nombre;
}
