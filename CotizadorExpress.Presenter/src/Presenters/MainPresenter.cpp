
#include "MainPresenter.h"
#include "../Interfaces/IView.h"

MainPresenter::MainPresenter(IView* view) :m_view(view)
{

}

MainPresenter::~MainPresenter()
{

}

void MainPresenter::showMessage(const char* message)
{
	m_view->showMessage(message);
}


