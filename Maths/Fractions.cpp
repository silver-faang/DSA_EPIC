#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a==0)
     return b;
    return gcd(b%a,a); 
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=gcd(a*d+b*c,b*d);
    cout<<(a*d+b*c)/x<<" "<<(b*d)/x<<"\n";
    return 0;
}
