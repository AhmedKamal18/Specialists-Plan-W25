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

         Node() : sum(0) {
         }

         Node(int x) {
             sum = x;
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
         ans.sum = l.sum + r.sum;
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
         if (r <= left or l >= right) {return Node();}
         if (l >= left and r <= right) {return segData[node];}

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

     int query(int lf, int ri) {
         return query(lf, ri, 0, 0, tree_size).sum;
     }

#undef LeftChild
#undef RightChild
#undef mid
 };


struct coordinate_compression {
private:
    vector<long long> comp; // A vector to store the unique, sorted elements for compression.

    // A private method to perform compression by sorting and removing duplicates.
    void compress() {
        sort(comp.begin(), comp.end()); // Sort the vector to arrange elements in ascending order.
        comp.erase(unique(comp.begin(), comp.end()), comp.end()); // Remove duplicates to keep only unique elements.
    }

public:
    // Constructor that initializes the compression vector with the input and compresses it.
    coordinate_compression(vector<long long> & v) {
        comp = v; // Copy the input vector to the internal 'comp' vector.
        compress(); // Call the compress function to sort and remove duplicates.
    }

    // Method to get the compressed index of a given value.
    int get_index(long long val) {
        return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
        // Finds the position where 'val' fits in the sorted 'comp' vector.
        // Subtracting comp.begin() gives the zero-based index of 'val'.
        // If a 1-based index is needed, add +1 to the result.
    }

    // Method to get the original value from the compressed index.
    int get_origin(size_t idx) {
        return comp[idx]; // Returns the original value corresponding to the given index in the compressed vector.
    }
};

void Cook(int testcase) {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    vector<int> arrWithUpdates = arr;
    vector<tuple<int, int, int>> queries;
    while (q--) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            queries.push_back({0, k - 1, x});
            arrWithUpdates.push_back(x);
        } else {
            int l, r;
            cin >> l >> r;
            queries.push_back({1, l, r});
        }
    }

    coordinate_compression comp(arrWithUpdates);
    int mx = *max_element(all(arrWithUpdates));
    int sz = comp.get_index(mx) + 2;
    vector<int> freq(sz);
    for (int i = 0; i < n; ++i) {
        freq[comp.get_index(arr[i])]++;
    }

    SegmentTree st(sz, freq);
    for (int i = 0; i < sz(queries); ++i) {
        auto [op, l, r] = queries[i];
        if (op) { // get range
            int from = comp.get_index(l);
            int to = comp.get_index(r + 1);
            cout << st.query(from, to) << '\n';
         } else { // update
             int idxSub = comp.get_index(arr[l]);
             arr[l] = r;
             int idxAdd = comp.get_index(arr[l]);
             st.update(idxSub, -1);
             st.update(idxAdd, 1);
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