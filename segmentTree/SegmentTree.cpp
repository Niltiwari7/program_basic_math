class SegT {
public:
    vector<int> seg;
    
    SegT(int n) {
        seg.resize(4 * n);
    }
    
    void build(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, arr);
        build(2 * i + 2, mid + 1, r, arr);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    
    void update(int idx, int val, int i, int l, int r) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * i + 1, l, mid);
        } else {
            update(idx, val, 2 * i + 2, mid + 1, r);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    
    int query(int start, int end, int i, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (start <= l && r <= end) {
            return seg[i];
        }
        int mid = (l + r) / 2;
        return query(start, end, 2 * i + 1, l, mid) + query(start, end, 2 * i + 2, mid + 1, r);
    }
};
