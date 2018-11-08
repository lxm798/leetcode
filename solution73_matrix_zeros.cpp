#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return;
        }
        int v_size = matrix.size();
        int c_size = matrix[0].size();
        for (int i = 0; i < v_size; ++i) {
            for (int j = 0; j < c_size; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 0; i < v_size; ++i) {
            for (int j = 0; j < c_size; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> v;
    v.push_back({0,1,2,0});
    v.push_back({3,4,5,2});
    v.push_back({1,3,1,5});
    Solution s;
    s.setZeroes(v);
    for(auto & i : v) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
