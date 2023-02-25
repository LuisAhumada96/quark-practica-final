
#include "MainPresenter.h"
#include "../Interfaces/IView.h"

MainPresenter::MainPresenter(IView* view) :m_view(view)
{
	Tienda* tienda = new Tienda("Quark Gear Store", "Avenida Siempre Viva 500");
	m_vendedor = new Vendedor(1, "Juan", "Campanaso",tienda);
}

MainPresenter::~MainPresenter()
{

}

void MainPresenter::showMessage(const char* message)
{
	m_view->showMessage(message);
}


