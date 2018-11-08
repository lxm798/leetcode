#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution11 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            int j = target - nums[i];
            auto iter = umap.find(j);
            if (iter != umap.end()) {
                return vector<int>{i, iter->second};
            }
            umap.insert(make_pair(nums[i], i));
        }
    }
};
int main() {
    auto i = vector<int> {2,3,4,1};
    Solution11 s;
    auto j = s.twoSum(i,7);
    cout << j[0] << " "<< j[1] << endl;
    j = s.twoSum(i,5);
    cout << j[0] << " "<< j[1] << endl;
    cout << (1<0) << endl;
    return 0;
}
