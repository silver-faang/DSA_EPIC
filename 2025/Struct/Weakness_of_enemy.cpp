#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
vector <int> tr;
ll ranks( vector<ll> &v){
    vector<ll> t=v;
    ll n=v.size();
    sort(t.begin(),t.end());
    unordered_map<ll,ll> mp;
    ll mx=0;
    for(ll i=0;i<n;i++){
        if(mp.find(t[i])==mp.end())
         mp[t[i]]=mx++;
    }
    for(ll i=0;i<n;i++)
     v[i]=mp[v[i]];
    return mx; 
}
int query(int s,int e,int qs,int qe, int parent){
    if(s>qe || e<qs) return 0;
    if(s>=qs && e<=qe) return tr[parent];
    int md=(s+e)>>1;
    return query(s,md,qs,qe,parent*2+1)+query(md+1,e,qs,qe,parent*2+2);
}
void update(int s,int e, int parent,int ele,int val){
    if(s==e)
     {
         tr[parent]+=val;
         return;
     }
    int md=(s+e)>>1;
    if(ele<=md)
     update(s,md,parent*2+1,ele,val);
    else
     update(md+1,e,parent*2+2,ele,val);
    tr[parent]=tr[2*parent+1]+tr[2*parent+2];   

}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
     cin>> v[i];
    ll mxs=ranks(v);
    tr.resize(4*mxs+1);
    vector<int> rc(n,0);
    for(int i=n-1;i>=0;i--){
        rc[i]=query(0,mxs,0,v[i]-1,0);
        update(0,mxs,0,v[i],1);
        //cout<<rc[i]<<" ";
    }
    //cout<<"rc\n";

    fill(tr.begin(),tr.end(),0);
    ll rs=0;
    for(int i=0;i<n;i++){
        ll lc=query(0,mxs,v[i]+1,mxs,0);
        //cout<<lc<<" ";
        rs+=1ll*lc*rc[i];
        update(0,mxs,0,v[i],1);
    }
    //cout<<"lc\n";
    cout<<rs;
    return 0;
     
    
}