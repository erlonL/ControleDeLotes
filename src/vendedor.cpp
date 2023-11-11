#include "vendedor.h"

Vendedor::Vendedor(const string& n, const string& e, const string& t, float s, int pc)
: Pessoa(n, e, t)
{
    salario = s;
    percentual_comissao = pc;
}
Vendedor::Vendedor(){

}
string Vendedor::get_nome() const{ return Pessoa::get_nome(); };
string Vendedor::get_endereco() const{ return Pessoa::get_endereco(); };
string Vendedor::get_telefone() const{ return Pessoa::get_telefone(); };
float Vendedor::get_salario(){ return salario; };
int Vendedor::get_percentual(){ return percentual_comissao; };
void Vendedor::print_info(){

}

