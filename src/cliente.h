#ifndef CLIENTE_H
#define CLIENTE_H
#include "pessoa.h"

class Cliente : public Pessoa
{
    string profissao;
    float renda_anual;
public:
    Cliente(const string& n, const string& e, const string& t, const string& p, float ra);
    Cliente();
    string get_nome() const;
    string get_endereco() const;
    string get_telefone() const;
    string get_profissao() const;
    float get_renda_anual();
    void print_info();
};

#endif // CLIENTE_H
