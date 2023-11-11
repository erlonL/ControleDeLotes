#include "cliente.h"

Cliente::Cliente(const string& n, const string& e, const string& t, const string& p, float ra) : Pessoa(n, e, t)
{
    profissao = p;
    renda_anual = ra;
}
Cliente::Cliente(){

}
float Cliente::get_renda_anual(){ return renda_anual; }
string Cliente::get_endereco() const{ return Pessoa::get_endereco(); }
string Cliente::get_nome() const{ return Pessoa::get_nome(); }
string Cliente::get_profissao() const{ return profissao; }
string Cliente::get_telefone() const{ return Pessoa::get_telefone(); }
void Cliente::print_info(){

}
