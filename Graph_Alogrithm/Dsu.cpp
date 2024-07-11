class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    // Constructor to initialize the DSU
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the parent of a node with path compression
    int find_parent(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        return parent[x] = find_parent(parent[x]);
    }

    // Union by rank
    void Union(int x, int y) {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if (parent_x == parent_y) return;

        if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    // Union by size
    void UnionBySize(int x, int y) {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if (parent_x == parent_y) return;

        if (size[parent_x] < size[parent_y]) {
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        } else {
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
    }
};