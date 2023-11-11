#include "clientes_ui.h"
#include "ui_clientes_ui.h"

clientes_ui::clientes_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientes_ui)
{
    ui->setupUi(this);
    load_clientes();
}

clientes_ui::~clientes_ui()
{
    delete ui;
}

void clientes_ui::on_actionVendas_Clientes_triggered()
{
    clear_forms();
    emit move_vendas();
}

void clientes_ui::on_actionVendedores_Clientes_triggered()
{
    clear_forms();
    emit move_vendedores();
}

void clientes_ui::on_actionClientes_Clientes_triggered()
{
    clear_forms();
    emit move_clientes();
}

void clientes_ui::on_actionLotes_Clientes_triggered()
{
    clear_forms();
    emit move_lotes();
}
void clientes_ui::clear_forms(){
    ui->nome_form->clear();
    ui->endereco_form->clear();
    ui->telefone_form->clear();
    ui->profissao_form->clear();
    ui->renda_anual_form->clear();
}

void clientes_ui::load_clientes()
{
    ui->ListWidget->clear();
    clear_forms();

//    qDebug() << "Loading clientes";
//    qDebug() << "Tamanho do vector " << Clientes.size();
//    qDebug() << "Chamando o for...";
    for(int i = 0; i < Clientes.size(); i++)
    {
        Cliente* client = &Clientes[i];
        std::stringstream ss;

        ss << client->get_nome() << " - "
           << client->get_endereco() << " - "
           << client->get_telefone() << " - "
           << client->get_profissao() << " - "
           << client->get_renda_anual();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->ListWidget->insertItem(i, newItem);
    }
}

void clientes_ui::add_cliente()
{
    string nome = ui->nome_form->toPlainText().toStdString();
    string endereco = ui->endereco_form->toPlainText().toStdString();
    string telefone = ui->telefone_form->toPlainText().toStdString();
    string profissao = ui->profissao_form->toPlainText().toStdString();
    float renda_anual = ui->renda_anual_form->toPlainText().toFloat();

    Cliente* newCliente = new Cliente(nome, endereco, telefone, profissao, renda_anual);

    Clientes.push_back(*newCliente);
    load_clientes();
}

void clientes_ui::on_add_btn_clicked()
{
    add_cliente();
}

void clientes_ui::remove_cliente(){
    QString client_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem()); // remove da lista

    QStringList params = client_info.split(" - ");

    string nome = params[0].toStdString();
    for(int i = 0 ; i < Clientes.size(); i++){
        if(nome == Clientes[i].get_nome()){
            Clientes.remove(i);
        }
    }

    load_clientes();
}

void clientes_ui::on_rm_btn_clicked()
{
    remove_cliente();
}

void clientes_ui::edit_cliente(){
    clear_forms();
    QString client_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem());

    QStringList params = client_info.split(" - ");
    ui->nome_form->setPlainText(params[0]);
    ui->endereco_form->setPlainText(params[1]);
    ui->telefone_form->setPlainText(params[2]);
    ui->profissao_form->setPlainText(params[3]);
    ui->renda_anual_form->setPlainText(params[4]);

    string nome = params[0].toStdString();

    for(int i = 0 ; i < Clientes.size(); i++){
        if(nome == Clientes[i].get_nome()){
            Clientes.remove(i);
        }
    }
}

void clientes_ui::on_edit_btn_clicked()
{
    edit_cliente();
}

QVector<Cliente> clientes_ui::get_clientes(){ return Clientes; }

