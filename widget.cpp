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
    //On suprime notre liste et on initialise nos différentes variables
    ui->listWidget->clear();
    
    unsigned long max = static_cast<unsigned long> (ui->finSpinBox->value());
    
    unsigned long u = 2, v = 0, a = 0, b = 0;
    
    while (! (a > max || b > max)) {
    
        //Si 'u' est pair, 'v' doit etre impair et inversement, puisque 'p' et 'u' n'ont pas la meme parité
        if (u % 2 == 0) {
            v = 1;
        }
        else {
            v = 2;
        }
        
        while (v < u) {
        
            if (pgcd (u, v) != 1) {
                //Si 'u' et 'v' ne sont pas premier entre eux on ajoute 2 à 'v'
                v += 2;
            }
            else {
                //Sinon on a trouvé un triplet pythagoricien irréductible (avec a = u²-v² et b = 2uv)
                a = u * u - v * v;
                b = 2 * u * v;
                
                //On l'ajoute à la liste
                ui->listWidget->addItem (QString::number (a) + QString::fromUtf8 ("² + ") + QString::number (b) +  QString::fromUtf8 ("² = ") + QString::number (u * u + v * v) +  QString::fromUtf8 ("²"));
                //                                        a²                         +                       b²                          =                             c²
                v += 2;
            }
        }
        
        ++u;
    }
}

unsigned long Widget::pgcd (unsigned long a, unsigned long b)
{
    //Calcul du PGCD
    
    unsigned long r;
    
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}