#include "maincontext.h"
#include "ui_maincontext.h"

mainContext::mainContext(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainContext)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&_clientes_ui); // 1 - clientes
    ui->stackedWidget->addWidget(&_vendedores_ui); // 2 - vendedores
    ui->stackedWidget->addWidget(&_vendas_ui); // 3 - vendas
    ui->stackedWidget->addWidget(&_lotes_ui); // 4 - lotes

    // clientes / form.ui
    connect(&_clientes_ui, SIGNAL(move_lotes()), this, SLOT(move_lotes()));
    connect(&_clientes_ui, SIGNAL(move_clientes()), this, SLOT(move_clientes()));
    connect(&_clientes_ui, SIGNAL(move_vendedores()), this, SLOT(move_vendedores()));
    connect(&_clientes_ui, SIGNAL(move_vendas()), this, SLOT(move_vendas()));


    // vendedores / form2.ui
    connect(&_vendedores_ui, SIGNAL(move_lotes()), this, SLOT(move_lotes()));
    connect(&_vendedores_ui, SIGNAL(move_clientes()), this, SLOT(move_clientes()));
    connect(&_vendedores_ui, SIGNAL(move_vendedores()), this, SLOT(move_vendedores()));
    connect(&_vendedores_ui, SIGNAL(move_vendas()), this, SLOT(move_vendas()));

    // vendas / form3.ui
    connect(&_vendas_ui, SIGNAL(move_lotes()), this, SLOT(move_lotes()));
    connect(&_vendas_ui, SIGNAL(move_clientes()), this, SLOT(move_clientes()));
    connect(&_vendas_ui, SIGNAL(move_vendedores()), this, SLOT(move_vendedores()));
    connect(&_vendas_ui, SIGNAL(move_vendas()), this, SLOT(move_vendas()));



    connect(&_vendas_ui, SIGNAL(get_clientes()), &_clientes_ui, SLOT(get_clientes()));
    connect(&_vendas_ui, SIGNAL(get_lotes()), &_lotes_ui, SLOT(get_lotes()));
    connect(&_vendas_ui, SIGNAL(get_vendedores()), &_vendedores_ui, SLOT(get_vendedores()));


    connect(this, SIGNAL(load_clientes()), &_vendas_ui, SLOT(load_clientes()));
    connect(this, SIGNAL(load_vendas()), &_vendas_ui, SLOT(load_vendas()));
    connect(this, SIGNAL(load_lotes()), &_vendas_ui, SLOT(load_lotes()));
    connect(this, SIGNAL(load_vendedores()), &_vendas_ui, SLOT(load_vendedores()));





    // lotes / form4.ui
    connect(&_lotes_ui, SIGNAL(move_lotes()), this, SLOT(move_lotes()));
    connect(&_lotes_ui, SIGNAL(move_clientes()), this, SLOT(move_clientes()));
    connect(&_lotes_ui, SIGNAL(move_vendedores()), this, SLOT(move_vendedores()));
    connect(&_lotes_ui, SIGNAL(move_vendas()), this, SLOT(move_vendas()));

    setWindowTitle("Controle de Lotes");
}

mainContext::~mainContext()
{
    delete ui;
}

void mainContext::move_lotes()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void mainContext::move_clientes()
{
    ui->stackedWidget->setCurrentIndex(1);
//    load_clientes();
}

void mainContext::move_vendedores()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void mainContext::move_vendas()
{
    emit load_clientes();
    emit load_vendedores();
    emit load_lotes();
    emit load_vendas();
    ui->stackedWidget->setCurrentIndex(3);
}


void mainContext::on_lotes_btn_clicked()
{
    move_lotes();
//    ui->stackedWidget->setCurrentIndex(4);
}


void mainContext::on_clientes_btn_clicked()
{
    move_clientes();
//    ui->stackedWidget->setCurrentIndex(1);
}


void mainContext::on_vendedores_btn_clicked()
{
    move_vendedores();
//    ui->stackedWidget->setCurrentIndex(2);
}


void mainContext::on_vendas_btn_clicked()
{
    move_vendas();
//    ui->stackedWidget->setCurrentIndex(3);
}



