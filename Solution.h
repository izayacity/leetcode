//
//  Solution.h
//  leetcode
//
//  Created by Francis Yang on 2/7/17.
//  Copyright © 2017 izayacity. All rights reserved.
//

#ifndef Solution_h
#define Solution_h
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    // 38. Count and Say
    // The count-and-say sequence is the sequence of integers beginning as follows:
    // 1, 11, 21, 1211, 111221, ...
    string countAndSay(int n) {
        string result = "1";
        if (n == 0) return "";
        // n = 2
        while (--n) {
            string cur = "";
            for (int i = 0; i < result.size(); i++) {
                int count = 1;
                while (i+1 < result.size() && result[i] == result[i+1]) {
                    count++;
                    i++;
                }
                
                cur += to_string(count) + result[i];
            }
            result = cur;
        }
        
        return result;
    }
    
    void countAndSayTest () {
        if (countAndSay(2) == "11")
            cout << "Test case of input 2 passed" << endl;
        else{
            cout << "Test case of input 2 failed" << endl;
            cout << "Result of 2 is: " << countAndSay(2) << endl;
        }
        
        if (countAndSay(3) == "21")
            cout << "Test case of input 3 passed" << endl;
        else{
            cout << "Test case of input 3 failed" << endl;
            cout << "Result of 3 is: " << countAndSay(3) << endl;
        }
        
        if (countAndSay(4) == "1211")
            cout << "Test case of input 4 passed" << endl;
        else{
            cout << "Test case of input 4 failed" << endl;
            cout << "Result of 4 is: " << countAndSay(4) << endl;
        }
        
        if (countAndSay(5) == "111221")
            cout << "Test case of input 5 passed" << endl;
        else{
            cout << "Test case of input 5 failed" << endl;
            cout << "Result of 5 is: " << countAndSay(5) << endl;
        }
        
        if (countAndSay(6) == "312211")
            cout << "Test case of input 6 passed" << endl;
        else{
            cout << "Test case of input 6 failed" << endl;
            cout << "Result of 5 is: " << countAndSay(5) << endl;
        }
    }
    
    // 35. Search Insert Position
    // Given a sorted array and a target value, return the index if the target is found.
    // If not, return the index where it would be if it were inserted in order.
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        int length = (int) nums.size();
        cout << "length is " << length << endl;
        
        if (target > nums [length - 1]) {
            pos = length;
            nums.push_back(target);
        } else {
            for (int i = 0; i < length; i++) {
                if (target <= nums[i]) {
                    nums.push_back(nums[length - 1]);
                    for (int j = length - 2; j >= i; j--) {
                        nums [j + 1] = nums [j];
                    }
                    nums[i] = target;
                    pos = i;
                    break;
                }
            }
        }
        
        return pos;
    }
    
    void searchInsertTest () {
        vector<int> data = {1, 3, 5, 6};
        
        if (searchInsert(data, 0) == 0)
            cout << "Test case of input 0 passed" << endl;
        else{
            cout << "Test case of input 0 failed" << endl;
            cout << "Result of 0 is: " << searchInsert(data,0) << endl;
        }
        
        data = {1, 3, 5, 6};
        
        if (searchInsert(data, 2) == 1)
            cout << "Test case of input 2 passed" << endl;
        else{
            cout << "Test case of input 2 failed" << endl;
            cout << "Result of 2 is: " << searchInsert(data,2) << endl;
        }
        
        data = {1, 3, 5, 6};
        
        if (searchInsert(data, 5) == 2)
         cout << "Test case of input 5 passed" << endl;
         else{
         cout << "Test case of input 5 failed" << endl;
         cout << "Result of 5 is: " << searchInsert(data,5) << endl;
         }
        
        data = {1, 3, 5, 6};
        
        if (searchInsert(data, 7) == 4)
            cout << "Test case of input 7 passed" << endl;
        else{
            cout << "Test case of input 7 failed" << endl;
            cout << "Result of 7 is: " << searchInsert(data,7) << endl;
        }
    }
    
    
    // 14. Longest Common Prefix
    // Write a function to find the longest common prefix string amongst an array of strings.
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
    
    void longestCommonPrefixTest () {
        vector<string> strs = {"ab", "abc"};
        cout << "Result is: " << longestCommonPrefix(strs) << endl;
    }
};

#endif /* Solution_h */
