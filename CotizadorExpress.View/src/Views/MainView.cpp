#include "MainView.h"
#include "../src/Presentador.h"
#include <iostream>
#include <iomanip>

const std::string COTIZADOR_NAME = "COTIZADOR EXPRESS";
const std::string INVALID_OPTION_MESSAGE = "Por favor, seleccione una opción válida. Presione ENTER para continuar.";
const std::string INVALID_ARGUMENT_ERROR = "Por favor, ingrese un valor válido. Presione ENTER para continuar.";
const std::string UNEXPECTED_ERROR = "Un error inesperado ha ocurrido. Presione ENTER para continuar.";
const std::string HEADER_PRINCIPAL = COTIZADOR_NAME + " - MENÚ PRINCIPAL";
const std::string HEADER_COTIZACION = COTIZADOR_NAME + " - COTIZAR";
const std::string HEADER_REGISTER = COTIZADOR_NAME + " - HISTORIAL DE COTIZACIONES";

const std::string RETURN_MENU_PRINCIPAL = "Presione 3 para volver al menú principal";

MainView::MainView()
{
	this->m_presentador = new Presentador(this);
	MostrarMenuPrincipal();
}

MainView::~MainView()
{
}


void MainView::MostrarMenuPrincipal()
{
	std::string opcion;
	bool haSalido = false;
	do
	{
		std::system("cls");
		MostrarTexto(HEADER_PRINCIPAL);
		MostrarTexto("-----------------------------------------------------");
		m_presentador->MostrarDatosDeVendedor();
		MostrarTexto("-----------------------------------------------------");
		m_presentador->MostrarDatosDeTienda();
		MostrarTexto("");
		MostrarTexto("1) Historial de Cotizaciones");
		MostrarTexto("2) Realizar Cotización");
		MostrarTexto("3) Salir");
		std::cin >> opcion;
		std::system("cls");
		EjecutarOpcion(opcion.c_str(), haSalido);

	} while (!haSalido);
}

