#pragma once

#include "../Prenda/Prenda.h"
#include <string>

enum class TipoManga {Corta, Larga};
enum class TipoCuello { Comun,Mao };

class Camisa:public Prenda
{
	friend class CamisaCotizacionStrategy;
private:
	TipoCuello m_tipoCuello;
	TipoManga m_tipoManga;
public:
	Camisa(Calidad calidad, double precioUnitario, int unidadesStock, TipoCuello tipoCuello, TipoManga tipoManga) :Prenda(calidad, precioUnitario, unidadesStock),
																												  m_tipoCuello(tipoCuello), m_tipoManga(tipoManga){};
	~Camisa();
	virtual std::string MostrarTipoDePrenda() override;

};

