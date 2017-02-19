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
        string result;
        
        return result;
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
