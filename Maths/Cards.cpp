#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp(1000,-1);
ll fct(int n){
    if(n<=1) return 1;
    if(dp[n]!=-1)
     return dp[n];
    dp[n]=n*fct(n-1);
    return dp[n]; 
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    unordered_map<char,int> mp;
    for(auto i:s){
        mp[i]++;
    }
    ll v=fct(n);
    for(auto i:mp){
        v/=fct(i.second);
    }
    cout<<v<<"\n";
    return 0;
}