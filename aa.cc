#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int value = 0;
        int state = 0;
        int prefix = 1;
        for (const auto & c : str) {
            if((c == ' ' || c == '\t' || c == '\n') && state == 0) {
                continue;
            } else if (c == '-' && state == 0) {
                prefix = -1;
                state = 1;
            } else if (c== '+' &&state==0) {
                prefix = 1;
                state =1;
            } else if (c >= '0' && c <= '9' && (state == 1 || state == 0)) {
                state = 1;
                value = 10 * value + (c - '0') * prefix;
                if (value == INT_MIN) {
                    state = 2;
                    break;
                }
                if (value *  < 0) {
                    if (prefix > 0) {
                        value = INT_MAX;
                    } else {
                        value = INT_MIN;
                    }
                    state = 2;
                    break;
                }
            } else if (state ==1 || state ==2) {
                break;
            } else {
                value = 0;
                break;
            }
        }
        return value;
    }
};

int main () {
    std::string str("2147483648");
    std::cout << Solution().myAtoi(str) << std::endl;
}

