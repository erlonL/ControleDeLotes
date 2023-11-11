#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>

using std::string;

class Pessoa
{
    string nome;
    string endereco;
    string telefone;
public:
    Pessoa(const string& n, const string& e, const string& t);
    Pessoa();
    string get_nome() const;
    string get_endereco() const;
    string get_telefone() const;
    virtual void print_info()=0; // classe abstrata
};

#endif // PESSOA_H
