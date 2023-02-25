#pragma once
#include "PrendaCotizacionStrategy.h"
class PantalonCotizacionStrategy:public PrendaCotizacionStrategy
{
	
private:
	double m_chupinAjuste = -0.12; // 12% para pantalon chupin
public:
	PantalonCotizacionStrategy();
	~PantalonCotizacionStrategy() = default;

	// Heredado vía IPrendaCotizacionStrategy
	const std::string GetStrategyType() override;
	virtual double CotizarPrenda(Prenda* prenda) override;
};

