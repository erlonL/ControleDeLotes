#ifndef MAINCONTEXT_H
#define MAINCONTEXT_H

#include <QWidget>
#include <lotes_ui.h>
#include <clientes_ui.h>
#include <vendedores_ui.h>
#include <vendas_ui.h>
#include <iostream>

namespace Ui {
class mainContext;
}

class mainContext : public QWidget
{
    Q_OBJECT

public:
    explicit mainContext(QWidget *parent = nullptr);
    ~mainContext();

private slots:

    void on_lotes_btn_clicked();

    void on_clientes_btn_clicked();

    void on_vendedores_btn_clicked();

    void on_vendas_btn_clicked();

    void move_lotes();
    void move_clientes();
    void move_vendedores();
    void move_vendas();

signals:
    void load_clientes();
    void load_vendedores();
    void load_lotes();
    void load_vendas();

private:
    Ui::mainContext *ui;
    lotes_ui _lotes_ui;
    clientes_ui _clientes_ui;
    vendedores_ui _vendedores_ui;
    vendas_ui _vendas_ui;
};

#endif // MAINCONTEXT_H
