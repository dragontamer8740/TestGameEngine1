#include <QString>

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    /* Starting class. Just determines stat buffs when game begins. */
    enum ClassType {Fighter, BlackMage, WhiteMage, RedMage, Thief};

    /* { constructors */
    Player();
    Player(QString &name, int level, ClassType classType);
    /* } constructors */

    QString name();
    void setName(QString &name);

    int level();
    void setLevel(int level);

    ClassType classType();
    void setClassType(ClassType classType);

/*    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;*/
private:
    QString mName;
    int mLevel;
    ClassType mClassType;
};




#endif // PLAYER_H
