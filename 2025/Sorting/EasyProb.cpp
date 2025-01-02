#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    fastio();
    ll n,x,y;
    cin>>n>>x>>y;
    auto chk=[&](ll mid)->bool {
        return ((mid/x)+(mid/y)>=n-1);
    };
    // ll v=min(min(x,y)*n,min(x,y)+(ll)ceil((float)(n-1)*(x*y)/((float)(y+x))));
    // cout<<v;

    
    ll l=0,h=n*min(x,y)+1;
    ll mid,ans=-1;
    while(l<=h){
         //cout<<l<<" "<<h<<" "<<mid<<endl;
         mid=(l+h)>>1;
        if(chk(mid))
         {   //cout<<l<<"YES "<<h<<" "<<mid<<endl;
             ans=mid;
             h=mid-1;}
        else
         l=mid+1; 
    }
    cout<<ans+min(x,y)<<endl;
    return 0;
}