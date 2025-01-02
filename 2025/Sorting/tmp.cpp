#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cout<<(int)5/2;
    int n,x,y;
    cin>>n>>x>>y;
    auto chk=[&](int mid)->bool {
        return ((mid/x)+(mid/y)>=n-1);
    };
    // ll v=min(min(x,y)*n,min(x,y)+(int)ceil((float)(n-1)*(x*y)/((float)(y+x))));
    // cout<<v;

    
    int l=0,h=n*min(x,y)+1;
    int mid,ans=-1;
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