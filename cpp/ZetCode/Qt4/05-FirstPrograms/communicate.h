/* 
 * File:   communicate.h
 * Author: Slxe
 *
 * Created on November 16, 2013, 10:49 PM
 */

#ifndef COMMUNICATE_H
#define	COMMUNICATE_H

#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>


class Communicate : public QWidget {
    Q_OBJECT
            
    public:
        Communicate(QWidget *parent=0);
        
    private slots:
        void OnPlus();
        void OnMinus();
        
    private:
        QLabel *label;
};

#endif	/* COMMUNICATE_H */

