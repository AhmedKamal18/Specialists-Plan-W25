//      ﷽

/*
    "أََرَاكَ تَنظُرُ فِي الآفَاقِ مُنتَظِرًا
    وَعدَ الشُّرُوقِ وَ فِي عَينَيكَ مَغرِبُهُ

    قُل لِلهُمُومِ الَّتِي أَبقَتكَ مُنكَسِرًا
    إِنْ طَالَ لَيلُ الأَسَىٰ فَالصُّبحُ يَعقُبُهُ

    عَمَّا قَرِيبٍ يَعُودُ الحَقُّ مُنتَصِرًا
    وَ يَكتُبُ اللّٰهُ أَمرًا كُنتَ تَرقُبُهُ"
 */


#include <bits/stdc++.h>

using namespace std;

#define Besm_Allah       ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int              long long
#define all(vec)         vec.begin(), vec.end()
#define rall(vec)        vec.rbegin(), vec.rend()
#define retv(x)          return void(cout << (x) << '\n')
#define sz(s)            (int)(s).size()
#define debug(x)         cout << #x << " = " << x << "\n";
#define vdebug(a)        cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

struct SegmentTree {
#define LeftChild  (node * 2 + 1)
#define RightChild (node * 2 + 2)
#define mid        (l + r >> 1)

private:
    struct Node {
        int mx;

        Node() : mx(0) {
        }

        Node(int x) : mx(x) {
        }

        void change(int x) {
            mx -= x;
        }
    };

    vector<Node> segData;
    int tree_size;

    void build(vector<int> &arr, int node, int l, int r) {
        if (r - l == 1) {
            if (l < arr.size()) {
                segData[node] = Node(arr[l]);
            }
            return;
        }

        build(arr, LeftChild, l, mid);
        build(arr, RightChild, mid, r);

        segData[node] = merge(segData[LeftChild], segData[RightChild]);
    }

    Node merge(Node &l, Node &r) {
        Node ans = Node();
        ans.mx = max(l.mx, r.mx);
        return ans;
    }

    void update(int idx, int val, int node, int l, int r) {
        if (r - l == 1) {
            segData[node].change(val);
            return;
        }

        if (idx < mid) {
            update(idx, val, LeftChild, l, mid);
        } else {
            update(idx, val, RightChild, mid, r);
        }

        segData[node] = merge(segData[LeftChild], segData[RightChild]);
    }

    int query(int x, int node, int l, int r) {
        if (segData[node].mx < x) return -1;
        if (r - l == 1) {
            if (segData[node].mx >= x) return l;
            return -1;
        }

        int ans = query(x, LeftChild, l, mid);
        if (ans == -1) ans = query(x, RightChild, mid, r);

        return ans;
    }

public:
    SegmentTree(int n, vector<int> &arr) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        segData = vector<Node>(2 * tree_size);
        build(arr, 0, 0, tree_size);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, tree_size);
    }

    int query(int x) {
        return query(x, 0, 0, tree_size);
    }

#undef LeftChild
#undef RightChild
#undef mid
};


void Cook(int testcase) {
    int n, m;
    cin >> n >> m;
    vector<int> rooms(n);
    for (int i = 0; i < n; i++) cin >> rooms[i];

    SegmentTree st(n, rooms);

    for (int i = 0, g; i < m; ++i) {
        cin >> g;
        int ans = st.query(g);
        if (ans == -1) {
            cout << 0 << ' ';
            continue;
        }
        cout << ans + 1 << ' ';
        st.update(ans, g);
    }
}

signed main() {
    Besm_Allah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    // cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        // cout << "Case #" << testcase << ": ";
        Cook(testcase);
    }

    return 0;
}
