/** @file Cjt_sesiones.cc
	@brief Implementacion de la clase Cjt_sesiones
*/

#include "Cjt_sesiones.hh"

Cjt_sesiones::Cjt_sesiones()
{

}

Cjt_sesiones::~Cjt_sesiones()
{

}

bool Cjt_sesiones::existe_sesion(const string& nombre) const
{
	map<string, Sesion>::const_iterator it = lista.find(nombre);
	return it != lista.end();
}

int Cjt_sesiones::total_sesiones() const
{
	return lista.size();
}

Sesion Cjt_sesiones::consultar_sesion(const string& se) 
{
	return lista[se];
}

void Cjt_sesiones::anadir_sesion_verif(const string& nombre, bool& m) 
{
	Sesion _in;
	_in.leer();
	map<string, Sesion>::iterator it = lista.find(nombre);
	m = (it == lista.end());
	if (m) lista.insert(make_pair(nombre, _in));
}

void Cjt_sesiones::anadir_enviables_sesion_id(const string& id, Envio& en)
{
	lista[id].anadir_enviables(en);
}

void Cjt_sesiones::escribir_sesiones()
{
	map<string, Sesion>::iterator it;
	for (it = lista.begin(); it != lista.end(); ++it) {
		Sesion a = it->second;
		cout << (*it).first << ' ';
		cout << a.total_problemas() << ' ';
		a.imprimir();
		cout << endl;
	}
}

void Cjt_sesiones::escribir_sesion_id(const string& id)
{		
	cout << id << ' ';
	Sesion a = lista[id];
	cout << a.total_problemas() << ' ';
	a.imprimir();
	cout << endl;
}

void Cjt_sesiones::leer()
{
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string id_sesion;
		cin >> id_sesion;
		Sesion in;
		in.leer();
		lista.insert(make_pair(id_sesion, in));
	}
}