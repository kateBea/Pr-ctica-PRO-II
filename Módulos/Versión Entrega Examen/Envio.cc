/** @file Envio.cc
	@brief Implementacion de la clase Envio
*/

#include "Envio.hh"

Envio::Envio()
{
	intentados = 0;
}

Envio::~Envio()
{

}

int Envio::total_enviables() const
{
	return enviables.size();
}

int Envio::total_resueltos() const
{
	return resueltos.size();
}

int Envio::total_intentados() const
{
	return intentados;
}

bool Envio::esta_resuelto(const string& p) const
{
	map<string, int>::const_iterator it = resueltos.find(p);
	return it != resueltos.end();
}

void Envio::anadir_enviable(const string& env)
{
	pair<string, int> _in = make_pair(env, 0);
	enviables.insert(_in);
}

void Envio::anadir_resuelto(const string& res)
{
	int n = enviables[res];
	if (n == 0) intentados += 1;
	n += 1;
	enviables[res] = n;
	resueltos[res] = n;
}

void Envio::incrementar_enviables(const string& b)
{
	if (enviables[b] == 0) intentados += 1;
	enviables[b] += 1;
}

void Envio::vaciar_enviables()
{
	enviables = map<string, int>();
}

void Envio::escribir_enviables()
{
	if (not enviables.empty()) {
		map<string, int>::const_iterator it;
		for (it = enviables.begin(); it != enviables.end(); ++it) {
			cout << (*it).first << endl;
		}
	}
}

void Envio::escribir_resueltos()
{
	if (not resueltos.empty()) {
		map<string, int>::const_iterator it;
		for (it = resueltos.begin(); it != resueltos.end(); ++it) {
			cout << (*it).first << endl;
		}
	}
}