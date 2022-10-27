/** @file Problema.cc
	@brief Implementacion de la clase Problema
*/
#include "Problema.hh"

Problema::Problema()
{
	identificador = "-";
	total_envios = 0;
	envios_correctos = 0;
	ratio = (double(total_envios) + 1) / (double(envios_correctos) + 1);
}

Problema::Problema(const string& id)
{
	identificador = id;
	total_envios = 0;
	envios_correctos = 0;
	ratio = (double(total_envios) + 1) / (double(envios_correctos) + 1);
}

Problema::~Problema()
{

}

string Problema::consultar_identificador() const
{
	return identificador;
}

int Problema::consultar_total_envios() const
{
	return total_envios;
}

int Problema::consultar_envios_correctos() const
{
	return envios_correctos;
}

double Problema::consultar_ratio() const
{
	return ratio;
}

void Problema::incrementar_total_envios()
{
	total_envios = total_envios + 1;
	ratio = (double(total_envios) + 1) / (double(envios_correctos) + 1);
}

void Problema::incrementar_envios_correctos()
{
	envios_correctos = envios_correctos + 1;
	ratio = (double(total_envios) + 1) / (double(envios_correctos) + 1);
	incrementar_total_envios();
}

void Problema::imprimir()
{
	cout << identificador;
	cout << '(' << total_envios << ',';
	cout << envios_correctos << ',';
	cout << ratio << ')' << endl;
}