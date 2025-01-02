#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<n;i++){
        while(dq.size()&& dq.front()<i-k+1)
         dq.pop_front();
        while(dq.size() && v[dq.back()]>v[i])
         dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)
         cout<<v[dq.front()]<<" ";  
    }

    //deque 
    return 0;
}