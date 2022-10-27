/** @mainpage

	Documntación <b>completa</b> sobre EVALUATOR: una plataforma para 
	la gestión de un conjunto de problemas y cursos de programación
	(incluyendo elementos privados y código).

	El programa principal se encuentra en el módulo program.cc.
	Para resolver el problema planteado en esta práctica se ha visto 
	necesaria la creación de varios módulos. Necesitamos cuatro módulos 
	para guardar la información relacionada a un Usuario, a una Sesion, a 
	un Curso y a un Problema. Por otro lado necesitamos otros cuatro módulos
	que guardan información relacionada a conjuntos formandos por los elementos 
	mencionados anteriormente, es decir, necesitaremos los módulos
	Cjt_usuarios (que representa un conjunto de elementos de tipo Usuario),
	Cjt_sesiones (que representa un conjunto de elementos de tipo Sesion), Cjt_cursos
	(que representa un conjunto de elementos de tipo Curso) y Cjt_problemas 
	(que representa un conjunto de elementos de tipo Problema).

	Comentarios:

	- Tal como se menciona en esta práctica, un Problema por lo general consta de
	 su enunciado, juegos de pruebas públicos y privados y solución de referencia 
	 que está oculta, pero sólo se tendrá, para esta ocasión, en cuenta el número 
	 total de envíos de un problema y el númro de envíos correctos que es lo que 
	 se ha tenido en cuenta en esta implementación.

	- No se comprueba la corrección de los datos introducidos al inicio del programa,
	asume que son válidos y partiendo de ellos el programa ofrece un repertorio de
	funcionalidades.

*/

/** @file program.cc

	@brief Programa principal

	Suponemos que los datos introducidos incicialmente son válidos, por tanto,
	no se ve necesario la comprobación de los mismos. Los comando aceptados por 
	el programa son secuencias de caracteres (string) y se usa la secuencia 
	específica "fin" para indicar la finalización de ejecución del programa.
*/

#include "Cjt_problemas.hh"
#include "Cjt_sesiones.hh"
#include "Cjt_cursos.hh"
#include "Cjt_usuarios.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

