/** @file Sesion.cc
	@brief Implementacion de la clase Sesion
*/

#include "Sesion.hh"

Sesion::Sesion()
{
	numero_problemas = 0;
}

Sesion::~Sesion()
{

}

int Sesion::total_problemas() const
{
	return numero_problemas;
}

void Sesion::anadir_problemas_sesion(const string& a, Problemas_Sesion& pr)
{
	i_anadir_prob_se_priv(a, pr, problemas_sesion);
}

void Sesion::i_anadir_prob_se_priv(const string& nm, Problemas_Sesion& pr, const BinTree<string>& a)
{
	if (not a.empty()) {
		pr.anadir_problema(a.value(), nm);
		i_anadir_prob_se_priv(nm, pr, a.left());
		i_anadir_prob_se_priv(nm, pr, a.right());
	}
}

void Sesion::anadir_enviables(Envio& env)
{
	i_anadir_env_priv(env, problemas_sesion);
}

void Sesion::i_modificar_enviables_priv(const string& id_prob, Envio& env, const BinTree<string>& a)
{
	if (not a.empty()) {
		if (a.value() == id_prob) {
			i_anadir_env_priv(env, a.left());
			i_anadir_env_priv(env, a.right());
		}
		else {
			i_modificar_enviables_priv(id_prob, env, a.left());
			i_modificar_enviables_priv(id_prob, env, a.right());
		}
	}
}

void Sesion::i_anadir_prob_sesion_verif_priv(const string& a, Problemas_Sesion& pr, bool& b, const BinTree<string>& arb)
{
	if (not arb.empty()) {
		if (pr.existe_problema(arb.value())) b = false;
		else {
			pr.anadir_problema(arb.value(), a);
			i_anadir_prob_sesion_verif_priv(a, pr, b, arb.left());
			i_anadir_prob_sesion_verif_priv(a, pr, b, arb.right());
		}
	}
}

void Sesion::anadir_prob_sesion_verif(const string& a, Problemas_Sesion& pr, bool& b)
{
	i_anadir_prob_sesion_verif_priv(a, pr, b, problemas_sesion);
}

void Sesion::modificar_enviables(const string& id_prob, Envio& env)
{
	env.anadir_resuelto(id_prob);
	i_modificar_enviables_priv(id_prob, env, problemas_sesion);
}

void Sesion::i_anadir_env_priv(Envio& env, const BinTree<string>& a)
{
	if (not a.empty()) {
		//si el arbol no esta vacio se comprueba si el problema esta reesuelto o no
		//si el problema no esta resulto se añade al conjunto de problemas enviables
		if (not env.esta_resuelto(a.value())) {
			env.anadir_enviable(a.value());
		}
		else {
			i_anadir_env_priv(env, a.left());
			i_anadir_env_priv(env, a.right());
		}
	}
}

void Sesion::i_leer_priv(BinTree<string>& b, int& count)
{
	string _id;
	cin >> _id;
	if (_id != "0") {
		++count;
		BinTree<string> lft_tree;
		BinTree<string> rgt_tree;
		i_leer_priv(lft_tree, count);
		i_leer_priv(rgt_tree, count);
		b = BinTree<string>(_id, lft_tree, rgt_tree);
	}
}

void Sesion::leer() {
	i_leer_priv(problemas_sesion, numero_problemas);
}

void Sesion::i_imprimir_priv(const BinTree<string>& a)
{
	if (not a.empty()) {
		cout << '(';
		BinTree<string> l = a.left();
		BinTree<string> r = a.right();
		i_imprimir_priv(l);
		i_imprimir_priv(r);
		cout << a.value() << ')';
	}
}

void Sesion::imprimir()
{
	i_imprimir_priv(problemas_sesion);
}