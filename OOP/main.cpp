#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

class ArcherContract{
    virtual void SignContract() = 0; // Pure virtual function
};

class Archer : ArcherContract{
    private:
        int age;
        int accuracy;
    protected:
        string name;
    public:
        Archer(string name, int age, int accuracy) // Constructor
        : name(name), age(age), accuracy(accuracy) {}

        void details(){
            cout << name << " is " << age << " years old and has an accuracy of " << accuracy << "%\n";
        }
        void set_name(string name){
            this->name = name;
        }
        void set_age(int age){
            this->age = age;
        }
        void set_accuracy(int accuracy){
            this->accuracy = accuracy;
        }

        void SignContract(){
            if(age > 30){
                cout << "OKeydokey, you're in\n";
            }
            else{
                cout << "Sorry, you're too young\n";
            }
        }

        virtual void Shooting(){
            cout << name << " is shooting\n";
        }
};

class Student: public Archer{
    public:
        string master;

        Student(string name, int age, int accuracy, string master)
        :Archer(name, age, accuracy) {
            master = master;
        }

        void PracticeStance(){
            cout << name << " Practicing stance\n";
        }

        void Shooting(){
            cout << name << " is shooting\n";
        }
};

int main(){
    Archer legend = Archer("Mark Vaughan" , 23, 95);
    Archer rookie = Archer("Obi Wan Kenobi", 19, 17);

    legend.SignContract(); // Abstraction, they're in if old enough

    Student freshman = Student("Oski Anoski", 9, 44, "Master Vaughan");

    freshman.PracticeStance(); // Inheritance, student can practice stance

    freshman.SignContract();

    Archer* OskiAnoski = &freshman;

    OskiAnoski->Shooting(); // Polymorphism, Robin is a student but can still shoot;

    return 0;
}