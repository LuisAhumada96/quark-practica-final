#pragma once


#include <list>
#include <string>

enum class PrendaTipo{Camisa,Pantalon};

class PrendaCotizacionStrategy;
class CotizacionStrategyFactory
{
public:
	CotizacionStrategyFactory();
	~CotizacionStrategyFactory() = default;
	static PrendaCotizacionStrategy* GetStrategy(std::string prenda);
};

