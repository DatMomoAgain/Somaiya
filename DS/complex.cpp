#include <iostream>

using namespace std;

class Complex{
public:
    float r;
    float i;
};

Complex add(Complex n1, Complex n2)
{
    Complex q1;
    q1.i = n1.i+n2.i;
    q1.r = n1.r+n2.r;
    return q1;
}
Complex sub(Complex n1, Complex n2)
{
    Complex q1;
    q1.i = n1.i-n2.i;
    q1.r = n1.r-n2.r;
    return q1;
}
Complex mult(Complex n1, Complex n2)
{
    Complex q1;
    q1.r = n1.r*n2.r - n1.i*n2.i;
	q1.i = n1.r*n2.i + n1.i*n2.r;
	return q1;
}
Complex divi(Complex n1, Complex n2)
{
    Complex q1;
    float ad = n2.r*n2.r + n2.i*n2.i;
	q1.r = (n1.r*n2.r + n1.i*n2.i)/ad;
	q1.i = (n1.r*(-n2.i) + n1.i*(n2.r))/ad;
	return q1;
}
bool equal(Complex n1, Complex n2)
{
    if(n1.r==n2.r && n1.i==n2.i)
    {
        return true;
    }
    return false;
}

int main()
{
    Complex n1, n2, q1, q2;
    cout<<"Enter real part of 1st no.: ";
    cin>>n1.r;
    cout<<"Enter imaginary part of 1st no.: ";
    cin>>n1.i;
    cout<<"Enter real part of 2nd no.: ";
    cin>>n2.r;
    cout<<"Enter imaginary part of 2nd no.: ";
    cin>>n2.i;
    
    int q;
    
    while(q!=0){
    cout<<"Enter 1-addition 2-subtraction 3-multiplication 4-division 5-equal 0-exit: ";
    cin>>q;
    switch(q)
    {
     case 0:
        break;
     case 1:
        q1 = add(n1,n2);
        cout<<"Addition gives: " << q1.r << " + (" << q1.i << "i)\n";
        break;
     case 2:
        q1 = sub(n1,n2);
        cout<<"Subtraction gives: " << q1.r << " + (" << q1.i << "i)\n";
        break;
     case 3:
        q1 = mult(n1,n2);
        cout<<"Multiplication gives: " << q1.r << " + (" << q1.i << "i)\n";
        break;
     case 4:
        q1 = divi(n1,n2);
        cout<<"Division gives: " << q1.r << " + (" << q1.i << "i)\n";
        break;
     case 5:
        if(equal(n1,n2))
        {
            cout<<"they are equal\n";
        }
        else
        {
           cout<<"they are not equal\n"; 
        }
        break;
    }
    }

    return 0;
}