void MainView::EjecutarOpcion(const char* opcion, bool& haSalido) {
	auto str_opcion = std::string(opcion);

	if (str_opcion == "1")
	{

		MostrarHistorialDeVendedor();
		haSalido = false;
	}
	else if (str_opcion == "2") {
		MostrarMenuPrendas();
		haSalido = false;

	}
	else if (str_opcion == "3") {
		haSalido = true;
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else {
		MostrarTexto(INVALID_OPTION_MESSAGE);
		std::cin.get();
		haSalido = false;
	}
}

void MainView::RegresarAMenuPrincipal()
{
	MostrarMenuPrincipal();
}

void MainView::MostrarHistorialDeVendedor() {
	system("cls");
	MostrarTexto(HEADER_REGISTER);
	MostrarTexto("-----------------------------------------------------");
	MostrarTexto(RETURN_MENU_PRINCIPAL);
	MostrarTexto("-----------------------------------------------------");

	m_presentador->ListarCotizacionesDeVendedor();

	MostrarMensaje(RETURN_MENU_PRINCIPAL);
}


void MainView::MostrarMenuPrendas() {

	std::string opcionString = "";
	bool esOpcionValida = false;

	do
	{

		MostrarTexto(HEADER_PRINCIPAL);
		MostrarTexto("-----------------------------------------------------");
		MostrarTexto(RETURN_MENU_PRINCIPAL);
		MostrarTexto("-----------------------------------------------------");
		MostrarTexto("PASO 1: Selecciona la prenda a cotizar: ");
		MostrarTexto("");
		m_presentador->GetItemsMenuDePrendas();

		int contador = 1;
		for (auto& item : m_menuPrendasItems)
		{
			std::string menuItem = std::to_string(contador) + ") " + m_menuPrendasItems[item.first];
			MostrarTexto(menuItem);
			contador++;
		}
		MostrarTexto("-----------------------------------------------------");

		std::cin >> opcionString;
		SeleccionarPrenda(opcionString.c_str(), esOpcionValida);

		std:system("cls");

	} while (!esOpcionValida);

}

void MainView::SeleccionarPrenda(const char* opcion, bool& esOpcionValida) {

	std::system("cls");
	MostrarTexto(HEADER_COTIZACION);
	MostrarTexto("-----------------------------------------------------");
	MostrarTexto(RETURN_MENU_PRINCIPAL);
	MostrarTexto("-----------------------------------------------------");

		int opcionInt = std::stoi(opcion);
		for (const auto& item : m_menuPrendasItems)
		{
			if (opcionInt == item.first)
			{
				m_presentador->SeleccionarTipoDePrenda(opcionInt);
				esOpcionValida = true;
				SeleccionarCalidadDePrenda();
				IngresarPrecioUnitario();
				IngresarCantidadACotizar();
				std::system("cls");
				m_presentador->CotizarPrenda();
				break;
			}
			if (opcionInt == 3) {
				esOpcionValida = true;
				RegresarAMenuPrincipal();
				break;
			}
			else
			{
				esOpcionValida = false;
			}
		}
		if (!esOpcionValida)
		{
			MostrarMensaje(INVALID_OPTION_MESSAGE);
		}
	
}

void MainView::SeleccionarCalidadDePrenda()
{
	bool esValido = false;
	do
	{
		try
		{
			std::system("cls");
			MostrarTexto(HEADER_COTIZACION);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto(RETURN_MENU_PRINCIPAL);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto("PASO 3: Seleccione la calidad de la prenda");
			std::map<std::string, std::string> calidades = m_presentador->GetItemsCalidad();

			std::string valor = "";
			SetValor(valor, calidades, esValido);
			if (esValido) {
				m_presentador->SetCalidadDePrendaCotizada(valor);
			}
			std::system("cls");
		}
		catch (const std::exception&)
		{
			MostrarMensaje(INVALID_OPTION_MESSAGE);
		}
	} while (!esValido);
}

void MainView::IngresarPrecioUnitario() {

	std::string valor = "";
	double valorToDouble = 0;
	bool esValido = false;
	do
	{
		try
		{
			std::system("cls");
			MostrarTexto(HEADER_COTIZACION);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto(RETURN_MENU_PRINCIPAL);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto("Paso 4: Ingrese el precio unitario de la prenda a cotizar: ");
			std::cin >> valor;
			valorToDouble = std::stod(valor);
			esValido = true;
			std::cin.get();
			m_presentador->SetPrecioDePrenda(valorToDouble);
		}
		catch (const std::exception)
		{
			MostrarMensaje(INVALID_ARGUMENT_ERROR);
		}

			
	} while (!esValido);

}

void MainView::IngresarCantidadACotizar()
{
	bool esValido = false;
	std::string valor = "0";
	int valorInt = 0;
	do
	{
		try
		{
			std::system("cls");
			MostrarTexto(HEADER_COTIZACION);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto(RETURN_MENU_PRINCIPAL);
			MostrarTexto("-----------------------------------------------------");

			m_presentador->BuscarStockDePrendaACotizar();
			MostrarTexto("PASO 5: Ingrese la cantidad de unidades a cotizar");
			std::cin >> valor;

			valorInt= std::stod(valor);
			esValido = true;
			m_presentador->ReservarStockDePrenda(valorInt, esValido);

		}
		catch (const std::exception e)
		{
			MostrarMensaje(INVALID_ARGUMENT_ERROR);
		}

	} while (!esValido);

}

void MainView::MostrarCotizacion(std::map<std::string, std::string>& datos)
{

	for (auto& d : datos)
	{
		MostrarTexto(d.first + d.second);
	}
}



void MainView::SolicitarDatoDeCotizacion(std::string& valor, std::string& mensaje, std::map<std::string, std::string>& opciones)
{
	bool esValido = false;

	do
	{
			std::system("cls");
			MostrarTexto(HEADER_COTIZACION);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto(RETURN_MENU_PRINCIPAL);
			MostrarTexto("-----------------------------------------------------");
			MostrarTexto(mensaje);
			SetValor(valor, opciones, esValido);
			std::system("cls");

	} while (!esValido);
}

void MainView::SetValor(std::string& valor, std::map<std::string, std::string>& opciones, bool& esValido)
{

	CargarOpciones(opciones);
	std::cin >> valor;
	esValido = true;

	//Verifica si el valor ingresado está en las opciones
	if (valor == "3") {
		MostrarMenuPrincipal();
		esValido = true;
	}

	if (opciones.find(valor) == opciones.end())
	{
		MostrarMensaje(INVALID_OPTION_MESSAGE);
		esValido = false;
	}

}

void MainView::CargarOpciones(std::map<std::string, std::string>& opciones) {

	if (opciones.size() > 0) {
		for (auto& op : opciones)
		{
			std::cout << op.first << ") " << op.second << std::endl;
		}
	}
	MostrarTexto("-----------------------------------------------------");
}

void MainView::MostrarTexto(const char* texto)
{
	std::cout << texto << std::endl;
}

void MainView::MostrarTexto(const std::string& texto)
{
	std::cout << texto << std::endl;
}

void MainView::SetMenuPrendaItems(std::map<int, std::string> items)
{
	if (items.empty())
	{
		MostrarTexto("Ups!! No se encontró ningún tipo de prenda.");
	}
	else
	{
		m_menuPrendasItems = items;
	}
}

void MainView::MostrarMensaje(std::string mensaje)
{
	MostrarTexto(mensaje);
	std::cin.get();
	std::cin.get();
}
