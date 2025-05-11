#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

struct Node{
    vector<pair<int,int>> mx;
    Node() {
        mx.resize(2);
    }
    Node(int val) : Node(){
        mx[0] = {val, 1};
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
        Node res = x;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (y.mx[i].first == res.mx[j].first) {
                    res.mx[j].second += y.mx[i].second;
                    goto it;
                }
            }
            res.mx.push_back(y.mx[i]);
            it:;
        }
        sort(rbegin(res.mx), rend(res.mx));
        res.mx.resize(2);
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
        if (right < ql || left > qr) return Node(-1e9);
        int mid = (left + right) / 2;
        Node left_query = query(node << 1, left , mid, ql, qr);
        Node right_query = query(node << 1 | 1, mid + 1, right, ql, qr);
        return merge(left_query, right_query);
    }

    void update(int idx, int val){
        update(1, 0, N - 1, idx, val);
    }

    int query(int l, int r){
        return query(1, 0, N - 1, l, r).mx[1].second;
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
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1){
            x--;
            st.update(x, y);
        }else{
            x--, y--;
            cout << st.query(x, y) << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >>t;
    while(t--) solve();
}
