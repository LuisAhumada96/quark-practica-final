#pragma once

#include "../Prenda/Prenda.h"


enum PantalonTipo {Comun, Chupin};

class Pantalon:public Prenda
{
	friend class PantalonCotizacionStrategy;

private:
	const char* m_nombre = "Pantalon";
	PantalonTipo m_pantalonTipo;

public:
	Pantalon(Calidad calidad, double precioUnitario, int unidadesStock,PantalonTipo pantalonTipo) :Prenda(calidad, precioUnitario, unidadesStock), 
																								   m_pantalonTipo(pantalonTipo) {};
	~Pantalon();

	// Heredado vía Prenda
	virtual std::string MostrarTipoDePrenda() override;

};