int main() {
	Cjt_problemas lista_problemas;
	Cjt_sesiones lista_sesiones;
	Cjt_cursos lista_cursos;
	Cjt_usuarios lista_usuarios;
	
	lista_problemas.leer();
	lista_sesiones.leer();
	lista_cursos.leer(lista_sesiones);
	lista_usuarios.leer();

	string comando;
	cin >> comando;
	while (comando != "fin") {
		//////////////////////////////OPERATION//////////////////////////////
		if (comando == "nuevo_problema" or comando == "np") {
			string ident_problema;
			cin >> ident_problema;
			if (comando == "nuevo_problema") cout << "#nuevo_problema ";
			else cout << "#np ";
			cout << ident_problema << endl;
			bool marca;
			lista_problemas.anadir_problema_verif(ident_problema, marca);
			if (marca) cout << lista_problemas.total_problemas() << endl;
			else cout << "error: el problema ya existe" << endl;

		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "nueva_sesion" or comando == "ns") {
			string ident_sesion;
			cin >> ident_sesion;
			if (comando == "nueva_sesion") cout << "#nueva_sesion ";
			else cout << "#ns ";
			cout << ident_sesion << endl;
			bool marca;
			lista_sesiones.anadir_sesion_verif(ident_sesion,marca);
			if (marca) cout << lista_sesiones.total_sesiones() << endl;
			else cout << "error: la sesion ya existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "nuevo_curso" or comando == "nc") {
			if (comando == "nuevo_curso") cout << "#nuevo_curso" << endl;
			else cout << "#nc" << endl;
			bool marca;
			lista_cursos.anadir_curso(lista_sesiones, marca);
			if (marca) cout << lista_cursos.total_cursos() << endl;
			else cout << "error: curso mal formado" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "alta_usuario" or comando == "a") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "alta_usuario") cout << "#alta_usuario ";
			else cout << "#a ";
			cout << ident_usuario << endl;
			bool marca;
			lista_usuarios.anadir_usuario_verif(ident_usuario, marca);
			if (marca) cout << lista_usuarios.total_usuarios() << endl;
			else cout << "error: el usuario ya existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "baja_usuario" or comando == "b") {
			string ident_usuario;
			int c;
			bool ins;
			cin >> ident_usuario;
			if (comando == "baja_usuario") cout << "#baja_usuario ";
			else cout << "#b ";
			cout << ident_usuario << endl;
			bool marca = lista_usuarios.elimininar_usuario(ident_usuario, c, ins);
			if (not marca) cout << "error: el usuario no existe" << endl;
			else {
				if (ins) lista_cursos.modificar_inscritos_i_esimo(c, 0);
				cout << lista_usuarios.total_usuarios() << endl;
			}
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "inscribir_curso" or comando == "i") {
			string ident_usuario;
			int ident_curso;
			cin >> ident_usuario >> ident_curso;
			if (comando == "inscribir_curso") cout << "#inscribir_curso ";
			else cout << "#i ";
			cout << ident_usuario << ' ' << ident_curso << endl;
			bool a = lista_usuarios.existe_usuario(ident_usuario);
			bool b = ident_curso >= 1 and ident_curso <= lista_cursos.total_cursos();
			if (a and b) {
				bool marca;
				lista_usuarios.inscribir_curso(lista_cursos, lista_sesiones, ident_usuario, ident_curso, marca);
				if (marca) {
					
					cout << lista_cursos.usuarios_inscritos_curso_id(ident_curso) << endl;
				}
				else cout << "error: usuario inscrito en otro curso" << endl;
			}
			else if (not a) cout << "error: el usuario no existe" << endl;
			else cout << "error: el curso no existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "acabar_curso" or comando == "ac") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "acabar_curso") cout << "#acabar_curso ";
			else cout << "#ac ";
			cout << ident_usuario << endl;
			bool a = lista_usuarios.existe_usuario(ident_usuario);
			if (a) {
				bool b = lista_usuarios.esta_inscrito_id(ident_usuario);
				if (not b) cout << "error: usuario no inscrito en ningun curso" << endl;
				else {
					int c;
					lista_usuarios.acabar_curso_usuario_id(lista_cursos, ident_usuario, c);
					cout << lista_cursos.usuarios_inscritos_curso_id(c) << endl;
				}
			}
			else cout << "error: el usuario no existe" << endl;
	
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "curso_usuario" or comando == "cu") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "curso_usuario") cout << "#curso_usuario ";
			else cout << "#cu ";
			cout << ident_usuario << endl;
			bool m = lista_usuarios.existe_usuario(ident_usuario);
			if (not m) cout << "error: el usuario no existe" << endl;
			else cout << lista_usuarios.curso_usuario_id(ident_usuario) << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "sesion_problema" or comando == "sp") {
			int ident_curso;
			string ident_problema;
			cin >> ident_curso >> ident_problema;
			if (comando == "sesion_problema") cout << "#sesion_problema ";
			else cout << "#sp ";
			cout << ident_curso << ' ' << ident_problema << endl;
			bool a = ident_curso >= 1 and ident_curso <= lista_cursos.total_cursos();
			bool b = lista_problemas.existe_problema(ident_problema);
			if (a and b) {
				string id_sesion;
				bool c = lista_cursos.pertenece_problema(ident_curso, ident_problema, id_sesion);
				if (c) cout << id_sesion << endl;
				else cout << "error: el problema no pertenece al curso" << endl;
			}
			else if (not a) cout << "error: el curso no existe" << endl;
			else cout << "error: el problema no existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "problemas_resueltos" or comando == "pr") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "problemas_resueltos") cout << "#problemas_resueltos ";
			else cout << "#pr ";
			cout << ident_usuario << endl;
			bool m = lista_usuarios.existe_usuario(ident_usuario);
			if (not m) cout << "error: el usuario no existe" << endl;
			else lista_usuarios.imprimir_prob_res_id(ident_usuario);
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "problemas_enviables" or comando == "pe") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "problemas_enviables") cout << "#problemas_enviables ";
			else cout << "#pe ";
			cout << ident_usuario << endl;
			bool m = lista_usuarios.existe_usuario(ident_usuario);
			if (not m) cout << "error: el usuario no existe" << endl;
			else {
				bool sub;
				lista_usuarios.imprimir_prob_env_id_verif(ident_usuario, sub);
				if (not sub) cout << "error: usuario no inscrito en ningun curso" << endl;
			}
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "envio" or comando == "e") {
			string ident_usuario;
			string ident_problma;
			int resultado;
			if (comando == "envio") cout << "#envio ";
			else cout << "#e ";
			cin >> ident_usuario >> ident_problma >> resultado;
			cout << ident_usuario << ' ' << ident_problma << ' ' << resultado << endl;
			bool is_solved;
			lista_usuarios.actualizar_estad_usuario(lista_sesiones, lista_cursos, ident_usuario, ident_problma, resultado, is_solved);
			if (not is_solved) lista_problemas.actualizar_estad_prob(ident_problma, resultado);
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "listar_problemas" or comando == "lp") {
			if (comando == "listar_problemas") cout << "#listar_problemas" << endl;
			else cout << "#lp" << endl;
			lista_problemas.escribir_problemas();
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "escribir_problema" or comando == "ep") {
			string ident_problema;
			cin >> ident_problema;
			if (comando == "escribir_problema") cout << "#escribir_problema ";
			else cout << "#ep ";
			cout << ident_problema << endl;
			bool a;
			lista_problemas.escribir_problema_id_verif(ident_problema, a);
			if (not a) cout << "error: el problema no existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "listar_sesiones" or comando == "ls") {
			if (comando == "listar_sesiones") cout << "#listar_sesiones" << endl;
			else cout << "#ls" << endl;
			lista_sesiones.escribir_sesiones();
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "escribir_sesion" or comando == "es") {
			string ident_sesion;
			cin >> ident_sesion;
			if (comando == "escribir_sesion") cout << "#escribir_sesion ";
			else cout << "#es ";
			cout << ident_sesion << endl;
			bool a = lista_sesiones.existe_sesion(ident_sesion);
			if (a) lista_sesiones.escribir_sesion_id(ident_sesion);
			else cout << "error: la sesion no existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "listar_cursos" or comando == "lc") {
			if (comando == "listar_cursos") cout << "#listar_cursos" << endl;
			else cout << "#lc" << endl;
			lista_cursos.imprimir_cursos();	
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "escribir_curso" or comando == "ec") {
			int ident_curso;
			cin >> ident_curso;
			if (comando == "escribir_curso") cout << "#escribir_curso ";
			else cout << "#ec ";
			cout << ident_curso << endl;
			bool a = ident_curso >= 1 and ident_curso <= lista_cursos.total_cursos();
			if (a) lista_cursos.imprimir_curso_id(ident_curso);
			else cout << "error: el curso no existe" << endl;
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "listar_usuarios" or comando == "lu") {
			if (comando == "listar_usuarios") cout << "#listar_usuarios" << endl;
			else cout << "#lu" << endl;
			lista_usuarios.imprimir_usuarios();
		}
		//////////////////////////////OPERATION//////////////////////////////
		else if (comando == "escribir_usuario" or comando == "eu") {
			string ident_usuario;
			cin >> ident_usuario;
			if (comando == "escribir_usuario") cout << "#escribir_usuario ";
			else cout << "#eu ";
			cout << ident_usuario << endl;
			bool a = lista_usuarios.existe_usuario(ident_usuario);
			if (a) lista_usuarios.imprimir_usuario_id(ident_usuario);
			else cout << "error: el usuario no existe" << endl;
		}
		cin >> comando;
	}
}