#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest substring without repeating characters
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Array to store the last seen index of each character (ASCII size is 256)
        int lastIndex[256];

        // Initialize all characters as not seen (-1)
        for (int i = 0; i < 256; ++i)
        {
            lastIndex[i] = -1;
        }

        int maxlen = 0; // Stores the length of the longest substring
        int l = 0;      // Left boundary of current window

        for (int r = 0; r < s.length(); ++r)
        {
            char currentChar = s[r];

            if (lastIndex[currentChar])
            {
                // If the character was seen and is inside the current window
                if (lastIndex[currentChar] >= l)
                {
                    // Move the left pointer to one position after last occurrence
                    l = lastIndex[currentChar] + 1;
                }
            }

            // Update the last seen index of current character
            lastIndex[currentChar] = r;

            // Update max length if current window is larger
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

/*
🧠 Logic Explanation (with Example)
Problem:
Find the length of the longest substring without repeating characters.

Approach:
Use the sliding window technique with two pointers l and r.
 Track the last seen index of characters using an integer array of size 256 (ASCII range).
  If a character repeats within the window, move the left pointer to avoid it. 
  Calculate the current window size: r - l + 1 and update maxlen.
🔁 Example: "abcabcbb"

| Step | Char | Left (l) | Right (r) | Window | maxlen |
| ---- | ---- | -------- | --------- | ------ | ------ |
| 1    | a    | 0        | 0         | "a"    | 1      |
| 2    | b    | 0        | 1         | "ab"   | 2      |
| 3    | c    | 0        | 2         | "abc"  | 3      |
| 4    | a    | 1        | 3         | "bca"  | 3      |
| 5    | b    | 2        | 4         | "cab"  | 3      |
| 6    | c    | 3        | 5         | "abc"  | 3      |
| 7    | b    | 5        | 6         | "cb"   | 3      |
| 8    | b    | 6        | 7         | "b"    | 3      |

➡️ Final Answer = 3 ("abc" is the longest substring without repeating characters)

⏱️ Time & Space Complexity
Time Complexity: O(n) where n is the length of the string (each character is visited once by the right pointer and possibly once by the left pointer)

Space Complexity: O(1) (Using a fixed-size array of 256 for ASCII characters)
*/