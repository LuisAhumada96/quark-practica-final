#pragma once

#include "../Prendas/PrendaCotizacionStrategy.h"
class CotizacionStrategyFactory
{
public:
	CotizacionStrategyFactory();
	~CotizacionStrategyFactory() = default;
	static PrendaCotizacionStrategy* GetStrategy(std::string prenda);
};

