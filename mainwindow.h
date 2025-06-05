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
    void onAddItemClicked();
    void onFindItemClicked();
    void onRemoveItemClicked();
    void updateItemList();

private:
    Ui::MainWindow *ui;


    StorageManager manager;
};
#endif // MAINWINDOW_H


