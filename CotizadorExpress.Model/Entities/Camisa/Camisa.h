#pragma once

#include "../Prenda/Prenda.h"
#include <string>

enum TipoManga {Corta, Larga};
enum TipoCuello {Mao, Comun};

class Camisa:public Prenda
{
private:
	TipoCuello m_tipoCuello;
	TipoManga m_tipoManga;
public:
	virtual std::string MostrarTipoDePrenda() override;

};

