#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (!matrix.size() || !matrix[0].size()) {
            return ret;
        }
        int height = matrix.size() - 1,low = 0;
        int left = 0, right = matrix[0].size() - 1;
        while (left <= right && low <= height) {
            for (int i = left;i <= right && low <= height; ++i) {
                ret.push_back(matrix[low][i]);
            }
            ++low;
            for (int i = low; i <= height && left <= right; ++i) {
                ret.push_back(matrix[i][right]);
            }
            --right;
            for (int i = right; i >= left && low <= height; --i) {
                ret.push_back(matrix[height][i]);
            }
            --height;
            for (int i = height; i >= low && left <= right; --i) {
                ret.push_back(matrix[i][left]);
            }
            ++left;
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> v;
    v.push_back({1,2,3});
    Solution s;
    auto ret = s.spiralOrder(v);
    for(auto i : ret) {
        cout << i << endl;
    }
}
