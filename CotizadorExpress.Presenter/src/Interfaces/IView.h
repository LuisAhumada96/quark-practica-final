#pragma once

#include <string>
class IView
{
public:
	IView() = default;
	~IView() = default;
	virtual void MostrarTexto(const char* texto) = 0;
	virtual void MostrarTexto(const std::string& texto) = 0;
};