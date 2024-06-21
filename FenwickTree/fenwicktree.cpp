class ST {
    vector<int> st, lazy;
public:
    ST(int n) {
        st.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(int ind, int low, int high, int arr[]) {
        if (low == high) {
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {
        // Update the previous remaining updates and propagate downwards
        if (lazy[ind] != 0) {
            st[ind] += (high - low + 1) * lazy[ind];
            // Propagate the lazy update downwards for the remaining nodes to get updated
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap
        if (high < l || r < low) {
            return;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            st[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // Update if any updates are remaining as the node will stay fresh and updated
        if (lazy[ind] != 0) {
            st[ind] += (high - low + 1) * lazy[ind];
            // Propagate the lazy update downwards for the remaining nodes to get updated
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap
        if (high < l || r < low) {
            return 0;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            return st[ind];
        }

        // Partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};
