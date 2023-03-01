#pragma once


#include <list>
#include <string>

enum class PrendaTipo{Camisa,Pantalon};

class PrendaCotizacionStrategy;
class CotizacionStrategyFactory
{
private:
	CotizacionStrategyFactory();
	static CotizacionStrategyFactory* m_cotizacionStrategyFactory;
public:

	CotizacionStrategyFactory(CotizacionStrategyFactory& other) = delete;
	void operator=(const CotizacionStrategyFactory&) = delete;
	
	PrendaCotizacionStrategy* GetStrategy(std::string prenda);

	static CotizacionStrategyFactory* GetInstance();


};

