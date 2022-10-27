/** @file Cjt_cursos.cc
	@brief Implementacion de la clase Cjt_cursos
*/
#include "Cjt_cursos.hh"

Cjt_cursos::Cjt_cursos()
{

}

Cjt_cursos::~Cjt_cursos()
{

}

Curso Cjt_cursos::consultar_curso(int n) const
{
	return lista[n - 1];
}

int Cjt_cursos::total_cursos() const
{
	return lista.size();
}

void Cjt_cursos::modificar_envios_curso_id(int n, Envio& en, Cjt_sesiones& se)
{
	lista[n - 1].modificar_envios(se, en);
}

string Cjt_cursos::consultar_sesion_curso_id(int curso, const string& prob_id)
{
	return lista[curso - 1].sesion_poblema_id(prob_id);
}

int Cjt_cursos::usuarios_inscritos_curso_id(int n) const
{
	return lista[n - 1].usuarios_inscritos();
}

bool Cjt_cursos::pertenece_problema(int n, const string& id, string& id_se)
{	
	bool m =  lista[n - 1].existe_problema(id);
	if (m) id_se = lista[n - 1].sesion_poblema_id(id);

	return m;
}

void Cjt_cursos::nuevo_usuario_curso_id(int id)
{
	lista[id - 1].modificar_usuarios_inscritos(true);
}

void Cjt_cursos::anadir_curso(Cjt_sesiones& se, bool& marca)
{
	Curso c;
	c.leer_verif(se, marca);
	if (marca) lista.push_back(c);

}

void Cjt_cursos::modificar_inscritos_i_esimo(int id, int val)
{
	if (val == 1) lista[id - 1].modificar_usuarios_inscritos(true);
	else lista[id - 1].modificar_usuarios_inscritos(false);
}

void Cjt_cursos::modificar_comple_curso_id(int n)
{
	lista[n - 1].modificar_usuarios_completado();
}

void Cjt_cursos::modificar_envios_id(const string& id_prob, int curs, int res, Cjt_sesiones& se, Envio& env)
{
	lista[curs - 1].modificar_envios(id_prob, res, se, env);
}

void Cjt_cursos::leer(Cjt_sesiones& se)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		Curso in;
		in.leer(se);
		lista.push_back(in);
	}
}

void Cjt_cursos::imprimir_cursos()
{
	int n = lista.size();
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ' ';
		lista[i].imprimir();
		cout << endl;
	}
}

void Cjt_cursos::imprimir_curso_id(int id)
{	
	cout << id << ' ';
	lista[id - 1].imprimir();
	cout << endl;
}