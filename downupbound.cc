#include <vector>
class Solution {
    public:
        int searchNumBound(vector<int>& nums, int target, int flag) {
            auto end = nums.size();
            decltype(end) start = 0;
            decltype(end) i = -1;
            while (start < end) {
                i = (end+start) /2;
                if (nums[i] >= target) {
                    end = i
                } else {
                    start = i + 1;
                }
            }
            return i;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ret = vector<int>(2,-1);
            int low = searchNumBound(num, target, -1);
            if (low == -1 || nums[low] == target) {
                return ret;
            }
            ret[0] = low;
            low = searchNumBound(num tartget + 1, -1);
            if (a[low - 1] == target) {
                ret[1] = low - 1;
            }
            return ret;
                            
        }
};
