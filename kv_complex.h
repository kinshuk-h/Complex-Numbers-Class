/// ===============================================================================================================================
///                                               kv_complex.h (Header File)
/// ===============================================================================================================================
///
/// Made By         -            Kinshuk Vasisht
/// Version         -            3.0.5 - (v1.0.0 Created 08th March, 2017)
/// Status          -            0xFFFFFF (Complete)
/// Features        -            Complex Number Operations, Radian <-> Degree Conversion,
/// Overloads       -            Generic Templates and Multiple Declarations...
/// Functions       -            radtodeg(), degtorad(),  Signum(), Complex Class Methods ...
/// Main Data Type  -            Long Double ( as Alias - ld , Real )
/// Templates       -            typenames & classes.
/// Macros          -            elif() - for else if()
/// Classes         -            Complex ( Operators and Functions )
/// -> Features             -        Get the Real and Imaginary Parts of the Complex Number (From a File Stream as Well),
///                                  Prints the Complex Number (To a File Stream as Well),
///                                  Sets the Real Part to 're', Sets the Imaginary Part to 'im',
///                                  Returns the Real Part & the Imaginary Part of the Complex Number,
///                                  Returns |z| & |z|^2 for Complex z, Returns Conj(z) of Complex z,
///                                  Returns The Slope's Angle of Complex in Argand Plane,
///                                  Returns Inverse of the Complex Number, Gets the Complex z in Polar Form,
///                                  Prints Polar form of z - r(cos(x)+isin(x)) & re^ix
///                                  Converts Polar Form of the Complex Number to Original Form
///                                  Returns Square Roots of Complex z in x1 and x2
///                                  Returns nth Roots of Complex z in Complex array
///                                  Rotates the Complex Number by 'angle' Degrees, Returns a raised to Complex z
///                                  Returns Cosine of Complex z, Returns Hyperbolic Cosine of Complex z,
///                                  Returns Sine of Complex z, Returns Hyperbolic Sine of Complex z,
///                                  Returns Tangent of Complex z, Returns Hyperbolic Tangent of Complex z,
///                                  Returns Eu raised to the Complex Number, Returns Log of the Complex No. to the base
/// -> Operators            -        ==, !=, >, <, +, -, *, /, ^, <<, >>, ~, +=, -=, *=, /=, ^=   ---  Usual Purposes
/// Constants       -            Pi (Pi), Eu (Euler's Number)
/// No. of Lines    -            494 (No Extras, Excluding Comments and Docstrings)
/// Sub-Headers     -            <iostream>, <cstdlib>, <cmath>, <iomanip>, "kv_special.h"
/// Notes           -            Thanks to JPM from SoloLearn Community for his Contributions to the
///                              Complex Class' Math...
///
/// ===============================================================================================================================

#ifndef KV_COMPLEX_H_INCLUDED
#define KV_COMPLEX_H_INCLUDED

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

typedef long double ld;
typedef long double Real;

const Real Pi = 3.141592653589793;
const Real Eu = 2.7182818284590452354;

///______Utility_Functions________________

int signum(ld x)
{
    return (x>0)-(0>x);
}

ld degtorad(ld deg)
{
    cout.setf(ios::fixed);
    ld cnst=Pi/180.0;
    return deg*cnst;
}

ld radtodeg(ld rad)
{
    cout.setf(ios::fixed);
    ld cnst=180.0/Pi;
    return rad*cnst;
}

///______Complex_Class_____________________

