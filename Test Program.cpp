#include"kv_special.h"
#include"kv_math.h"
#include"kv_bigint.h"
//#include"kv_symbolic_char.h"

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

/** \Matrix \Programs

*/
/** // - Example Program 01 - To Perform Elementary Operations on a Matrix - Real

    Matrix<ld>a(1,1),b(1,1),c(1,1);
    char ch;
    int rr,cc,aa=0;
    ld* arr;
    cout<<"Enter the Rows - ";cin>>rr;
    cout<<"Enter the Columns - ";cin>>cc;
    a.Reset(rr,cc);
    b.Reset(rr,cc);
    c.Reset(rr,cc);
    b.Identity();
    c.Identity();
    cout<<"\nEnter a Matrix - "<<endl<<endl;cin>>a;cout<<endl;
    cout<<"Enter Type of Transformation - ";cin>>ch;
    for(int i=0;i<2*rr*cc;i++)
    {
        arr=new ld[rr];
        for(int j=0;j<rr;j++)
            arr[j]=0;
        cout<<"\nEnter the ";
        if(ch=='R')
            cout<<"Row ";
        else
            cout<<"Column ";
        cout<<"to be Altered - ";cin>>aa;
        cout<<"\nEnter the Condition Array - ";
        for(int k=0;k<rr;k++)
            cin>>arr[k];
        cout<<"\nTransforming ...";
        a.TransformC(ch,aa,arr);
        b.TransformC(ch,aa,arr);
        cout<<"\n\nPartial Result - \n\n"<<a<<endl<<b<<endl;
        if(a==c)
            break;
    }
    cout<<"Result - \n\n"<<a<<endl;
    cout<<"\nInverse - \n\n"<<b<<endl;

*/
/** // - Example Program 02 - Find Elements with log(element) as Integer   - Real

    Matrix<ld>a(2,2);
    cout<<"Enter a Matrix - "<<endl<<endl;
    cin>>a;
    cout.flags(ios_base::fixed|ios_base::scientific);
    cout.precision(15);
    cout<<endl;
    cout<<"List of Elements with ln(element) as integer - :"<<endl<<endl;
    vector<ld>vec;
    auto func=[&](ld val){if(decimal(log(val)))return true; return false;};
    vec=a.Specials(func);
    vector<ld>::iterator it;
    it=vec.begin();
    for(it;it<vec.end();it++)
        cout<<*it<<endl;

*/
/** // - Example Program 03 - Altering the Elements of a Matrix            - Complex

    Matrix<Complex> a(2,2);
    cout<<"Enter a Matrix - "<<endl<<endl;cin>>a;cout<<endl;
    auto alt = [](Complex& val){val*=(val+val);};
    Alter(a,alt);
    cout<<"New Matrix - "<<endl<<endl;
    cout<<a<<endl;

*/
/** // - Example Program 04 - Reading and Writing a Matrix from a MRX File - Complex

    int ch;
    Matrix<Complex>a(1,1);
    cout<<"Enter a Choice - "<<endl<<endl;
    cout<<"1) Read a Matrix from a mrx File"<<endl;
    cout<<"2) Write a Matrix to a mrx File"<<endl<<endl;
    state:
    while(true)
    {
        cout<<"Enter an Option - ";cin>>ch;
        if(ch==1)
        {
            string nm;
            cout<<"\nEnter Name of the File - ";
            cin.ignore();
            getline(cin,nm);
            nm+=".mrx";
            fstream file;
            file.open(nm.c_str(),ios::in);
            if(bool(file))
            {
                file>>a;
                file.close();
                cout<<"\nYour Matrix - \n\n"<<a<<endl;
            }
            else
                cout<<"\nFile Not Found. Does it exist ? \nTry Writing First!!"<<endl;
        }
        else if(ch==2)
        {
            string nm;
            cout<<"\nEnter Name of the File - ";
            cin.ignore();
            getline(cin,nm);
            nm+=".mrx";
            int rr,cc;
            cout<<"\nEnter Rows and Columns - ";cin>>rr>>cc;
            a.Reset(rr,cc);
            cout<<"\nEnter the Matrix - \n"<<endl;cin>>a;
            fstream file;
            file.open(nm.c_str(),ios::out|ios::trunc);
            file<<a;
            file.close();
            cout<<"\nData Written Successfully!\n"<<endl;
        }
        else
        {
            cout<<"\nInvalid!"<<endl<<endl;
            goto state;
        }
    }

*/
/** // - Example Program 05 - Checking If the Parts of a Matrix are 0      - Real

    Matrix<ld>a(3,3);
    cout<<"Enter a Matrix - "<<endl<<endl;
    cin>>a;
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        if(a.Row_Zero(i+1))
            cout<<"Row "<<i+1<<" is Zero."<<endl;
        if(a.Column_Zero(i+1))
            cout<<"Column "<<i+1<<" is Zero."<<endl;
    }
    if(a.Diagonal_Zero())
            cout<<"Diagonal is Zero."<<endl;

*/
/** // - Example Program 06 - Returning a Vector containing Non-Zero Vals  - Real

    int r,c;
    cout<<"\nEnter the Rows and Columns of a Matrix - ";cin>>r>>c;
    Matrix<ld>a(r,c);
    cout<<"\nEnter the Matrix - "<<endl<<endl;
    cin>>a;
    vector<ld>nz=a.Non_Zero();
    vector<ld>::iterator it=nz.begin();
    cout<<"\nNon-Zero Elements - ";
    for(it;it<nz.end();it++)
        cout<<*it<<" ";
    cout<<endl;

*/
/** // - Example Program 07 - Initialize a Matrix using Initializer Lists  - Complex

    cout.precision(2);
    Matrix<Complex>a={{{1.23,1.23},{2.23,2.23},{3.23,3.23},{7.54,4.34}},
                      {{4.23,4.23},{5.23,5.23},{6.23,6.23},{7.54,4.34}},
                      {{7.23,7.23},{8.23,8.23},{9.23,9.23},{7.54,4.34}}};
    cout<<"Your Initialized Matrix - \n\n"<<a<<endl;
    cout<<"Rows    - "<<a.Rows()<<endl;
    cout<<"Columns - "<<a.Cols()<<endl;

*/
/** // - Example Program 08 - Get the Sorted Coordinates of a Matrix       - Complex

    cout.precision(3);
    Matrix<Complex>a={{{1.23,1.23},{2.23,2.23},{3.23,3.23}},
                      {{4.23,4.23},{5.23,5.23},{6.23,6.23}},
                      {{7.23,7.23},{8.23,8.23},{-9.23,-9.23}}};
    cout<<"Your Initialized Matrix - \n\n"<<a<<endl;
    Coords* arr=new Coords[9];
    for(int i=0;i<9;i++)
        arr[i]=0;
    arr=Sort_Pos(a,'D');
    cout<<"Now Trying to Sort the Matrix in Descending Order..."<<endl<<endl;
    for(int i=0;i<9;i++)
        cout<<"Position of element "<<i+1<<" to make the Matrix Sorted - ",arr[i].Print();

*/
/** // - Example Program 09 - Get the Upper & Lower Triangles of a Matrix  - Real

    Matrix<int>a(8,8),b(8,8),c(8,8);
    srand(time(nullptr));
    a.Random(1,9);
    b=a.Triangle('U');
    c=a.Triangle('L');
    cout<<"The Matrix - \n\n"<<a;
    cout<<"\nThe Lower Triangle - "<<endl<<endl;
    c.PrintTriangle('L');
    cout<<"The Upper Triangle - "<<endl<<endl;
    b.PrintTriangle('U');

*/
/** // - Example Program 10 - Joins and Splits 4 n*n Matrices              - Real

    int n;
    cout<<"Enter A Number - ";cin>>n;
    Matrix<ld> a(n,n),b(n,n),c(n,n),d(n,n);
    cout<<"\nEnter 4 "<<n<<"*"<<n<<" Matrices - "<<endl<<endl;
    cin>>a;
    cout<<endl;
    cin>>b;
    cout<<endl;
    cin>>c;
    cout<<endl;
    cin>>d;
    cout<<endl;
    cout<<"Joining The Matrices - ";
    cout<<"\n\n";
    cout<<"a b\nc d\n\n";
    Matrix<ld> a1(2*n,n),a2(2*n,n),af(2*n,2*n);
    a1=Join(a,c,'C');
    a2=Join(b,d,'C');
    af=Join(a1,a2,'R');
    cout<<"The Final Matrix - \n\n"<<af<<endl;
    cout<<"Breaking the Matrices - "<<endl<<endl;
    cout<<"a | b"<<endl;
    cout<<"- + -"<<endl;
    cout<<"c | d"<<endl<<endl;
    Matrix<ld>**bf=new Matrix<ld>*[2];
    for(int i=0;i<2;i++)
        bf[i]=new Matrix<ld>[2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            bf[i][j].Reset(n,n);
    bf=Split(af,n,n);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<"Matrix at - "<<i+1<<","<<j+1<<" = \n\n"<<bf[i][j]<<endl;
    if(a==bf[0][0]&&b==bf[0][1]&&c==bf[1][0]&&d==bf[1][1])
        cout<<"\nJoin and Split Operations were Successful! :) "<<endl;
    else
        cout<<"\nJoin and Split Operations Failed... :( "<<endl;

*/

