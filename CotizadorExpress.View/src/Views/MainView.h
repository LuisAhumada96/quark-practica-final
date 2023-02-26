#pragma once

#include "../src/Interfaces/IView.h"
#include <iostream>


class Presentador;
class MainView :public IView
{
private:
	Presentador* m_presentador;
public:
	MainView();
	~MainView();

	// Heredado v�a IView

	void MostrarMenuPrincipal();

	// Heredado v�a IView
	 void MostrarTexto(const char* texto) override;
	 void MostrarTexto(const std::string& texto) override;
};


#pragma once
