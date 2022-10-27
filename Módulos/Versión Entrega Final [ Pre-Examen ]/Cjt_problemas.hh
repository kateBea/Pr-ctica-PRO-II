/** @file Cjt_problemas.hh
	@brief Especificación de la clase Cjt_problemas
*/

#ifndef CJT_PROBLEMAS_HH
#define CJT_PROBLEMAS_HH

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#endif

using namespace std;

/** @class Cjt_problemas

	@brief Representa una conjunto de problemas.

	Puede guardar un conjunto de problemas. Contiene
	una serie de operaciones que se puede realizar sobre el conjunto.
	Los problemas están listados en orden creciente por su identificador.
	Ofrece operaciones de lectura y escritura.
*/

class Cjt_problemas {
private:
	/** Estructura que contiene el listado de problemas ordenados crecientemente
	por identificador */
	map<string, Problema> lista;
	/** @brief Operación de comparación sobre Problemas
		\pre Cierto
		\post el resultado es cierto si el a tiene menor valor de ratio que b, 
		en caso de empate se retorna cierto si el identificador de a es menor
		al de b, falso en cualquier otro caso
	*/
	static bool comp(const Problema& a, const Problema& b);
	
public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un conjunto de problemas vacío
	*/
	Cjt_problemas();
	/** @brief Destructora 
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Cjt_problemas();


	//Consultoras

	/** @brief Consultora del número de problemas
		\pre Cierto
		\post El resultado es el número total de problemas del parámetro implícito
	*/
	int total_problemas() const;
	/** @brief Consultora sobre un problema
		\pre Cierto
		\post Retorna cierto si el problema con identificador "ident" existe
		en el conjunto de problemas, falso en caso contrario
	*/
	bool existe_problema(const string& ident) const;


	//Modificadoras

	/** @brief Operación para añadir Problema
		\pre Cierto
		\post Si no existe problema con identificador "nombre" en el parámetro implícito,
		éste se le añade y b = cierto, si existe problema con identificador "nombre" 
		en el p.i. no se hace ninguna modificación  y b = falso
	*/
	void anadir_problema_verif(const string& nombre, bool& b);
	/** @brief Modificadora de un Problema
		\pre resultado = 1 o resultado = 0 y existe problema con identificador "nombre"
		en el parámetro implícito
		\post Si resultado = 1 incrementa el número de envíos correctos del Problema 
		con identificador "nombre" del p.i., con resultado = 0 sólo se incrementa su número 
		de envíos totales 
	*/
	void actualizar_estad_prob(const string& nombre, int resultado);


	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Hay preparado en el canal de entrada estándar un entero > 0 y una 
		serie de identificadores de problemas 
		\post Se han añadido los problemas al parámetro implícito
	*/
	void leer();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se imprime el conjunto de problemas del parámetro implícito por la
		salida estándard en orden creciente por ratio, en caso de empate, en oreden
		creciente por identificador
	*/
	void escribir_problemas();
	/** @brief Operación de escritura
		\pre Problema con identificador "id" existe en el p.i.
		\post Se escribe problema con identificador "id" por la salida
		estándar, si forma parte del parámetro implícito
	*/
	void escribir_problema_id(const string& id);
	/** @brief Operación de escritura
		\pre Cierto
		\post Se escribe Problema con identificador "id" por la salida estándar 
		si existe en el p.i. y b = cierto, si no existe entonces b = falso 
	*/
	void escribir_problema_id_verif(const string& id, bool& b);
};

#endif