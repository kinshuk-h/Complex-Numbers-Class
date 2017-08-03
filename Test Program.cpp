#include"kv_complex.h"
#include<iostream>
#include<cmath>
using namespace std;

/** \Complex \Numbers \Programs
*/
/** // - Example Program 1 - To Find Orthocentre of 3 Complex Numbers on Argand Plane

    Complex z1,z2,z3,t1,t2,t3,r1,r2,r3,res;
    ld a1,a2,a3;
    z1.Get();
    z2.Get();
    z3.Get();
    t1=z1.Conjugate();
    t2=z2.Conjugate();
    t3=z3.Conjugate();
    a1=z1.Normal();
    a2=z2.Normal();
    a3=z3.Normal();(base*(log10(base)))
    r1=((z1^2)*(t2-t3))+((z2^2)*(t3-t1))+((z3^2)*(t1-t2));
    r2=((z2-z3)*a1)+((z3-z1)*a2)+((z1-z2)*a3);
    r3=(z1*t2)-(z2*t1)+(z2*t3)-(z3*t2)+(z3*t1)-(z1*t3);
    res=(r1+r2)/r3;
    cout<<"Orthocentre - "<<endl;
    res.Print();

*/
/** // - Example Program 2 - To Find the Logarithm of a Complex Number to any Base

    Complex z1,z2;
    ld base;
    while(1)
    {
    z1.Get();
    cout<<"Enter a Valid Base - ";cin>>base;
    z2=z1.Log(base);
    z2.Print();
    cout<<endl;

*/
/** // - Example Program 3 - To Find n-th Roots of a Complex Number

    Complex z1,*z2,sum;
    z1.Get();
    ld no;
    cout<<"Enter 'n' in nth Root - ";cin>>no;
    cout<<endl;
    z2=z1.Root(no);
    for(int i=0;i<no;i++)
    {
        z2[i].Print();
        sum+=z2[i];
    }
    cout<<"\nSum of Roots - "<<endl;
    sum.Print();
    Complex z3;
    z3=z2[2]^no;
    z3.Print();

*/

int main()
{

}
