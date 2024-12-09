#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

class ArcherContract{
    virtual void SignContract() = 0; // Pure virtual function
};

class Archer : ArcherContract{
    private:
        string name;
        int age;
        int accuracy;
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
};

int main(){
    Archer legend = Archer("Mark Vaughan" , 23, 95);
    Archer rookie = Archer("Obi Wan Kenobi", 19, 17);

    legend.SignContract(); // Abstraction, they're in if old enough

    return 0;
}