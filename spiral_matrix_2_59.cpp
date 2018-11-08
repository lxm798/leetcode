#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> ret(n, tmp);

        int s_w = 0;
        int e_w = n - 1;
        int s_h = 0;
        int e_h = n -1;
        int num = 0;
        while (true) {
            for (int i = s_w; i <= e_w; ++i) {
                ret[s_h][i] = ++num;
            }
            if (++s_h > e_h) {
                break;
            }
            for (int i = s_h; i <= e_h; ++i) {
                ret[i][e_w] = ++num;
            }
            if (--e_w < s_w) {
                break;
            }
            for (int i = e_w; i >= s_w; --i) {
                ret[e_h][i] = ++num;
            }
            if (--e_h < s_h) {
                break;
            }
            for (int i = e_h; i>= s_h; --i) {
                ret[i][s_w] = ++num;
            }
            if (++s_w > e_w) {
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    auto && ret = s.generateMatrix(3);
    // for (auto & row : ret) {
    //     for (auto & i : row) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // }
}