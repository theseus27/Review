#include <iostream>
#include <string>
#include <thread>
using namespace std;

void me();
void pet();

int main() {
    thread t1(me);
    thread t2(pet);
    t1.join();
    t2.join();
    return 0;
}

void me() {
    string name, age, food;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    getline(cin, age);
    cout << "Enter your favorite food: ";
    getline(cin, food);
    cout << "You are " << name << ", a " << age << " year old who likes " << food << endl;
}

void pet() {
    string name, age, food;
    cout << "Enter your pet's name: ";
    getline(cin, name);
    cout << "Enter your pet's age: ";
    getline(cin, age);
    cout << "Enter your pet's favorite food: ";
    getline(cin, food);
    cout << "Your pet is " << name << ", a " << age << " year old who likes " << food << endl;
}

