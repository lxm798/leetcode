#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution11 {
public:
    int maxArea(vector<int>& height) {
        auto length = height.size();
        int maxWater = 0;
        int start=0,end=length-1;
        while (start<end) {
            auto h = min(height[start], height[end]);
            maxWater = max(maxWater, h*(end-start));
            while(height[start] <= h && start < end) ++start;
            while(height[end] <= h && start < end) --end;
        }
        return maxWater;
    }
};
int main() {
    auto i = vector<int> {2,3,4,1};
    Solution11 s;
    auto j = s.maxArea(i);
    cout << j << endl;
    return 0;
}
