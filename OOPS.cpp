#include <iostream>
using namespace std;

// Base class (Abstraction and Encapsulation)
class Animal {
private:
    string name;
    int age;
public:
    // Constructor
    Animal(string _name, int _age) : name(_name), age(_age) {}

    // Abstraction: Hide internal details
    virtual void makeSound() {
        cout << "Animal makes a sound." << endl;
    }
    // Encapsulation: Getter methods
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};
// Derived class (Inheritance)
class Dog : public Animal {
public:
    Dog(string _name, int _age) : Animal(_name, _age) {}

    // Method overriding
    void makeSound() override {
        cout << "Dog barks: Woof Woof!" << endl;
    }

    void playFetch() {
        cout << getName() << " plays fetch." << endl;
    }
};

int main() {
    // Creating objects
    Animal genericAnimal("Generic Animal", 5);
    Dog myDog("Buddy", 3);

    // Calling methods (Polymorphism)
    genericAnimal.makeSound();  // Calls base class method
    myDog.makeSound();          // Calls derived class method
    myDog.playFetch();          // Accessing a derived class method

    // Accessing private members through getter methods (Encapsulation)
    cout << "Name: " << myDog.getName() << ", Age: " << myDog.getAge() << endl;

    return 0;
}
