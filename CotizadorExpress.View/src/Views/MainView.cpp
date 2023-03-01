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
		std::cin.get();

	} while (!haSalido);
}

void MainView::EjecutarOpcion(const char* opcion, bool& haSalido) {
	auto str_opcion = std::string(opcion);

	if (str_opcion == "1")
	{
		std::cin.get();
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
			MostrarTexto(INVALID_OPTION_MESSAGE);
			std::cin.get();
			std::cin.get();
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
			m_presentador->SetCalidadDePrendaCotizada(valor);
			std::system("cls");
		}
		catch (const std::exception&)
		{
			MostrarTexto(INVALID_OPTION_MESSAGE);
			std::cin.get();
			std::cin.get();
		}
	} while (!esValido);
}

void MainView::IngresarPrecioUnitario() {

	double valor = 0;
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
			esValido = true;
			std::cin.get();
			m_presentador->SetPrecioDePrenda(valor);
		}
		catch (const std::exception&)
		{

		}

			
	} while (!esValido);

}

void MainView::IngresarCantidadACotizar()
{
	bool esValido = false;
	int valor = 0;
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
			m_presentador->ReservarStockDePrenda(valor, esValido);

		}
		catch (const std::exception e)
		{
			MostrarTexto(INVALID_ARGUMENT_ERROR);
			esValido = false;
			std::cin.get();
			std::cin.get();
		}

	} while (!esValido);

}

void MainView::ImprimirCotizacion(std::map<std::string, std::string>& cotizacionDatos)
{
	std::system("cls");
	MostrarTexto(HEADER_COTIZACION);
	MostrarTexto("-----------------------------------------------------");
	MostrarTexto(RETURN_MENU_PRINCIPAL);
	MostrarTexto("-----------------------------------------------------");

	for (auto& d : cotizacionDatos)
	{
		MostrarTexto(d.first + d.second);
	}
	MostrarTexto("-----------------------------------------------------");
	MostrarTexto(RETURN_MENU_PRINCIPAL);
	std::cin.get();
	std::cin.get();
}

void MainView::SolicitarDatoDeCotizacion(std::string& valor, std::string& mensaje, std::map<std::string, std::string>& opciones)
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
			MostrarTexto(mensaje);
			SetValor(valor, opciones, esValido);
			std::system("cls");
		}
		catch (const std::exception&)
		{

		}

	} while (!esValido);
}

void MainView::SetValor(std::string& valor, std::map<std::string, std::string>& opciones, bool& esValido)
{

	CargarOpciones(opciones);
	std::cin >> valor;
	esValido = true;

	//Verifica si el valor ingresado está en las opciones

	if (opciones.find(valor) == opciones.end() && valor != "3")
	{
		MostrarTexto(INVALID_OPTION_MESSAGE);
		std::cin.get();
		std::cin.get();
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


