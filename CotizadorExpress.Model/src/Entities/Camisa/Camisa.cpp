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
	std::string valor = "";
	valor.append(this->m_nombre);
	valor.append(" - ");
	valor.append(this->m_tipoManga == TipoManga::Corta ? "Corta" : "Larga");
	valor.append(" - ");
	valor.append(this->m_tipoCuello == TipoCuello::Comun ? "Común" : "Mao");
	valor.append(" - ");
	valor.append(this->GetCalidad() == Calidad::Premium ? "Premium" : "Standard");
	return valor;
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
