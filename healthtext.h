#ifndef HEALTHTEXT_H
#define HEALTHTEXT_H
#include <QGraphicsTextItem>
#include "player.h"

class HealthText : public QGraphicsTextItem
{
public:
    HealthText(QGraphicsItem * parent=0);
    void decrease();
    int getHealth() { return health_; }

    int redHealth;
    int blueHealth;

private:
    int health_;
};

#endif // HEALTHTEXT_H
