#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StorageManagerSystem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //slot the gets triggered when user press add button
    void onAddItemClicked();
    //slot the gets triggered when user press find button
    void onFindItemClicked();
    //slot the gets triggered when user press remove button
    void onRemoveItemClicked();
    //updates list view
    void updateItemList();

private:
    Ui::MainWindow *ui;


    StorageManager manager; //instance of storage manager
};
#endif // MAINWINDOW_H


