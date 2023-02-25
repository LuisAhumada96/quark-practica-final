#pragma once
#include "../Tienda/Tienda.h"
#include "../Cotizacion/Cotizacion.h"
class Vendedor
{
private:
	int m_codigoVendedor;
	std::string m_nombre;
	std::string m_apellido;
	Tienda* m_tienda;
	std::list<Cotizacion*> l_cotizaciones = {};

public:
	Vendedor(int codigoVendedor, std::string nombre, std::string apellido,Tienda* tienda):m_codigoVendedor(codigoVendedor),
																						  m_nombre(nombre),
																						  m_apellido(apellido),
																						  m_tienda(tienda){}
	~Vendedor();

	void realizarCotizacion();
};

