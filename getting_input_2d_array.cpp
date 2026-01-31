#include<iostream>

using namespace std;

int main()
{
    int A[2][3];

    cout << "Enter the elements of the matrix:" << endl;

    // Input matrix elements
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "A[" << row << "][" << col << "] = ";
            cin >> A[row][col];
        }
    }

    // Display matrix elements
    cout << "\nThe matrix is:" << endl;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            cout << A[row][col] << " ";
        }
        cout << endl;  // Move to the next line after printing each row
    }

    return 0;  // Correct placement of return statement
}
