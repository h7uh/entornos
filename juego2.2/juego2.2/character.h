#pragma once
#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int hp;
    int damage;
public:
    Character(string name, int hp, int damage);
    virtual void attack(Character& target);
    virtual string getStatus() const;
    bool isAlive() const;
    string getName() const;
};

class Player : public Character {
public:
    Player(string name, int hp, int damage);
    void attack(Character& target) override;
};

class Enemy : public Character {
public:
    Enemy(string name, int hp, int damage);
    void attack(Character& target) override;
};

class Boss : public Enemy {
public:
    Boss(string name, int hp, int damage);
    void attack(Character& target) override;
};

