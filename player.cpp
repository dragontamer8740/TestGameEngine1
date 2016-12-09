#include "player.h"
#include <QString>

Player::Player():
    mLevel(0),
    mClassType(Fighter)
{
}

Player::Player(QString &name, int level, Player::ClassType classType):
    mName(name),
    mLevel(level),
    mClassType(classType)
{
}

QString Player::name()
{
    return mName;
}

void Player::setName(QString &name)
{
    mName = name;
}

int Player::level()
{
    return mLevel;
}

void Player::setLevel(int level)
{
    mLevel = level;
}

Player::ClassType Player::classType()
{
    return mClassType;
}

void Player::setClassType(Player::ClassType classType)
{
    mClassType = classType;
}
