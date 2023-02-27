#pragma once
#include <map>
#include <string>
class Prenda;
enum class TipoPrenda {Camisa = 1, Pantalon};
class PrendaFactory
{
public:
	PrendaFactory();
	~PrendaFactory() = default;
	static std::map<int, std::string> GetPrendasTipos();
	static Prenda* GetPrenda(int tipoPrenda);
	
};
