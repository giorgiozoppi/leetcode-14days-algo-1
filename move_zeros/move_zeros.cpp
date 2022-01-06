#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::vector;
using std::begin;
using std::end;
/**
 * Problem statement:
 * Given an integer array nums, move all 0's to the 
 * end of it while maintaining the relative order of the non-zero elements.
 *  Note that you must do this in-place without making a copy of the array.
 */ 
namespace leetcode {
void moveZeros(vector<int>& nums) {
        std::reverse(begin(nums), end(nums));
        for (size_t i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            if (tmp == 0) {
                for (int k = i; k >0 && nums[k-1]!=0; k--) {
                    std::swap(nums[k], nums[k-1]);
                }
            }
        }
        std::reverse(begin(nums), end(nums));
    }
}
int main(int arg, char** argv) {
    std::vector<int> v{0,1,0,3,13,14,23,12,0};
    leetcode::moveZeros(v);
    for (auto& k: v) {
        std::cout << k;
    }
    std::cout << std::endl; 
    return 0;
}