#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QListWidget>


class ListWidget : public QWidget {
    Q_OBJECT

    QListWidget *moviesListWidget;
    QPushButton *addButton;
    QPushButton *renameButton;
    QPushButton *removeButton;
    QPushButton *removeAllButton;

public:
    ListWidget(QWidget *parent=0);

private slots:
    void addItem();
    void renameItem();
    void removeItem();
    void clearItems();
};

#endif // LISTWIDGET_H
