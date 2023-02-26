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
	 void MostrarTexto(const char* texto, bool justified = false) override;
	 void MostrarTexto(const std::string& texto, bool justified = false) override;
};


#pragma once
