#include<bits/stdc++.h>
using namespace std;
int toInt(char a)
{
    int d=a-48;
    return d;
}
void multiply(string num1, string num2) {
    // int a=toInt('4');
    // char c=toChar(a);
    // cout<<c;
    int n=num1.size();
    int n1=num2.size();
    int vecSize=(n+n1);
    vector<int> ans(vecSize,0);
    //string ans;
    string s;
    int carry=0;
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int a=toInt(num2[i]);
            int b=toInt(num1[j]);
            int posForDigit=vecSize-((n1-i-1)+(n-j-1)+1);
            int posForCarry=vecSize-((n1-i-1)+(n-j-1)+2);
            int c=a*b+ans[posForDigit];
            int lastdigit=c%10;
            //char ins=toChar(lastdigit);
            carry=c/10;
            ans[posForDigit]=lastdigit;
            ans[posForCarry]+=carry;
        }
    }
    for(auto i:ans)
    {
        //s.push_back(i + '0');
        cout<<i<<" ";
    }
   // return s;
}
int main()
{
    multiply("456","123");
}