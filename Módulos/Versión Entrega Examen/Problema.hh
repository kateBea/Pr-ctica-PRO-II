/** @file Problema.hh
	@brief Especificación de la clase Problema
*/

#ifndef PROBLEMA_HH
#define PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Problema

	@brief Representa los datos y operaciones de un Problema.

	Puede contener el nombre o identificador de un problema, 
	el número total de envíos sobre éste (que incluye los 
	intentos sin éxito), el número total de envíos correctos 
	y el ratio definido como (t+1) / (e+1) donde t es el número
	total de envíos y e es el número total de envíos correctos.
	Ofrece operacion de escritura
*/

class Problema {
private:
	/** Identificador del Problema */
	string identificador;
	/** Ratio del Problema */
	double ratio;
	/** Número total de envíos */
	int total_envios;
	/** Número total de envíos correctos */
	int envios_correctos;

public:
	//Constructoras y destructora

	/** @brief Constructora por defecto 
		\pre Cierto
		\post El resultado es un problema nuevo con número total de envíos 
		igual a 0 y número total de envíos correctos igual a 0 
	*/
	Problema();
	/** @brief Construtora con parámetros
		\pre Cierto
		\post El resultado es un problema con identificador = id número total 
		de envíos igual a 0 y número total de envíos correctos igual a 0
	*/
	Problema(const string& id);
	/** @brief Destructora
		\pre Cierto
		\post Elimina automáticamente los objetos locales al
		salir de un ámbito de visibilidad
	*/
	~Problema();

													
	//Consultoras

	/** @brief Consultora del idenficador
		\pre Cierto
		\post El resultado es el identificador del parámetro implícito
	*/
	string consultar_identificador() const;
	/** @brief Consultora del número de envíos
		\pre Cierto
		\post El resultado es el número de envíos total que se ha realizado
		sobre el parámetro implícito
	*/
	int consultar_total_envios() const;
	/** @brief Consultora del número de envíos correctos
		\pre Cierto
		\post El resultado es el número total de envíos correctos que
		se ha realizado sobre el parámetro implícito
	*/
	int consultar_envios_correctos() const;
	/** @brief Consultora del ratio
		\pre Cierto
		\post El resultado es el ratio del p.i.
	*/
	double consultar_ratio() const;


	//Modificadoras

	/** @brief Modificadora del número de envíos total
		\pre Cierto
		\post Se ha incrementado en una unidad el número total de
		envíos del parámetro implícito
	*/
	void incrementar_total_envios();
	/** @brief Modificadora del número de envíos correctos
		\pre Cierto
		\post Se ha incrementado en una unidad el número total de
		envíos correctos del parámetro implícito
	*/
	void incrementar_envios_correctos();

	//Operaciones de lectura y escritura

	/** @brief Operación de escritura
		\pre Cierto
		\post Se ha escrito por el canal de salida estándard el identificador, 
		el número total de envíos del parámetro implícito seguido de su número 
		total de envíos correctos
	*/
	void imprimir();
};

#endif