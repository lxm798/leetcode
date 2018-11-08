class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        auto length = s.size();
        for (decltype(length) k =0; (k-1) * (numRows -1) < length; ++k) {
            for (decltype(length) i =0; i < numRows-2; ++i) {
                    if (i%(numRows-1) == 0) {
                        ret.append();
                    }

            }
        }
    }
};
