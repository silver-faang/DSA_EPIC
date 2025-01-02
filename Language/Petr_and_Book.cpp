#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<int> v(7);
    vector<ll> p(8,0);
    
    for(int i=0;i<7;i++)
     {cin>>v[i];
      p[i+1]=p[i]+v[i];
      }
    n=n%p[7];
    //cout<<n<<"here\n";
    ll idx;
    if(n==0){
        idx=7;
        for(int i=6;i>=0;i--)
         if(!v[i])
         idx=i;
         else 
          break;
    }
    else{
    for(int i=0;i<7;i++){
        ll tmp=n-p[i+1];
        //cout<<tmp<<"\n";
        if(tmp<=0)
        {
            //cout<<"in\n";
            idx=i;
            break;
        }
    }
    idx++;
    }
    //=lower_bound(p.begin()+1,p.end(),n)-p.begin();
    cout<<idx<<"\n";  
     
    return 0;
}