#include "Views/MainView.h"
#include <iostream>
#include <Windows.h>
int main() {
	SetConsoleTitleW(L"COTIZADOR EXPRESS");
	setlocale(LC_ALL, "es_Es");
	MainView view;
	return 0;
}