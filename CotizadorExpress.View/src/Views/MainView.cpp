
#include "MainView.h"
#include "../src/Presentador.h"
MainView::MainView()
{
	//this->m_presentador = new Presentador(this);
	MostrarMenuPrincipal();
}

MainView::~MainView()
{
}

void MainView::MostrarTexto(const char* texto)
{
	std::cout << texto << std::endl;
}

void MainView::MostrarTexto(const std::string& texto)
{
	std::cout << texto << std::endl;
}

void MainView::MostrarMenuPrincipal()
{
	std::string opcion;
	bool haSalido = false;
	do
	{
		std::system("cls");
		MostrarTexto("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		MostrarTexto("-----------------------------------------------------");
		m_presentador->MostrarDatosDeVendedor();
		m_presentador->MostrarDatosDeTienda();

	} while (!haSalido);
}

