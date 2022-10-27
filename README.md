# Práctica PRO II [ Evaluator ]

REPO de la práctica de sobre modularidad de PRO2.

La plataforma EVALUATOR integra una colección de problemas de programación,
un repositorio de sesiones compuestas por problemas de dicha colección, un conjunto
de cursos formados por una o más sesiones, y un conjunto de usuarios registrados.


- Estructura del programa principal
```cc
  @main 
  lectura de la coleccion inicial de problemas;
  lectura del repositorio inicial de sesiones;
  lectura del conjunto inicial de cursos;
  lectura de los usuarios iniciales;
  lee comando;
  while (comando != "fin") 
  {
    procesa comando;
    lee comando;
  }
```
