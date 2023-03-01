#pragma once

#include "../Prenda/Prenda.h"


enum PantalonTipo {Chupin = 1, Comun};

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
	void SetTipoPantalon(PantalonTipo tipo);

	// Heredado v�a Prenda
	virtual std::string GetCaracteristicasDePrenda() override;


	// Heredado v�a Prenda
	virtual std::string GetNombreDePrenda() override;
	bool DescripcionCoincide(Prenda* prenda) override;
};



