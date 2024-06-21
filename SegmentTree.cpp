class SegmentTree {
public:
    vector<ll> seg;
    SegmentTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<ll>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l)
            return 0;
        if (low >= l && high <= r)
            return seg[idx];
        
        int mid = (low + high) >> 1;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};