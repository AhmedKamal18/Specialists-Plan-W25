#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()

using namespace std ;
using ll = long long;

/*
     * Thinkig phase ......
     * Instead of the regular DP that we're used to
     * we will define the dp array differntly in order to
     * minimize the number of states
     *
     * let dp[i][j]: the minimum weight to obtain a subset sum equal
     *      to j from the first i -1 elements
     * dp[i][j] = min (dp[i -1][j - v[i]] + w[i] , dp[i -1][j])
*/

const int N = 101 , V = 1e5 +1;
const ll INF = 1e15 +1;

ll memo [N][V];
int w [N] , v [N];

ll dp (int i , int j){
    if (i == -1) return j ? INF : 0;
    if (memo[i][j] != -1) return memo[i][j];
    memo[i][j] = dp(i -1 , j); // leave
    if (v[i] <= j)
        memo[i][j] = min(memo[i][j] , dp(i -1 , j - v[i]) + w[i]);
    return memo[i][j];
}

void solve(){
    // recursive solution
    int n , weight;
    cin >> n >> weight;

    for (int i = 0 ; i < n ; i ++){
        cin >> w[i] >> v[i];
    }

    memset(memo , -1 , sizeof memo);

    for (int val = V -1 ; val >= 0 ; val --){
        if (dp(n -1 , val) <= weight){
            cout << val;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../in.txt" , "r" , stdin);
    freopen("../out.txt" , "w" , stdout);
#endif
    solve();
    return 0;
}
