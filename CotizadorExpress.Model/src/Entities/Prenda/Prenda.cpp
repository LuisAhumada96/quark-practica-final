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

Calidad Prenda::GetCalidad()
{
	return this->m_calidad;
}

void Prenda::SetCalidad(Calidad calidad)
{
	m_calidad = calidad;
}

bool Prenda::DescripcionCoincide(Prenda* prenda)
{
	if (prenda->GetNombreDePrenda() != this->GetNombreDePrenda()) return false;
	if ((this->GetCalidad() != prenda->GetCalidad())) return false;
	return true;
}

int Prenda::GetStockDisponible() {
	return this->m_unidadesStock;
}
void Prenda::SetStockDisponible(int cantidad) {
	this->m_unidadesStock = cantidad;
}