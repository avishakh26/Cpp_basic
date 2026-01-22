#include<iostream>

using namespace std ;


int main()

{
    char ch;

    cout << "Enter any letter : ";
    cin >> ch;



    ch = tolower(ch);

    switch(ch)
    {

        case 'a' :
            cout << "It's a vowel";
            break;
        
        case 'e' :
            cout << "It's a vowel";
            break;


         case 'i' :
            cout << "It's a vowel";
            break;



         case 'o' :
            cout << "It's a vowel";
            break;


         case 'u' :
            cout << "It's a vowel";
            break;

        default :
            cout << "It's not a Consonant";
            break;

    }


    return 0 ;
}









/*case gula por por o use kora jay like....



case 'a' :
case'e' :
case 'i' :
case'o':
case 'u' :
    cout << "Vowel";
    break;
default:
    cout << consonant;
    break;



*/