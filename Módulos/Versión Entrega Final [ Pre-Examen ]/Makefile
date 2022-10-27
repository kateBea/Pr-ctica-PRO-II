OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -std=c++11

program.exe: program.o Cjt_problemas.o Problema.o Cjt_usuarios.o Usuario.o Cjt_cursos.o Curso.o Cjt_sesiones.o Sesion.o Problemas_Sesion.o Envio.o
			g++ -o program.exe *.o

program.o: program.cc
			g++ -c program.cc $(OPCIONS)
			
Problema.o: Problema.cc Problema.hh
			g++ -c Problema.cc $(OPCIONS)

Sesion.o: Sesion.cc Sesion.hh Problemas_Sesion.hh
			g++ -c Sesion.cc $(OPCIONS)

Curso.o: Curso.cc Curso.hh 
			g++ -c Curso.cc $(OPCIONS)

Usuario.o: Usuario.cc Usuario.hh
			g++ -c Usuario.cc $(OPCIONS)

Envio.o: Envio.cc Envio.hh
			g++ -c Envio.cc $(OPCIONS)

Problemas_Sesion.o: Problemas_Sesion.cc Problemas_Sesion.hh
			g++ -c Problemas_Sesion.cc $(OPCIONS)

Cjt_problemas.o: Cjt_problemas.cc Cjt_problemas.hh
			g++ -c Cjt_problemas.cc $(OPCIONS)
						
Cjt_sesiones.o: Cjt_sesiones.cc Cjt_sesiones.hh
			g++ -c Cjt_sesiones.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc Cjt_cursos.hh
			g++ -c Cjt_cursos.cc $(OPCIONS)

Cjt_usuarios.o: Cjt_usuarios.cc Cjt_usuarios.hh
			g++ -c Cjt_usuarios.cc $(OPCIONS)
	
clean:
			rm -f *.o
			rm -f *.exe