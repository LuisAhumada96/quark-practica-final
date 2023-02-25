#include "Cotizacion.h"
#include "../Prenda/Prenda.h"


class Pantalon:public Prenda
{
public:
	Pantalon();
	~Pantalon();

private:


	// Heredado vía Prenda
	virtual std::string MostrarTipoDePrenda() override;

};