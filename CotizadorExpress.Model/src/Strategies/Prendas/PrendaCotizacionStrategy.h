#pragma once
#include <string>
#include "../../Entities/Prenda/Prenda.h"


class PrendaCotizacionStrategy
{
private:
	double m_calidadPremiumAjuste = 0.30; // 30% de aumento en el precio
public:
	PrendaCotizacionStrategy() = default;
	~PrendaCotizacionStrategy() = default;

	virtual const std::string GetStrategyType() = 0;
	virtual double CotizarPrenda(Prenda* prenda) = 0;
protected:
	virtual void CotizarPorCalidad(Prenda* prenda, double &subtotal);
};

