#include "Prenda.h"

Prenda::Prenda()
{
}

Prenda::~Prenda()
{
}

double Prenda::GetPrecioUnitario()
{
	return this->m_precioUnitario;
}

void Prenda::SetPrecioUnitario(double precioUnitario)
{
	m_precioUnitario = precioUnitario;
}

Calidad Prenda::getCalidad()
{
	return this->m_calidad;
}

void Prenda::setCalidad(Calidad calidad)
{
	m_calidad = calidad;
}
