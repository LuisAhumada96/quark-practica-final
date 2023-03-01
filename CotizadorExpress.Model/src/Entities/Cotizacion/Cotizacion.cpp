#include "Cotizacion.h"
#include "../Prenda/Prenda.h"
#include<format>

Cotizacion::~Cotizacion()
{

}

std::map<std::string,std::string> Cotizacion::ImprimirDatos()
{
	float precioUnitario = this->m_prendaCotizada->GetPrecioUnitario();

	std::string numeroTexto = std::to_string(precioUnitario);
	std::string precioRedondeado = numeroTexto.substr(0, numeroTexto.find(".") + 3);

	numeroTexto = std::to_string(this->m_resultadoCotizacion);
	std::string precioFinalRedondeado = numeroTexto.substr(0, numeroTexto.find(".") + 3);


	return std::map<std::string, std::string>{ {"Número de identificación: ", std::to_string(this->m_id)},
			{"Fecha y hora de la cotización: " , this->m_fechaCotizada },
			{"Código del Vendedor: " , std::to_string(this->m_codigoVendedor)},
			{"Prenda cotizada: " , this->m_prendaCotizada->GetCaracteristicasDePrenda() },
			{"Precio unitario:" , precioRedondeado },
			{"Cantidad de Unidades Cotizadas: " , std::to_string(this->m_unidadesCotizadas)},
			{"Precio Final: " , precioFinalRedondeado } };
}
