#pragma once

#include <string>
#include <map>
class Prenda;
class Cotizacion
{
private:
	int m_id;
	std::string m_fechaCotizada;
	int m_codigoVendedor;
	Prenda* m_prendaCotizada;
	int m_unidadesCotizadas;
	double m_resultadoCotizacion = 0;
public:
	Cotizacion(int id, int codigoVendedor, Prenda* prenda, int cantidadCotizada, std::string fechaCotizada, double resultadoCotizacion):m_id(id),
																				m_codigoVendedor(codigoVendedor),
																				m_prendaCotizada(prenda),
																				m_unidadesCotizadas(cantidadCotizada),
																				m_fechaCotizada(fechaCotizada),
																				m_resultadoCotizacion(resultadoCotizacion){}
	~Cotizacion();
	std::map<std::string,std::string> ImprimirDatos();
};

