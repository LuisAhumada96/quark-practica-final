#include "Presentador.h"
#include "Interfaces/IView.h"
#include "../Entities/Vendedor/Vendedor.h"
#include "Tienda/Tienda.h"
#include "Camisa/Camisa.h"
#include <Pantalon/Pantalon.h>
#include "Cotizacion/Cotizacion.h"
#include "../../CotizadorExpress.Model/PrendaFactory.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

Presentador::Presentador(IView* view) :m_view(view)
{
	this->m_vendedor = new Vendedor(1, "Juan", "Campanaso", new Tienda("Quark Gear Store", "Avenida Siempre Viva 500"));
}

Presentador::~Presentador()
{

}

void Presentador::GetItemsMenuDePrendas()
{
	auto items = PrendaFactory::GetInstance()->GetPrendasTipos();
	m_view->SetMenuPrendaItems(items);
}

std::map<std::string, std::string> Presentador::GetItemsCalidad()
{
	auto items = PrendaFactory::GetInstance()->GetPrendasCalidad();
	return items;
}

void Presentador::MostrarDatosDeTienda()
{
	Tienda* tienda = this->m_vendedor->GetTienda();
	this->m_view->MostrarTexto(tienda->GetNombre() + " | " + tienda->GetDireccion());
}

void Presentador::MostrarDatosDeVendedor()
{
	this->m_view->MostrarTexto(this->m_vendedor->GetNombre() + " " +
		this->m_vendedor->GetApellido() + " | " +
		std::to_string(this->m_vendedor->GetCodigo()));
}

void Presentador::ListarCotizacionesDeVendedor(){

	if (m_vendedor->GetCotizaciones().size() == 0) {
		m_view->MostrarTexto("No hay cotizaciones registradas para este vendedor.");
	}

	for (auto& c : m_vendedor->GetCotizaciones())
	{
		auto datos = c->ImprimirDatos();

		for (auto& d : datos)
		{
			m_view->MostrarTexto(d.first + d.second);
		}

		m_view->MostrarTexto("-----------------------------------------------------");
	}
}

void Presentador::SeleccionarTipoDePrenda(int option)
{
	m_prendaCotizada = PrendaFactory::GetInstance()->GetPrenda(option);

	auto prendas = PrendaFactory::GetInstance()->GetPrendasTipos();
	
	std::map<std::string, std::string> opciones = std::map<std::string, std::string>{ {"1","Si"},{"2","No"} };

	switch (option)
	{
	case (int)TipoPrenda::Camisa:
	{
		Camisa* camisa = dynamic_cast<Camisa*>(m_prendaCotizada);
		
		std::string input = "";
		std::string paso = "PASO 2.a: La camisa a cotizar, ?Es Manga Corta?";

		
		m_view->SolicitarDatoDeCotizacion(input, paso, opciones);
		m_view->MostrarTexto("");
		
		int mangaInt = std::stoi(input);

		camisa->setTipoManga(static_cast<TipoManga>(mangaInt));

		paso = "PASO 2.b: La camisa a cotizar, ?Es Cuello Mao?";

		m_view->SolicitarDatoDeCotizacion(input, paso, opciones);
		m_view->MostrarTexto("");
		int cuelloInt = std::stoi(input);

		camisa->SetTipoCuello(static_cast<TipoCuello>(cuelloInt));
		break;
	}
	case (int)TipoPrenda::Pantalon:
	{
		Pantalon* pantalon = dynamic_cast<Pantalon*>(m_prendaCotizada);
		std::string input = "";
		std::string paso = "PASO 2: El Pantal?n a cotizar, ?Es Chup?n?";
		
		m_view->SolicitarDatoDeCotizacion(input, paso, opciones);
		m_view->MostrarTexto("");

		int pantalonTipoInt = std::stoi(input);
		pantalon->SetTipoPantalon(static_cast<PantalonTipo>(pantalonTipoInt));

		break;
	}
	default:
		break;
	}
}

void Presentador::SetCalidadDePrendaCotizada(std::string calidad) {

	int calidadInt = std::stoi(calidad);
	m_prendaCotizada->SetCalidad(static_cast<Calidad>(calidadInt));
}

void Presentador::SetPrecioDePrenda(double valor) {
	m_prendaCotizada->SetPrecioUnitario(valor);
}

void Presentador::BuscarStockDePrendaACotizar() {
	
	auto tienda = m_vendedor->GetTienda();
	auto prendaEnExistencia = tienda->BuscarPrenda(m_prendaCotizada);

	if (prendaEnExistencia == nullptr) {
		m_view->MostrarTexto("No se encontr? la prenda que buscaba");
		return;
	}

	m_prendaCotizada->SetStockDisponible(prendaEnExistencia->GetStockDisponible());

	m_view->MostrarTexto("");
	m_view->MostrarTexto("INFORMACI?N:");
	m_view->MostrarTexto("EXISTE " + std::to_string(prendaEnExistencia->GetStockDisponible()) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
	m_view->MostrarTexto("");
}

void Presentador::ReservarStockDePrenda(int &cantidad, bool &stockValido)
{
	Prenda* p = m_vendedor->GetTienda()->BuscarPrenda(m_prendaCotizada);
	if (cantidad > p->GetStockDisponible()) {
		
		m_view->MostrarMensaje("La cantidad ingresada supera al stock disponible. Por favor ingrese una cantidad menor o igual al stock actual");
		stockValido = false;
		return;
	}
	else {
		p->SetStockDisponible(p->GetStockDisponible() - cantidad);
		m_cantidadCotizada = cantidad;
		stockValido = true;

	}
}
void Presentador::CotizarPrenda() {
	
	char buffer[80];
	time_t rawtime = time(nullptr);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);

	struct tm* timeinfoPtr = &timeinfo;
	strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfoPtr);

	auto cotizacion = m_vendedor->RealizarCotizacion(m_prendaCotizada, m_cantidadCotizada,buffer);
	auto cotizacionDatos = cotizacion->ImprimirDatos();
	
	m_view->MostrarCotizacion(cotizacionDatos);

}