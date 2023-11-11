#ifndef LOTE_H
#define LOTE_H
#include <iostream>

using std::string;

class Lote
{
    int numero;
    float tamanho;
    float valor;
    string status;
public:
    Lote(int n, float t, float v, const string& s);
    Lote();
    int get_numero();
    float get_tamanho();
    float get_valor();
    string get_status() const;
};

#endif // LOTE_H
