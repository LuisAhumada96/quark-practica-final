#pragma once

class Prenda;

class Cotizacion
{
private:
	int m_id;
	int m_codigoVendedor;
	Prenda* m_prendaCotizada;
	int m_cantidadCotizadas;
	double resultadoCotizacion;
public:
	Cotizacion();
	~Cotizacion();
};

