#pragma once

class Prenda;

class Cotizacion
{
private:
	int m_id;
	int m_codigoVendedor;
	Prenda* m_prendaCotizada;
	int m_cantidadCotizadas;
	double resultadoCotizacion = 0;
public:
	Cotizacion(int id, int codigoVendedor, Prenda* prenda, int cantidadCotizada):m_id(id),
																				m_codigoVendedor(codigoVendedor),
																				m_prendaCotizada(prenda),
																				m_cantidadCotizadas(cantidadCotizada) {}
	~Cotizacion();
};

