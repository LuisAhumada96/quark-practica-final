#pragma once
class MainPresenter
{
	IView* m_view = nullptr;
public:
	explicit MainPresenter(IView *view);
	~MainPresenter();
	void showMessage(const char* message);
};
