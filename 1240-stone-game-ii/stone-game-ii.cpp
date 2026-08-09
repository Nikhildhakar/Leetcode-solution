class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // All piles are taken
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int newM = max(M, X);

            // Stones opponent can get after our move
            int opponent = solve(i + X, newM);

            // Total stones remaining - opponent's stones
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Suffix sum
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can go up to n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};