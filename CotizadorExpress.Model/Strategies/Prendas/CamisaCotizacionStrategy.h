#pragma once
#include "PrendaCotizacionStrategy.h"
class CamisaCotizacionStrategy:public PrendaCotizacionStrategy
{
private:
	double m_mangaCortaAjuste = -0.10; // 12% para pantalon chupin
	double m_cuelloMaoAjuste = 0.03; // 3% para cuello mao

public:
	CamisaCotizacionStrategy();
	~CamisaCotizacionStrategy() = default;

	// Heredado vía IPrendaCotizacionStrategy
	const std::string GetStrategyType() override;
	virtual double CotizarPrenda(Prenda* prenda) override;
};

