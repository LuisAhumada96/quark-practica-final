#include "PrendaFactory.h"
#include<iostream>
#include "src/Entities/Camisa/Camisa.h"
#include "src/Entities/Pantalon/Pantalon.h"

PrendaFactory::PrendaFactory()
{
}

std::map<int,std::string> PrendaFactory::GetPrendasTipos()
{

    return std::map<int,std::string> {
        {1, "Camisa"},
        {2, "Pantalon"}
    };
}

Prenda* PrendaFactory::GetPrenda(int tipoPrenda)
{
    auto prendas = GetPrendasTipos();
    auto prenda = prendas[tipoPrenda];

    if (prenda == "Camisa") return new Camisa();
    if (prenda == "Pantalon") return new Pantalon();
}
