#ifndef SHOOTER_H
#define SHOOTER_H

#include <QObject>

class Shooter : public QObject
{
    Q_OBJECT
public:
    explicit Shooter(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SHOOTER_H