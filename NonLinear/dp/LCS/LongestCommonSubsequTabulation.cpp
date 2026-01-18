#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m];  // Output: 4
    return 0;
}
// for find the lenght of shortest common subsequence we have to use the formula
// Length of SCS = Length of s1 + Length of s2 - Length of LCS
// 1143
// 1092
// 583
// 712
// 1035
// 1458
// 97
// 115
// 72
// 392
// 516
// 1312
// 1682

// 1. Two-Pointer / Greedy / Pairing under Constraints

// LeetCode 881 – Boats to Save People

// LeetCode 452 – Minimum Number of Arrows to Burst Balloons

// LeetCode 435 – Non-overlapping Intervals

// LeetCode 253 – Meeting Rooms II

// LeetCode 986 – Interval List Intersections

// Pattern to practice: sort → two pointers → greedy decision

// 2. DP on Subsequences / Strings

// LeetCode 718 – Maximum Length of Repeated Subarray

// LeetCode 516 – Longest Palindromic Subsequence

// LeetCode 1092 – Shortest Common Supersequence Length

// LeetCode 647 – Palindromic Substrings

// LeetCode 115 – Distinct Subsequences

// Pattern: dp[i][j] over substrings → count / length / boolean

// 3. DP on Partitions / Groupings

// LeetCode 312 – Burst Balloons

// LeetCode 1039 – Minimum Score Triangulation of Polygon

// LeetCode 139 – Word Break

// LeetCode 279 – Perfect Squares

// LeetCode 322 – Coin Change

// Pattern: Partition sequence → combine subproblems → optimize

// 4. DP on Intervals / Matrix

// LeetCode 85 – Maximal Rectangle

// LeetCode 62 – Unique Paths

// LeetCode 63 – Unique Paths II

// LeetCode 221 – Maximal Square

// Pattern: Build DP over 2D states → careful with base cases

// 5. DP with State Compression / Optimization

// LeetCode 198 – House Robber

// LeetCode 213 – House Robber II

// LeetCode 256 – Paint House

// LeetCode 265 – Paint House II

// Pattern: Optimize space → 1D instead of 2D → rolling array