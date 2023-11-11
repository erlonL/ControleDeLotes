#include "vendedores_ui.h"
#include "ui_vendedores_ui.h"

vendedores_ui::vendedores_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vendedores_ui)
{
    ui->setupUi(this);
    load_vendedores();
}

vendedores_ui::~vendedores_ui()
{
    delete ui;
}

void vendedores_ui::on_actionVendas_Vendedores_triggered()
{
    emit move_vendas();
}


void vendedores_ui::on_actionVendedores_Vendedores_triggered()
{
    emit move_vendedores();
}


void vendedores_ui::on_actionClientes_Vendedores_triggered()
{
    emit move_clientes();
}


void vendedores_ui::on_actionLotes_Vendedores_triggered()
{
    emit move_lotes();
}

void vendedores_ui::clear_forms(){
    ui->nome_form->clear();
    ui->endereco_form->clear();
    ui->telefone_form->clear();
    ui->salario_form->clear();
    ui->percentual_spinBox->setValue(1);
}

void vendedores_ui::load_vendedores()
{
    ui->ListWidget->clear();
    clear_forms();
    for(int i = 0; i < Vendedores.size(); i++)
    {
        Vendedor* vendedor = &Vendedores[i];
        std::stringstream ss;

        ss << vendedor->get_nome() << " - "
           << vendedor->get_endereco() << " - "
           << vendedor->get_telefone() << " - "
           << vendedor->get_salario() << " - "
           << vendedor->get_percentual();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->ListWidget->insertItem(i, newItem);
    }
}

void vendedores_ui::add_vendedor()
{
    string nome = ui->nome_form->toPlainText().toStdString();
    string endereco = ui->endereco_form->toPlainText().toStdString();
    string telefone = ui->telefone_form->toPlainText().toStdString();
    float salario = ui->salario_form->toPlainText().toFloat();
    int percentual = ui->percentual_spinBox->text().toInt();

    Vendedor* newVendedor = new Vendedor(nome, endereco, telefone, salario, percentual);

    Vendedores.push_back(*newVendedor);
    load_vendedores();
}

void vendedores_ui::on_add_btn_clicked()
{
    add_vendedor();
}

void vendedores_ui::remove_vendedor(){
    QString vendedor_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem()); // remove da lista

    QStringList params = vendedor_info.split(" - ");

    string nome = params[0].toStdString();
    for(int i = 0 ; i < Vendedores.size(); i++){
        if(nome == Vendedores[i].get_nome()){
            Vendedores.remove(i);
        }
    }

    load_vendedores();
}

void vendedores_ui::on_rm_btn_clicked()
{
    remove_vendedor();
}

void vendedores_ui::edit_vendedor(){
    clear_forms();
    QString vendedor_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem());

    QStringList params = vendedor_info.split(" - ");
    ui->nome_form->setPlainText(params[0]);
    ui->endereco_form->setPlainText(params[1]);
    ui->telefone_form->setPlainText(params[2]);
    ui->salario_form->setPlainText(params[3]);
    ui->percentual_spinBox->setValue(params[4].toInt());

    string nome = params[0].toStdString();

    for(int i = 0 ; i < Vendedores.size(); i++){
        if(nome == Vendedores[i].get_nome()){
            Vendedores.remove(i);
        }
    }
}

void vendedores_ui::on_edit_btn_clicked()
{
    edit_vendedor();
}


QVector<Vendedor> vendedores_ui::get_vendedores(){ return Vendedores; }
