public class RegexMatching {
    int [][] dp;
    // Memoized Recursive T.C: O(n*m)
    public int solve(String s, String p, int i, int j) {
        int n = s.length(), m = p.length();

        if (dp[i][j] != -1) return dp[i][j];
        if (j == m) return dp[i][j] = (i == n) ? 1 : 0;

        if (j + 1 < m && p.charAt(j + 1) == '*') {
            if (solve(s, p, i, j + 2) == 1) {
                return dp[i][j] = 1;
            }
            if (i < n && (p.charAt(j) == '.' || p.charAt(j) == s.charAt(i))) {
                if (solve(s, p, i + 1, j) == 1) {
                    return dp[i][j] = 1;
                }
            }
        }
        else if (i < n && (p.charAt(j) == '.' || p.charAt(j) == s.charAt(i))) {
            return dp[i][j] = solve(s, p, i + 1, j + 1);
        }
        return dp[i][j] = 0;
    }

    // Bottom Up T.C: O(n*m)
    public boolean bottomUp(String s, String p) {
        int n = p.length(), m = s.length();
        boolean [][] dp = new boolean[n + 1][m + 1];

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            if (p.charAt(i - 1) == '*') dp[i][0] = dp[i - 2][0];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p.charAt(i - 1) == '*') {
                    dp[i][j] = dp[i - 2][j];

                    if (p.charAt(i - 2) == '.' || p.charAt(i - 2) == s.charAt(j - 1)) {
                        dp[i][j] = (dp[i][j] || dp[i][j - 1]);
                    }
                }
                else if (p.charAt(i - 1) == '.' || p.charAt(i - 1) == s.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }

    public static void main(String[] args) {
        String s, p;
        dp = new int[25][25];

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                dp[i][j] = -1;
            }
        }
        int result = solve(s, p, 0, 0);
    }
}