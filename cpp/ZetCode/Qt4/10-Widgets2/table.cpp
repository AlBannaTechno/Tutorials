#include <QtGui/QHBoxLayout>
#include <QtGui/QTableWidget>

#include "table.h"


Table::Table(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    QTableWidget *table = new QTableWidget(25, 25, this);

    mainLayout->addWidget(table);
    setLayout(mainLayout);
}
