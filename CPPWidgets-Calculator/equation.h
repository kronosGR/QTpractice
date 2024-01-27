#ifndef EQUATION_H
#define EQUATION_H

#include <QObject>

class Equation : public QObject
{
    Q_OBJECT

public:
    explicit Equation(QObject *parent = nullptr);

    enum Action { NONE, RESET, ADD, SUBTRACT, MULTIPLY, DIVIDE };

    QString sum() const;
    void setSum(const QString &newSum);

    QString getValue1() const;
    void setValue1(const QString &newValue1);

    QString getValue2() const;
    void setValue2(const QString &newValue2);

    void calculate();
    QString toString();

    Equation::Action getAction() const;
    void setAction(const Equation::Action &action);

signals:

public slots:

private:
    QString m_sum;
    QString m_value1;
    QString m_value2;
    Equation::Action m_action;

    double getValue(QString data);
};

#endif // EQUATION_H
