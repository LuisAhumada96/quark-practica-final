#pragma once

#include "../Prendas/PrendaCotizacionStrategy.h"

#include <list>

enum class PrendaTipo{Camisa,Pantalon};

class CotizacionStrategyFactory
{
public:
	CotizacionStrategyFactory();
	~CotizacionStrategyFactory() = default;
	static PrendaCotizacionStrategy* GetStrategy(std::string prenda);
	static std::list<std::string> GetPrendasCategorias();
};

