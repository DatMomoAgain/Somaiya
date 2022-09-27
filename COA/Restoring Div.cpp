#include <iostream>
#include <string>
using namespace std;

class Ans{
public:
    string rem;
    string quo;
};

//BINARY ADDITION
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

//RESTORING DIVISION
Ans divi(string n1, string n2)
{
    int a[4] = {0,0,0,0};
    int q[4];
    int m[4];
    //converting string to int array
    for(int i=0; i<4; i++)
    {
      m[i] = n2[i] - '0';
      q[i] = n1[i] - '0';
    }
    
    for(int i=0; i<4; i++)
    {
        //storing original value of a
        int temp[4];
        
        //left shift
        for(int j=0; j<3; j++)
        {
            a[j] = a[j+1];
        }
        a[3] = q[0];
        for(int j=0; j<3; j++)
        {
            q[j] = q[j+1];
        }
        q[3] = 0;
        
        for(int j=0; j<4; j++)
        {
            temp[j] = a[j];
        }
        
        //converting a to string as
        string as = "";
        for(int j=0; j<4; j++)
        {
            char c = a[j] + '0';
            as += c;
        }
        as = subt(as,n2);
        //converting string to int array
        for(int j=0; j<4; j++)
        {
          a[j] = as[j] - '0';
        }
        
        //most sig bit
        if(a[0] == 1)
        {
            q[3] = 0;
            for(int j=0; j<4; j++)
            {
                a[j] = temp[j];
            }
        }
        else
        {
            q[3] = 1;
        }
        
    }
    
    Ans ans;
    ans.rem="";
    ans.quo="";
    
    for(int i=0; i<4; i++)
    {
        char d = a[i] + '0';
        ans.rem += d;
        char e = q[i] + '0';
        ans.quo += e;
    }
    return ans;
}

int main()
{
    string n1;
    string n2;
    cout<<"Enter 1st number: ";
    cin>>n1;
    cout<<"Enter 2nd number: ";
    cin>>n2;
    
    Ans ans;
    ans = divi(n1,n2);
    
    cout<<"Division gives: " << ans.quo <<" as quotient; " << ans.rem <<"as remainder\n";
    
}
