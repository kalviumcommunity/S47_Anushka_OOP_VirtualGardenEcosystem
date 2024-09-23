#include <iostream>
using namespace std;

// Class representing a Plant
class Plant {
private:
    string name;
    int height;

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
    int age; 

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
    // Dynamically allocating memory for Plant objects
    Plant* garden[2];
    garden[0] = new Plant("Rose", 30);
    garden[1] = new Plant("Tulip", 15);

    // Dynamically allocating memory for Insect objects
    Insect* insects[2];
    insects[0] = new Insect("Bee", 10);
    insects[1] = new Insect("Butterfly", 5);

    // Using member functions
    for (int i = 0; i < 2; i++) {
        garden[i]->display();
        garden[i]->grow(10);

        insects[i]->display();
        insects[i]->ageInsect(3);
    }

    // Deleting dynamically allocated memory
    for (int i = 0; i < 2; i++) {
        delete garden[i]; 
        delete insects[i]; 
    }

    return 0;
}
