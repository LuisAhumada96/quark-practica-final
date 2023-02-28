#include "PrendaCotizacionStrategy.h"

void PrendaCotizacionStrategy::CotizarPorCalidad(Prenda* prenda, double& subtotal)
{
    if (prenda->GetCalidad() == Premium) subtotal = subtotal * (1 + m_calidadPremiumAjuste);
}
