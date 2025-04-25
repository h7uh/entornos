#include "Character.h"
Character::Character(string name, int hp, int damage) : name(name), hp(hp), damage(damage) {}
void Character::attack(Character& target) {
    target.hp -= damage;
    cout << name << " ataca a " << target.getName() << " causando " << damage << " de dano!" << endl;
}
string Character::getStatus() const {
    return "\nName: " + name + "\nHP: " + to_string(hp) + "\nDamage: " + to_string(damage);
}
bool Character::isAlive() const { return hp > 0; }
string Character::getName() const { return name; }

Player::Player(string name, int hp, int damage) : Character(name, hp, damage) {}
void Player::attack(Character& target) {
    Character::attack(target);
}

Enemy::Enemy(string name, int hp, int damage) : Character(name, hp, damage) {}
void Enemy::attack(Character& target) {
    Character::attack(target);
}

Boss::Boss(string name, int hp, int damage) : Enemy(name, hp, damage) {}
void Boss::attack(Character& target) {
    cout << name << " realiza un ataque devastador!" << endl;
    target.hp -= (damage * 2);
}