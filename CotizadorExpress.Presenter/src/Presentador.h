#pragma once


class IView;
class Vendedor;
class Tienda;
class Presentador
{
private:
	IView* m_view = nullptr;
	Vendedor* m_vendedor = nullptr;
public:
	Presentador(IView* view);
	~Presentador();
	void MostrarDatosDeTienda();
	void MostrarDatosDeVendedor();
};

