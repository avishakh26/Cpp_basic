#include<iostream>
using namespace std;




class student
{
    public :
        int id ;
        double gpa;
        void display ()
        {
            cout << "Id and GPA are " << " = " << id << " & " << gpa <<endl;

        }

       student(int x , double y)
       {

            id = x;
            gpa = y;


       }
};



int main()

{


    student Suporna(101,3.90);
    Suporna.display();

    student Jalim(103,3.98);
    Jalim.display();


    return 0 ;
}