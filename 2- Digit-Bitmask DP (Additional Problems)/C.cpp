#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
#define int ll
int dp[18][2][18][2][2];
void solve(){
    int l , r;
    cin >> l >> r;
    if (l > r) swap(l , r);
    l--;
    string l_string = to_string(l) , r_string = to_string(r);
    while (l >= 0 && l_string.size()!= r_string.size()) l_string = '0' + l_string;
    int ans1 = 0 , ans2 = 0;
    memset(dp , -1 , sizeof dp);
    auto go = [&](auto &&go, int idx, int tight , int last , int pos , int greater)->int {
        if (idx > last) return pos & ((tight & !greater) || !tight);
        if (~dp[idx][tight][last][pos][greater]) return dp[idx][tight][last][pos][greater];
        int ans = 0;
        int end = tight ? r_string[idx] - '0' : 9;
        for (int i = 0; i <= end; i++) {
            int lead = pos | (i != 0);
            if (lead){
                int nwgreater = 0;
                if(i == r_string[last]-'0') nwgreater = greater;
                else nwgreater = (i >  r_string[last]-'0');
                ans+=go(go , idx + 1 , tight & ((r_string[idx] - '0') == i) , last - 1 , lead ,nwgreater);
            }else ans+=go(go , idx + 1 , tight & ((r_string[idx] - '0') == i) ,last , lead , greater);
        }
        return dp[idx][tight][last][pos][greater] = ans;
    };
    ans1 = go(go , 0 ,1 ,r_string.size() -1 , 0,0);
    r_string = l_string;
    memset(dp, -1, sizeof dp);
    ans2 = go(go, 0, 1, r_string.size() - 1, 0,0);
    cout << ans1 - ans2 + (l == -1)<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    int cnt =0;
    while(t--) {
        cnt++;
        cout << "Case "<<cnt<<": ";
        solve();
    }
}
