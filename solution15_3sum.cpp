#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0;
        vector<vector<int>> ret;
        int size = nums.size();
        cout << nums.size() -2 << endl;
        for (; start < size - 2;) {
            int target = -nums[start];
            decltype(start) i = start + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] > target) {
                    while (i < j && nums[j-1] == nums[j]){
                        --j;
                    }
                    --j;
                } else if (nums[i] + nums[j] < target) {
                    while ( i < j && nums[i+1] == nums[i]){
                        ++i;
                    }
                    ++i;
                } else {
                    ret.push_back(vector<int>{nums[start],nums[i], nums[j]});
                    while (i < j && nums[j-1] == nums[j]){
                        --j;
                    }
                    while ( i < j && nums[i+1] == nums[i]){
                        ++i;
                    }
                    --j;
                    ++i;
                }
            }
            while (start <nums.size()-2 && nums[start] == nums[start+1]) {
                ++start;
            };
            ++start;
        }

        return ret;
    }
};

int main() {
    auto i = vector<int> {};
    Solution s;
    auto j = s.threeSum(i);
    for_each(j.begin(), j.end(),[](vector<int> &v) {
        for_each(v.begin(), v.end(), [](int & value){ cout << value << " ";});
        cout << endl;
    });
    return 0;
}
