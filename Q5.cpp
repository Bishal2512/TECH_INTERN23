#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ability {
protected:
    string name;
    int damage;
    int manaCost;

public:
    Ability(const string& name, int damage, int manaCost)
        : name(name), damage(damage), manaCost(manaCost) {}

    virtual void execute() = 0;

    string getName() const {
        return name;
    }

    int getDamage() const {
        return damage;
    }

    int getManaCost() const {
        return manaCost;
    }
};

class Character {
protected:
    string name;
    int health;
    int level;

public:
    Character(const string& name, int health, int level)
        : name(name), health(health), level(level) {}

    virtual void useAbility(Ability* ability) {
        cout << "Character " << name << " used ability: " << ability->getName() << endl;
        ability->execute();
    }

    virtual void displayStatus() const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

class Warrior : public Character {
public:
    Warrior(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(Ability* ability) override {
        cout << "Warrior " << name << " used ability: " << ability->getName() << endl;
        ability->execute();
    }
};

class Archer : public Character {
public:
    Archer(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(Ability* ability) override {
        cout << "Archer " << name << " used ability: " << ability->getName() << endl;
        ability->execute();
    }
};

class Mage : public Character {
public:
    Mage(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(Ability* ability) override {
        cout << "Mage " << name << " used ability: " << ability->getName() << endl;
        ability->execute();
    }
};

class FireballAbility : public Ability {
public:
    FireballAbility() : Ability("Fireball", 50, 20) {}

    void execute() override {
        cout << "Fireball ability executed!" << endl;
    }
};

class SlamAbility : public Ability {
public:
    SlamAbility() : Ability("Slam", 30, 15) {}

    void execute() override {
        cout << "Slam ability executed!" << endl;
    }
};

class RapidShotAbility : public Ability {
public:
    RapidShotAbility() : Ability("Rapid Shot", 40, 25) {}

    void execute() override {
        cout << "Rapid Shot ability executed!" << endl;
    }
};

int main() {
    Warrior warrior("Garen", 100, 10);
    Archer archer("Ashe", 80, 8);
    Mage mage("Ryze", 70, 12);

    FireballAbility fireball;
    SlamAbility slam;
    RapidShotAbility rapidShot;

    warrior.displayStatus();
    archer.displayStatus();
    mage.displayStatus();

    warrior.useAbility(&slam);
    archer.useAbility(&rapidShot);
    mage.useAbility(&fireball);

    return 0;
}
