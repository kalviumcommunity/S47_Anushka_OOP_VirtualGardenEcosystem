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

    // Member function to display plant details
    void display() {
        cout << "Plant Name: " << name << ", Height: " << height << " cm" << endl;
    }

    // Member function to grow the plant
    void grow(int growth) {
        height += growth;
        cout << name << " has grown by " << growth << " cm." << endl;
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

    // Member function to display insect details
    void display() {
        cout << "Insect Species: " << species << ", Age: " << age << " days" << endl;
    }

    // Member function to age the insect
    void ageInsect(int days) {
        age += days;
        cout << species << " has aged by " << days << " days." << endl;
    }
};

int main() {
    // Array of Plant objects
    Plant garden[2] = {
        Plant("Rose", 30),
        Plant("Tulip", 15)
    };

    // Array of Insect objects
    Insect insects[2] = {
        Insect("Bee", 10),
        Insect("Butterfly", 5)
    };

    // Using member functions
    for (int i = 0; i < 2; i++) {
        garden[i].display();
        garden[i].grow(10);

        insects[i].display();
        insects[i].ageInsect(3);
    }

    return 0;
}
