/** @file Problemas_Sesion.cc
	@brief Implementacion de la clase Problemas_Sesion
*/

#include "Problemas_Sesion.hh"

Problemas_Sesion::Problemas_Sesion()
{
	
}

Problemas_Sesion::~Problemas_Sesion()
{

}

int Problemas_Sesion::total_problemas_curso() const
{
	return conj.size();
}

string Problemas_Sesion::problema_sesion(const string& prob_nom)
{
	return conj[prob_nom];
}

void Problemas_Sesion::anadir_problema(const string& prob, const string& se)
{
	pair<string, string> _in = make_pair(prob, se);
	conj.insert(_in);
}

bool Problemas_Sesion::existe_problema(const string& p) const
{
	map<string, string>::const_iterator it = conj.find(p);
	return it != conj.end();
}

void Problemas_Sesion::escribir()
{
	if (not conj.empty()) {
		map<string, string>::iterator it;
		for (it = conj.begin(); it == conj.end(); ++it) {
			cout << it->first << ' ' << it->second << endl;
		}
	}
}

void Problemas_Sesion::escribir_sesion(const string& p)
{
	cout << conj[p];
}