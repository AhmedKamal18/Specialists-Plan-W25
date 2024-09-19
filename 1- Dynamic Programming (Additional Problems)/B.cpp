#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

const char nl = '\n', sp = ' ';
const int inf = 1e9 +7 , N = 1001;

string a , b;
int n , m;
int memo [N][N];

int dp (int i , int j){
    if (i == n) return m - j;
    if (j == m) return n - i;
    if (memo[i][j] != -1) return memo[i][j];
    memo[i][j] = inf;
    memo[i][j] = min(memo[i][j] , dp (i +1 , j) +1); // DELETE
    memo[i][j] = min(memo[i][j] , dp (i , j +1) +1); // INSERT
    if (a[i] == b[j]){
        memo[i][j] = min(memo[i][j] , dp (i +1 , j +1));
    } else {
        memo[i][j] = min(memo[i][j] , dp (i +1 , j +1) +1);
    }
    return memo[i][j];
}

void trace (int i , int j , int k) {
    if (i == n) { // first string is finished
        for (int l = j ; l < m ; l ++ , k ++){
            cout << "INSERT " << k << sp << b[l] << nl;
        }
        return;
    }
    if (j == m) { // second string is finished
        for (int l = i ; l < n ; l ++){
            cout << "DELETE " << k << nl;
        }
        return;
    }
    int ret = dp (i , j);
    if (ret == dp (i +1 , j) +1){ // DELETE
        cout << "DELETE " << k << nl;
        trace(i +1 , j , k);
        return;
    }
    if (ret == dp (i , j +1) +1){ // INSERT
        cout << "INSERT " << k << sp << b[j] << nl;
        trace(i , j +1 , k +1);
        return;
    }
    if (a[i] != b[j]){
        cout << "REPLACE " << k << sp << b[j] << nl;
    }
    trace(i +1 , j +1 , k +1);
}

void solve(){
    cin >> a >> b;
    n = sz(a) , m = sz(b);

    memset(memo , -1 , sizeof memo);

    cout << dp(0 , 0) << nl;
    trace (0 , 0 , 1);
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
