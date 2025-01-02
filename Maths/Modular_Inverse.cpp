#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Leq{
    ll gcd,x,y;
    Leq(ll g,ll x,ll y){
        this->gcd=g;
        this->x=x;
        this->y=y;
    }
};
Leq gcd(ll a,ll b){
    if(a==0)
     return Leq(b,0,1);
    Leq sol=gcd(b%a,a);
    return Leq(sol.gcd,sol.y-((b/a)*sol.x),sol.x); 
}
int main(){
    ll a,m,c;
    cin>>a>>m;
    Leq solv=gcd(a,m);
    //cout<<solv.x<<" "<<solv.y<<"\n";
    solv.x=((solv.x%m)+m)%m;
    if(solv.gcd!=1)
     cout<<"-1\n";
    else{
        
        cout<<solv.x<<"\n";
    } 
    return 0;
}

