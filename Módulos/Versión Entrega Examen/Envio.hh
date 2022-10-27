/** @file Envio.hh
	@brief Especificación de la clase Envio
*/

#ifndef ENVIO_HH
#define ENVIO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Envio

	@brief Representa un conjunto de problemas resueltos y enviables.

	Puede contener un conjunto de problemas enviables y un conjunto
	de problemas resueltos, cada uno ofrece para cada Problema
	el número total de envíos que se han hecho. En ambos conjuntos 
	los problemas están ordenados crecientemente por identificador. 
	También permite saber el número total de problemas que se han intentado
	entre ambos conjuntos. Ofrece operaciones de escritura.
*/

class Envio {
private:
	/** Estructura que contiene identificadores de problemas enviables ordenados crecientemente por identificador*/
	map<string, int> enviables;
	/** Estructura que contiene identificadores de problemas resueltos ordenados crecientemente por identificador*/
	map<string, int> resueltos;
	/** Número de problemas intentados */
	int intentados;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un Envio vacío
	*/
	Envio();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Envio();


	//Consultoras

	/** @brief Consultora sobre el conjunto de enviables
		\pre Cierto
		\post El resultado es el número total de problemas enviables del p.i.
	*/
	int total_enviables() const;
	/** @brief Consultora sobre el conjunto de resueltos
		\pre Cierto
		\post El resultado es el número total de problemas resueltos del p.i.
	*/
	int total_resueltos() const;
	/** @brief Consultora sobre el conjunto de resueltos
		\pre Cierto
		\post El resultado es cierto si existe problema con identificador "p" en el
		conjunto de problemas resueltos del p.i.
	*/
	bool esta_resuelto(const string& p) const;
	/** @brief Consultora sobre el conjunto de envíos
		\pre Cierto
		\post El resultado es número total de problemas intentados en el p.i.
	*/
	int total_intentados() const;


	//Modificadoras

	/** @brief Método para el conjunto de envibles
		\pre NO existe Problema con identificador "env" en el conjunto de problemas enviables del p.i.
		\post Se ha añadido Problema con identificador "env" al conjunto de problemas enviavles del p.i.
	*/
	void anadir_enviable(const string& env);

	/** @brief Método para el conjunto de reseltos
		\pre Existe Problema con identificador "res" en el conjunto de problemas enviables del p.i.
		\post Se ha añadido Problema con identificador "res" al conjunto de problemas resueltos del p.i.
	*/
	void anadir_resuelto(const string& res);

	/** @brief Método para el conjunto de reseltos
		\pre Existe Problema con identificador "b" en el conjunto de problemas enviables del p.i.
		\post Se ha incrementado en una unidad el número de envíos sobre Problema con identificador 
		"b" del conjunto de problemas enviavles del p.i.
	*/
	void incrementar_enviables(const string& b);

	//vacia el cjt de probs enviablss
	void vaciar_enviables();

	//Operaciones de escritura

	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard la lista de problemas
		enviables del p.i. por orden creciente de identificador
	*/
	void escribir_enviables();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard la lista de problemas
		resueltos del p.i. por orden creciente de identificador
	*/
	void escribir_resueltos();
};

#endif