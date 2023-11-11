#include "lote.h"

Lote::Lote(int n, float t, float v, const string& s)
{
    numero = n;
    tamanho = t;
    valor = v;
    status = s;
}
Lote::Lote(){

}

int Lote::get_numero(){ return numero; };
float Lote::get_tamanho(){ return tamanho; };
float Lote::get_valor(){ return valor; };
string Lote::get_status() const{ return status; };
