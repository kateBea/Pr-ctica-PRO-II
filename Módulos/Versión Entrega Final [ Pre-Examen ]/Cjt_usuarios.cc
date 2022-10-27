/** @file Cjt_usuarios.cc
    @brief Implementación de la clase Cjt_usuarios
*/

#include "Cjt_usuarios.hh"

Cjt_usuarios::Cjt_usuarios()
{

}

Cjt_usuarios::~Cjt_usuarios()
{

}

bool Cjt_usuarios::esta_inscrito_id(const string& nombre)
{
    return lista[nombre].esta_inscrito();
}

bool Cjt_usuarios::existe_usuario(const string& nombre) const
{
    map<string, Usuario>::const_iterator it = lista.find(nombre);
    return it != lista.end();
}

int Cjt_usuarios::total_usuarios() const
{
    return lista.size();
}

Usuario Cjt_usuarios::consultar_usuario(const string& nombre)
{
    return lista[nombre];
}

int Cjt_usuarios::curso_usuario_id(const string& id)
{
    return lista[id].consultar_curso();
}

void Cjt_usuarios::anadir_usuario_verif(const string& nombre, bool& m)
{
    map<string, Usuario>::iterator it = lista.find(nombre);
    m = it == lista.end();
    if (m) {
        Usuario us;
        pair<string, Usuario> _in = make_pair(nombre, us);
        lista.insert(_in);
    }
}

bool Cjt_usuarios::elimininar_usuario(const string& nombre, int& c, bool& b)
{
    map<string, Usuario>::iterator it = lista.find(nombre);
    bool result;
    if (it != lista.end()) {
        c = lista[nombre].consultar_curso();
        b = c != 0;
        lista.erase(nombre);
        result = true;
    }
    else result = false;

    return result;
}

void Cjt_usuarios::actualizar_estad_usuario(Cjt_sesiones& se, Cjt_cursos& cu, const string& nombre_us, const string& nombre_prob, int resultado)
{
    if (resultado == 1) {
        //envio correcto, actualizar enviables del usuario
        //necesito saber si el Usuario completa el curso al hacer el envío

        int c = lista[nombre_us].consultar_curso();
        
        //resultado es 1, se necesita actualizar el conjunto de problemas enviables del usuario
        bool is_sub;
        lista[nombre_us].envio_prob(nombre_prob, resultado, cu, se, is_sub);
        
        //si sigue inscrito despues de hacer el envio quiere decir que no ha completado el curso
        //en caso contario, se entra en el condicional (ha completado el curso y ya no está inscrito a é)
        if (not is_sub) {
            //incremento usuarios que han completado el curso
            cu.modificar_comple_curso_id(c);
            //decremento usuarios inscritos
            cu.modificar_inscritos_i_esimo(c, 0);
        }
    }
    else {
        //envio incorrecto, solo se incrementa los intentoss en el enviable con nombre "nombre_prob"
        //y tambien se incrementa el numero de problemas intentados si es necesrio
        lista[nombre_us].aumentar_intentos(nombre_prob);
    }
}

void Cjt_usuarios::inscribir_curso(Cjt_cursos& b, Cjt_sesiones& s, const string& nombre, int curso, bool& marca)
{
    //al inscribir un Usuario "nombre" cualquiera con identificador "curso", 
    //necesito que el Usuario tenga acceso a los problemas enviables de las sesiones del
    //curso siguiendo la restricción de prerequisito

    //Usuario inscrito en otro Curso?
    int curs = lista[nombre].consultar_curso();
    if (curs != 0) marca = false;
    else {
        lista[nombre].modificar_curso(curso, b, s);
        marca = true;
    }
}

void Cjt_usuarios::leer()
{
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string id_usuario;
        cin >> id_usuario;
        Usuario in;
        pair<string, Usuario> _value = make_pair(id_usuario, in);
        lista.insert(_value);
    }
}

void Cjt_usuarios::imprimir_usuarios()
{
    map<string, Usuario>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it) {
        cout << it->first;
        it->second.imprimir();
        cout << endl;
    }
}

void Cjt_usuarios::imprimir_usuario_id(const string& id)
{
    cout << id;
    lista[id].imprimir();
    cout << endl;
}

void Cjt_usuarios::imprimir_prob_res_id(const string& id)
{
    lista[id].imprimir_problemas_resueltos();
}

void Cjt_usuarios::imprimir_prob_env_id_verif(const string& id, bool& b)
{
    b = lista[id].esta_inscrito();
    if (b) lista[id].imprimir_problemas_enviables();
}