#include <iostream>
using namespace std;

// Abstract base class representing an Organism
class Organism {
public:
    // Pure virtual function to display organism details
    virtual void display() const = 0;

    // Pure virtual function for growth/aging behavior
    virtual void growOrAge(int value) = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Organism() {}
};

// Class representing a Plant (inherits from Organism)
class Plant : public Organism {
private:
    string name;
    int height;

    // Static variable to keep track of the number of plants
    static int plantCount;

public:
    // Default constructor
    Plant() : name("Unnamed"), height(0) {
        plantCount++;
        cout << "Default constructor of Plant called" << endl;
    }

    // Parameterized constructor
    Plant(string n, int h) : name(n), height(h) {
        plantCount++;
        cout << "Parameterized constructor of Plant called" << endl;
    }

    // Destructor
    ~Plant() {
        plantCount--;
        cout << "Destructor of Plant called" << endl;
    }

    // Implementation of display function (from Organism)
    void display() const override {
        cout << "Plant Name: " << name << ", Height: " << height << " cm" << endl;
    }

    // Implementation of growOrAge function (from Organism)
    void growOrAge(int growth) override {
        if (growth >= 0) {
            height += growth;
            cout << name << " has grown by " << growth << " cm." << endl;
        }
    }

    // Static function to get the current plant count
    static int getPlantCount() {
        return plantCount;
    }
};

// Initialize static variable
int Plant::plantCount = 0;

// Class representing an Insect (inherits from Organism)
class Insect : public Organism {
private:
    string species;
    int age;

    // Static variable to keep track of the number of insects
    static int insectCount;

public:
    // Default constructor
    Insect() : species("Unknown"), age(0) {
        insectCount++;
        cout << "Default constructor of Insect called" << endl;
    }

    // Parameterized constructor
    Insect(string s, int a) : species(s), age(a) {
        insectCount++;
        cout << "Parameterized constructor of Insect called" << endl;
    }

    // Destructor
    ~Insect() {
        insectCount--;
        cout << "Destructor of Insect called" << endl;
    }

    // Implementation of display function (from Organism)
    void display() const override {
        cout << "Insect Species: " << species << ", Age: " << age << " days" << endl;
    }

    // Implementation of growOrAge function (from Organism)
    void growOrAge(int days) override {
        if (days >= 0) {
            age += days;
            cout << species << " has aged by " << days << " days." << endl;
        }
    }

    // Static function to get the current insect count
    static int getInsectCount() {
        return insectCount;
    }
};

// Initialize static variable
int Insect::insectCount = 0;

int main() {
    // Dynamically allocating memory for Plant objects
    Organism* garden[2];
    garden[0] = new Plant("Rose", 30);   // Parameterized constructor
    garden[1] = new Plant();             // Default constructor

    // Dynamically allocating memory for Insect objects
    Organism* insects[2];
    insects[0] = new Insect("Bee", 10);  // Parameterized constructor
    insects[1] = new Insect();           // Default constructor

    // Using member functions from the abstract Organism class
    for (int i = 0; i < 2; i++) {
        garden[i]->display();
        garden[i]->growOrAge(10);  // Plants grow by 10 cm

        insects[i]->display();
        insects[i]->growOrAge(3);  // Insects age by 3 days
    }

    // Display the static variables (total number of plants and insects)
    cout << "Total number of plants: " << Plant::getPlantCount() << endl;
    cout << "Total number of insects: " << Insect::getInsectCount() << endl;

    // Deleting dynamically allocated memory
    for (int i = 0; i < 2; i++) {
        delete garden[i];
        delete insects[i];
    }

    // Display the counts after deletion
    cout << "Total number of plants after deletion: " << Plant::getPlantCount() << endl;
    cout << "Total number of insects after deletion: " << Insect::getInsectCount() << endl;

    return 0;
}
