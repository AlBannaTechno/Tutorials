#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QListWidget>
#include "layouts.h"


Layouts::Layouts(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *buttonLayout = new QVBoxLayout();

    QListWidget *movieListWidget = new QListWidget(this);
    movieListWidget->addItem("The Omen");
    movieListWidget->addItem("The Exorcist");
    movieListWidget->addItem("Notes on a Scandal");
    movieListWidget->addItem("Fargo");
    movieListWidget->addItem("Capote");

    QPushButton *addButton = new QPushButton("Add", this);
    QPushButton *renameButton = new QPushButton("Rename", this);
    QPushButton *removeButton = new QPushButton("Remove", this);
    QPushButton *removeAllButton = new QPushButton("Remove All", this);

    buttonLayout->setSpacing(3);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(renameButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(removeAllButton);
    buttonLayout->addStretch(1);

    mainLayout->addWidget(movieListWidget);
    mainLayout->addSpacing(15);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}
