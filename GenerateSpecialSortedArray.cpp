//Given two arrays A and B, generate arrays such that it starts with A and ends with
//B. The generated array should be sorted and such that if element from A is inserted,
//the next element should be inserted and viceversa.

#include<iostream>
#include<vector>
using namespace std;

void SpecialArray(vector<int>& A, vector<int>& B, int idx1, int idx2, vector<int> ans,bool fromA)
{
    if(!fromA){
        for(int i=0;i<ans.size();i++)
          cout<<ans[i]<<" ";
        cout<<endl;
    }
    cout<<"Hello";
    if(fromA){
          while(fromA){ 
            if(B[idx2]>ans[ans.size()-1]){
                ans.push_back(B[idx2]);
                SpecialArray(A,B,idx1,idx2+1,ans,fromA);
                ans.pop_back();
            }
            else idx2++;
          }
    }
    else{ cout<<"Hello";
        while(!fromA){
             if(A[idx1]>ans[ans.size()-1]||ans.size()==0){
                    ans.push_back(A[idx1]);
                    fromA=true;
                    SpecialArray(A,B,idx1+1,idx2,ans,fromA);
                    ans.pop_back();
                }
            else{
                    idx1++;
                }
        }
    }
    return;
}
void mergedArray(vector<int> arr1, vector<int> arr2, int i, int j, vector<int> ans, int flag)//If flag is true, insert element to arr1.
{
    // if((ans.size()!=0)&&flag)
    // {
    //     for(int i=0;i<ans.size();i++)
    //       cout<<ans[i]<<" ";
    //     cout<<endl;
        
    // } 
    if(flag)
    {
        for(int k=i;k<arr1.size();k++)
        {
            if(ans.size()==0||ans[ans.size()]<arr1[k])
            {
                ans.push_back(arr1[k]);
                mergedArray(arr1,arr2,k+1,j,ans,!flag);
                ans.pop_back();
            }
        }
        for(int k=0;k<ans.size();k++)
            cout<<ans[k]<<" ";
        cout<<endl;
    
    }

          

    else
    {
        for(int k=j;k<arr2.size();k++)
        {
            if(ans[ans.size()-1]<arr2[k])
            {
                ans.push_back(arr2[k]);
                mergedArray(arr1,arr2,i,k+1,ans,!flag);
                ans.pop_back();
            }
        }
    }
}

int main()
{
    vector<int> A={1,3}, B={2,4,6};
    vector<int> ans={};
    mergedArray(A,B,0,0,ans,true);
}

