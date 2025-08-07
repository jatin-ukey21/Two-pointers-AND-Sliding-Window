#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Map to store: (fruitType -> count of that fruit in current window)
        unordered_map<int, int> mpp;

        int maxlen = 0;  // Tracks the maximum number of fruits collected
        int l = 0, r = 0; // Sliding window pointers

        // Expand the window with the right pointer
        while (r < fruits.size()) {
            // Add the current fruit to the basket (increase its count)
            mpp[fruits[r]]++;

            // If we have more than 2 types of fruits, shrink the window from the left
            if (mpp.size() > 2) {
                // Remove one fruit from the left side of the window
                mpp[fruits[l]]--;

                // If count becomes zero, remove that fruit type from the map
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }

                // Move the left pointer forward to restore the constraint (max 2 fruit types)
                l++;
            }

            // Current window length
            int len = r - l + 1;

            // Update maximum length if this window is larger
            maxlen = max(len, maxlen);

            // Move right pointer forward to consider the next fruit
            r++;
        }

        // Return the maximum number of fruits we can collect
        return maxlen;
    }
};
//Time Complexity: O(n), where n is the number of fruits.
//Space Complexity: O(1), since the map will store at most 2 types of fruits.