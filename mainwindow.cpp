// MainWindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(R"(
    QLineEdit {
        border: 2px solid #4682B4;       // Blue border
        border-radius: 5px;
        padding: 4px;
        background-color: #f0f8ff;       // Blue
    }

    QPushButton {
        background-color: #6ca6cd;       // Sky Blue
        color: white;
        font-weight: bold;
        border: 2px solid #5b9bd5;
        border-radius: 4px;
        padding: 4px;
    }

    QPushButton:hover {
        background-color: #5b9bd5;
    }

)");

    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::onAddItemClicked);
    connect(ui->pushButtonFind, &QPushButton::clicked, this, &MainWindow::onFindItemClicked);
    connect(ui->pushButtonRemove, &QPushButton::clicked, this, &MainWindow::onRemoveItemClicked);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, this, [=]() {
        QMessageBox::about(this, "About", "This is an Inventory system with fully functional GUI. \n"
                                          "There is a space to input the item ID, the description,\n"
                                          "and the location. The ID  allows for either a number or\n"
                                          "letter id. However, each id must be unique. On the other\n"
                                          "hand, the descriptions and location allow for anything.\n"
                                          "After adding the item, it will show up in the display  \n"
                                          "box below. The remove option and find button can be used\n"
                                          "to find or remove your item by typing in the item id.");
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onAddItemClicked() {
    QString id = ui->lineEditID->text();
    QString desc = ui->lineEditDesc->text();
    QString loc = ui->lineEditLoc->text();

    try {
        auto item = std::make_shared<StoredItem>(id.toStdString(), desc.toStdString(), loc.toStdString());
        manager.addItem(item);
        ui->lineEditID->clear();
        ui->lineEditDesc->clear();
        ui->lineEditLoc->clear();
        updateItemList();
    } catch (const DuplicateItemException &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::onFindItemClicked() {
    QString id = ui->lineEditFindID->text();

    try {
        auto item = manager.findById(id.toStdString());

        QString info = "ID: " + QString::fromStdString(item->getId()) +
                       "\nDescription: " + QString::fromStdString(item->getDescription()) +
                       "\nLocation: " + QString::fromStdString(item->getLocation());

        QMessageBox::information(this, "Item Found", info);

    } catch (const ItemNotFoundException &e) {
        QMessageBox::warning(this, "Not Found", e.what());
    }
}


void MainWindow::onRemoveItemClicked() {
    QString id = ui->lineEditRemoveID->text();
    try {
        manager.removeItem(id.toStdString());
        updateItemList();
    } catch (const ItemNotFoundException &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::updateItemList() {
    ui->listWidgetItems->clear();
    for (const auto &item : manager.listItemsByDescription()) {
        QString text = QString::fromStdString("ID: " + item->getId() + ", Desc: " + item->getDescription() + ", Loc: " + item->getLocation());
        ui->listWidgetItems->addItem(text);
    }
}
