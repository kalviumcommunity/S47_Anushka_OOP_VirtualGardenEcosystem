#include <iostream>
#include <memory>
using namespace std;

// Abstract class for display behavior
class DisplayBehavior {
public:
    virtual void display(const string& name, int value, const string& extraInfo = "") const = 0;
    virtual ~DisplayBehavior() {}
};

// Concrete display behavior for plants
class PlantDisplay : public DisplayBehavior {
public:
    void display(const string& name, int height, const string& extraInfo = "") const override {
        cout << "Plant Name: " << name << ", Height: " << height << " cm" << endl;
    }
};

// Concrete display behavior for insects
class InsectDisplay : public DisplayBehavior {
public:
    void display(const string& species, int age, const string& extraInfo = "") const override {
        cout << "Insect Species: " << species << ", Age: " << age << " days" << endl;
        if (!extraInfo.empty()) {
            cout << "Additional Info: " << extraInfo << endl;
        }
    }
};

// Abstract base class for Organisms
class Organism {
protected:
    string name;
    int primaryValue; // Height for plants, Age for insects
    string extraInfo; // Unified field for additional information
    shared_ptr<DisplayBehavior> displayBehavior; // Strategy for display behavior

public:
    Organism(const string& n, int value, const string& info, shared_ptr<DisplayBehavior> db)
        : name(n), primaryValue(value), extraInfo(info), displayBehavior(db) {}

    virtual ~Organism() {}

    virtual void growOrAge(int value) = 0;
    virtual void reproduce() const = 0;

    virtual void display() const {
        displayBehavior->display(name, primaryValue, extraInfo);
    }
};

// Class for plants
class Plant : public Organism {
public:
    Plant(const string& n, int height)
        : Organism(n, height, "", make_shared<PlantDisplay>()) {}

    void growOrAge(int growth) override {
        if (growth > 0) {
            primaryValue += growth;
            cout << name << " grew by " << growth << " cm." << endl;
        }
    }

    void reproduce() const override {
        cout << name << " produced seeds." << endl;
    }
};

// Class for insects
class Insect : public Organism {
public:
    Insect(const string& s, int age, const string& info = "")
        : Organism(s, age, info, make_shared<InsectDisplay>()) {}

    void growOrAge(int days) override {
        if (days > 0) {
            primaryValue += days;
            cout << name << " aged by " << days << " days." << endl;
        }
    }

    void reproduce() const override {
        cout << name << " laid eggs." << endl;
    }
};

int main() {
    // Create plants and insects
    Plant rose("Rose", 30);
    Plant oak("Oak", 500);
    Insect bee("Bee", 10);
    Insect butterfly("Butterfly", 5, "Orange wings");

    // Display their information
    rose.display();
    oak.display();
    bee.display();
    butterfly.display();

    // Modify and display their growth/aging
    rose.growOrAge(5);
    bee.growOrAge(3);

    cout << endl << "After growth/aging:" << endl;
    rose.display();
    bee.display();

    return 0;
}
