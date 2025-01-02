#include<bits/stdc++.h>
using namespace std;
#define ll long long

int longestCommonSubsequence(vector<int> text1, vector<int> text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
int main(){
    int n,m;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    cin>>m;
    vector<int> y(m);
    for(int i=0;i<m;i++)cin>>y[i];
    
    
    cout<<longestCommonSubsequence(x,y);
    return 0;
}