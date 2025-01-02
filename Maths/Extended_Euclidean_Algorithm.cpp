#include<bits/stdc++.h>
using namespace std;
struct Leq{
    int gcd,x,y;
    Leq(int g,int x,int y){
        this->gcd=g;
        this->x=x;
        this->y=y;
    }
};
Leq gcd(int a,int b){
    if(a==0)
     return Leq(b,0,1);
    Leq sol=gcd(b%a,a);
    return Leq(sol.gcd,sol.y-((b/a)*sol.x),sol.x); 
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    Leq solv=gcd(a,b);
    if(c%solv.gcd)
     cout<<"Impossible\n";
    else{
        int v=c/solv.gcd;
        cout<<solv.gcd<<" "<<solv.x*v<<" "<<solv.y*v<<"\n";
    } 
    return 0;
}