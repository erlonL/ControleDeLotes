#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "pessoa.h"

class Vendedor : public Pessoa
{
    float salario;
    int percentual_comissao;
public:
    Vendedor(const string& n, const string& e, const string& t, float s, int pc);
    Vendedor();
    string get_nome() const;
    string get_endereco() const;
    string get_telefone() const;
    float get_salario();
    int get_percentual();
    void print_info();
};

#endif // VENDEDOR_H
