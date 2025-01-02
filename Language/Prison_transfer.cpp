#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,t,c;
    cin>>n>>t>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];
    int res=0,cc=0;
    for(int i=0;i<n;i++){
        if(v[i]<=t)
         cc++;
        else
         cc=0;
        if(cc>=c)
         res++;  
    } 
    cout<<res<<endl;
    return 0;
}