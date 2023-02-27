#pragma once

#include <string>
#include<map>

class IView
{
public:
	IView() = default;
	~IView() = default;
	virtual void MostrarTexto(const char* texto) = 0;
	virtual void MostrarTexto(const std::string& texto) = 0;
	virtual void SetMenuPrendaItems(std::map<int,std::string> items) = 0;
	virtual void SolicitarDatoDeCotizacion(std::string& valor, std::string& mensaje, std::map<std::string, std::string>& opciones) = 0;
	virtual void SetValor(std::string& valor, std::map<std::string, std::string>& opciones) = 0;
};