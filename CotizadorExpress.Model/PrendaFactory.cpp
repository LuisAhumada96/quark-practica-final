#include "PrendaFactory.h"
#include<iostream>
#include "src/Entities/Camisa/Camisa.h"
#include "src/Entities/Pantalon/Pantalon.h"

PrendaFactory* PrendaFactory::m_prendaFactory = nullptr;

PrendaFactory::PrendaFactory()
{
}

PrendaFactory::~PrendaFactory()
{
}

PrendaFactory* PrendaFactory::GetInstance()
{
    if (m_prendaFactory == nullptr) {
        m_prendaFactory = new PrendaFactory();
    }
    return m_prendaFactory;
}

std::map<int,std::string> PrendaFactory::GetPrendasTipos()
{

    return std::map<int,std::string> {
        {1, "Camisa"},
        {2, "Pantalon"}
    };
}

std::map<std::string, std::string> PrendaFactory::GetPrendasCalidad()
{
    return std::map<std::string, std::string> {
        { "1", "Standard"},
        { "2", "Premium" }
    };
}

Prenda* PrendaFactory::GetPrenda(int tipoPrenda)
{
    auto prendas = GetPrendasTipos();
    auto prenda = prendas[tipoPrenda];

    if (prenda == "Camisa") return new Camisa();
    if (prenda == "Pantalon") return new Pantalon();
}

