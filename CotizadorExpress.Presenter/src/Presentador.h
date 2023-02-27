#pragma once


class IView;
class Vendedor;
class Tienda;
class Prenda;
class Presentador
{
private:
	IView* m_view = nullptr;
	Vendedor* m_vendedor = nullptr;
	Prenda* m_prendaCotizada = nullptr;
public:
	Presentador(IView* view);
	~Presentador();
	void GetItemsMenuDePrendas();
	void MostrarDatosDeTienda();
	void MostrarDatosDeVendedor();
	void SeleccionarTipoDePrenda(int option);
};

