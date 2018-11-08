#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if (target == 0) {
            return ret;
        }
        vector<int> tmp;
        doCombinationSum(candidates, target, tmp, 0 , ret);
        return ret;
    }
    void doCombinationSum(vector<int>& candidates, int target, vector<int>& v,int start,vector<vector<int>> & ret) {
        if (start == candidates.size()) {
            return;
        }
        int sum = 0;
        int vectorSize = v.size();

        while (sum <= target) {
            int sum1 = 0;
            for (auto i :v) {
                sum1 += i;
            }

            if (sum == target) {
                ret.push_back(v);
                return;
            }
            doCombinationSum(candidates, target - sum,v, start + 1, ret);
            if (v.size() > vectorSize) {
                v.erase(v.begin() + vectorSize, v.end());
            }
            v.push_back(candidates[start]);
            sum += candidates[start];
            ++vectorSize;
        }
        return;
    }
};

void printVV(vector<vector<int>> j) {
    for_each(j.begin(), j.end(),[](vector<int> &v) {
        for_each(v.begin(), v.end(), [](int & value){ cout << value << " ";});
        cout << endl;
    });
}

int main () {
    Solution s;
    vector<int> v {2,3,4,8,9};
    printVV(s.combinationSum(v, 9));
}
