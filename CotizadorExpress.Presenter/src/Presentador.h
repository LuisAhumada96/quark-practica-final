#pragma once
#include<map>
#include<string>
class IView;
class Vendedor;
class Tienda;
class Prenda;
class PrendaCotizacionStrategy;
class Presentador
{
private:
	IView* m_view = nullptr;
	Vendedor* m_vendedor = nullptr;
	Prenda* m_prendaCotizada = nullptr;
	int m_cantidadCotizada;
public:
	Presentador(IView* view);
	~Presentador();
	void GetItemsMenuDePrendas();
	std::map<std::string, std::string> GetItemsCalidad();
	void MostrarDatosDeTienda();
	void MostrarDatosDeVendedor();
	void ListarCotizacionesDeVendedor();

	void SeleccionarTipoDePrenda(int option);
	void SetCalidadDePrendaCotizada(std::string calidad);
	void SetPrecioDePrenda(double valor);
	void BuscarStockDePrendaACotizar();
	void ReservarStockDePrenda(int& cantidad, bool& stockValido);
	void CotizarPrenda();
};

