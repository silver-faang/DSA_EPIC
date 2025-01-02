#include <bits/stdc++.h>
using namespace std;

#define ll long long
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastio();
    int n,k;
    cin>>n>>k;
    vector<int>v(n),u(k);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<k;i++)cin>>u[i];
    for(int i=0;i<k;i++){
    int low=0,high=n-1;    
    int ans=-1;
    while (high>=low)
    {
        int mid = (low + high) / 2;
        if (v[mid] == u[i])
        {
            cout<<"YES\n";
            ans=1;
            break;
            
        }
        else if(v[mid]<u[i]) low = mid+1;
        else
        {
            high = mid-1;
        }
    }
     if(ans==-1)
      cout<<"NO\n";
    }
    
    return 0;
}