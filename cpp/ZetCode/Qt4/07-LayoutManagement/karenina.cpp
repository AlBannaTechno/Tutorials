#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>

#include "karenina.h"


Karenina::Karenina(QWidget *parent)
    : QWidget(parent) {
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(20);

    QLabel *titleLabel = new QLabel("Title", this);
    mainLayout->addWidget(titleLabel, 0, 0, 1, 1);

    QLineEdit *titleLineEdit = new QLineEdit(this);
    mainLayout->addWidget(titleLineEdit, 0, 1, 1, 1);

    QLabel *authorLabel = new QLabel("Author", this);
    mainLayout->addWidget(authorLabel, 1, 0, 1, 1);

    QLineEdit *authorLineEdit = new QLineEdit(this);
    mainLayout->addWidget(authorLineEdit, 1, 1, 1, 1);

    QLabel *reviewLabel = new QLabel("Review", this);
    mainLayout->addWidget(reviewLabel, 2, 0, 1, 1);

    QTextEdit *reviewTextEdit = new QTextEdit(this);
    mainLayout->addWidget(reviewTextEdit, 2, 1, 3, 1);
}
