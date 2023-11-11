#include "vendas_ui.h"
#include "ui_vendas_ui.h"

vendas_ui::vendas_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vendas_ui)
{
    ui->setupUi(this);
    load_vendas();
}

vendas_ui::~vendas_ui()
{
    delete ui;
}

void vendas_ui::clear_focus(){
    ui->cliente_list->clearFocus();
    ui->vendedor_list->clearFocus();
    ui->lote_list->clearFocus();
}

void vendas_ui::load_clientes(){
    QVector<Cliente> _Clientes = emit get_clientes();

    ui->cliente_list->clear();

    for(int i = 0; i < _Clientes.size(); i++)
    {
        Cliente* client = &_Clientes[i];
        std::stringstream ss;

        ss << client->get_nome() << " - "
           << client->get_endereco() << " - "
           << client->get_telefone() << " - "
           << client->get_profissao() << " - "
           << client->get_renda_anual();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->cliente_list->insertItem(i, newItem);
    }
}

void vendas_ui::load_lotes(){
    QVector<Lote> _Lotes = emit get_lotes();

    ui->lote_list->clear();
    for(int i = 0; i < _Lotes.size(); i++)
    {
        Lote* lote = &_Lotes[i];
        std::stringstream ss;

        ss << lote->get_numero() << " - "
           << lote->get_tamanho() << " - "
           << lote->get_valor() << " - "
           << lote->get_status();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->lote_list->insertItem(i, newItem);
    }
}

void vendas_ui::load_vendedores(){
    QVector<Vendedor> _Vendedores = emit get_vendedores();

    ui->vendedor_list->clear();
    for(int i = 0; i < _Vendedores.size(); i++)
    {
        Vendedor* vendedor = &_Vendedores[i];
        std::stringstream ss;

        ss << vendedor->get_nome() << " - "
           << vendedor->get_endereco() << " - "
           << vendedor->get_telefone() << " - "
           << vendedor->get_salario() << " - "
           << vendedor->get_percentual();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->vendedor_list->insertItem(i, newItem);
    }
}

void vendas_ui::load_vendas(){
    qDebug() << "Clear list widget";
    ui->ListWidget->clear();


    qDebug() << "Vendas size: " << Vendas.size();
    for(int i = 0; i < Vendas.size() ; i++){
        Venda* venda = &Vendas[i];
        std::stringstream ss;

        ss << venda->get_data() << " - "
           << venda->get_lote()->get_numero() << " - "
           << venda->get_cliente()->get_nome() << " - "
           << venda->get_vendedor()->get_nome();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->ListWidget->insertItem(i, newItem);
    }
}

void vendas_ui::on_actionVendas_Vendas_triggered()
{
    emit move_vendas();
}


void vendas_ui::on_actionVendedores_Vendas_triggered()
{
    emit move_vendedores();
}


void vendas_ui::on_actionClientes_Vendas_triggered()
{
    emit move_clientes();
}


void vendas_ui::on_actionLotes_Vendas_triggered()
{
    emit move_lotes();
}

Lote* vendas_ui::find_lote(QListWidgetItem* item)
{
    qDebug() << "FIND LOTE";
    QStringList params =  item->text().split(" - ");
    int numero_lote = params[0].toInt();
    QVector<Lote> Lotes_ = emit get_lotes();

    qDebug() << "Lotes size: " << Lotes_.size();

    for(int i = 0; i < Lotes_.size(); i++){
        if(numero_lote == Lotes_[i].get_numero()){
            qDebug() << "Lote " << Lotes_[i].get_numero() << "encontrado";
            return &Lotes_[i];
        }
    }
    return nullptr;
}

Cliente* vendas_ui::find_cliente(QListWidgetItem* item){
    QStringList params = item->text().split(" - ");
    string nome = params[0].toStdString();
    QVector<Cliente> Clientes_ = emit get_clientes();

    for(int i = 0; i < Clientes_.size(); i++){
        if(nome == Clientes_[i].get_nome()){
            return &Clientes_[i];
        }
    }
    return nullptr;
}

Vendedor* vendas_ui::find_vendedor(QListWidgetItem* item){
    QStringList params = item->text().split(" - ");
    string nome = params[0].toStdString();
    QVector<Vendedor> Vendedores_ = emit get_vendedores();

    for(int i = 0; i < Vendedores_.size(); i++){
        if(nome == Vendedores_[i].get_nome()){
            return &Vendedores_[i];
        }
    }
    return nullptr;
}

void vendas_ui::add_venda(){
    string data = ui->data_dateEdit->text().toStdString();
    Lote* lote = find_lote(ui->lote_list->currentItem());
    Cliente* cliente = find_cliente(ui->cliente_list->currentItem());
    Vendedor* vendedor = find_vendedor(ui->vendedor_list->currentItem());

    qDebug() << data;
    if(lote == nullptr || cliente == nullptr || vendedor == nullptr)
        qDebug() << "NULL PTR";

    qDebug() << "Criando nova venda";
    Venda newVenda(data, lote, cliente, vendedor);


    qDebug() << "push back";
    Vendas.push_back(newVenda);

    qDebug() << "Load vendas";
}


void vendas_ui::on_add_btn_clicked()
{
    add_venda();
}

void vendas_ui::remove_venda(){
    QString vendas_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem()); // remove da lista

    QStringList params = vendas_info.split(" - ");

    int numero_lote = params[0].toInt();
    for(int i = 0 ; i < Vendas.size(); i++){
        if(numero_lote == Vendas[i].get_lote()->get_numero()){
            Vendas.remove(i);
        }
    }

    load_lotes();
}

void vendas_ui::on_rm_btn_clicked()
{
    remove_venda();
}

void vendas_ui::edit_venda(){

}

void vendas_ui::on_edit_btn_clicked()
{

}

