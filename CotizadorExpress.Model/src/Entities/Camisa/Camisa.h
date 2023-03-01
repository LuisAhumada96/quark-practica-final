#pragma once

#include "../Prenda/Prenda.h"
#include <string>

enum class TipoManga {Corta = 1, Larga};
enum class TipoCuello { Mao = 1,Comun };

class Camisa:public Prenda
{
	friend class CamisaCotizacionStrategy;
private:
	TipoCuello m_tipoCuello;
	TipoManga m_tipoManga;
	const char* m_nombre = "Camisa";
public:
	Camisa();
	Camisa(Calidad calidad, int unidadesStock, TipoCuello tipoCuello, TipoManga tipoManga) :Prenda(calidad, unidadesStock),
																						    m_tipoCuello(tipoCuello), m_tipoManga(tipoManga){};
	~Camisa();
	void SetTipoCuello(TipoCuello tipoCuello);
	void setTipoManga(TipoManga tipoManga);

	virtual std::string GetCaracteristicasDePrenda() override;


	// Heredado vía Prenda
	virtual std::string GetNombreDePrenda() override;


	// Heredado vía Prenda
	virtual bool DescripcionCoincide(Prenda* prenda) override;

};

