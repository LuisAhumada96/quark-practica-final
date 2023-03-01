#pragma once

#include "../src/Interfaces/IView.h"
#include <iostream>
#include <map>


class Presentador;
class MainView :public IView
{
private:
	Presentador* m_presentador;
	std::map<int,std::string> m_menuPrendasItems;
	void MostrarMenuPrincipal();
	void MostrarMenuPrendas();
	void MostrarHistorialDeVendedor();
	void EjecutarOpcion(const char* opcion, bool& haSalido);
	void RegresarAMenuPrincipal();
	void CargarOpciones(std::map<std::string, std::string>& opciones);
public:
	MainView();
	~MainView();

	// Heredado vía IView
	 void MostrarTexto(const char* texto) override;
	 void MostrarTexto(const std::string& texto) override;
	 void SetMenuPrendaItems(std::map<int,std::string> items) override;
	 void SolicitarDatoDeCotizacion(std::string& valor, std::string& mensaje, std::map<std::string, std::string>& opciones) override;
	 void SetValor(std::string& valor, std::map<std::string, std::string>& opciones,bool& esValido) override;
	 void MostrarCotizacion(std::map<std::string, std::string>& datos) override;

	 void SeleccionarPrenda(const char* opcion, bool& esOpcionValida);
	 void SeleccionarCalidadDePrenda();
	 void IngresarPrecioUnitario();
	 void IngresarCantidadACotizar();
};


#pragma once
