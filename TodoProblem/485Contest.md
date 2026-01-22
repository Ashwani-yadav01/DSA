# Two-Items-Under-Budget Problem Roadmap

This is a mini roadmap to master the pattern of selecting at most two items under a constraint (like budget) to maximize reward.

---

## Step 1 – Basic Pairing / Sum Constraint

1. [LC 1 – Two Sum](https://leetcode.com/problems/two-sum/)

   * Focus: finding pairs efficiently (hashmap / two pointers)
   * Goal: understand "select 2 items to meet a target condition"

---

## Step 2 – Two Items Under Limit

2. [LC 1099 – Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/)

   * Core pattern: exactly like the machine problem
   * Constraint: sum < K
   * Technique: sort + two pointers

---

## Step 3 – Pairing With Counts / Greedy

3. [LC 1679 – Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/)

   * Pick pairs under a sum constraint
   * Understand "how greedy + sorting helps maximize reward"

---

## Step 4 – Weight Limit / Pair Optimization

4. [LC 881 – Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)

   * Similar two-pointer logic
   * Learn pairing smallest + largest to maximize usage under constraint

---

## Step 5 – Single / Multiple Items + Reward

5. [LC 2542 – Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/)
   * learn this question
   * Generalizes from 2 items → k items
   * Teaches combining value + constraint efficiently

---

## Step 6 – Optional Extension

6. [LC 16 – 3Sum Closest](https://leetcode.com/problems/3sum-closest/)

   * Optional: move from pairs → triplets
   * Great for practicing two/three pointer ideas under sum constraints

---

**Tip:** Start from Step 1 and progress downwards. Steps 1–3 focus on the exact two-item pattern; Steps 4–6 extend the concept for mor
