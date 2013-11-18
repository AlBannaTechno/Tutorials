#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

#include "ledit.h"


Ledit::Ledit(QWidget *parent)
    : QWidget(parent) {
    QLabel *nameLabel = new QLabel("Name:", this);
    QLabel *ageLabel = new QLabel("Age:", this);
    QLabel *jobLabel = new QLabel("Occupation:", this);

    QLineEdit *nameLineEdit = new QLineEdit(this);
    QLineEdit *ageLineEdit = new QLineEdit(this);
    QLineEdit *jobLineEdit = new QLineEdit(this);

    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLineEdit, 0, 1);
    mainLayout->addWidget(ageLabel, 1, 0);
    mainLayout->addWidget(ageLineEdit, 1, 1);
    mainLayout->addWidget(jobLabel, 2, 0);
    mainLayout->addWidget(jobLineEdit, 2, 1);

    setLayout(mainLayout);
}
