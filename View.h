#ifndef VIEW_H
#define VIEW_H

#include <QObject>

class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VIEW_H