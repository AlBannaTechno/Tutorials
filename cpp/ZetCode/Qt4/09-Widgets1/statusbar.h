#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtGui/QMainWindow>
#include <QtGUi/QPushButton>


class Statusbar : public QMainWindow {
    Q_OBJECT

    QPushButton *okButton;
    QPushButton *applyButton;

public:
    Statusbar(QWidget *parent=0);

private slots:
    void OnOkPressed();
    void OnApplyPressed();
};

#endif // STATUSBAR_H
