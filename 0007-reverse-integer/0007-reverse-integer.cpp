#include<algorithm>
class Solution {
public:
    int reverse(int x) {
        int isnegative = 0;
        if(x<0){
            isnegative = 1;
        }
        string s = to_string(x);
        std::reverse(s.begin(),s.end());
        long long k = stoll(s);
        if(isnegative ==1){
            k = -k;
        }
        if(k<INT_MIN||k>INT_MAX) return 0;

        return int(k);
    }
};