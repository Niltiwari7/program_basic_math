#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll sum; 
    node(ll val = 0) {
        sum = val;
    }
};

class SegmentTree {
public:
    vector<node> seg;  

    SegmentTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<ll>& arr) {
        if (low == high) {
            seg[idx].sum = arr[low];  
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        merge(idx);
    }

    ll query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l)
            return 0;  
        if (low >= l && high <= r)
            return seg[idx].sum; 
        int mid = (low + high) >> 1;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx].sum = val;  
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        merge(idx); 
    }

private:
    void merge(int idx) {
        seg[idx].sum = seg[2 * idx + 1].sum + seg[2 * idx + 2].sum; 
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree segTree(n);
    segTree.build(0, 0, n - 1, arr);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            segTree.update(0, 0, n - 1, l - 1, r);
        } else {
            cout << segTree.query(0, 0, n - 1, l - 1, r - 1) << endl;
        }
    }

    return 0;
}
