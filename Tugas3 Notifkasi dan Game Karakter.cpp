#include <iostream>
#include <vector>
using namespace std;

// ===== Kasus 1: Notifikasi Sistem =====
// Abstract class untuk tipe Notifikasi
class Notification {
public:
    virtual void send(const string& target, const string& message) = 0;
    virtual ~Notification() {}
};

class Email : public Notification {
public:
    void send(const string& target, const string& message) override {
        cout << "Mengirim Email ke " << target << ": " << message << endl;
    }
};

class SMS : public Notification {
public:
    void send(const string& target, const string& message) override {
        cout << "Mengirim SMS ke " << target << ": " << message << endl;
    }
};

class Push : public Notification {
public:
    void send(const string& target, const string& message) override {
        cout << "Mengirim Push Notification ke " << target << ": " << message << endl;
    }
};

class NotificationManager {
public:
    void deliver(Notification* notification, const string& target, const string& message) {
        notification->send(target, message);
    }
};

// ===== Kasus 2: Sistem Karakter Game =====
// Abstract class untuk Karakter
class Character {
protected:
    string name;
    int health;
public:
    Character(const string& name, int health) : name(name), health(health) {}

    virtual void showDetails() = 0;
    virtual ~Character() {}
};

class IAttack {
public:
    virtual void attack() = 0;
    virtual ~IAttack() {}
};

class IDefend {
public:
    virtual void defend() = 0;
    virtual ~IDefend() {}
};

class IHeal {
public:
    virtual void heal() = 0;
    virtual ~IHeal() {}
};

class Player : public Character, public IAttack, public IDefend, public IHeal {
public:
    Player(const string& name, int health) : Character(name, health) {}

    void attack() override {
        cout << name << " melakukan serangan!" << endl;
    }

    void defend() override {
        cout << name << " sedang bertahan!" << endl;
    }

    void heal() override {
        cout << name << " sedang menyembuhkan diri!" << endl;
        health += 10;
    }

    void showDetails() override {
        cout << "Pemain: " << name << ", Kesehatan: " << health << endl;
    }
};

class Enemy : public Character, public IAttack {
public:
    Enemy(const string& name, int health) : Character(name, health) {}

    void attack() override {
        cout << name << " menyerang lawan!" << endl;
    }

    void showDetails() override {
        cout << "Musuh: " << name << ", Kesehatan: " << health << endl;
    }
};

class NPC : public Character {
public:
    NPC(const string& name, int health) : Character(name, health) {}

    void showDetails() override {
        cout << "NPC: " << name << ", Kesehatan: " << health << endl;
    }
};

// ===== MAIN PROGRAM =====
int main() {
    cout << "\n=== KASUS 1: SISTEM NOTIFIKASI ===" << endl;
    NotificationManager manager;

    Email email;
    SMS sms;
    Push push;

    manager.deliver(&email, "user@example.com", "Selamat datang di game!");
    manager.deliver(&sms, "08123456789", "Ada quest baru untukmu!");
    manager.deliver(&push, "Player123", "Kamu mendapatkan hadiah!");

    cout << "\n=== KASUS 2: SISTEM KARAKTER GAME ===" << endl;

    Player player("Warrior", 100);
    Enemy enemy("Orc", 60);
    NPC npc("Pedagang", 30);

    player.showDetails();
    player.attack();
    player.defend();
    player.heal();
    player.showDetails();

    cout << endl;

    enemy.showDetails();
    enemy.attack();

    cout << endl;

    npc.showDetails();

    return 0;
}
