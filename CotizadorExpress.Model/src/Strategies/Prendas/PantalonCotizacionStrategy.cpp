#include "PantalonCotizacionStrategy.h"
#include "../../Entities/Pantalon/Pantalon.h"

PantalonCotizacionStrategy::PantalonCotizacionStrategy()
{
}

const std::string PantalonCotizacionStrategy::GetStrategyType()
{
    return "Pantalon";
}

double PantalonCotizacionStrategy::CotizarPrenda(Prenda* prenda)
{
    auto total = PrendaCotizacionStrategy::CotizarPrenda(prenda);
    auto pantalon = dynamic_cast<Pantalon*>(prenda);
    
    if (pantalon->m_pantalonTipo == Chupin) {
        total = total + (1 + this->m_chupinAjuste);
    }
    CotizarPorCalidad(prenda, total);
    return total;
}