class Complex
{
private:
    ld real;
    ld imag;
public:
    Complex(ld re=0,ld im=0):real(re),imag(im){}///Complex Constructor -- Assigns Real and Imaginary values...
    void Get()                                  ///Gets the Real and Imaginary Parts of the Complex Number
    {
        cout<<"Enter Real Value = ";cin>>real;
        cout<<"Enter Imaginary Value = ";cin>>imag;
        cout<<endl;
    }
    void Get(istream& is)                       ///Gets the Real and Imaginary Parts of the Complex Number from a Stream
    {
        is>>real;
        is>>imag;
    }
    void Print()                                ///Prints the Complex Number
    {
        if(imag>0)
        {
            cout<<"The Number is - "<<real<<" + "<<imag<<" i "<<endl;
        }
        else if(imag==0)
        {
            cout<<"The Number is - "<<real<<endl;
        }
        else if(imag<0)
        {
            cout<<"The Number is - "<<real<<" - "<<abs(imag)<<" i "<<endl;
        }
        else
        {
            cout<<"The Number is - "<<imag<<" i "<<endl;
        }
    }
    void Print(ostream& os)                     ///Prints the Complex Number to a Stream
    {
        if(imag>0)
        {
            cout<<real<<" + "<<imag<<" i ";
        }
        else if(imag<0)
        {
            cout<<real<<" - "<<abs(imag)<<" i ";
        }
    }
    void Re(ld re)                              ///Sets the Real Part to 're'
	{
		real=re;
    }
	void Im(ld im)                              ///Sets the Imaginary Part to 'im'
	{
		imag=im;
    }
	ld Re()                                     ///Returns the Real Part of the Complex Number
    {
        return real;
    }
    ld Im()                                     ///Returns the Imaginary Part of the Complex Number
    {
        return imag;
    }
    ld Modulus()                                ///Returns |z| for Complex z
    {
        ld term=pow(real,2)+pow(imag,2);
        return sqrt(term);
    }
    ld Normal()                                 ///Returns |z|^2 for Complex z
    {
        ld term=pow(real,2)+pow(imag,2);
        return term;
    }
    Complex Conjugate()                         ///Returns Conj(z) of Complex z
    {
        Complex res;
        res.real=real;
        res.imag=-imag;
        return res;
    }
    ld Argument()                               ///Returns The Slope's Angle of Complex in Argand Plane
    {
        ld term;
        term=atan2(imag,real);
        return radtodeg(term);
    }
    void Inverse()                              ///Returns Inverse of the Complex Number
    {
        imag=-imag;
        ld a=Normal();
        real/=a;
        imag/=a;
    }
    void GetPolar()                             ///Gets the Complex z in Polar Form
    {
        ld arg,mod;
        cout<<"Enter the Argument - ";cin>>arg;
        cout<<"Enter the Modulus - ";cin>>mod;
        cout<<endl;
        ld newarg=degtorad(arg);
        real=mod*cos(newarg);
        imag=mod*sin(newarg);
    }
    void Polar1Print()                          ///Prints Polar form of z - r(cos(x)+isin(x))
    {
        cout<<"The Polar Form is = ";
        cout<<Modulus()<<"( cos("<<Argument()<<")+sin("<<Argument()<<") )"<<endl;
    }
    void Polar2Print()                          ///Prints Polar form of z - re^ix
    {
        Complex term,t1(0,1),t2;
        term.real=t1.real*degtorad(Argument());
        term.imag=t1.imag*degtorad(Argument());
        t2.RaiseToComplex(Eu,term);
        cout<<"The Polar Form is = ";
        cout<<Modulus()<<"( e ^ "<<degtorad(Argument())<<"i )"<<endl;
        cout<<"                             OR "<<endl;
        cout<<"The Polar Form is = ";
        cout<<Modulus()<<"( "<<Eu<<" ^ "<<degtorad(Argument())<<"i )"<<endl;
        cout<<"                             OR "<<endl;
        cout<<"The Polar Form is = ";
        if(imag>0)
            cout<<Modulus()<<"( "<<t2.real<<" + "<<t2.imag<<" i )"<<endl;
        else if(imag<0)
            cout<<Modulus()<<"( "<<t2.real<<" - "<<abs(t2.imag)<<" i )"<<endl;
    }
    Complex Polar(ld mod,ld arg)                ///Converts Polar Form of the Complex Number to Original Form
    {
        Complex res;
        ld newarg=degtorad(arg);
        res.real=mod*cos(newarg);
        res.imag=mod*sin(newarg);
        return res;
    }
    void Root(Complex& x1, Complex& x2)         ///Returns Square Roots of Complex z in x1 and x2
    {
        ld a=Modulus();
        x1.real=sqrt((a+real)/2);
        x1.imag=signum(imag)*sqrt((-real+a)/2);
        x2.real=-(sqrt((a+real)/2));
        x2.imag=-(signum(imag)*sqrt((-real+a)/2));
    }
    Complex* Root(int m)                        ///Returns nth Roots of Complex z in Complex array
    {
        int n=abs(m);
        Complex *z=new Complex[n];
        ld rn=pow(Modulus(),1.0/n);
        ld narg=(degtorad(Argument()))/n;
        ld npi=(2.0*Pi)/n;
        for(int i=0;i<n;i++)
        {
            z[i]=Complex(0,0);
        }
        for(int k=0;k<n;k++)
        {
            if(n>0)
                z[k]=Complex(rn*cos(narg+k*npi),rn*sin(narg+k*npi));
            else
                z[k]=Complex(rn*cos(narg+(-k)*npi),rn*sin(narg+(-k)*npi));
        }
        return z;
    }
    void Rotate(ld angle)                       ///Rotates the Complex Number by 'angle' Degrees
    {
        ld a=Modulus(),b=Argument();
        b+=angle;
        ld bx=degtorad(b);
        real=a*cos(bx);
        imag=a*sin(bx);
    }
    void RaiseToComplex(ld a,Complex& z)        ///Returns a raised to Complex z
    {
        cout.precision(8);
        cout.setf(ios::fixed);
        ld t1,t2,t3;
        t1=pow(a,z.real);
        t2=cos(z.imag*log(a));
        t3=sin(z.imag*log(a));
        real=t1*t2;
        imag=t1*t3;
    }
    Complex Cos()                               ///Returns Cosine of Complex z
    {
        Complex res,t1(0,1),t2(0,-1),t3,t4,t5,t6,t7;
        t3.real=(real*t1.real)-(imag*t1.imag);
        t3.imag=(real*t1.imag)+(imag*t1.real);
        t4.real=(real*t2.real)-(imag*t2.imag);
        t4.imag=(real*t2.imag)+(imag*t2.real);
        t5.RaiseToComplex(2.718281828459045,t3);
        t6.RaiseToComplex(2.718281828459045,t4);
        t7=t5+t6;
        res.real=t7.real/2;
        res.imag=t7.imag/2;
        return res;
    }
    Complex Cosh()                              ///Returns Hyperbolic Cosine of Complex z
    {
        Complex res,t1(real,imag),t2(-real,-imag),t3,t4,t5;
        t3.RaiseToComplex(2.718281828459045,t1);
        t4.RaiseToComplex(2.718281828459045,t2);
        t5=t4+t3;
        res.real=t5.real/2;
        res.imag=t5.imag/2;
        return res;
    }
    Complex Sin()                               ///Returns Sine of Complex z
    {
        Complex res,t(0,1),t1(0,1),t2(0,-1),t3,t4,t5,t6,t7,t8;
        t3.real=(real*t1.real)-(imag*t1.imag);
        t3.imag=(real*t1.imag)+(imag*t1.real);
        t4.real=(real*t2.real)-(imag*t2.imag);
        t4.imag=(real*t2.imag)+(imag*t2.real);
        t5.RaiseToComplex(2.718281828459045,t3);
        t6.RaiseToComplex(2.718281828459045,t4);
        t7=t6-t5;
        t8=t7*t;
        res.real=t8.real/2;
        res.imag=t8.imag/2;
        return res;
    }
    Complex Sinh()                              ///Returns Hyperbolic Sine of Complex z
    {
        Complex res,t1(real,imag),t2(-real,-imag),t3,t4,t5;
        t3.RaiseToComplex(2.718281828459045,t1);
        t4.RaiseToComplex(2.718281828459045,t2);
        t5=t3-t4;
        res.real=t5.real/2;
        res.imag=t5.imag/2;
        return res;
    }
    Complex Tan()                               ///Returns Tangent of Complex z
    {
        Complex res,t1,t2;
        t1=Sin();
        t2=Cos();
        res=t1/t2;
        return res;
    }
    Complex Tanh()                              ///Returns Hyperbolic Tangent of Complex z
    {
        Complex res,t1,t2;
        t1=Sinh();
        t2=Cosh();
        res=t1/t2;
        return res;
    }
    Complex Exp()                               ///Returns Eu raised to the Complex Number
    {
        Complex res;
        res.RaiseToComplex(Eu,*this);
        return res;
    }
    Complex Log(ld base)                        ///Returns Log of the Complex No. to the base
    {
        Complex res;
        res.real=log(Modulus())/((log(base)));
        res.imag=degtorad(Argument())/((log(base)));
        return res;
    }
    bool operator==(const Complex& rhs)         ///Checks if the Complex Numbers are Equal
    {
        return(real==rhs.real&&imag==rhs.imag);
    }
    bool operator!=(const Complex& rhs)         ///Checks if the Complex Numbers are Unequal
    {
        return(real!=rhs.real&&imag!=rhs.imag);
    }
    bool operator>(const Complex& rhs)          ///Checks if Complex Number is Greater or not
    {
        return((real>rhs.real)||(imag>rhs.imag));
    }
    bool operator<(const Complex& rhs)          ///Checks if Complex Number is Greater or not
    {
        return((real<rhs.real)||(imag<rhs.imag));
    }
    Complex operator~()                         ///Returns Conjugate of the Complex Number
    {
        *this=Conjugate();
        return *this;
    }
    Complex operator+(Complex rhs)              ///Adds Two Complex Numbers
    {
        Complex res;
        res.real=real+rhs.real;
        res.imag=imag+rhs.imag;
        return res;
    }
    Complex operator+(ld rhs)                   ///Adds Constant to Complex Number
    {
        Complex res;
        res.real=real+rhs;
        res.imag=imag;
        return res;
    }
    Complex operator-(Complex rhs)              ///Subtracts Two Complex Numbers
    {
        Complex res;
        res.real=real-rhs.real;
        res.imag=imag-rhs.imag;
        return res;
    }
    Complex operator-(ld rhs)                   ///Subtracts Constant from Complex Number
    {
        Complex res;
        res.real=real-rhs;
        res.imag=imag;
        return res;
    }
    Complex operator*(Complex rhs)              ///Multiplies Two Complex Numbers
    {
        Complex res;
        res.real=(real*rhs.real)-(imag*rhs.imag);
        res.imag=(real*rhs.imag)+(imag*rhs.real);
        return res;
    }
    Complex operator*(ld rhs)                   ///Multiplies Complex z by a Constant
    {
        Complex res;
        res.real=real*rhs;
        res.imag=imag*rhs;
        return res;
    }
    Complex operator/(Complex rhs)              ///Divides Two Complex Numbers
    {
        rhs.Inverse();
        Complex res;
        res.real=(real*rhs.real)-(imag*rhs.imag);
        res.imag=(real*rhs.imag)+(imag*rhs.real);
        return res;
    }
    Complex operator/(ld rhs)                   ///Divides Complex z by a Constant
    {
        Complex res;
        res.real=real/rhs;
        res.imag=imag/rhs;
        return res;
    }
    void operator+=(Complex rhs)                ///Adds z2 to z1
    {
        real+=rhs.real;
        imag+=rhs.imag;
    }
    void operator-=(Complex rhs)                ///Subtracts z2 from z1
    {
        real-=rhs.real;
        imag-=rhs.imag;
    }
    void operator*=(Complex rhs)                ///Multiplies z2 and z1 and returns to z1
    {
        real=(real*rhs.real)-(imag*rhs.imag);
        imag=(real*rhs.imag)+(imag*rhs.real);
    }
    void operator/=(Complex rhs)                ///Divides z2 and z1 and returns to z1
    {
        rhs.Inverse();
        real=(real*rhs.real)-(imag*rhs.imag);
        imag=(real*rhs.imag)+(imag*rhs.real);
    }
    void operator+=(ld rhs)                     ///Adds Constant to z1
    {
        real+=rhs;
        imag=imag;
    }
    void operator-=(ld rhs)                     ///Subtracts Constant from z1
    {
        real-=rhs;
        imag=imag;
    }
    void operator*=(ld rhs)                     ///Multiplies z1 with a Constant and returns to z1
    {
        real*=rhs;
        imag*=rhs;
    }
    void operator/=(ld rhs)                     ///Divides z1 with a Constant and returns to z1
    {
        real/=rhs;
        imag/=rhs;
    }
    Complex operator^(ld power)                 ///Returns Complex z Raised to 'power'
    {
        ld a,b;
        a=Modulus();
        b=pow(a,power);
        ld c,d;
        d=Argument();
        c=degtorad(d);
        Complex res;
        res.real=b*cos(power*c);
        res.imag=b*sin(power*c);
        return res;
    }
    Complex operator^(Complex b)                ///Returns Complex z1 raised to Complex z2
    {
        Complex res,t1(0,1),t2(b.real/2,b.imag/2),t3,t4,t5,t6;
        ld a1,a2;
        a1=Normal();a2=degtorad(Argument());
        t3.RaiseToComplex(a1,t2);
        t4=t1*b;
        t5.real=t4.real*a2;
        t5.imag=t4.imag*a2;
        t6.RaiseToComplex(Eu,t5);
        res=t6*t3;
        return res;
    }
    ~Complex(){}                                ///Complex Destructor -- Does Nothing till now...
    ///Non - Member friend Overloads...
    friend Complex operator+(ld rhs,Complex c)
    {
        return(Complex(c.real+rhs,c.imag));
    }
    friend Complex operator-(ld rhs,Complex c)
    {
        return(Complex(c.real-rhs,c.imag));
    }
    friend Complex operator*(ld rhs,Complex c)
    {
        return(Complex(c.real*rhs,c.imag*rhs));
    }
    friend Complex operator/(ld rhs,Complex c)
    {
        return(Complex(c.real/rhs,c.imag/rhs));
    }
    friend Complex operator^(ld rhs,Complex c)
    {
        Complex res;
        ld t1,t2,t3;
        t1=pow(rhs,c.real);
        t2=cos(c.imag*log(rhs));
        t3=sin(c.imag*log(rhs));
        res.real=t1*t2;
        res.imag=t1*t3;
        return res;
    }
    friend ostream& operator<<(ostream& os, const Complex& c)
    {
        os.setf(ios::fixed);
        os<<"("<<c.real<<","<<c.imag<<")";
        return os;
    }
    friend istream& operator>>(istream& is,Complex& c)
    {
        is>>c.real>>c.imag;
        return is;
    }
    friend Complex abs(Complex c)
    {
        return Complex(abs(c.real),abs(c.imag));
    }
    friend void Write(const Complex& c,fstream& fs)
    {
        fs.setf(ios::fixed);
        fs<<c.real<<" "<<c.imag;
    }
};

#endif // KV_COMPLEX_H_INCLUDED
