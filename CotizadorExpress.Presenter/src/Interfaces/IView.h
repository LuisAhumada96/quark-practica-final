#pragma once
class IView
{
public:
	IView() = default;
	~IView() = default;
	virtual void showMessage(const char* message) = 0;
};