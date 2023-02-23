#pragma once

#include "IView.h"
#include "MainPresenter.h"
#include <iostream>




class MainView :public IView
{
private:
	MainPresenter* presenter;
public:
	MainView();
	~MainView();

	virtual void showMessage(const char* message) override;

};

MainView::MainView()
{
	this->presenter = new MainPresenter(this);
}

MainView::~MainView()
{
}

void MainView::showMessage(const char* message)
{

}
#pragma once
