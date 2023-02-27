#pragma once



#include <string>

enum Calidad {Standard = 1, Premium};

class Prenda
{
private:
	Calidad m_calidad;
	double m_precioUnitario;
	int m_unidadesStock;
public:
	Prenda();
	Prenda(Calidad calidad, int unidadesStock) :m_calidad(calidad), m_unidadesStock(unidadesStock){}
	virtual ~Prenda();
	
	double GetPrecioUnitario();
	void SetPrecioUnitario(double precioUnitario);	
	
	Calidad getCalidad();
	void setCalidad(Calidad calidad);
	virtual bool DescripcionCoincide(Prenda* prenda) = 0;
	virtual std::string GetCaracteristicasDePrenda() = 0;
	virtual std::string GetNombreDePrenda() =0;

};

