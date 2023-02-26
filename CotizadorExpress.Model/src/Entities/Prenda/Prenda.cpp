#include "Prenda.h"

Prenda::~Prenda()
{
}

double Prenda::GetPrecioUnitario()
{
	return this->m_precioUnitario;
}

Calidad Prenda::getCalidad()
{
	return this->m_calidad;
}
