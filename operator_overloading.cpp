#include <iostream>
using namespace std;

class number {

    public:
    int n;

    number (int set_n)
    {
    
        n = set_n;

     }

        number operator+ (const number &numA){
        return number(this->n + numA.n);
    }


    bool operator == (const number &numA){

        if (this-> n == numA.n) return true;
        else return false;
    }

};



int main()
{

    number a = 5;
    number b = 10;

    number c = a + b;  
    
    cout << "Ans is :" << c.n << endl;

    if (a==c) cout << "a == c" << endl; 
    else cout << "a != c" << endl;

    return 0;
}