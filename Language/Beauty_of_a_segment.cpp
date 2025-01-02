#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];
    vector<ll>ps(n+1,0);
    for(int i=1;i<=n;i++)
     ps[i]=ps[i-1]+v[i-1];
    stack<int> lst,rst;
    vector<int> ls(n),rs(n);
    
    for(int i=0;i<n;i++){
        
        while(lst.size() && v[lst.top()]>=v[i])
         lst.pop();
        if(lst.size())
         ls[i]=lst.top()+1;
        else
         ls[i]=0; 
        lst.push(i);  
    }
    for(int i=n-1;i>=0;i--){
        while(rst.size() && v[rst.top()]>=v[i])
         rst.pop();
        if(rst.size())
         rs[i]=rst.top()-1;
        else 
         rs[i]=n-1; 
        rst.push(i);  
    }  
    ll mxps=0;
    for(int i=0;i<n;i++){
        ll tmp=v[i]*(ps[rs[i]+1]-ps[ls[i]]);
        //cout<<tmp<<" "<<i<<"\n";
        mxps=max(mxps,tmp);
    }
    cout<<mxps<<"\n";

    //deque 
    return 0;
}