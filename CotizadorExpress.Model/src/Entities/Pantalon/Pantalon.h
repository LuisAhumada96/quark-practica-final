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
	Pantalon();
	Pantalon(Calidad calidad, int unidadesStock,PantalonTipo pantalonTipo) :Prenda(calidad, unidadesStock), m_pantalonTipo(pantalonTipo) {};
	~Pantalon();

	// Heredado v�a Prenda
	virtual std::string GetCaracteristicasDePrenda() override;


	// Heredado v�a Prenda
	virtual std::string GetNombreDePrenda() override;

};


