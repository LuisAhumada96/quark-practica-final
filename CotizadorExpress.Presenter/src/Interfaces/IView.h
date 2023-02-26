#pragma once

#include <string>
class IView
{
public:
	IView() = default;
	~IView() = default;
	virtual void MostrarTexto(const char* texto, bool justified = false) = 0;
	virtual void MostrarTexto(const std::string& texto, bool justified = false) = 0;
};