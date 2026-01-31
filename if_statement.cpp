#include<iostream>

using namespace std;

int main()
{

    int num ;

    cout<< "Enter your number :";
    cin >> num;


    if (num > 0){

        cout<<"positive";
    }


    if (num<0){

        cout<<"negative";
    }


    if (num == 0){

        cout<<"zero";
    }



    return 0 ;
}