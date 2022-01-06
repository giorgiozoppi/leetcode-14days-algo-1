#include <vector>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::vector;
using std::begin;
using std::end;
using std::back_inserter;
/** Problem statement:
 * Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 */
namespace leetcode {

using std::vector;

int search(vector<int>& nums, int target) {
        int lower{0};
        int upper{static_cast<int>(nums.size())-1};
        bool found{false};
        int index{-1};
        while(lower <= upper) {
            auto mid = lower + (upper - lower) / 2;
            if (nums[mid] < target) {
                lower = mid + 1;
            } else if (target < nums[mid]) {
                upper = mid -1;
            } else {
                index = mid;
                break;
            }
        }
        return index;
    }
}
int main(int arg, char** argv) {
    std::vector<int> v{13,3,4,1,3};
    int idx =  leetcode::search(v,4);
    std::cout << "Index :" << std::endl;
    return 0;
}