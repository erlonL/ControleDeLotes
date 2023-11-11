#include "lotes_ui.h"
#include "ui_lotes_ui.h"

// VENDAS
lotes_ui::lotes_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lotes_ui)
{
    ui->setupUi(this);
    load_lotes();

}

lotes_ui::~lotes_ui()
{
    delete ui;
}

void lotes_ui::on_actionClientes_Lotes_triggered()
{
    emit move_clientes();
}


void lotes_ui::on_actionVendas_Lotes_triggered()
{
    emit move_vendas();
}


void lotes_ui::on_actionVendedores_Lotes_triggered()
{
    emit move_vendedores();
}


void lotes_ui::on_actionLotes_Lotes_triggered()
{
    emit move_lotes();
}

void lotes_ui::clear_forms(){
    ui->number_form->clear();
    ui->size_form->clear();
    ui->value_form->clear();

    ui->available_box->setChecked(false);
    ui->reserved_box->setChecked(false);
    ui->sold_box->setChecked(false);
}

void lotes_ui::load_lotes()
{
    ui->ListWidget->clear();
    clear_forms();
    for(int i = 0; i < Lotes.size(); i++)
    {
        Lote* lote = &Lotes[i];
        std::stringstream ss;

        ss << lote->get_numero() << " - "
           << lote->get_tamanho() << " - "
           << lote->get_valor() << " - "
           << lote->get_status();

        QString client_info = QString::fromStdString(ss.str());

        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(client_info);
        ui->ListWidget->insertItem(i, newItem);
    }
}

void lotes_ui::add_lote()
{
    string status = "";
    if(ui->available_box->isChecked()){
        status = "Disponivel";
    }else if(ui->reserved_box->isChecked()){
        status = "Reservado";
    }else if(ui->sold_box->isChecked()){
        status = "Vendido";
    }else{
        QMessageBox statusWarning;
        statusWarning.setText("Selecione uma das opções de status!");
        statusWarning.exec();
        return;
    }

    int numero = ui->number_form->toPlainText().toInt();
    float tamanho = ui->size_form->toPlainText().toFloat();
    float valor = ui->value_form->toPlainText().toFloat();

    Lote* newLote = new Lote(numero, tamanho, valor, status);

    Lotes.push_back(*newLote);
    load_lotes();
}

void lotes_ui::on_add_btn_clicked()
{
    add_lote();
}

void lotes_ui::remove_lote(){
    QString lote_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem()); // remove da lista

    QStringList params = lote_info.split(" - ");

    int numero = params[0].toInt();
    for(int i = 0 ; i < Lotes.size(); i++){
        if(numero == Lotes[i].get_numero()){
            Lotes.remove(i);
        }
    }

    load_lotes();
}

void lotes_ui::on_rm_btn_clicked()
{
    remove_lote();
}

void lotes_ui::edit_lote(){
    clear_forms();
    QString client_info = ui->ListWidget->currentItem()->text();
    ui->ListWidget->removeItemWidget(ui->ListWidget->currentItem());

    QStringList params = client_info.split(" - ");
    ui->number_form->setPlainText(params[0]);
    ui->size_form->setPlainText(params[1]);
    ui->value_form->setPlainText(params[2]);

    int numero = params[0].toInt();

    QString status = params[3];
    if(status == "Disponivel"){
        ui->available_box->setChecked(true);
    }else if(status == "Reservado"){
        ui->reserved_box->setChecked(true);
    }else if(status == "Vendido"){
        ui->sold_box->setChecked(true);
    }

    for(int i = 0 ; i < Lotes.size(); i++){
        if(numero == Lotes[i].get_numero()){
            Lotes.remove(i);
        }
    }
}

void lotes_ui::on_edit_btn_clicked()
{
    edit_lote();
}


void lotes_ui::on_available_box_stateChanged(int arg1)
{
    if(arg1){
        ui->reserved_box->setChecked(false);
        ui->sold_box->setChecked(false);
    }
}


void lotes_ui::on_reserved_box_stateChanged(int arg1)
{
    if(arg1){
        ui->available_box->setChecked(false);
        ui->sold_box->setChecked(false);
    }
}


void lotes_ui::on_sold_box_stateChanged(int arg1)
{
    if(arg1){
        ui->available_box->setChecked(false);
        ui->reserved_box->setChecked(false);
    }
}

QVector<Lote> lotes_ui::get_lotes(){ return Lotes; }

