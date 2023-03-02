#pragma once


#include <list>
#include <string>

enum class PrendaTipo{Camisa,Pantalon};

class PrendaCotizacionStrategy;
class CotizacionStrategyFactory
{
private:
	static CotizacionStrategyFactory* m_cotizacionStrategyFactory;
	CotizacionStrategyFactory();
	~CotizacionStrategyFactory();
public:

	// No est� permitido crear una copia, es una instancia �nica en el sistema
	CotizacionStrategyFactory(CotizacionStrategyFactory& otro) = delete;
	void operator=(const CotizacionStrategyFactory&) = delete;
	
	PrendaCotizacionStrategy* GetStrategy(std::string prenda);

	static CotizacionStrategyFactory* GetInstance();


};

