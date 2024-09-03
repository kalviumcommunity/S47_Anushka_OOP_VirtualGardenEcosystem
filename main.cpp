#include <iostream>
using namespace std;

// Class representing a Plant
class Plant {
private:
    string name;
    int height; // in cm

public:
    // Constructor
    Plant(string n, int h) : name(n), height(h) {}

    // Member function to display plant details using this pointer
    void display() {
        cout << "Plant Name: " << this->name << ", Height: " << this->height << " cm" << endl;
    }

    // Member function to grow the plant using this pointer
    void grow(int growth) {
        this->height += growth;
        cout << this->name << " has grown by " << growth << " cm." << endl;
    }
};

// Class representing an Insect
class Insect {
private:
    string species;
    int age; // in days

public:
    // Constructor
    Insect(string s, int a) : species(s), age(a) {}

    // Member function to display insect details using this pointer
    void display() {
        cout << "Insect Species: " << this->species << ", Age: " << this->age << " days" << endl;
    }

    // Member function to age the insect using this pointer
    void ageInsect(int days) {
        this->age += days;
        cout << this->species << " has aged by " << days << " days." << endl;
    }
};

int main() {
    // Creating objects of Plant and Insect classes
    Plant rose("Rose", 30);
    Insect bee("Bee", 10);

    // Using member functions
    rose.display();
    rose.grow(5);

    bee.display();
    bee.ageInsect(2);

    return 0;
}
