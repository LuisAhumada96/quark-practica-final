#include "CotizacionStrategyFactory.h"
#include "../Prendas/PantalonCotizacionStrategy.h"
#include "../Prendas/CamisaCotizacionStrategy.h"
PrendaCotizacionStrategy* CotizacionStrategyFactory::GetStrategy(std::string prenda)
{
	if (prenda._Equal("Pantalon")) return new PantalonCotizacionStrategy();
	if (prenda._Equal("Camisa")) return new CamisaCotizacionStrategy();
}
