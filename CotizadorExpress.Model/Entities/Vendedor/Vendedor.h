#pragma once
class Vendedor
{
private:
	int m_codigoVendedor;
	char* m_nombre;
	char* m_apellido;

public:
	Vendedor(int codigoVendedor, char* nombre, char* apellido);
	~Vendedor();
};

