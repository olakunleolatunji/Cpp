#include <iostream>
using std::cin, std::cout;

int main(){
    int num{0};
    cout << "How many courses did you take? ";
    cin >> num;
    const unsigned courseNum = num;

    char grades[courseNum];

    cout << "\nFill in your grade and the unit of each"
            "course e.g A3, A in a 3 Units course\n";

    unsigned total = 0;
    unsigned totalUnits = 0;

    for(int i=0; i<courseNum; ++i){
        cin >> grades[i];
        unsigned unit{0};
        cin >> unit;
        totalUnits += unit;
        switch(grades[i]){
        case 'A':
            total += (5*unit);
            break;
        case 'B':
            total += (4*unit);
            break;
        case 'C':
            total += (3*unit);
            break;
        case 'D':
            total += (2*unit);
            break;
        case 'E':
            total += (1*unit);
            break;
        case 'F':
            total += (0*unit);
            break;
        default:
            break;
        }
    }

    double gpa = total / double(totalUnits);
    cout << "GPA: " << gpa;

    return 0;
}