/** \BigInt \Programs

*/
/** // - Example Program 01 - Executing Basic Operations on BigInt Numbers

    ios_base::sync_with_stdio(false);
    BigInt n1,n2,res;
    char op;
    start:
    cout<<"\t\t\tBigInt Binary Operations"<<endl;
    cout<<"\t\t\t------------------------"<<endl<<endl;
    cout<<"Enter 1st Number  ( Arbitrary Size ) -- "; cin>>n1;
    cout<<"Enter Valid Operator ( +,-,*,/,%,^ ) -- "; op=cin.get();
    cout<<"Enter 2nd Number  ( Arbitrary Size ) -- "; cin.ignore(); cin>>n2;
    cout<<"\n\n";
    cout<<"Result                               -- ";
    switch(op)
    {
        case '+':
            res = n1+n2;
            cout<<res;
            break;
        case '-':
            res = n1-n2;
            cout<<res;
            break;
        case '*':
            res = n1*n2;
            cout<<res;
            break;
        case '/':
            res = n1/n2;
            cout<<res;
            break;
        case '%':
            res = n1%n2;
            cout<<res;
            break;
        case '^':
            res = n1^n2;
            cout<<res;
            break;
        default:
            cout<<"Invalid Operator Recieved. Resetting...";
            goto start;
            break;
    }
    cout<<endl<<endl;

*/
/** // - Example Program 02 - Calculating Super Large Factorials ( N < 10000 )

    int n;
    cout<<"Enter Any Number <= 10000 - ";cin>>n;
    cout<<endl;
    BigInt a(1,false);
    ///Constructor - (bool,int) - bool to check if one wants the starting number to be 0 or 1. int to specify size
    for(int i=1;i<=n;i++)
        a*=i;
    cout<<n<<"!  -  \n"<<endl;
    cout<<a<<endl;
    a.Write("Factorial of " + ValueOut(n));

*/
/** // - Example Program 03 - Calculating Super Large Powers of 10

    string aa = "";
    cout<<"Enter a Number - \n";getline(cin,aa);
    BigInt B (aa) ;
    cout<<"\nOriginal Size = "<<B.CurrentSize()<<endl;
    cout<<B<<endl<<endl;
    int n=0;
    cout<<"Enter The Power of 10 - ";cin>>n;
    B.PadZeroes(n);
    cout<<"\nNew Size = "<<B.CurrentSize()<<endl;
    cout<<B<<endl;

*/

main()
{

}
