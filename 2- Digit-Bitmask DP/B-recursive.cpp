//لعمرك ما أمرى على بغمة    نهارى و لا ليلى على بسرمد

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

string K;
int D;

int dp[2][100][10001];

int calc(int is_upper_bound, int current_mod_sum, int ind){
    if(ind==K.size()){
        return current_mod_sum==0;
    }
    int &ret = dp[is_upper_bound][current_mod_sum][ind];
    if(~ret)return ret;

    ret = 0;
    int limit = 9;

    if(is_upper_bound)limit = K[ind]-'0';

    for(int i=0;i<=limit;i++){
        ret += calc(is_upper_bound && (limit==i),
                    (current_mod_sum+i)%D,
                    ind+1);
        ret%=mod;
    }
    return ret;
}

void solve(){
    cin >> K >> D;
    memset(dp , -1 , sizeof(dp));
    cout<< (calc(1,0,0) -1 + mod) % mod;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}