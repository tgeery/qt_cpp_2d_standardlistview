#include "mainwindow.h"
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLayout * lyt = this->layout();
    QTreeView * view = new QTreeView;
    QStandardItemModel * model = new QStandardItemModel;
    model->setHorizontalHeaderItem(0, new QStandardItem("Tag"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Value"));
    model->setColumnCount(2);
    for(int r = 0; r < 3; r++) {
        QStandardItem * row = new QStandardItem(QString("Row %0").arg(r));
        row->setEditable(false);
        for(int sr = 0; sr < 2; sr++) {
            QStandardItem * key = new QStandardItem(QString("Item r%0c%1").arg(r).arg(sr));
            key->setEditable(false);
            QStandardItem * val = new QStandardItem(QString("Value %0").arg(r*2+sr));
            QList<QStandardItem *> l;
            l.append(key);
            l.append(val);
            row->appendRow(l);
//            row->push_back(key);
//            row->push_back(val);
        }
        model->appendRow(row);
    }
    view->setModel(model);
    lyt->addWidget(view);
}

MainWindow::~MainWindow()
{
}

