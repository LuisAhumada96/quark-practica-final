#pragma once



#include <string>

enum Calidad {Standard, Premium};

class Prenda
{
private:
	Calidad m_calidad;
	double m_precioUnitario;
	int m_unidadesStock;

public:
	Prenda(Calidad calidad, double precioUnitario, int unidadesStock) :m_calidad(calidad), m_precioUnitario(precioUnitario), m_unidadesStock(unidadesStock){}
	virtual ~Prenda();
	double GetPrecioUnitario();
	Calidad getCalidad();
	virtual std::string MostrarTipoDePrenda() = 0;

};

