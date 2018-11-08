#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ret = equal_range(nums.begin(), nums.end(), target);
        if (ret.first == nums.end()) {
            return {-1,-1};
        }
        return {ret.first - nums.begin(), ret.second - nums.begin() - 1};
    }
    int upBound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int index = 0;
        while (start < end) {
            index = (start+end)/2;
            if (nums[index] <= target) {
                cout << "left" << endl;
                start = index + 1;
            } else if (nums[index] > target) {
                cout << "right" << endl;
                end = index;
            }
        }
        cout << index << " " << start << " " << end << endl;
        if (nums[start] >= target) {
            return start;
        }
        return -1;
    }
};

int main() {
    auto i = vector<int> {7,9,9,9,10};
    Solution s;
    auto j = s.upBound(i,9);
    cout << j << endl;
    return 0;
}
