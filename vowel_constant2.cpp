#include<iostream>

using namespace std;


int main()
{

    char ch;

    cout << "Enter a character : ";
    cin >> ch ;




    ch = tolower(ch);           // jai inpout dik nah keno lower case e conver kore kaj korbe
                                // same vhabe to upper function o use kora jay , jeta dea shob gula ke upper case e convert kora jay






    if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch == 'u'){

        cout << "YES it's a vowel";
    }


    else {
        cout << "It's a consonant" ; 
    }




    return 0;
}