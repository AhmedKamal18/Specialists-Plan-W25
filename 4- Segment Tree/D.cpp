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
         int sum;
         int val;

         Node() : sum(0), val(0) {
         }

         Node(int x, int v) : sum(x), val(v) {
         }

         void change() {
             sum = 0;
         }
     };

     vector<Node> segData;
     int tree_size;

     void build(vector<int> &arr, int node, int l, int r) {
         if (r - l == 1) {
             if (l < arr.size()) {
                 segData[node] = Node(1, arr[l]);
             }
             return;
         }

         build(arr, LeftChild, l, mid);
         build(arr, RightChild, mid, r);

         segData[node] = merge(segData[LeftChild], segData[RightChild]);
     }

     Node merge(Node &l, Node &r) {
         Node ans = Node();
         ans.sum = l.sum + r.sum;
         return ans;
     }

     void update(int idx, int node, int l, int r) {
         if (r - l == 1) {
             segData[node].change();
             return;
         }

         if (idx < mid) {
             update(idx, LeftChild, l, mid);
         } else {
             update(idx, RightChild, mid, r);
         }

         segData[node] = merge(segData[LeftChild], segData[RightChild]);
     }

     pair<int, int> query(int idx, int node, int l, int r) {
         if (r - l == 1) {
             return {segData[node].val, l};
         }

         if (idx <= segData[LeftChild].sum) {
             return query(idx, LeftChild, l, mid);
         }
         return query(idx - segData[LeftChild].sum, RightChild, mid, r);
     }

 public:
     SegmentTree(int n, vector<int> &arr) {
         tree_size = 1;
         while (tree_size < n) tree_size <<= 1;
         segData = vector<Node>(2 * tree_size);
         build(arr, 0, 0, tree_size);
     }

     void update(int idx) {
         update(idx, 0, 0, tree_size);
     }

     pair<int, int> query(int idx) {
         return query(idx, 0, 0, tree_size);
     }

#undef LeftChild
#undef RightChild
#undef mid
 };

void Cook(int testcase) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st = SegmentTree(n, arr);

    for (int i = 0, p; i < n; ++i) {
        cin >> p;
        auto [v, idx] = st.query(p);
        cout << v << " \n"[i == n - 1];
        st.update(idx);
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