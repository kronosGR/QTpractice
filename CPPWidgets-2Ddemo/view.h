#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();
};
#endif // VIEW_H
