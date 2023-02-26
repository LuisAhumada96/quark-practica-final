#include "Presentador.h"
#include "Interfaces/IView.h"
#include "../Entities/Vendedor/Vendedor.h"
#include "Tienda/Tienda.h"

Presentador::Presentador(IView* view):m_view(view)
{
	this->m_vendedor = new Vendedor(1, "Juan", "Campanaso", new Tienda("Quark Gear Store", "Avenida Siempre Viva 500"));
}

Presentador::~Presentador()
{
	
}

void Presentador::MostrarDatosDeTienda()
{
	Tienda* tienda = this->m_vendedor->GetTienda();
	this->m_view->MostrarTexto(tienda->GetNombre() + " | " + tienda->GetDireccion());
}

void Presentador::MostrarDatosDeVendedor()
{
	this->m_view->MostrarTexto(this->m_vendedor->GetNombre() + " " +
		this->m_vendedor->GetApellido() + " | " +
		std::to_string(this->m_vendedor->GetCodigo()));
}