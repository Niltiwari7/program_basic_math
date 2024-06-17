typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define rfo(i, n) for (int i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)x.size()

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

template <typename T> void debug_vector(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T> void debug_2d_vector(const vector<vector<T>>& v) {
    for (const auto& row : v) {
        for (const auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

