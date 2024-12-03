#include <iostream>
using namespace std;

// Abstract base class representing an Organism
class Organism {
public:
    virtual void display() const = 0;   // Display details
    virtual void reproduce() const = 0; // Reproduce behavior
    virtual ~Organism() {}
    virtual void growOrAge(int value) = 0; // Grow or age
};

// Utility class for displaying Plant information
class PlantDisplay {
public:
    static void displayPlant(const string& name, int height) {
        cout << "Plant Name: " << name << ", Height: " << height << " cm" << endl;
    }
};

// Utility class for tracking Plant count
class PlantManager {
private:
    static int plantCount;

public:
    static void incrementCount() {
        plantCount++;
    }

    static void decrementCount() {
        plantCount--;
    }

    static int getPlantCount() {
        return plantCount;
    }
};

// Initialize static variable
int PlantManager::plantCount = 0;

// Class representing a Plant
class Plant : public Organism {
protected:
    string name;
    int height;

public:
    Plant() : name("Unnamed"), height(0) {
        PlantManager::incrementCount();
        cout << "Default constructor of Plant called" << endl;
    }

    Plant(string n, int h) : name(n), height(h) {
        PlantManager::incrementCount();
        cout << "Parameterized constructor of Plant called" << endl;
    }

    ~Plant() {
        PlantManager::decrementCount();
        cout << "Destructor of Plant called" << endl;
    }

    void display() const override {
        PlantDisplay::displayPlant(name, height);
    }

    void growOrAge(int growth) override {
        if (growth >= 0) {
            height += growth;
            cout << name << " has grown by " << growth << " cm." << endl;
        }
    }

    void reproduce() const override {
        cout << name << " has produced seeds." << endl;
    }
};

// Utility class for displaying Insect information
class InsectDisplay {
public:
    static void displayInsect(const string& species, int age) {
        cout << "Insect Species: " << species << ", Age: " << age << " days" << endl;
    }
};

// Utility class for tracking Insect count
class InsectManager {
private:
    static int insectCount;

public:
    static void incrementCount() {
        insectCount++;
    }

    static void decrementCount() {
        insectCount--;
    }

    static int getInsectCount() {
        return insectCount;
    }
};

// Initialize static variable
int InsectManager::insectCount = 0;

// Class representing an Insect
class Insect : public Organism {
protected:
    string species;
    int age;

public:
    Insect() : species("Unknown"), age(0) {
        InsectManager::incrementCount();
        cout << "Default constructor of Insect called" << endl;
    }

    Insect(string s, int a) : species(s), age(a) {
        InsectManager::incrementCount();
        cout << "Parameterized constructor of Insect called" << endl;
    }

    ~Insect() {
        InsectManager::decrementCount();
        cout << "Destructor of Insect called" << endl;
    }

    void display() const override {
        InsectDisplay::displayInsect(species, age);
    }

    void growOrAge(int days) override {
        if (days >= 0) {
            age += days;
            cout << species << " has aged by " << days << " days." << endl;
        }
    }

    void reproduce() const override {
        cout << species << " has laid eggs." << endl;
    }
};

// Class representing a Tree
class Tree : public Plant {
private:
    int age;

public:
    Tree(string n, int h, int a) : Plant(n, h), age(a) {
        cout << "Tree created with age: " << age << " years." << endl;
    }

    void display() const override {
        cout << "Tree Name: " << name << ", Height: " << height << " cm, Age: " << age << " years" << endl;
    }

    void reproduce() const override {
        cout << name << " is producing acorns." << endl;
    }
};

// Class representing a Butterfly
class Butterfly : public Insect {
private:
    string color;

public:
    Butterfly(string s, int a, string c) : Insect(s, a), color(c) {
        cout << "Butterfly created with color: " << color << endl;
    }

    void display() const override {
        cout << "Butterfly Species: " << species << ", Age: " << age << " days, Color: " << color << endl;
    }

    void reproduce() const override {
        cout << species << " butterfly is laying eggs." << endl;
    }
};

int main() {
    Organism* garden[2];
    garden[0] = new Plant("Rose", 30);
    garden[1] = new Tree("Oak", 500, 80);

    Organism* insects[2];
    insects[0] = new Insect("Bee", 10);
    insects[1] = new Butterfly("Monarch", 5, "Orange");

    for (int i = 0; i < 2; i++) {
        garden[i]->display();
        insects[i]->display();
    }

    cout << "Total number of plants: " << PlantManager::getPlantCount() << endl;
    cout << "Total number of insects: " << InsectManager::getInsectCount() << endl;

    for (int i = 0; i < 2; i++) {
        delete garden[i];
        delete insects[i];
    }

    cout << "Total number of plants after deletion: " << PlantManager::getPlantCount() << endl;
    cout << "Total number of insects after deletion: " << InsectManager::getInsectCount() << endl;

    return 0;
}
