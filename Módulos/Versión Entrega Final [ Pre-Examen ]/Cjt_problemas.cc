/** @file Cjt_problemas.cc
	@brief Implementacion de la clase Cjt_problemas
*/

#include "Cjt_problemas.hh"

bool Cjt_problemas::comp(const Problema& a, const Problema& b)
{
	if (a.consultar_ratio() != b.consultar_ratio()) return a.consultar_ratio() < b.consultar_ratio();
	else return a.consultar_identificador() < b.consultar_identificador();
}

Cjt_problemas::Cjt_problemas()
{

}

Cjt_problemas::~Cjt_problemas()
{

}

int Cjt_problemas::total_problemas() const
{
	return lista.size();
}

void Cjt_problemas::anadir_problema_verif(const string& nombre, bool& b)
{
	map<string, Problema>::iterator it = lista.find(nombre);
	if (it == lista.end()) {
		b = true;
		pair<string, Problema> _in = make_pair(nombre, Problema(nombre));
		lista.insert(_in);
	}
	else b = false;
}

void Cjt_problemas::actualizar_estad_prob(const string& nombre, int resultado)
{
	if (resultado == 1) lista[nombre].incrementar_envios_correctos();
	else lista[nombre].incrementar_total_envios();
}

bool Cjt_problemas::existe_problema(const string& ident) const
{
	map<string, Problema>::const_iterator it = lista.find(ident);
	return it != lista.end();
}

void Cjt_problemas::leer()
{
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string nombre;
		cin >> nombre;
		Problema a(nombre);
		pair<string, Problema> _in = make_pair(nombre, Problema(nombre));
		lista.insert(_in);
	}
}

void Cjt_problemas::escribir_problemas()
{
	int n = lista.size();
	vector<Problema> conjunto;
	map<string, Problema>::iterator it;
	for (it = lista.begin(); it != lista.end(); ++it) conjunto.push_back(it->second);
	sort(conjunto.begin(), conjunto.end(), comp);
	for (int i = 0; i < n; ++i) conjunto[i].imprimir();
}

void Cjt_problemas::escribir_problema_id_verif(const string& id, bool& b)
{
	map<string, Problema>::iterator it = lista.find(id);
	b = it != lista.end();
	if (b) it->second.imprimir();
}

