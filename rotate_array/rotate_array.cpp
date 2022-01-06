#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::vector;
using std::begin;
using std::end;
using std::back_inserter;
/**
 *  Problem statement:
 *  Given an array, rotate the array to the right by k steps, where k is non-negative.
 *  Please consider the case of a big array.
 */ 
namespace leetcode {

void rotate(std::vector<int>& nums, int k){
    auto upper_bound{nums.size()-1};
        std::vector<int> v(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            v[(i+k) % nums.size()] = nums[i];
        }
        nums.clear();
        std::copy(begin(v), end(v), back_inserter(nums));
}
}
int main(int arg, char** argv) {
    std::vector<int> v{13,3,4,1,3};
    leetcode::rotate(v,4);
    for (auto& k: v) {
        std::cout << k;
    }
    std::cout << std::endl; 
    return 0;
}
