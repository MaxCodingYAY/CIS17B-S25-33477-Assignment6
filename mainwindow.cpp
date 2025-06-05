#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> //shows messages

//constructor for mainwindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //setup the UI components

    //this applys the color and border to buttons and text
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
    //connects button clicks to their slots basically the event handlers
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::onAddItemClicked);
    connect(ui->pushButtonFind, &QPushButton::clicked, this, &MainWindow::onFindItemClicked);
    connect(ui->pushButtonRemove, &QPushButton::clicked, this, &MainWindow::onRemoveItemClicked);
    //these are for the menu actions
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    //this is the about option of the menu and tells you how to use the program
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
//destructor, cleans up
MainWindow::~MainWindow() {
    delete ui;
}

// handles the Add Item button
void MainWindow::onAddItemClicked() {
    //gets user input
    QString id = ui->lineEditID->text();
    QString desc = ui->lineEditDesc->text();
    QString loc = ui->lineEditLoc->text();

    try {
        //creates storeditem and adds it to manager
        auto item = std::make_shared<StoredItem>(id.toStdString(), desc.toStdString(), loc.toStdString());
        manager.addItem(item);
        //clear input fields
        ui->lineEditID->clear();
        ui->lineEditDesc->clear();
        ui->lineEditLoc->clear();
        //refresh item display
        updateItemList();
    } catch (const DuplicateItemException &e) {
        //show error message if item ID already exists
        QMessageBox::warning(this, "Error", e.what());
    }
}

// handles find item button
void MainWindow::onFindItemClicked() {
    QString id = ui->lineEditFindID->text(); //get id from input

    try {
        // loop up the item by ID
        auto item = manager.findById(id.toStdString());

        //display information
        QString info = "ID: " + QString::fromStdString(item->getId()) +
                       "\nDescription: " + QString::fromStdString(item->getDescription()) +
                       "\nLocation: " + QString::fromStdString(item->getLocation());

        QMessageBox::information(this, "Item Found", info);

    } catch (const ItemNotFoundException &e) {
        // show not found if it's not found
        QMessageBox::warning(this, "Not Found", e.what());
    }
}

// handles remove item button
void MainWindow::onRemoveItemClicked() {
    QString id = ui->lineEditRemoveID->text();
    try {
        //remove item from manager
        manager.removeItem(id.toStdString());
        // refresh list
        updateItemList();
    } catch (const ItemNotFoundException &e) {
        //show error if it does not exist
        QMessageBox::warning(this, "Error", e.what());
    }
}

// updates list widget to show all items by description
void MainWindow::updateItemList() {
    ui->listWidgetItems->clear();
    //add each item to list widget
    for (const auto &item : manager.listItemsByDescription()) {
        QString text = QString::fromStdString("ID: " + item->getId() + ", Desc: " + item->getDescription() + ", Loc: " + item->getLocation());
        ui->listWidgetItems->addItem(text); //add item to display
    }
}
