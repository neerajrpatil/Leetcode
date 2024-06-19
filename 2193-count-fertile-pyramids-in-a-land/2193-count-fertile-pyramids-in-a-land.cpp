class Solution {
public:
#define V(type) vector<type>
#define pb(vec, val) vec.push_back(val)
#define ppb(vec) vec.pop_back()
#define so(vec) sort(vec.begin(), vec.end())
#define rev(vec) reverse(vec.begin(), vec.end())
#define f0(i, n) for(int i = 0; i < n; ++i)
#define p(vec) do { cout << "//"; for (const auto& elem : vec) cout << " " << elem; cout << " //" << endl; } while (0)
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long

    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        
        
        auto val = [&]() {
            ll ans = 0;
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = m - 2; i >= 0; i--) {
                for (int j = 1; j + 1 < n; j++) {
                    if (grid[i][j] == 1) {
                        if (grid[i + 1][j - 1] == 1 && grid[i + 1][j] == 1 && grid[i + 1][j + 1] == 1) {
                            int val = 1 + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
                            dp[i][j] = val;
                            ans += dp[i][j];
                        }
                    }
                }
            }
            return ans;
        };

        ll a = val();
        reverse(begin(grid),end(grid));
        ll b=val();
        return a+b;
    }
};
