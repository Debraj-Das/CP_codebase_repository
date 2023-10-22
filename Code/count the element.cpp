/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vb vector<bool>
#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

template <class T, class V> class SegmentTree
{
  private:
    struct SegmentTreeNode;

    SegmentTreeNode *nodes;
    int N;

    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
    {
        if (left == lo && right == hi)
            return nodes[stIndex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return getValue(2 * stIndex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return getValue(2 * stIndex, left, mid, lo, hi);

        SegmentTreeNode leftResult = getValue(2 * stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        SegmentTreeNode result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N)
    {
        int size = 1;
        for (; size < N; size <<= 1)
            ;
        return size << 1;
    }

    void update(int stIndex, int lo, int hi, int index, T value)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid + 1, hi, index, value);

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

  public:
    SegmentTree(T arr[], int N)
    {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    SegmentTree(vector<T> vrr)
    {
        const int N = vrr.size();
        int arr[N];
        for (int i = 0; i < N; i++)
            arr[i] = vrr[i];

        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    ~SegmentTree()
    {
        delete[] nodes;
    }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode result = getValue(1, 0, N - 1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value)
    {
        update(1, 0, N - 1, index, value);
    }
};

/*
**  Some Importance Ideas of Segment Trees -->
1.   T -> type of input array elements
2.   V -> type of required aggregate statistic or data type of Node vaule

** 	Definite the Segment Tree Node -->
1.   assignLeaf function -> Update the value of node
2.   merge function -> Combined the nodes
3.   getValue function -> return the value of the node

**  Functions of Segment Tree -->
1.   Constructor(ar , n) -> Build the segment Tree -> arguments : array , size of array
     Constructor(vect) -> Build the segment Tree -> arguments : vector
2.   getVaule(lo , hi) -> return value Queries -> argument : range of zero based indexing
3.   update(index , value) -> update the index-> argument : index , update vaule

**  Some example of Sum Query ->

        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        SegmentTree<int, int> tree(arr, 8);
        cout << tree.getValue(0, 4) << '\n';
        tree.update(4, 10);
        cout << tree.getValue(2, 6) << '\n';

*/

template <class T, class V> struct SegmentTree<T, V>::SegmentTreeNode
{
    V value;

    void assignLeaf(T a)
    {
        // assign the node Depends of Node Storage
        value = a;
        return;
    }

    void merge(SegmentTreeNode a, SegmentTreeNode b)
    {
        // Update according to Questions Depends of Node Storage
        value = a.value + b.value;
        return;
    }

    V getValue()
    {
        // Return the value of the node Depends of Node Storage
        return value;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    pqg<pii> p;
    int a;
    f(i, 0, n)
    {
        cin >> a;
        p.push(mp(a, i));
    }

    int b, x;
    array<int, 5> qr[q];

    f(i, 0, q)
    {
        qr[i][0] = i;
        cin >> a >> b >> x;
        qr[i][1] = a - 1;
        qr[i][2] = b - 1;
        qr[i][3] = x;
    }

    sort(qr, qr + q, [](auto &a, auto &b) {
        if (a[3] < b[3])
            return true;
        if (a[3] == b[3] and a[0] < b[0])
            return true;

        return false;
    });

    SegmentTree<int, int> sg(vi(n, 0));

    f(i, 0, q)
    {
        x = qr[i][3];
        while (p.size() and p.top().ff <= x)
        {
            sg.update(p.top().ss, 1);
            p.pop();
        }

        qr[i][4] = sg.getValue(qr[i][1], qr[i][2]);
    }

    sort(qr, qr + q);

    f(i, 0, q)
    {
        cout << qr[i][4] << el;
    }

    return;
}