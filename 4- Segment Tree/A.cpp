#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

struct Node{
    ll sum{}, ans{}, mx_pref{}, mx_suff{};
    Node() {}
    Node(ll val) {
        sum = val;
        ans = mx_pref = mx_suff = max(0ll, val);
    }
};

struct SegTree{
    int N;
    vector<Node> tree;

    SegTree(int n){
        N = 1;
        while(N < n) N <<= 1;
        tree.resize(N << 1);
    }

    SegTree(vector<int>& a) : SegTree(a.size()){
        build(1, 0, N - 1, a);
    }

    Node merge(Node x, Node y){
        Node res;
        res.sum = x.sum + y.sum;
        res.ans = max({x.ans, y.ans, x.mx_suff + y.mx_pref});
        res.mx_pref = max(x.mx_pref, x.sum + y.mx_pref);
        res.mx_suff = max(y.mx_suff, y.sum + x.mx_suff);
        return res;
    }

    void build(int node, int left, int right, vector<int>& a){
        if (left == right) {
            if(left < a.size()) tree[node] = a[left];
            return;
        }
        int mid = (left + right) /2;
        build(node << 1, left, mid, a);
        build(node << 1 | 1, mid + 1, right, a);
        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void build(vector<int>& a){
        for (int i = 0; i < a.size(); ++i) {
            tree[N + i] = a[i];
        }
        for (int i = N - 1; i > 0; --i) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int node, int left,int right, int idx, int val){
        // left - right    node
        // left_child ( 2 * node):  left - mid       right_child (2 * node + 1):  mid + 1 - right
        if (left == right){
            tree[node] = Node(val);
            return;
        }
        int mid = (left + right)/2;
        if (idx <= mid){
            update(node << 1, left, mid, idx, val);
        }else{
            update(node << 1 | 1, mid + 1, right, idx, val);
        }
        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    Node query(int node, int left, int right, int ql, int qr){
        if (left >= ql && right <= qr) return tree[node];
        if (right < ql || left > qr) return Node(0);
        int mid = (left + right) / 2;
        Node left_query = query(node << 1, left , mid, ql, qr);
        Node right_query = query(node << 1 | 1, mid + 1, right, ql, qr);
        return merge(left_query, right_query);
    }

    void update(int idx, int val){
        update(1, 0, N - 1, idx, val);
    }

    ll query(int l, int r){
        return query(1, 0, N - 1, l, r).ans;
    }

};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree st(a);
    for (int i = 0; i < m; ++i) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        st.update(idx , val);
        cout << st.query(0, n - 1) << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >>t;
    while(t--) solve();
}
