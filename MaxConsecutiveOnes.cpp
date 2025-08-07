#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count_0 = 0;   // number of zeros in the current window [l..r]
        int maxlen = 0;    // answer: maximum valid window size seen so far
        int l = 0, r = 0;  // sliding-window pointers

        while (r < nums.size()) {
            // Expand the window to the right by including nums[r]
            if (nums[r] == 0) count_0++;

            // If we have more than k zeros, shrink from the left
            // until the window becomes valid again (count_0 <= k).
            while (count_0 > k) {
                if (nums[l] == 0) count_0--;  // we're removing a zero
                l++;                           // move left pointer forward
            }

            // At this point, window [l..r] has at most k zeros → it's valid.
            // Update the maximum length.
            if(count_0 <= k) maxlen = max(maxlen, r - l + 1);

            // Move right pointer forward to try a bigger window
            r++;
        }

        return maxlen;
    }

    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;     // Two pointers for sliding window
        int zeros = 0;        // Count of zeros in current window
        int len = 0;          // Current window length
        int maxlen = 0;       // Maximum window length found so far

        // Expand the window with r pointer
        while(r < nums.size()) {
            // If current element is zero, increment zero count
            if(nums[r] == 0) zeros++;

            // If zero count exceeds k, shrink window from the left
            if(zeros > k) {
                if(nums[l] == 0) zeros--; // Adjust zero count if we remove a zero
                l++; // Move left pointer ahead
            }

            // If zero count is within allowed limit, calculate window size
            if(zeros <= k) {
                len = r - l + 1;                  // Current window length
                maxlen = max(len, maxlen);        // Update max length if needed
            }

            r++; // Expand window from the right
        }

        return maxlen;
    }


};


