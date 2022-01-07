#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::vector;
/**
 * Problem statement:
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] 
 * where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 */
namespace leetcode {
      vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        auto i{0};
        auto j{numbers.size()-1};
        while (i < j) {
            auto data = numbers[i] + numbers[j];
            if (data == target) {
                v.emplace_back(++i);
                v.emplace_back(++j);
		return v;
            } else if (data < target) {
                i++;
            } else {
                j--;
            }
        }
        return v;
    }
}
int main(int argc, char** argv) {
    vector<int> values{2,3,4};
    auto result = leetcode::twoSum(values, 3);
    std::cout << result[0] << std::endl;
}
