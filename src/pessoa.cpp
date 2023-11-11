#include "pessoa.h"

Pessoa::Pessoa(const string& n, const string& e, const string& t)
{
    nome = n;
    endereco = e;
    telefone = t;
}
Pessoa::Pessoa(){}
string Pessoa::get_telefone() const{ return telefone; }
string Pessoa::get_endereco() const{ return endereco; }
string Pessoa::get_nome() const{ return nome; }
