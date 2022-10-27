/** @file Curso.hh
	@brief Especificación de la clase Curso
*/

#ifndef CURSO_HH
#define CURSO_HH

#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include "Problemas_Sesion.hh"
#include "Envio.hh"
#include <iostream>
#include <list>
#include <vector>
#include <map>
#endif

using namespace std;

/** @class Curso

	@brief Representa los datos y operaciones de un curso.

	Puede contener una lista de sesines. Si las
	tiene, estas se mantienen en el orden en el que se añaden.
	Para cada problema del Curso, permite saber la sesión a la 
	que pertenece. Ofrece operaciones de lectura y escritura
*/

class Curso {
private:
	/** Estructura que guarda las sesiones del curso */
	list<string> lista;
	/** Estructra de datos que guarda las sesiones de los problemas */
	Problemas_Sesion pr;
	/** Número de usuarios que han completado el curso */
	int us_completado; 
	/** Número de usuarios que estan inscritos al curso */
	int us_inscritos; 

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un Curso vacío
	*/
	Curso();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Curso();


	//Consultoras

	/** @brief Consultora sobre número de usuarios
		\pre Cierto
		\post El resultado es el número de usuarios que han completado el p.i.
	*/
	int usuarios_completado() const;
	/** @brief Consultora sobre número de usuarios
		\pre Cierto
		\post El resultado es el número de usuarios inscritos del p.i.
	*/
	int usuarios_inscritos() const;
	/** @brief Consultora sobre una Sesion
		\pre Cierto
		\post El resultado es el identificador de Sesion
		del problema con identificador "id" (si existe) del p.i.
	*/
	string sesion_poblema_id(const string& id);
	/** @brief Consultora sobre el Curso
		\pre Cierto
		\post El resultado es el número de sesiones del p.i.
	*/
	int numero_sesiones() const;

	/** @brief Consultora sobre el Curso
		\pre Cierto
		\post El resultado es cierto si existe Problema con identificador "prob" en el p.i.,
		el resultado es falso en caso contrario
	*/
	bool existe_problema(const string& prob) const;


	//Modificadoras

	/** @brief Modificadora sobre número de usuarios
		\pre Cierto
		\post si b = falso se reduce el número de usuarios inscritos al 
		parámetro implícito, se aumenta en caso contrario
	*/
	void modificar_usuarios_inscritos(bool b);
	/** @brief Modificadora sobre número de usuarios
		\pre Cierto
		\post Se incrementa en una unidad el numero de usuarios que han
		completado el p.i.
	*/
	void modificar_usuarios_completado();
	/** @brief Modificadora para el conjunto de cursos
		\pre Cierto
		\post Se han añadido al conjunto de problemas enviables "en" los identificadores
		de los problemas de las sesiones que forman p.i.
	*/
	void modificar_envios(Cjt_sesiones& se, Envio& en);

	//res es el resultado del envio sobre el problema id_prob, si b = cierto entonces se ha completado el curso
	//se modifican los problemas enviables del usuario. se completa el curso si al hacer el envio
	//este es correcto y el conjunto de enviables queda vacío

	/** @brief Modificadora para el Curso
		\pre res = 0 o res = 1
		\post Se añaden problemas de las se sesiones del p.i. al conjunto deproblemas enviables "env"
	*/
	void modificar_envios(const string& id_prob, int res, Cjt_sesiones& se, Envio& en);


	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Están preparados en el canal de entrada estándard un entero > 0 y una secuencia
		de identificadores de problemas
		\post Se han añadido los problemas al parámetro implícito
	*/
	void leer(Cjt_sesiones& se);

	/** @brief Operación de lectura
		\pre Están preparados en el canal de entrada estándard un entero > 0 y una secuencia
		de identificadores de problemas
		\post Si las intersección entre las sesiones es vacía b = cierto y estas se añaden 
		al p.i., en caso contrario no se modifica el p.i. y b = falso
	*/
	void leer_verif(Cjt_sesiones& se, bool& b);
	/** @brief Operación de escritura
		\pre Cierto
		\post Se imrpime el número de usuarios que han completado el p.i., el número de usuarios inscritos, 
		el número de sesiones que lo forman y los identificadores de estas por la canal de salida estándard
	*/
	void imprimir();
};
#endif