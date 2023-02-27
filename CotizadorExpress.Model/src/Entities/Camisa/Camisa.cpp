#include "Camisa.h"

Camisa::Camisa()
{

}

Camisa::~Camisa()
{
}

void Camisa::SetTipoCuello(TipoCuello tipoCuello) {
	m_tipoCuello = tipoCuello;
}
void Camisa::setTipoManga(TipoManga tipoManga) {
	m_tipoManga = tipoManga;
}

std::string Camisa::GetCaracteristicasDePrenda()
{
	return "";
}

std::string Camisa::GetNombreDePrenda()
{
	return "Camisa";
}

bool Camisa::DescripcionCoincide(Prenda* prenda)
{
	return false;
}
