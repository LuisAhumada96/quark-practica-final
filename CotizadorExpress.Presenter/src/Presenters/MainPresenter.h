#pragma once

#include "../Interfaces/IView.h"
#include "../../../CotizadorExpress.Model/Entities/Vendedor/Vendedor.h"

class MainPresenter
{
	IView* m_view = nullptr;
	Vendedor* m_vendedor = nullptr;
public:
	explicit MainPresenter(IView *view);
	~MainPresenter();
	void showMessage(const char* message);
};
