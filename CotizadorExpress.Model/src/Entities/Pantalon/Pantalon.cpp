
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
	std::string valor = "";
	valor.append(this->m_nombre);
	valor.append(" - ");
	valor.append(this->m_pantalonTipo == PantalonTipo::Comun ? "Común" : "Chupin");
	return valor;
}

std::string Pantalon::GetNombreDePrenda()
{
	return m_nombre;
}

bool Pantalon::DescripcionCoincide(Prenda* prenda)
{
	bool base = Prenda::DescripcionCoincide(prenda);
	if (!base) return false;

	auto pantalon = dynamic_cast<Pantalon*>(prenda);
	
	if (pantalon == nullptr) return false;

	if (this->m_pantalonTipo != pantalon->m_pantalonTipo) return false;

	return true;
}
