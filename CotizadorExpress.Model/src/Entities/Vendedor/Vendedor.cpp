#include "Vendedor.h"

#include "../Tienda/Tienda.h"

Vendedor::~Vendedor()
{
}

void Vendedor::realizarCotizacion()
{
}

std::string Vendedor::GetNombre()
{
	return this->m_nombre;
}

std::string Vendedor::GetApellido()
{
	return this->m_apellido;
}

Tienda* Vendedor::GetTienda()
{
	return this->m_tienda;
}

int Vendedor::GetCodigo() {
	return this->m_codigoVendedor;
}
