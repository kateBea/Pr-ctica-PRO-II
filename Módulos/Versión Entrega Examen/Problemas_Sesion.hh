/** @file Problemas_Sesion.hh
	@brief Especificación de la clase Problemas_Sesion
*/

#ifndef PROBLEMAS_SESION_HH
#define PROBLEMAS_SESION_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Problemas_Sesion

	@brief Representa un conjunto de problemas y las seiones a que pertenecen.

	Puede contener un conjunto de Problemas, para cada uno
	se guarda la Sesión a la cual pertenece. El conjunto está 
	ordenado crecientemente por identificador de Problema. 
	Ofrece operaciones de escritura
*/

class Problemas_Sesion {
private:
	/** Estructura que contiene un identificador de Sesión para cada Problema, ordenada crecientemente
	por identificador de Problema*/
	map<string, string> conj;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un conjunto vacío
	*/
	Problemas_Sesion();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Problemas_Sesion();


	//Consultoras

	/** @brief Consultora sobre el conjunto
		\pre Cierto
		\post El resultado es el número total de Problemas del p.i.
	*/
	int total_problemas_curso() const;
	/** @brief Consultora sobre el conjunto
		\pre Existe Problema con identificador prob_nom en el p.i.
		\post El resultado es el identificador de la Sesión a la que pertenece el 
		Problema con identificador "prob_nom" del p.i.
	*/
	string problema_sesion(const string& prob_nom);
	/** @brief Consultora sobre el conjunto
		\pre Cierto
		\post El resultado es cierto si existe Problema con identificador "p" 
		en el p.i., falso en caso contrario
	*/
	bool existe_problema(const string& p) const;

	//Modificadoras

	/** @brief Consultora sobre el conjunto
		\pre No existe Problema con identificador "prob" en el p.i.
		\post Se ha añadido Problema con identificador "prob" y Sesión "se" al p.i.
	*/
	void anadir_problema(const string& prob, const string& se);

	
	//Operación de escritura

	/**  @brief Operación de escritura
		\pre Cierto
		\post Se escribe para cada Problema del p.i. el identificador del Problema y 
		la Sesión a la cual pertenece por el canal de salida estándard, ordenados 
		crecientemente por identificador
	*/
	void escribir();
	/** @brief Operación de escritura
		\pre Existe Problema con identificador "prob" en el p.i.
		\post Se escrito el identificador del Problema y la Sesión a la cual pertenece por 
		el canal de salida estándard
	*/
	void escribir_sesion(const string& p);
};

#endif