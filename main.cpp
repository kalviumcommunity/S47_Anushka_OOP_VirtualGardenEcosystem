#include <iostream>
using namespace std;

// Class representing a Plant
class Plant {
private:
    string name;
    int height;

    // Static variable to keep track of the number of plants
    static int plantCount;

public:
    // Constructor
    Plant(string n, int h) : name(n), height(h) {
        plantCount++; // Increment the count when a new plant is created
    }

    // Destructor
    ~Plant() {
        plantCount--; // Decrement the count when a plant is destroyed
    }

    // Getter for plant name
    string getName() const {
        return name;
    }

    // Setter for plant name
    void setName(string n) {
        name = n;
    }

    // Getter for plant height
    int getHeight() const {
        return height;
    }

    // Setter for plant height
    void setHeight(int h) {
        if (h >= 0) {
            height = h;
        }
    }

    // Member function to display plant details
    void display() const {
        cout << "Plant Name: " << name << ", Height: " << height << " cm" << endl;
    }

    // Member function to grow the plant
    void grow(int growth) {
        setHeight(height + growth);  // Using setter for encapsulation
        cout << name << " has grown by " << growth << " cm." << endl;
    }

    // Static function to get the current plant count
    static int getPlantCount() {
        return plantCount;
    }
};

// Initialize static variable
int Plant::plantCount = 0;

// Class representing an Insect
class Insect {
private:
    string species;
    int age;

    // Static variable to keep track of the number of insects
    static int insectCount;

public:
    // Constructor
    Insect(string s, int a) : species(s), age(a) {
        insectCount++; // Increment the count when a new insect is created
    }

    // Destructor
    ~Insect() {
        insectCount--; // Decrement the count when an insect is destroyed
    }

    // Getter for insect species
    string getSpecies() const {
        return species;
    }

    // Setter for insect species
    void setSpecies(string s) {
        species = s;
    }

    // Getter for insect age
    int getAge() const {
        return age;
    }

    // Setter for insect age
    void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }

    // Member function to display insect details
    void display() const {
        cout << "Insect Species: " << species << ", Age: " << age << " days" << endl;
    }

    // Member function to age the insect
    void ageInsect(int days) {
        setAge(age + days);  // Using setter for encapsulation
        cout << species << " has aged by " << days << " days." << endl;
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
