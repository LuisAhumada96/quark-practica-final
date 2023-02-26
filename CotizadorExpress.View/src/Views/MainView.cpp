
#include "MainView.h"
#include "../src/Presentador.h"
#include <iostream>
#include <iomanip>


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
		MostrarTexto("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		MostrarTexto("-----------------------------------------------------");
		m_presentador->MostrarDatosDeVendedor();
		MostrarTexto("-----------------------------------------------------");
		m_presentador->MostrarDatosDeTienda();

	} while (!haSalido);
}

void MainView::MostrarTexto(const char* texto, bool justified)
{
	justified ? std::cout << std::setw(60) << std::right << texto << std::endl :
		std::cout << texto << std::endl;
}

void MainView::MostrarTexto(const std::string& texto, bool justified)
{
	justified ? std::cout << std::setw(60) << std::right << texto << std::endl :
		std::cout << texto << std::endl;
}

