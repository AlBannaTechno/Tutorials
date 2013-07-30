/********************************************************************************
** Form generated from reading UI file 'qnotepad.ui'
**
** Created: Fri Jan 4 14:30:55 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNOTEPAD_H
#define UI_QNOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QNotepad
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *quitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QNotepad)
    {
        if (QNotepad->objectName().isEmpty())
            QNotepad->setObjectName(QString::fromUtf8("QNotepad"));
        QNotepad->resize(400, 300);
        centralWidget = new QWidget(QNotepad);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 0, 258, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        QNotepad->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QNotepad);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        QNotepad->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QNotepad);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QNotepad->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QNotepad);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QNotepad->setStatusBar(statusBar);

        retranslateUi(QNotepad);

        QMetaObject::connectSlotsByName(QNotepad);
    } // setupUi

    void retranslateUi(QMainWindow *QNotepad)
    {
        QNotepad->setWindowTitle(QApplication::translate("QNotepad", "QNotepad", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("QNotepad", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QNotepad: public Ui_QNotepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNOTEPAD_H
