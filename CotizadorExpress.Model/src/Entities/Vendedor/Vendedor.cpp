#include "Vendedor.h"

#include "../Tienda/Tienda.h"
#include "../../Strategies/Prendas/PrendaCotizacionStrategy.h"
Vendedor::~Vendedor()
{
}

Cotizacion* Vendedor::RealizarCotizacion(Prenda *prenda,int cantidadCotizada, std::string fechaCotizada)
{

	auto nombre = prenda->GetNombreDePrenda();
	auto estrategiaDeCotizacion = this->m_tienda->GetPoliticaDeCotizacion(nombre);
	auto precioUnitarioCotizado = estrategiaDeCotizacion->CotizarPrenda(prenda);

	double total = precioUnitarioCotizado * cantidadCotizada;

	int id = static_cast<int>(l_cotizaciones.size() + 1);
	Cotizacion* cotizacion = new Cotizacion(id, this->m_codigoVendedor, prenda, cantidadCotizada, fechaCotizada, total);
	
	l_cotizaciones.push_back(cotizacion);

	return cotizacion;
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

std::list<Cotizacion*> Vendedor::GetCotizaciones() {
	return this->l_cotizaciones;
}