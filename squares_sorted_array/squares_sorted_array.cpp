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
vector<int> sortedSquares(vector<int>& nums) {
    std::vector<int> minor;
    std::vector<int> major;
    std::vector<int> squared(nums.size());
    // split the vector in two parts
    // [-3,-2,-1] --> [9, 4, 1] so this is the inverted sorted order
    // [5, 6, 7] --> [25,36,49] so this is the correct sorted order
    // later i will merge checking rhe last and first.
    for (auto value: nums) {
        if (value < 0) {
            minor.emplace_back(value*value);
        } else {
            major.emplace_back(value*value);
        }
    }
    auto i{0};
    auto j{0};
    auto lastminor{0};
    // merge of the lower part squared.
    for (; i < major.size() && j < minor.size();) {
        lastminor = minor.size() - 1 - j;
        if (major[i] >= minor[lastminor]) {
            squared.emplace_back(minor[lastminor]);
            j++;
        } else {
            squared.emplace_back(major[j]);
            i++;
        }
    }
    // putting the other things
    if (i < major.size()) {
        for (; i <major.size(); i++) {
            squared.emplace_back(major[i]);
        }
    }
    if (j < minor.size()) {
        for (; j < minor.size(); j++) {
            lastminor = minor.size() - 1 - j;
            squared.emplace_back(minor[lastminor]);
        }
    }
    return squared;
}
}
int main(int arg, char** argv) {
    std::vector<int> v{13,3,4,1,3};
    auto data = leetcode::sortedSquares(v);
    for (auto& k: data) {
        std::cout << k;
    }
    std::cout << std::endl; 
    return 0;
}
