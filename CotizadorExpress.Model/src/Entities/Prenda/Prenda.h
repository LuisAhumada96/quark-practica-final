#pragma once



#include <string>

enum Calidad {Standard = 1, Premium};

class Prenda
{
private:
	Calidad m_calidad;
	double m_precioUnitario = 0;
	int m_unidadesStock;
public:
	Prenda();
	Prenda(Calidad calidad, int unidadesStock) :m_calidad(calidad), m_unidadesStock(unidadesStock){}
	virtual ~Prenda();
	
	double GetPrecioUnitario();
	void SetPrecioUnitario(double precioUnitario);	
	
	void SetCalidad(Calidad calidad);
	Calidad GetCalidad();
	int GetStockDisponible();
	void SetStockDisponible(int cantidad);
	
	virtual bool DescripcionCoincide(Prenda* prenda);
	virtual std::string GetCaracteristicasDePrenda() = 0;
	virtual std::string GetNombreDePrenda() = 0;

};

