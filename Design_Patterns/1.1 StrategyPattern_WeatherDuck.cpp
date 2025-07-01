#include <iostream>
using namespace std;

// FlyBehaviour Interface
class FlyBehaviour {
public:
    virtual void fly() = 0;
    virtual ~FlyBehaviour() {}
};

// FlyWithWings class
class FlyWithWings : public FlyBehaviour {
public:
    void fly() override {
        cout << "I am flying with wings....." << endl;
    }
};

// FlyNoWay class
class FlyNoWay : public FlyBehaviour {
public:
    void fly() override {
        cout << "I can't fly....." << endl;
    }
};

// QuackBehaviour Interface
class QuackBehaviour {
public:
    virtual void quack() = 0;
    virtual ~QuackBehaviour() {}
};

// Quack class
class Quack : public QuackBehaviour {
public:
    void quack() override {
        cout << "Quack....Quack...." << endl;
    }
};

// Squeak class
class Squeak : public QuackBehaviour {
public:
    void quack() override {
        cout << "Squeak....Squeak...." << endl;
    }
};

// Duck Abstract Base Class
class Duck {
protected:
    FlyBehaviour* flyBehaviour;
    QuackBehaviour* quackBehaviour;

public:
    Duck(FlyBehaviour* fb, QuackBehaviour* qb) : flyBehaviour(fb), quackBehaviour(qb) {}

    virtual void display() = 0;

    void swim() {
        cout << "All Ducks Swim......" << endl;
    }

    void performFly() {
        flyBehaviour->fly();
    }

    void performQuack() {
        quackBehaviour->quack();
    }
    
    void setFlyBehaviour(FlyBehaviour *fb){
        this->flyBehaviour = fb;
    }
    
    void setQuackBehaviour(QuackBehaviour *qb){
        this->quackBehaviour = qb;
    }

    virtual ~Duck() {
        delete flyBehaviour;
        delete quackBehaviour;
    }
};

// Example of a specific Duck
class MallardDuck : public Duck {
public:
    MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display() override {
        cout << "I'm a Mallard Duck" << endl;
    }
};

// Main
int main() {
    Duck* duck = new MallardDuck();

    duck->display();
    duck->swim();
    duck->performFly();
    duck->performQuack();
    
    duck->setQuackBehaviour(new Squeak());
    duck->setFlyBehaviour(new FlyNoWay());
    duck->performFly();
    duck->performQuack();

    delete duck;
    return 0;
}
