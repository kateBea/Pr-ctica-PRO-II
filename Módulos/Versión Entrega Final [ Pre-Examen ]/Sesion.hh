/** @file Sesion.hh
	@brief Especificación de la clase Sesion
*/

#ifndef SESION_HH
#define SESION_HH

#ifndef NO_DIAGRAM
#include "Problemas_Sesion.hh"
#include "BinTree.hh"
#include "Envio.hh"
#include <iostream>
#endif

using namespace std;

/** @class Sesion

	@brief Representa los datos y operaciones de una sesión.

	Puede contener un conjunto de problemas. En
	este caso vienen organizados siguiendo un formato de 
	prerequisito. Ofrece operaciones de lectura y escritura
*/

class Sesion {
private:
	/** Estructura contenedora de los identificadores de los problemas de la sesión 
	siguiendo el formato de prerequisitos */
	BinTree<string> problemas_sesion; 
	/** Número total de problemas de la sesión */
	int numero_problemas; 

	/** @brief Operación de lectura
		\pre Hay por el canal de entrada estándard una serie de identificadores de
		Problemas en preorden 
		\post Se han añadido los identificadores de los problemas al p.i.
	*/
	void i_leer_priv(BinTree<string>& b, int& count);
	/** @brief Operación de lectura
		\pre Cierto
		\post Se escribe "a" por el canal estándard de salida en postorden
	*/
	void i_imprimir_priv(const BinTree<string>& a);
	/** @brief Modificadora para la Sesión
		\pre Cierto
		\post Si a no está vacío, se añadide Problema con identificador a.value() al
		conjunto de problemas enviables "en" si no existe, no se hace modificación alguna
		en caso contrario
	*/
	void i_anadir_env_priv(Envio& env, const BinTree<string>& a);
	/** @brief Modificadora para la Sesion
		\pre a identifica el p.i.
		\post Si a no está vacío, se añade identificador de Problema = a.value()
		al conjunto de problemas de Sesión "pr"
	*/
	void i_anadir_prob_se_priv(const string& nm, Problemas_Sesion& pr, const BinTree<string>& a);
	/** @brief Modificadora para la Sesión
		\pre Existe problema con identificador "id_prob" en el p.i. y en el conjunto de enviables de "env"
		\post Si a no está vacío y a.value() == id_prob, se añadide Problema con identificador a.value() al
		conjunto de problemas enviables "en" si no existe, no se hace modificación alguna en caso contrario
	*/
	void i_modificar_enviables_priv(const string& id_prob, Envio& env, const BinTree<string>& a);
	/** @brief Modificadora para la Sesion
		\pre a identifica el p.i. y b = cierto
		\post Si existe Problema con identificador = arb.value() en el conjunto de problemas de seión "pr" b = falso,
		en caso contrario éste se añade al conjunto de problemas de Sesión "pr"
	*/
	void i_anadir_prob_sesion_verif_priv(const string& a, Problemas_Sesion& pr, bool& b, const BinTree<string>& arb);

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es una Sesion vacía
	*/
	Sesion();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Sesion();


	//Consultoras

	/** @brief Consultora del número de problemas
		\pre Cierto
		\post El resultado es el número de problemas del parámetro implícito
	*/
	int total_problemas() const;


	//Modificadoras
	 
	/** @brief Modificadora para la Sesion
		\pre a identifica el p.i.
		\post se han añadido los problemas del p.i. al conjunto de problemas de Sesión "pr"
	*/
	void anadir_problemas_sesion(const string& a, Problemas_Sesion& pr);
	/** @brief Modificadora para la Sesion
		\pre a identifica el p.i. y b = cierto
		\post Si existen problemas del p.i. en el conjunto de problemas de seión "pr" b = falso,
		en caso contrario estos se añaden al conjunto de problemas de Sesión "pr"
	*/
	void anadir_prob_sesion_verif(const string& a, Problemas_Sesion& pr, bool& b);
	/** @brief Modificadora para la Sesion
		\pre Existe problema con identificador "id_prob" en el p.i. y en el conjunto de enviables de "env"
		\post Se añaden problemas sucesores de "id_prob" en el p.i. al conjunto de problemas enviables de "env"
	*/
	void modificar_enviables(const string& id_prob, Envio& env);
	/** @brief Modificadora para Sesión
		\pre Cierto
		\post Se han añadido problemas p.i. al conjunto de problemas enviables "en"
	*/
	void anadir_enviables(Envio& en);


	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Hay por el canal de entrada estándard una serie de identificadores en preorden
		\post Se han añadido los identificadores de los problemas al p.i.
	*/
	void leer();
	
	/** @brief Operación de lectura
		\pre Cierto
		\post Se escribe por el canal estándard de salida el número de problemas del p.i. y
		los identificadores de estos en postorden
	*/
	void imprimir();
};

#endif