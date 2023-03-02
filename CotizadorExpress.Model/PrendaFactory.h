#pragma once
#include <map>
#include <string>
class Prenda;
enum class TipoPrenda {Camisa = 1, Pantalon};
class PrendaFactory
{
private:
	static PrendaFactory* m_prendaFactory;
	PrendaFactory();
	~PrendaFactory();
public:
	
	static PrendaFactory* GetInstance();
	std::map<int, std::string> GetPrendasTipos();
	std::map<std::string, std::string> GetPrendasCalidad();
	Prenda* GetPrenda(int tipoPrenda);
	
};

