
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

bool Pantalon::DescripcionCoincide(Prenda* prenda)
{
	if (prenda->GetNombreDePrenda() != this->GetNombreDePrenda()) return false;
	if ((this->getCalidad() != prenda->getCalidad())) return false;
	
	auto pantalon = dynamic_cast<Pantalon*>(prenda);
	
	if (pantalon == nullptr) return false;

	if (this->m_pantalonTipo != pantalon->m_pantalonTipo) return false;

	return true;
}
