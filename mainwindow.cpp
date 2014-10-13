#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->colors = new QComboBox;

    this->colors->insertItem(0, "Blue");
    this->colors->insertItem(1, "Red");
    this->colors->insertItem(2, "Yellow");

    QObject::connect(this->colors, SIGNAL(currentIndexChanged(int)), this->ui->canvasWidget, SLOT(setColor(int)));

    this->ui->mainToolBar->addWidget(this->colors);

    this->penWidth = new QComboBox;

    this->penWidth->insertItem(2, "Light");
    this->penWidth->insertItem(5, "Medium");
    this->penWidth->insertItem(8, "Heavy");

    this->penWidth->setCurrentIndex(1);

    QObject::connect(this->penWidth, SIGNAL(currentIndexChanged(int)), this->ui->canvasWidget, SLOT(setPenWidth(int)));

    this->ui->mainToolBar->addWidget(this->penWidth);
}

MainWindow::~MainWindow()
{
    delete ui;
}
