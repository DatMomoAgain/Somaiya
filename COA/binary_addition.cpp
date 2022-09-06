#include <iostream>
#include <string>
using namespace std;

int* add(string a, string b)
{
  int num1[4];
  int num2[4];
  for(int i=0; i<4; i++)
    {
      num1[i] = a[i] - '0';
      num2[i] = b[i] - '0';
    }
    
    static int ans[5] = {0,0,0,0,0};
    int carry = 0;
    
    for(int i =0; i<4; i++)
    {
        if (i<3)
        {
            ans[5-1-i] = num1[4-i-1]+num2[4-i-1] + carry;
            if (ans[5-i-1] == 2)
            {
                carry += 1;
                ans[5-i-1] = 0;
            }
            else if(ans[5-i-1] == 3)
            {
                carry += 1;
                ans[5-i-1] = 1;
            }
        }
        else if(i==3)
        {
            ans[5-i-1] = num1[4-i-1]+num2[4-i-1] + carry;
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
    
  return ans;
}

int main() {
    cout << "enter 1st number: ";
  string nums1;
  cin >> nums1;
  cout << "enter 2nd number: ";
  string nums2;
  cin >> nums2;
  int *c;
  c = add(nums1, nums2);
  for(int i=0; i<5; i++)
    {
      cout << c[i];
    }
}

