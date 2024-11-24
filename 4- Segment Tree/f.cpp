#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

struct SegTree{
    int N;
    vector<int> tree;

    SegTree(int n){
        N = 1;
        while(N < n) N <<= 1;
        tree.resize(N << 1);
    }

    SegTree(vector<int>& a) : SegTree(a.size()){
        build(a);
    }

    void build(vector<int>& a){
        for (int i = 0; i < a.size(); ++i) {
            tree[i + N] = a[i];
        }
        for (int i = N - 1; i > 0; --i) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    int merge(int x, int y){
        return max(x, y);
    }

    void update(int node, int l, int r, int idx, int val){
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(node << 1, l, mid, idx, val);
        else update(node << 1 | 1, mid + 1, r, idx, val);
        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int idx, int val){
        update(1, 0, N - 1, idx, val);
    }

    int find(int node, int l, int r, int val){
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (tree[node << 1] >= val) return find(node << 1, l, mid, val);
        return find(node << 1 | 1, mid + 1, r, val);
    }

    int find(int val){
        return (tree[1] < val) ? -1 : find(1, 0, N - 1, val);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree st(a);
    while (q--){
        int x;
        cin >> x;
        int idx = st.find(x);
        if (idx != -1) st.update(idx, -x);
        cout << idx + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >>t;
    while(t--) solve();
}
