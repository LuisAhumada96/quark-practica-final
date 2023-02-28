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
	return  m_nombre;
}

bool Camisa::DescripcionCoincide(Prenda* prenda)
{
	bool base = Prenda::DescripcionCoincide(prenda);
	if (!base) return false;

	auto camisa = dynamic_cast<Camisa*>(prenda);

	if (camisa == nullptr) return false;

	if (this->m_tipoCuello != camisa->m_tipoCuello) return false;
	if (this->m_tipoManga != camisa->m_tipoManga) return false;

	return true;
}
