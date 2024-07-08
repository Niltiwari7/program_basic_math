class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    int find_parent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find_parent(parent[x]);
    }
    
    void Union(int u, int v) {
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);
        
        if (u_parent != v_parent) {
            if (rank[u_parent] < rank[v_parent]) {
                parent[u_parent] = v_parent;
            } else if (rank[u_parent] > rank[v_parent]) {
                parent[v_parent] = u_parent;
            } else {
                parent[v_parent] = u_parent;
                rank[u_parent]++;
            }
        }
    }
};

class Solution {
public:
    
    static bool comp(vector<int>& vec1, vector<int>& vec2) {
        return vec1[2] < vec2[2];
    }
    
    int Kruskal(vector<vector<int>>& vec, int n) {
        int sum = 0;
        DSU d(n);
        for (auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = d.find_parent(u);
            int parent_v = d.find_parent(v);
            if (parent_u != parent_v) {
                d.Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<int>> vec;
        for (int u = 0; u < V; ++u) {
            for (auto &temp : adj[u]) {
                int v = temp[0];
                int wt = temp[1];
                vec.push_back({u, v, wt});
            }
        }
        sort(vec.begin(), vec.end(), comp);
        
        return Kruskal(vec, V);
    }
};