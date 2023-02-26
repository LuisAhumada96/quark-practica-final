#include "Presentador.h"
#include "Interfaces/IView.h"
#include "../Entities/Vendedor/Vendedor.h"
#include "../../CotizadorExpress.Model/src/Entities/Tienda/Tienda.h"

Presentador::Presentador(IView* view):m_view(view)
{
	this->m_vendedor = new Vendedor(1, "Juan", "Campanaso", new Tienda("Quark Gear Store", "Avenida Siempre Viva 500"));
}

Presentador::~Presentador()
{
	
}

void Presentador::MostrarDatosDeTienda()
{
}

void Presentador::MostrarDatosDeVendedor()
{
	//this->m_view->MostrarTexto(this->m_vendedor->GetNombre() + " " +
	//	this->m_vendedor->GetApellido() + " | " +
	//	std::to_string(this->m_vendedor->GetCodigo()));
}