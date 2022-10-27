/** @file Usuario.cc
	@brief Implementacion de la clase Usuario
*/

#include "Usuario.hh"

Usuario::Usuario()
{	
	id_curso_ins = 0;
	envios_totales = 0;
}

Usuario::~Usuario()
{

}

int Usuario::consultar_curso() const
{
	return id_curso_ins;
}

int Usuario::consultar_prob_intent() const
{
	return env.total_enviables();
}

int Usuario::consultar_prob_res() const
{
	return env.total_resueltos();
}

int Usuario::consultar_envios_totales() const
{
	return envios_totales;
}

bool Usuario::esta_inscrito() const
{
	return id_curso_ins != 0;
}

void Usuario::modificar_curso(int c, Cjt_cursos& cu, Cjt_sesiones& se)
{
	//se garantiza que el p.i. no se ha inscrito anteriormente al Curso c
	cu.modificar_envios_curso_id(c, env, se);
	id_curso_ins = c;

	/*
	//si el conjunto de problemas esta vacío tras haber hecho esta llamada
	//quiere decir que el Usuario ha completado previamente problemas de todas las sesiones
	//del Curso c y por tanto ya lo tiene completado también
	if (env.total_enviables() != 0) id_curso_ins = c;
	else {
		id_curso_ins = 0;
		//incrmnto isncritos Curso c
		cu.modificar_comple_curso_id(c);
		//decremento usuarios inscritos Curso c
		cu.modificar_inscritos_i_esimo(c, 0);
	}
	*/
}

void Usuario::envio_prob(const string& id_prob, int res, Cjt_cursos& cu, Cjt_sesiones& se)
{
	envios_totales += 1;
	cu.modificar_envios_id(id_prob, id_curso_ins, res, se, env);
}

void Usuario::desuscribir(bool& b)
{
	id_curso_ins = 0;
	//si b entonces ya tenia el curso completado
	b = env.total_enviables() == 0;
	//en princio tndria qu vaciar loss enviabless
	env.vaciar_enviables();
}

void Usuario::aumentar_intentos(const string& id)
{
	envios_totales += 1;
	env.incrementar_enviables(id);
}

bool Usuario::prob_is_solved(const string& id)
{
	return env.esta_resuelto(id);
}

void Usuario::imprimir()
{
	cout << '(' << envios_totales << ',';
	cout << env.total_resueltos() << ',';
	cout << id_curso_ins << ')';
}

void Usuario::imprimir_problemas_resueltos()
{
	env.escribir_resueltos();
}

void Usuario::imprimir_problemas_enviables()
{
	env.escribir_enviables();
}


