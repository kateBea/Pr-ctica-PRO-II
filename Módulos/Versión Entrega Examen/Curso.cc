/** @file Curso.cc
	@brief Implementacion de la clase Curso
*/


#include "Curso.hh"

Curso::Curso()
{
	us_completado = 0;
	us_inscritos = 0;
}

Curso::~Curso()
{

}

void Curso::leer(Cjt_sesiones& se)
{
	int Sc;
	cin >> Sc;
	for (int i = 0; i < Sc; ++i) {
		string id_sesion;
		cin >> id_sesion;
		Sesion s = se.consultar_sesion(id_sesion);
		s.anadir_problemas_sesion(id_sesion, pr);
		lista.insert(lista.end(), id_sesion);
	}
}

void Curso::leer_verif(Cjt_sesiones& se, bool& b)
{
	int Sc;
	cin >> Sc;

	//variable buleana que indica si se mantiene condición de intersección vacía
	//entre las diferentes sesiones
	bool correcto = true;

	//supongo que no habia los problemas en el curso con anterioridad
	b = true;

	int i = 0;

	while (i < Sc and correcto) {
		string id_sesion;
		cin >> id_sesion;
		Sesion s = se.consultar_sesion(id_sesion);
		//NOTA: si es la primera sesion añaden los problemas a "pr" sin hacer ninguna comprobacin 
		//ya que el curso no contiene níngun problema para empezar. Por tanto, no puedo comprobar si hay 
		//intersección no vacía entre sesiones. Recorro la Sesión para comprobar si existen los problemas en "pr"
		//(a traves de pr que Problemas_Sesion)
		if (i == 0) s.anadir_problemas_sesion(id_sesion, pr);
		else s.anadir_prob_sesion_verif(id_sesion, pr, b);

		if (b) lista.insert(lista.end(), id_sesion);
		else correcto = false;
		++i;
	}

	//si ha habido coincidencia entre sesiones no hace falta seguir comprobando la intersección 
	//entre ellas, simplemente se lee los identificadores de las sesiones restantes del canal de entrada estándard
	if (not correcto) {
		int restantes = i;
		while (restantes < Sc) {
			string id_se;
			cin >> id_se;
			++restantes;
		}
	}
}

int Curso::usuarios_completado() const
{
	return us_completado;
}

int Curso::usuarios_inscritos() const
{
	return us_inscritos;
}

string Curso::sesion_poblema_id(const string& id)
{
	return pr.problema_sesion(id);
}

int Curso::numero_sesiones() const
{
	return lista.size();
}

bool Curso::existe_problema(const string& prob) const
{
	return pr.existe_problema(prob);
}

void Curso::modificar_usuarios_inscritos(bool b)
{
	if (b) us_inscritos = us_inscritos + 1;
	else us_inscritos = us_inscritos - 1;
}

void Curso::modificar_usuarios_completado()
{
	us_completado = us_completado + 1;
}

void Curso::modificar_envios(Cjt_sesiones& se, Envio& en)
{
	list<string>::iterator it;
	us_inscritos += 1;
	for (it = lista.begin(); it != lista.end(); ++it) {
		se.anadir_enviables_sesion_id((*it), en);
	}
}

void Curso::modificar_envios(const string& id_prob, int res, Cjt_sesiones& se, Envio& en)
{
	Sesion s1 = se.consultar_sesion(pr.problema_sesion(id_prob));
	s1.modificar_enviables(id_prob, en);
}

void Curso::imprimir()
{
	cout << us_inscritos << ' ';
	cout << lista.size();
	list<string>::const_iterator it;
	bool first = true;
	cout << " (";
	for (it = lista.begin(); it != lista.end(); ++it) {
		list<string>::const_iterator it1 = it;
		++it1;
		if (it1 == lista.end()) cout << (*it);
		else cout << (*it) << ' ';
	}
	cout << ')';
}
