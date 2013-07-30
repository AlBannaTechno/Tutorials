#ifndef QNOTEPAD_H
#define QNOTEPAD_H

#include <QMainWindow>

namespace Ui {
class QNotepad;
}

class QNotepad : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QNotepad(QWidget *parent = 0);
    ~QNotepad();
    
private:
    Ui::QNotepad *ui;
};

#endif // QNOTEPAD_H
