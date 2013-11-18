#include "verticalbox.h"
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>


VerticalBox::VerticalBox(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(1);

    QPushButton *settingsButton = new QPushButton("Settings", this);
    settingsButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *accountsButton = new QPushButton("Accounts", this);
    accountsButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *loansButton = new QPushButton("Loans", this);
    loansButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *cashButton = new QPushButton("Cash", this);
    cashButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *debtsButton = new QPushButton("Debts", this);
    debtsButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainLayout->addWidget(settingsButton);
    mainLayout->addWidget(accountsButton);
    mainLayout->addWidget(loansButton);
    mainLayout->addWidget(cashButton);
    mainLayout->addWidget(debtsButton);

    setLayout(mainLayout);
}
