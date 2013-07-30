#include "qnotepad.h"
#include "ui_qnotepad.h"

QNotepad::QNotepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QNotepad)
{
    ui->setupUi(this);
}

QNotepad::~QNotepad()
{
    delete ui;
}
