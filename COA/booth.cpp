#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//DECIMAL TO BINARY
string d2b(int x)
{
    string ans = "";
    int remainder;
    int dividend = x;

    if(x==0)
    {
        return "0000";
    }
    while(dividend!=0)
    {
        remainder = dividend%2;
        dividend = dividend/2;
        char r = remainder + '0';
        ans = r + ans;
    }
    int l =ans.length();
    for(int i=0; i<4-l; i++)
    {
        ans = '0' + ans;
    }
    return ans;
}

//BINARY TO DECIMAL
int b2d(string x)
{
    int num1[x.length()];
    for(int i=0; i<x.length(); i++)
    {
      num1[i] = x[i] - '0';
    }
    int ans=0;
    for(int i=0; i<x.length(); i++)
    {
        ans += pow(2,x.length()-1-i)*(num1[i]);
    }
    return ans;
}

//BINARY ADDITION
//returns string of length 5
string add(string a, string b)
{
  int num1[4];
  int num2[4];
  
  //converts string to array of int
  for(int i=0; i<4; i++)
    {
      num1[i] = a[i] - '0';
      num2[i] = b[i] - '0';
    }
    
    int ans[5] = {0,0,0,0,0};
    string ans1 = "";
    int carry = 0;
    
    //main logic
    for(int i =0; i<4; i++)
    {
        if (i<3)
        {
            ans[5-1-i] = num1[4-i-1]+num2[4-i-1] + carry;
            if (ans[5-i-1] == 2)
            {
                carry = 1;
                ans[5-i-1] = 0;
            }
            else if(ans[5-i-1] == 3)
            {
                carry = 1;
                ans[5-i-1] = 1;
            }
            else if(ans[5-i-1] == 1 || ans[5-i-1] == 0)
            {
                carry = 0;
            }
            else
            {
                cout << "error";
            }
        }
        else if(i==3)
        {
            ans[5-i-1] = num1[4-i-1]+num2[4-i-1] + carry;
            ans[5-i-2] = 0;
            if (ans[5-i-1] == 2)
            {
                ans[5-i-1] = 0;
                ans[5-i-2] = 1;
            }   
            else if(ans[5-i-1] == 3)
            {
                ans[5-i-2] = 1;
                ans[5-i-1] = 1;
            }
        }
    }

    //converts int array to string
    for(int i=0; i<5; i++)
    {
        char l = ans[i] + '0';
        ans1 += l;
    }
    
  return ans1;
}

//2'S COMPLEMENT
string two(string a)
{
    string s = "";
    for(int i=0; i<a.length(); i++)
    {
        if(a[i] == '0')
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }
    s = add(s,"0001");
    string ans = s.substr(1,s.size()-1);
    return ans;
}

//BINARY SUBTRACTION
string subt(string a, string b)
{
    b = two(b);
    string ans;
    ans = add(a,b);
    return ans.substr(1,ans.size()-1);
}

//BOOTH'S ALGO FOR MULTIPLICATION
string booth(string M, string Q)
{
    string ans;
    string a = "0000";
    string temp1;
    string temp2;
    string q = Q;
    string m = M;
    if (M < Q)
    {
        m = Q;
        q = M;
    }
    char q1 = '0';
    for(int i=0; i<4; i++)
    {
        if(q[3] == q1)
        {
            temp1 = a;
            temp2 = q;
            a = q[3];
            for(int j=0; j<3; j++)
            {
                a += temp1[j];
            }
            q = temp1[3];
            for(int j=0; j<3; j++)
            {
                q += temp2[j];
            }
            q1 = temp2[3];
        }
        else if(q[3] == '0' && q1 == '1')
        {
            a = add(a,m);
            a = a.substr(1,a.size()-1);

            temp1 = a;
            temp2 = q;
            a = q[3];
            for(int j=0; j<3; j++)
            {
                a += temp1[j];
            }
            q = temp1[3];
            for(int j=0; j<3; j++)
            {
                q += temp2[j];
            }
            q1 = temp2[3];
        }
        else if(q[3] == '1' && q1 == '0')
        {
            a = subt(a,m);

            temp1 = a;
            temp2 = q;
            a = q[3];
            for(int j=0; j<3; j++)
            {
                a += temp1[j];
            }
            q = temp1[3];
            for(int j=0; j<3; j++)
            {
                q += temp2[j];
            }
            q1 = temp2[3];
        }        
    }

    ans = a + q;
    return ans;
}


int main() {
    cout << "enter 1st number: ";
    int nums1;
    cin >> nums1;
    cout << "enter 2nd number: ";
    int nums2;
    cin >> nums2;
    string a = d2b(nums1);
    string b = d2b(nums2);
    cout << nums1 << " + " << nums2 << " = " << b2d(add(a,b)) << '\n';
    cout << nums1 << " - " << nums2 << " = " << b2d(subt(a,b)) << '\n';
    cout << nums1 << " * " << nums2 << " = " << b2d(booth(a,b)) << '\n';
}
