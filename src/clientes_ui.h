#ifndef CLIENTES_UI_H
#define CLIENTES_UI_H

#include <QWidget>
#include <sstream>
#include "cliente.h"

namespace Ui {
class clientes_ui;
}

class clientes_ui : public QWidget
{
    Q_OBJECT

public:
    explicit clientes_ui(QWidget *parent = nullptr);
    ~clientes_ui();

signals:
    void move_lotes();
    void move_clientes();
    void move_vendedores();
    void move_vendas();

private slots:
    void on_actionVendas_Clientes_triggered();

    void on_actionVendedores_Clientes_triggered();

    void on_actionClientes_Clientes_triggered();

    void on_actionLotes_Clientes_triggered();

    void clear_forms();

    void load_clientes();

    void add_cliente();

    void remove_cliente();

    void edit_cliente();

    void on_add_btn_clicked();

    void on_rm_btn_clicked();

    void on_edit_btn_clicked();

    QVector<Cliente> get_clientes();

private:
    Ui::clientes_ui *ui;
    QVector<Cliente> Clientes;
};

#endif // CLIENTES_UI_H
