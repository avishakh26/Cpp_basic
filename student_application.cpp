#include<iostream>

using namespace std ;

int main()
{

    int n, sum = 0;
    cout << "Enter the number of students = " ;
    cin >> n;


    int students[n];

    for (int i = 0 ; i <5 ; i++){
        cout << "Marks for student " <<  i + 1 << " = " ;
        cin >> students[i];
        sum = sum + students[i];


    }


    cout << "Total marks : " << sum << endl;

    float avg = (float)sum / 2 ;

    cout << "Average : " << avg ;


    return 0 ;
}