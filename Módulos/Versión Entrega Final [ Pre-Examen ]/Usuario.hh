/** @file Usuario.hh
	@brief Especificación de la clase Usuario
*/

#ifndef USUARIO_HH
#define USUARIO_HH

#include "Cjt_cursos.hh"

#ifndef NO_DIAGRAM
#include "Envio.hh"
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Usuario

	@brief Representa las datos y operaciones de un usuario.

	Contiene información referente al Curso al cual está
	inscrito actualmente el Usuario. Proporciona información
	sobre el número de problemas intentados por el Usuario y su número 
	de problemas resueltos. Ofrece operaciones de escritura.
*/

class Usuario {
private:
	/** Identificador del curso al cual esta inscrito el Usuario 
	(si está inscrito a alguno) */
	int id_curso_ins;
	/** Número total de envíos */
	int envios_totales;
	/** Estructura que contiene los problemas enviables y los problemas 
	resueltos con su número de intentos ordenados crecientemente por 
	identificador (env) */
	Envio env;

public:
	//Constructoras y destructora

	/** @brief Creadora por defecto
		\pre Cierto
		\post El resultado es un Usuario con identificador de curso = 0, 
		número de envíos totales = 0, conjunto de problemas enviables y 
		resueltos vacío
	*/
	Usuario();
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Usuario();


	//Consultoras

	/** @brief Consultora sobre el Usuario
		\pre Cierto
		\post El resultado es el identificador del Curso al cual está inscrito el p.i.
		o 0 si no está inscrito a ninguno
	*/
	int consultar_curso() const;
	/** @brief Consultora sobre el número de problemas
		\pre Cierto
		\post El resultado es el número de problemas intentados por el p.i.
	*/
	int consultar_prob_intent() const;
	/** @brief Consultora sobre el número de problemas
		\pre Cierto
		\post El resultado es el numero de problemas resueltos por el p.i.
	*/
	int consultar_prob_res() const;
	/** @brief Consultora sobre el número de envíos
		\pre Cierto
		\post El resultado es el numero total de envíos del p.i.
	*/
	int consultar_envios_totales() const;
	/** @brief Consultora sobre el Usuario
		\pre Cierto
		\post El resultado cierto si el p.i. esta inscrito a algun curso,
		falso en caso contario
	*/
	bool esta_inscrito() const;


	//Modificadoras

	/** @brief Modificadora sobre el Usuario
		\pre "identificador" es un identificador de curso válido y el p.i no está 
		inscrito a ningún Curso
		\post El p.i. tiene como Curso inscrito el Curso con identificador "c"
	*/
	void modificar_curso(int c, Cjt_cursos& cu, Cjt_sesiones& se);
	/** @brief Modificadora del conjunto de usuarios
		\pre El p.i. está inscrito a algún Curso y res = 1 o res = 0
		\post Si res es 1 se aumenta el número de envios correctos del p.i. sobre el Problema
		"nombre_prob", en caso contrario sólo se aumenta el número de intentos sobre "Nombre_prob". b
		es cierto si el conjunto de problemas enviables del p.i. no queda vacío, falso en caso contrario
	*/
	void envio_prob(const string& id_prob, int res, Cjt_cursos& cu, Cjt_sesiones& se, bool& b);
	/** @brief Modificadora del conjunto de usuarios
		\pre Existe Problema enviable con identificador "id" en el p.i.
		\post Se incrementa en una unidad el número de envíos totales sobre el Problema
		con identificador "id"
	*/
	void aumentar_intentos(const string& id);


	//Operaciones de lectura y escritura

	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard el número total de envíos = x, el
		número total de envíos correctos = y, el número total de problemas intentados = z, y
		el identificador del curso al que está inscrito el usuario = t, si lo está, 0 en caso
		de no estarlo. El formato de salida es (x,y,z,t)
	*/
	void imprimir();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard la lista de problemas 
		resueltos por el p.i. en orden creciente por identificador
	*/
	void imprimir_problemas_resueltos();
	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard la lista de problemas 
		enviables por el p.i. en orden creciente por identificador
	*/
	void imprimir_problemas_enviables();
};

#endif