/** @file Cjt_usuarios.hh
	@brief Especificación de la clase Cjt_usuarios
*/

#ifndef CJT_USUARIOS_HH
#define CJT_USUARIOS_HH

#include "Usuario.hh"
#include "Cjt_cursos.hh"
#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Cjt_usuarios

	@brief Representa un conjunto de usuarios.

	Puede contener un conjunto de usuarios donde a cada uno se le asigna un 
	identificador. Están ordenados crecientemente por ese identificador. Ofrece 
	operaciones sobre grupos de usuarios y usuarios en concreto. Ofrece 
	operaciones de lectura y escritura.
*/

class Cjt_usuarios {
private:
	/** Estructura que contiene una lista de usuarios ordenados crecientemente por identificador */
	map<string, Usuario> lista;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto
		\pre Cierto
		\post El resultado es un conjunto de usuarios vacío
	*/
	Cjt_usuarios();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
    ~Cjt_usuarios();

	//Consultoras

	/** @brief Consultora sobre un Usuario
		\pre Existe Usuario con identificador "nombre" en el p.i
		\post El resultado es cierto si el Usuario con identificador "nombre" 
		está inscrito a algún Curso
	*/
	bool esta_inscrito_id(const string& nombre);
	/** @brief Consultora sobre un Usuario
		\pre Cierto
		\post El resultado es cierto si existe Usuario con identificador "nombre", 
		en el p.i., falso en caso contrario
	*/
	bool existe_usuario(const string& nombre) const;
	/** @brief Consultora sobre el conjunto de usuarios
		\pre Cierto
		\post El resultado es el número total de usuarios del p.i.
	*/
	int total_usuarios() const;
	/** @brief Consultora sobre el conjunto de usuarios
		\pre Existe Usuario con identificador "nombre" en el p.i.
		\post El resultado es el Usuario con identificador "nombre" del p.i.
	*/
	Usuario consultar_usuario(const string& nombre);
	/** @brief Consultora sobre el conjunto de usuarios
		\pre Existe Usuario con identificador "id" en el p.i. 
		\post El resultado es el curso al cual esta inscrito el Usuario 
		con identificador "id" del p.i.
	*/
	int curso_usuario_id(const string& id);


	//Modificadoras

	/** @brief Modificadora del conjunto de usuarios
		\pre Cierto
		\post Si m = cierto, se ha añadido al p.i. un Usuario con identificador "nombre",
		m es falso en caso contrario
	*/
	void anadir_usuario_verif(const string& nombre, bool& m);
	/** @brief Modificadora del conjunto de usuarios
		\pre Cierto
		\post Si existe Usuario con identificador "nombre" en el p.i. éste se 
		elimina y b = cierto, b = falso en caso contrario
	*/
	bool elimininar_usuario(const string& nombre, int& c, bool& b);
	/** @brief Modificadora del conjunto de usuarios
		\pre Existe en el parámetro implícito Usuario con identificador "nombre_us" y está inscrito a algún Curso
		 res = 1 o res = 0
		\post Si resultado es 1 se aumenta el número de envios correctos del Usuario "nombre_us" sobre el Problema
		"nombre_prob", en caso contrario sólo se aumenta el número de intentos de "nombre_us" sobre "Nombre_prob"
	*/
	void actualizar_estad_usuario(Cjt_sesiones& se, Cjt_cursos& cu, const string& nombre_us, const string& nombre_prob, int resultado);
	/** @brief Modificadora sobre el conjunto de usuarios
		\pre existe Usuario con identificador "nombre" en el p.i.
		\post Usuario con identificador "nombre" pasa a tener atribuido
		el Curso con identificador "curso" y marca = cierto, marca = falso en caso contrario
	*/
	void inscribir_curso(Cjt_cursos& b, Cjt_sesiones& s, const string& nombre, int curso, bool& marca);


	//Operaciones de lectura y escritura

	/** @brief Operación de lectura
		\pre Por el canal de entrada estándard hay un entero > 0 y una secuencia de identificadores de usuarios
		\post Se han añadido al p.i. un conjunto de usuarios con los identificadores leídos
	*/
	void leer();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard los usuarios del p.i.
		en orden creciente por identificador
	*/
	void imprimir_usuarios();
	/** @brief Operación de escritura
		\pre Existe Usuario con identificador "id" en el parámetro implícito
		\post Se ha escrito por el canal de salida estándard el Usuario
		con identificador "id" del parámetro implícito
	*/
	void imprimir_usuario_id(const string& id);
	/** @brief Operación de escritura
		\pre Existe Usuario con identificador "id" en el parámetro implícito
		\post Se ha escrito por el canal de salida estándard una lista de los problemas
		resueltos por el Usuario con identificador "id" del p.i.
	*/
	void imprimir_prob_res_id(const string& id);
	/** @brief Operación de escritura
		\pre Existe Usuario con identificador "id" en el parámetro implícito
		\post Si el Usuario está inscrito a algún Curso, se escribe por el canal de salida 
		estándard una lista de los problemas enviables por el Usuario con identificador "id" del p.i.
		y b = cierto, si el Usuario no está inscrito a ningún Curso b = falso
	*/
	void imprimir_prob_env_id_verif(const string& id, bool& b);
};

#endif