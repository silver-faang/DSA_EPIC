#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
vector <pair<ll,ll>> tr;
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
pair<ll,ll> mergelr(pair<ll,ll> l,pair<ll,ll> r){
    if(l.first>r.first) return l;
    if(r.first>l.first) return r;
    return {l.first,(l.second+r.second) % MOD};
}
pair<ll,ll> query_tr(ll s,ll e, ll qs,ll qe,ll parent){
    if(s>qe || e<qs) return{0,0};
    if(s>=qs && qe>=e) return tr[parent];
    ll md=(s+e)>>1;
    auto l=query_tr(s,md,qs,qe,parent*2+1);
    auto r=query_tr(md+1,e,qs,qe,parent*2+2);
    return mergelr(l,r);
}

void update(ll s,ll e, ll parent, ll ele, ll mxln, ll w){
    if(s==e){
        if(mxln==tr[parent].first) tr[parent].second=(tr[parent].second+w) % MOD;
        else tr[parent]={mxln,w};
        return;
    }
    ll md=(s+e)>>1;
    if(ele<=md)
     update(s,md,parent*2+1,ele,mxln,w);
    else
     update(md+1,e,parent*2+2,ele,mxln,w);
    tr[parent]=mergelr(tr[parent*2+1],tr[parent*2+2]);  
}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
     cin>> v[i];
    ll mxs=ranks(v);
    tr.resize(4*mxs+1);
    for(ll i=0;i<n;i++){
        ll mxln=1,w=1;
        pair<ll,ll> prev_lis=query_tr(0,mxs,0,v[i]-1,0);
        if(prev_lis.first+1>mxln){
            mxln=prev_lis.first+1;
            w=prev_lis.second;
        }
        update(0,mxs,0,v[i],mxln,w);
    }
    cout<<tr[0].second%MOD;
    return 0;
     
    
}