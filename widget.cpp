#include "widget.h"
#include "ui_widget.h"

Widget::Widget (QWidget *parent) : QWidget (parent), ui (new Ui::Widget)
{
    ui->setupUi (this);
    QObject::connect (ui->finSpinBox, SIGNAL (editingFinished()), this, SLOT (calculer()));
    QObject::connect (ui->pushButton, SIGNAL (clicked()), this, SLOT (calculer()));
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculer()
{
    ui->listWidget->clear();
    //On récupère notre valeur de fin d'itération
    unsigned long max = static_cast<unsigned long> (ui->finSpinBox->value());
    
    unsigned long u = 2, v = 0, a = 0, b = 0;
    
    
    while (! (a > max || b > max)) {
    
        if (u % 2 == 0) {
            v = 1;
        }
        else {
            v = 2;
        }
        
        while (v < u) {
        
            if (pgcd (u, v) != 1) {
            
                v += 2;
            }
            else {
                a = u * u - v * v;
                b = 2 * u * v;
                
                //if (a > max || b > max) {
                //    return;
                //}
                
                ui->listWidget->addItem (QString::number (a) + QString::fromUtf8 ("² + ") + QString::number (b) +  QString::fromUtf8 ("² = ") + QString::number (u * u + v * v) +  QString::fromUtf8 ("²"));
                
                v += 2;
            }
        }
        
        ++u;
    }
}

unsigned long Widget::pgcd (unsigned long a, unsigned long b)
{
    unsigned long r;
    
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}