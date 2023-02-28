#include "Tienda.h"

#include "../Camisa/Camisa.h"
#include "../Pantalon/Pantalon.h"
#include "../../Strategies/Factory/CotizacionStrategyFactory.h"
#include "../../Strategies/Prendas/PrendaCotizacionStrategy.h"


Tienda::Tienda(std::string nombre, std::string direccion) :m_nombre(nombre), m_direccion(direccion)
{

	// STOCK DE PRENDAS
	this->l_prendasStock = { new Camisa(Standard, 100, TipoCuello::Mao,   TipoManga::Corta),
							new Camisa(Premium,   100, TipoCuello::Mao,   TipoManga::Corta),
							new Camisa(Standard,  150, TipoCuello::Comun, TipoManga::Corta),
							new Camisa(Premium,   150, TipoCuello::Comun, TipoManga::Corta),

							new Camisa(Standard,    75,  TipoCuello::Mao,   TipoManga::Larga),
							new Camisa(Premium,     75,  TipoCuello::Mao,   TipoManga::Larga),
							new Camisa(Standard,    175, TipoCuello::Comun, TipoManga::Larga),
							new Camisa(Premium,     175, TipoCuello::Comun, TipoManga::Larga),

							new Pantalon(Standard, 750, PantalonTipo::Chupin),
							new Pantalon(Premium,  750, PantalonTipo::Chupin),
							new Pantalon(Standard, 250, PantalonTipo::Comun),
							new Pantalon(Premium,  250, PantalonTipo::Comun)
							};
}

Tienda::~Tienda()
{

}

Prenda* Tienda::BuscarPrenda(Prenda* prenda)
{
	for (auto& p : l_prendasStock)
	{
		if (p->DescripcionCoincide(prenda)) return p;
	}
	return nullptr;
}
std::string Tienda::GetNombre()
{
	return this->m_nombre;
}
std::string Tienda::GetDireccion()
{
	return this->m_direccion;
}

PrendaCotizacionStrategy* Tienda::GetPoliticaDeCotizacion(std::string nombreDePrenda)
{
	return CotizacionStrategyFactory::GetStrategy(nombreDePrenda);
}
