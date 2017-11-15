#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
        Q_OBJECT
        
    public:
        explicit Widget (QWidget *parent = 0);
        ~Widget();
        
    public slots:
        void calculer();
        
    private:
        Ui::Widget *ui;
        unsigned long pgcd (unsigned long a, unsigned long b);
};

#endif // WIDGET_H
