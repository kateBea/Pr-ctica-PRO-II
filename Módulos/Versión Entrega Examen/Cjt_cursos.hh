/** @file Cjt_cursos.hh
	@brief Especificación de la clase Cjt_cursos
*/

#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

#include "Curso.hh"
#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Cjt_cursos

	@brief Representa un conjunto de cursos.

	Puede contener un conjunto de cursos. Cada curso viene 
	representado por un indentificador que es un entero natural. 
	Ofrece operaciones de lectura y escritura.
*/

class Cjt_cursos {
private:
	/** Estructura que guarda la los cursos por índice */
	vector<Curso> lista;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un conjunto vacío de cursos
	*/
	Cjt_cursos();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Cjt_cursos();


	//Consultoras

	/** @brief Consutltora sobre un Curso
		\pre 0 < n <= número total de cursos del p.i.
		\post El resultado es el curso n-ésimo del parámetro implícito
	*/
	Curso consultar_curso(int n) const;
	/** @brief Consultora sobre el número de cursos
		\pre Cierto
		\post El resultado es el número total de cursos del p.i.
	*/
	int total_cursos() const;
	/** @brief Consultora sobre un Curso
		\pre Cierto
		\post El resultado es el identificador de la sesión a la cual pertence el problema
		con identificador "prob_id" en el curso  con identificador "curso"
	*/
	string consultar_sesion_curso_id(int curso, const string& prob_id);
	/** @brief Consultora sobre un Curso
		\pre < n <= total_cursos()
		\post El resultado es el número de usuarios inscritos al curso con identificador "n"
	*/
	int usuarios_inscritos_curso_id(int n) const;

	/** @brief Consultora sobre un Curso
		\pre Cierto
		\post El resultado es cierto si en el Curso con identificador "n" existe Problema
		con identificador "id" y id_se es el identificador de la Sesión en que está el 
		Problema en ese Curso, el resultado es falso en caso contrario
	*/
	bool pertenece_problema(int n, const string& id, string& id_se);


	//Modificadoras

	/** @brief Modificadora sobre un Curso
		\pre 0 < id <= número total de cursos del p.i.
		\post Se incrementa el número de usuarios inscritos al Curso con identificador 
		"id" del parámetro implícito
	*/
	void nuevo_usuario_curso_id(int id);
	/** @brief Modificadora sobre el conjunto de cursos
		\pre Cierto
		\post Si marca = cierto se ha añadido un nuevo curso al p.i., marca = falso
		en caso contrario
	*/
	void anadir_curso(Cjt_sesiones& se, bool& marca);
	/** @brief Modificadora sobre el conjunto de cursos
		\pre 0 < id <= número total de cursos del p.i. y val = 1 o val = 0
		\post Si val = 0 se reduce el numero de usuarios inscritos al Curso con 
		identificador "id", si val = 1 se aumenta el numero de usuarios inscritos 
		al Curso con identificador "id"
	*/
	void modificar_inscritos_i_esimo(int id, int val);
	/** @brief Modificadora sobre el conjunto de cursos
		\pre Existe Curso con identificador n en el p.i.
		\post Se incrementa en una unidad el número de usuarios que han completado el Curso
		con identificador n
	*/
	void modificar_comple_curso_id(int n);
	/** @brief Modificadora para el conjunto de cursos
		\pre 0 < n <= número total de cursos del p.i.
		\post Se han añadido al conjunto de problemas enviables "en" los identificadores
		de los problemas de las sesiones que forman el Curso con identificador "n" del p.i.
	*/
	void modificar_envios_curso_id(int n, Envio& en, Cjt_sesiones& se);
	/** @brief Modificadora para el conjunto de cursos
		\pre 0 < curs <= número total de cursos del p.i.
		\post Se añaden problemas del Curso con identificador "curs" del p.i. al conjunto de 
		problemas enviables "env"
	*/
	void modificar_envios_id(const string& id_prob, int curs, int res, Cjt_sesiones& se, Envio& env);

	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Hay preparados en el canal de entrada estándard un entero > 0 y una secuencia de Cursos
		\post Se ha añadido al parámetro implícito la secuencia de cursos
	*/
	void leer(Cjt_sesiones& se);
	/** @brief  Operación de escritura
		\pre Cierto
		\post Se imprime por el canal de salida estándard los cursos del p.i.
	*/
	void imprimir_cursos();
	/** @brief Operación de escritura
		\pre 0 < id <= total_cursos()
		\post Se imprime por el canal de salida estándard el Curso con identificador "id"
	*/
	void imprimir_curso_id(int id);
};

#endif