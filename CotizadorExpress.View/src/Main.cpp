#include "Views/MainView.h"
#include <iostream>
#include <Windows.h>

/*
	Autor: Luis Ignacio Ahumada | Discord: elMister (#7337)
	
	Proyecto: Desafío Final de Curso de C++ de Quark Academy - 2023.
	Patrones de software utilizados: Factory, Strategy
	Patrones de arquitectura: MVP (Modelo - Vista - Presentador)

*/

int main() {
	SetConsoleTitleW(L"COTIZADOR EXPRESS");
	setlocale(LC_ALL, "es_Es");
	MainView view;
	return 0;
}