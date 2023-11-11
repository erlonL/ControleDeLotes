#ifndef LOTES_UI_H
#define LOTES_UI_H

#include <QWidget>
#include "lote.h"
#include <sstream>
#include <QMessageBox>

/*lotes*/

namespace Ui {
class lotes_ui;
}

class lotes_ui : public QWidget
{
    Q_OBJECT

public:
    explicit lotes_ui(QWidget *parent = nullptr);
    ~lotes_ui();

private slots:
    void on_actionClientes_Lotes_triggered();

    void on_actionVendas_Lotes_triggered();

    void on_actionVendedores_Lotes_triggered();

    void on_actionLotes_Lotes_triggered();

    void clear_forms();

    void load_lotes();

    void add_lote();

    void remove_lote();

    void edit_lote();

    void on_add_btn_clicked();

    void on_rm_btn_clicked();

    void on_edit_btn_clicked();

    void on_available_box_stateChanged(int arg1);

    void on_reserved_box_stateChanged(int arg1);

    void on_sold_box_stateChanged(int arg1);

    QVector<Lote> get_lotes();

signals:
    void move_lotes();
    void move_clientes();
    void move_vendedores();
    void move_vendas();

private:
    Ui::lotes_ui *ui;
    QVector<Lote> Lotes;
};

#endif // LOTES_UI_H
