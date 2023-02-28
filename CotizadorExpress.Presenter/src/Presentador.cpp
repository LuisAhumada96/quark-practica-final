#include "Presentador.h"
#include "Interfaces/IView.h"
#include "../Entities/Vendedor/Vendedor.h"
#include "Tienda/Tienda.h"
#include "Camisa/Camisa.h"
#include "Cotizacion/Cotizacion.h"
#include "../../CotizadorExpress.Model/PrendaFactory.h"

Presentador::Presentador(IView* view) :m_view(view)
{
	this->m_vendedor = new Vendedor(1, "Juan", "Campanaso", new Tienda("Quark Gear Store", "Avenida Siempre Viva 500"));
}

Presentador::~Presentador()
{

}

void Presentador::GetItemsMenuDePrendas()
{
	auto items = PrendaFactory::GetPrendasTipos();
	m_view->SetMenuPrendaItems(items);
}

std::map<std::string, std::string> Presentador::GetItemsCalidad()
{
	auto items = PrendaFactory::GetPrendasCalidad();
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

void Presentador::SeleccionarTipoDePrenda(int option)
{
	m_prendaCotizada = PrendaFactory::GetPrenda(option);

	auto prendas = PrendaFactory::GetPrendasTipos();

	switch (option)
	{
	case (int)TipoPrenda::Camisa:
	{
		Camisa* camisa = dynamic_cast<Camisa*>(m_prendaCotizada);
		
		std::string input = "";
		std::string paso = "PASO 2.a: La camisa a cotizar, �Es Manga Corta?";

		std::map<std::string, std::string> opciones = std::map<std::string, std::string>{ {"1","Si"},{"2","No"} };
		
		m_view->SolicitarDatoDeCotizacion(input, paso, opciones);
		m_view->MostrarTexto("");
		
		int mangaInt = std::stoi(input);

		camisa->setTipoManga(static_cast<TipoManga>(mangaInt));

		paso = "PASO 2.b: La camisa a cotizar, �Es Cuello Mao?";

		m_view->SolicitarDatoDeCotizacion(input, paso, opciones);
		m_view->MostrarTexto("");
		int cuelloInt = std::stoi(input);

		camisa->SetTipoCuello(static_cast<TipoCuello>(cuelloInt));

	}
	case (int)TipoPrenda::Pantalon:
	{

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
		m_view->MostrarTexto("No se encontr� la prenda que buscaba");
		return;

	}
	m_prendaCotizada = prendaEnExistencia;

	m_view->MostrarTexto("Existe " + std::to_string(prendaEnExistencia->GetStockDisponible()) + " de la prenda seleccionada");
}

void Presentador::ReservarStockDePrenda(int &cantidad, bool &stockValido)
{
	if (cantidad > m_prendaCotizada->GetStockDisponible()) {
		m_view->MostrarTexto("La cantidad ingresada supera al stock disponible. Por favor ingrese una cantidad menor o igual al stock actual");
		stockValido = false;
		return;
	}
	else {
		m_cantidadCotizada = cantidad;
		stockValido = true;
	}
}
void Presentador::IniciarCotizacion() {

	auto cotizacion = m_vendedor->RealizarCotizacion(m_prendaCotizada,m_cantidadCotizada,"");

}
