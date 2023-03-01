#include "CotizacionStrategyFactory.h"
#include "../../Strategies/Prendas/PrendaCotizacionStrategy.h"
#include "../Prendas/PantalonCotizacionStrategy.h"
#include "../Prendas/CamisaCotizacionStrategy.h"

CotizacionStrategyFactory::CotizacionStrategyFactory()
{
}

PrendaCotizacionStrategy* CotizacionStrategyFactory::GetStrategy(std::string prenda)
{
	if (prenda._Equal("Pantalon")) return new PantalonCotizacionStrategy();
	if (prenda._Equal("Camisa")) return new CamisaCotizacionStrategy();

	return nullptr;
}

CotizacionStrategyFactory* CotizacionStrategyFactory::GetInstance()
{
	if (m_cotizacionStrategyFactory == nullptr) {
		m_cotizacionStrategyFactory = new CotizacionStrategyFactory();
	}
	return m_cotizacionStrategyFactory;
}
