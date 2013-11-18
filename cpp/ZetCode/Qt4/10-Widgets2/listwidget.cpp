#include <QtGui/QVBoxLayout>
#include <QtGui/QInputDialog>

#include "listwidget.h"


ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->setSpacing(10);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    moviesListWidget = new QListWidget(this);
    moviesListWidget->addItem("The Omen");
    moviesListWidget->addItem("The Exorcist");
    moviesListWidget->addItem("Notes on a Scandal");
    moviesListWidget->addItem("Fargo");
    moviesListWidget->addItem("Capote");

    addButton = new QPushButton("Add", this);
    renameButton = new QPushButton("Rename", this);
    removeButton = new QPushButton("Remove", this);
    removeAllButton = new QPushButton("Remove All", this);

    buttonLayout->setSpacing(3);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(renameButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(removeAllButton);

    mainLayout->addWidget(moviesListWidget);
    mainLayout->addSpacing(15);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(renameButton, SIGNAL(clicked()), this, SLOT(renameItem()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeItem()));
    connect(removeAllButton, SIGNAL(clicked()), this, SLOT(clearItems()));
}

void ListWidget::addItem() {
    QString item = QInputDialog::getText(this, "Item", "Enter new item");
    item = item.simplified();

    if (!item.isEmpty()) {
        moviesListWidget->addItem(item);
        int row = moviesListWidget->count() - 1;
        moviesListWidget->setCurrentRow(row);
    }
}

void ListWidget::renameItem() {
    QListWidgetItem *currentItem = moviesListWidget->currentItem();
    int row = moviesListWidget->row(currentItem);
    QString text = currentItem->text();
    QString item = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, text);

    item = item.simplified();

    if (!item.isEmpty()) {
        moviesListWidget->takeItem(row);
        delete currentItem;
        moviesListWidget->insertItem(row, item);
        moviesListWidget->setCurrentRow(row);
    }
}

void ListWidget::removeItem() {
    QListWidgetItem *currentItem = moviesListWidget->currentItem();

    if (currentItem) {
        int row = moviesListWidget->row(currentItem);
        moviesListWidget->takeItem(row);
        delete currentItem;
    }
}

void ListWidget::clearItems() {
    if (moviesListWidget->count() != 0)
        moviesListWidget->clear();
}
