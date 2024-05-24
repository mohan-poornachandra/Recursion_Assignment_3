#include<iostream>
#include<cmath>
using namespace std;

void Reverse(int n, int &ans)
{
    if(n==0) return;
    ans = ans*10 + n%10;
    Reverse(n/10,ans);
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int ans=0;
    Reverse(n,ans);
    cout<<"Reverse: "<<ans;
}