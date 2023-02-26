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

	// Heredado vía IView

	void MostrarMenuPrincipal();

	// Heredado vía IView
	 void MostrarTexto(const char* texto) override;
	 void MostrarTexto(const std::string& texto) override;
};


#pragma once
