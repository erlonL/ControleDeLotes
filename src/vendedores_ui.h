#ifndef VENDEDORES_UI_H
#define VENDEDORES_UI_H

#include <QWidget>
#include "vendedor.h"
#include <sstream>

namespace Ui {
class vendedores_ui;
}

class vendedores_ui : public QWidget
{
    Q_OBJECT

public:
    explicit vendedores_ui(QWidget *parent = nullptr);
    ~vendedores_ui();

signals:
    void move_lotes();
    void move_clientes();
    void move_vendedores();
    void move_vendas();

private slots:
    void on_actionVendas_Vendedores_triggered();

    void on_actionVendedores_Vendedores_triggered();

    void on_actionClientes_Vendedores_triggered();

    void on_actionLotes_Vendedores_triggered();

    void clear_forms();

    void load_vendedores();

    void add_vendedor();

    void remove_vendedor();

    void edit_vendedor();

    void on_add_btn_clicked();

    void on_rm_btn_clicked();

    void on_edit_btn_clicked();

    QVector<Vendedor> get_vendedores();


private:
    Ui::vendedores_ui *ui;
    QVector<Vendedor> Vendedores;

};

#endif // VENDEDORES_UI_H
