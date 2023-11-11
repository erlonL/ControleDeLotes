#ifndef VENDAS_UI_H
#define VENDAS_UI_H

#include <QWidget>
#include "cliente.h"
#include "lote.h"
#include "qlistwidget.h"
#include "vendedor.h"
#include "venda.h"
#include <sstream>

namespace Ui {
class vendas_ui;
}

class vendas_ui : public QWidget
{
    Q_OBJECT

public:
    explicit vendas_ui(QWidget *parent = nullptr);
    ~vendas_ui();

signals:
    void move_lotes();
    void move_clientes();
    void move_vendedores();
    void move_vendas();

    QVector<Cliente> get_clientes();
    QVector<Vendedor> get_vendedores();
    QVector<Lote> get_lotes();

private slots:
    void on_actionVendas_Vendas_triggered();

    void on_actionVendedores_Vendas_triggered();

    void on_actionClientes_Vendas_triggered();

    void on_actionLotes_Vendas_triggered();

    void load_clientes();
    void load_vendedores();
    void load_lotes();
    void load_vendas();

    Lote* find_lote(QListWidgetItem* item);
    Cliente* find_cliente(QListWidgetItem* item);
    Vendedor* find_vendedor(QListWidgetItem* item);

    void clear_focus();

    void add_venda();
    void remove_venda();
    void edit_venda();

    void on_add_btn_clicked();

    void on_rm_btn_clicked();

    void on_edit_btn_clicked();

private:
    Ui::vendas_ui *ui;
    QVector<Venda> Vendas;
};

#endif // VENDAS_UI_H
