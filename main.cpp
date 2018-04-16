#include <iostream>
#include <string.h>
using namespace std;

struct Hero {
    string name;
    int maxHitPoints;
    int hitPoints;
    int level;
    int damage;
    bool isAlive;
    int xp;

    void heal(int x) {
        cout << "Healing on " << x << " points" << endl;
        hitPoints += x;
        if (hitPoints > maxHitPoints) {
            cout << "Current HP beyond the max HP, setting HP to max value." << endl;
            hitPoints = maxHitPoints;
        }
        if (hitPoints > 0 && !isAlive) { cout << name << " back to fight arena!" << endl; isAlive = true;}
        cout << "Hero HP equals " << hitPoints << endl;
    }

    void levelUp() {
        level += 1;
        cout << endl;
        cout << "----------------" << endl;
        cout << name << " LEVEL UP!!" << endl;
        cout << "----------------" << endl;
        cout << endl;
        cout << endl;
        cout << "NEW LEVEL: " << level << endl;
        cout << "Level up Hero!" << endl;
        cout << "Adding 250 damage" << endl;
        damage += 250;
        cout << "Adding 1000 HP" << endl;
        maxHitPoints += 1000;

        hitPoints = maxHitPoints;
        cout << "NEW Damage: " << damage << endl;
        cout << "NEW Max HP: " << maxHitPoints << endl;
    }
};

int fight(Hero &h1, Hero &h2) {
    int round = 1;
    while (h1.isAlive && h2.isAlive) {
        cout << endl;
        cout << "ROUND " << round << endl;
        cout << "Oh no! " << h1.name << " attacks " << h2.name << "!" << endl;
        h2.hitPoints -= h1.damage;
        if (h2.hitPoints < 0) { cout << "Oh no! " << h2.name << " dies as hero on round " << round << " as a hero!" << endl; h2.isAlive = false; return 0; }
        cout << "Wow! " << h2.name << " makes a beautiful hit in response!" << endl;
        h1.hitPoints -= h2.damage;
        if (h1.hitPoints < 0) { cout << "Oh no! " << h1.name << " dies as hero on round " << round << " as a hero!" << endl; h1.isAlive = false; return 0; }
        round++;
        cout << endl;
    }
}

int main() {
    Hero hero1;
    Hero hero2;
    hero1.xp = 0;
    hero1.level = 0;
    hero2.xp = 0;
    hero2.level = 0;

    cout << "First hero name: ";
    hero1.name;
    cin >> hero1.name;
    cout << "First hero max HP: ";
    cin >> hero1.maxHitPoints;
    hero1.hitPoints = hero1.maxHitPoints;
    cout << "First hero level: ";
    cin >> hero1.level;
    cout << "First hero max damage: ";
    cin >> hero1.damage;
    hero1.isAlive = true;
    cout << "Second hero name: ";
    cin >> hero2.name;
    cout << "Second hero max HP: ";
    cin >> hero2.maxHitPoints;
    hero2.hitPoints = hero2.maxHitPoints;
    cout << "Second hero level: ";
    cin >> hero2.level;
    cout << "Second hero max damage: ";
    cin >> hero2.damage;
    hero2.isAlive = true;
    cout << "Here is heroes stats:" << endl;
    cout << "First hero:" << endl;
    cout << "Name: " << hero1.name << endl;
    cout << "Max HP: " << hero1.maxHitPoints << endl;
    cout << "Level: " << hero1.level << endl;
    cout << "Max damage: " << hero1.damage << endl;
    cout << "Is that right? (y/n)";
    bool right1 = false;
    string right1s;
    cin >> right1s;
    if (right1s == "n") {
        while (!right1) {
            cout << "First hero name: ";
            cin >> hero1.name;
            cout << "First hero max HP";
            cin >> hero1.maxHitPoints;
            hero1.hitPoints = hero1.maxHitPoints;
            cout << "First hero level";
            cin >> hero1.level;
            cout << "First hero max damage: ";
            cin >> hero1.damage;
            cout << "Here is heroes stats:" << endl;
            cout << "First hero:" << endl;
            cout << "Name: " << hero1.name << endl;
            cout << "Max HP: " << hero1.maxHitPoints << endl;
            cout << "Level: " << hero1.level << endl;
            cout << "Max damage: " << hero1.damage << endl;
            cout << "Is that right? (y/n) ";
            cin >> right1s;
            if (right1s == "y") {
                right1 = true;
            }
        }
    }
    cout << "Second hero:" << endl;
    cout << "Name: " << hero2.name << endl;
    cout << "Max HP: " << hero2.maxHitPoints << endl;
    cout << "Level: " << hero2.level << endl;
    cout << "Max damage: " << hero2.damage << endl;
    cout << "Is that right? (y/n) ";
    bool right2 = false;
    string right2s;
    cin >> right2s;
    if (right2s == "n") {
        while (!right2) {
            cout << "Second hero name: ";
            cin >> hero2.name;
            cout << "Second hero max HP";
            cin >> hero2.maxHitPoints;
            hero2.hitPoints = hero2.maxHitPoints;
            cout << "Second hero level";
            cin >> hero2.level;
            cout << "Second hero max damage: ";
            cin >> hero2.damage;
            cout << "Second hero:" << endl;
            cout << "Name: " << hero2.name << endl;
            cout << "Max HP: " << hero2.maxHitPoints << endl;
            cout << "Level: " << hero2.level << endl;
            cout << "Max damage: " << hero2.damage << endl;
            cout << "Is that right? (y/n)";
            cin >> right2s;
            if (right2s == "y") {
                right2 = true;
            }
        }
    }
    int healwhom, lvlupwhom, menuchoice, healint;
    for (;;) {
        cout << "----- MAIN MENU -----" << endl;
        cout << "" << endl;
        cout << hero1.name << ":" << endl;
        cout << "- HP: " << hero1.hitPoints << endl;
        cout << "- Damage: " << hero1.damage << endl;
        cout << "- Max HP: " << hero1.maxHitPoints << endl;
        cout << "- Level: " << hero1.level << endl;
        cout << "- Alive: " << hero1.isAlive << endl;
        cout << endl;
        cout << endl;
        cout << hero2.name << ":" << endl;
        cout << "- HP: " << hero2.hitPoints << endl;
        cout << "- Damage: " << hero2.damage << endl;
        cout << "- Max HP: " << hero2.maxHitPoints << endl;
        cout << "- Level: " << hero2.level << endl;
        cout << "- Alive: " << hero2.isAlive << endl;
        cout << "---------------------" << endl;
        cout << "- CHOOSE ACTION" << endl;
        cout << "1. Heal Hero" << endl;
        cout << "2. Level Up Hero" << endl;
        cout << "3. MAKE THEM FIGHT" << endl;
        cout << "10. Exit" << endl;
        cout << "Your choice: ";
        cin >> menuchoice;
        switch (menuchoice) {
            case 1:
                cout << "Whom do you want to heal? (1/2) ";
                cin >> healwhom;
                cout << "How many HP to heal? ";
                cin >> healint;
                if (healwhom == 1) { hero1.heal(healint); } else { hero2.heal(healint); }
                break;
            case 2:
                cout << "Whom do you want to level up? (1/2) ";
                cin >> lvlupwhom;
                if (lvlupwhom == 1) { hero1.levelUp(); } else { hero2.levelUp(); }
                break;
            case 3:
                cout << "Uhh, guys I think you should fight yea" << endl;
                cout << "One, two, three FIGHT!" << endl;
                fight(hero1, hero2);
                break;
            case 10:
                cout << "Bye :C";
                return 0;
        }
    }
    return 0;
}
