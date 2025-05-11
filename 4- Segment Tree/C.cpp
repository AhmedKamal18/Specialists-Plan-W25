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

         Node() : sum(1e15) {
         }

         Node(int x) : sum(x) {
         }

         void change(int x) {
             sum += x;
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
         ans.sum = min(l.sum, r.sum);
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

     Node query(int left, int right, int node, int l, int r) {
         if (l >= left and r <= right) return segData[node];
         if (l >= right or left >= r) return Node();

         Node L = query(left, right, LeftChild, l, mid);
         Node R = query(left, right, RightChild, mid, r);

         return merge(L, R);
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

     int query(int left, int right) {
         return query(left, right, 0, 0, tree_size).sum;
     }

#undef LeftChild
#undef RightChild
#undef mid
 };


void Cook(int testcase) {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n, 0);
    SegmentTree rows(n, arr), cols(n, arr);

    while (q--) {
        int t;
        cin >> t;
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (t == 1) {
            rows.update(x, 1);
            cols.update(y, 1);
        } else if (t == 2) {
            rows.update(x, -1);
            cols.update(y, -1);
        } else {
            int x2, y2;
            cin >> x2 >> y2;

            int rowAttack = rows.query(x, x2);
            int colAttack = cols.query(y, y2);

            if (rowAttack or colAttack)           cout << "Yes\n";
            else                                  cout << "No\n";
        }
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