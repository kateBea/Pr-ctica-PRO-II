/** @file Cjt_sesiones.hh
	@brief Especificación de la clase Cjt_sesiones
*/

#ifndef CJT_SESIONES_HH
#define CJT_SESIONES_HH

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include "Envio.hh"
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Cjt_sesiones

	@brief Representa un conjunto de sesiones.

	Puede contener un conjunto de sesiones. Si el conjunto
	no es vacío las sesiones del conjunto están ordenadas
	crecientemente por identificador. Ofrece operaciones de
	lectura y de escritura
*/

class Cjt_sesiones{
private:
	/** Estructura que contiene las sesiones ordenadas crecientemente por identificador */
	map<string, Sesion> lista;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un conjunto de sesiones vacío
	*/
	Cjt_sesiones();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Cjt_sesiones();


	//Consultoras

	/** @brief Consultora sobre una sesión
		\pre Cierto
		\post Retorna falso si no existe sesión con identificador "nombre" en el p.i.,
		retorna cierto en caso contrario
	*/
	bool existe_sesion(const string& nombre) const;
	/** @brief Consultora sobre el conjunto de sesiones
		\pre Cierto
		\post El resultado es el número total de sesiones del p.i.
	*/
	int total_sesiones() const;
	/** @brief Consultora sobre el conjunto de sesiones
		\pre Existe Sesion con identificador "se" en el p.i.
		\post El resultado es la Sesión con identificador "se" del p.i.
	*/
	Sesion consultar_sesion(const string& se);

	//Modificadoras

	/** @brief Modificadora sobre el conjunto de sesiones
		\pre Cierto
		\post Si no existe Sesión con identificador "nombre" en el p.i. esta 
		se le añade y m = cierto, m = falso en caso contrario y no se añade 
		Sesión con identificador "Nombre"
	*/
	void anadir_sesion_verif(const string& nombre, bool& m);

	/** @brief Modificadora para el conjunto de sesiones
		\pre Existe Sesión con identificador "id" en el p.i.
		\post Se han añadido problemas de la Sesión con identificador "id" del p.i.
		al conjunto de problemas enviables "en"
	*/
	void anadir_enviables_sesion_id(const string& id, Envio& en);


	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Hay preparado en el canal de entrada estándard un entero > 0 y una secuencia 
		de sesiones
		\post Se han añadido al parámetro implícito la secuencia de sesiones
	*/
	void leer();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard todas 
		las sesiones del p.i.
	*/
	void escribir_sesiones();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard la Sesión con identificador 
		"id" del p.i.
	*/
	void escribir_sesion_id(const string& id);
};

#endif