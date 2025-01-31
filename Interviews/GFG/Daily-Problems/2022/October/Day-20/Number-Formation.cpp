class Solution {
public:
    int getSum(int x, int y, int z, int mod = 1e9 + 7) {
        int64_t exactsum[x + 1][y + 1][z + 1],  exactnum[x + 1][y + 1][z + 1];
        memset(exactnum, 0, sizeof exactnum);
        memset(exactsum, 0, sizeof exactsum);

        int64_t ans = 0;
        exactnum[0][0][0] = 1;

        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                for (int k = 0; k <= z; k++) {
                    if (i > 0) {
                        exactsum[i][j][k] += (exactsum[i - 1][j][k] * 10 + 4 * exactnum[i - 1][j][k]) % mod;
                        exactnum[i][j][k] += exactnum[i - 1][j][k] % mod;
                        exactsum[i][j][k] %= mod;
                    }
                    if (j > 0) {
                        exactsum[i][j][k] += (exactsum[i][j - 1][k] * 10 + 5 * exactnum[i][j - 1][k]) % mod;
                        exactnum[i][j][k] += exactnum[i][j - 1][k] % mod;
                        exactsum[i][j][k] %= mod;
                    }
                    if (k > 0) {
                        exactsum[i][j][k] += (exactsum[i][j][k - 1] * 10 + 6 * exactnum[i][j][k - 1]) % mod;
                        exactnum[i][j][k] += exactnum[i][j][k - 1] % mod;
                        exactsum[i][j][k] %= mod;
                    }
                    ans = (ans + exactsum[i][j][k]) % mod;
                }
            }
        }

        return int(ans);
    }
};