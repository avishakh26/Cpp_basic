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


    else if (num<0){

        cout<<"negative";
    }


    else if (num == 0){

        cout<<"zero";
    }

    else {
        cout<<"Wrong number";
    }                                                 // if else if er condition kaj korle else er tah kaj korate hobe must , else er modde kono conditon thake nh

    return 0 ;
}