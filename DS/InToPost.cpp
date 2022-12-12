#include <iostream>
#include <string>
#include <vector>

using namespace std;

int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    
    return -1;
}

int main()
{
    string s;
    cout<<"Enter infix expression: ";
    cin>>s;
    vector<int> stack;

    string ans="";

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<= 'Z')
        {
            ans += s[i];
        }
        else if(s[i]=='(')
        {
            stack.push_back(s[i]);
        }
        else if(s[i]==')')
        {
            for(int j=stack.size()-1; j>=0; j--)
            {
                if(stack[j]!='(')
                {
                    ans += stack[j];
                    stack.pop_back();
                }
                else{
                    stack.pop_back();
                    break;
                }
            }
        }
        else
        {
            if(prec(s[i])>prec(stack[stack.size()-1]))
            {
                stack.push_back(s[i]);
            }
            else
            {
                for(int j=stack.size()-1; j>=0; j--)
                {
                    if(prec(s[i])<=prec(stack[j]))
                    {
                        ans+=stack[j];
                        stack.pop_back();
                    }
                    else{
                        stack.push_back(s[i]);
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
