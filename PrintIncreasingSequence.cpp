//Print increasing sequence of length k in first n natural numbers.
#include<iostream>
#include<vector>
using namespace std;

void Sequence(int n,int k,int count,vector<int> ans )
{
    if(ans.size()==k){
        for(int i=0;i<ans.size();i++)
          cout<<ans[i]<<" ";
        cout<<endl;
    }
    for(int i=count;i<=n;i++)
    {
      ans.push_back(i);
      Sequence(n,k,i+1,ans);
      ans.pop_back();
    }

}
int main()
{
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int> ans={};
    Sequence(n,k,1,ans);
}