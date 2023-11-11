#ifndef VENDA_H
#define VENDA_H
#include "cliente.h"
#include "vendedor.h"
#include "lote.h"

class Venda
{
    string data;
    Lote* lote;
    Cliente* cliente;
    Vendedor* vendedor;
public:
    Venda(const string& d, Lote* l, Cliente* c, Vendedor* v);
    Venda();

    string get_data() const;
    Lote* get_lote();
    Cliente* get_cliente();
    Vendedor* get_vendedor();
};

#endif // VENDA_H
