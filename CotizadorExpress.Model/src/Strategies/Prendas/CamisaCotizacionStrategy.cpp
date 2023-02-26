#include "CamisaCotizacionStrategy.h"
#include "../../Entities/Camisa/Camisa.h"
CamisaCotizacionStrategy::CamisaCotizacionStrategy()
{
}

const std::string CamisaCotizacionStrategy::GetStrategyType()
{
    return "Camisa";
}

double CamisaCotizacionStrategy::CotizarPrenda(Prenda* prenda)
{
    double total = prenda->GetPrecioUnitario();
    auto camisa = dynamic_cast<Camisa*>(prenda);

    if (camisa->m_tipoManga == TipoManga::Corta) {
        total = total * (1 + this->m_mangaCortaAjuste);
    }
    CotizarPorCalidad(prenda, total);
    return total;
}
