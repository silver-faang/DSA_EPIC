#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    unordered_map<int,int> v,v2;
    for(int i=0;i<n;i++)
     {int tmp;
         cin>>tmp;
         v[tmp]++; }
    for(int i=0;i<n-1;i++){
        int tmp;
        cin>>tmp;
        v2[tmp]++;
        v[tmp]--;
        if(v[tmp]==0)
         v.erase(tmp);
    }
    for(int i=0;i<n-2;i++){
        int tmp;
        cin>>tmp;
        v2[tmp]--;
        if(v2[tmp]==0)
         v2.erase(tmp);
    }
    for(auto i:v)
    cout<<i.first<<"\n";
    for(auto i:v2)
    cout<<i.first<<endl;
    return 0; 
}