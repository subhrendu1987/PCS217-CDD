#include <iostream>
#include "calc.h"

using namespace std;

int main() {
    int a, b, choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Result = " << add(a, b);
            break;
        case 2:
            cout << "Result = " << sub(a, b);
            break;
        case 3:
            cout << "Result = " << mul(a, b);
            break;
        case 4:
            if (b == 0)
                cout << "Division by zero error!";
            else
                cout << "Result = " << divide(a, b);
            break;
        default:
            cout << "Invalid choice!";
    }

    cout << endl;
    return 0;
}
