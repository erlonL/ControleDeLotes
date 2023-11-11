#include "venda.h"

Venda::Venda(const string& d, Lote* l, Cliente* c, Vendedor* v)
{
    data = d;
    lote = l;
    cliente = c;
    vendedor = v;
}

Venda::Venda(){

}
string Venda::get_data() const{ return data; }
Lote* Venda::get_lote(){ return lote; }
Cliente* Venda::get_cliente(){ return cliente; }
Vendedor* Venda::get_vendedor(){ return vendedor; }
