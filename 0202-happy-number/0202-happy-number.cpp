class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int num) {
            int sum = 0;
            while (num) {
                int d = num % 10;
                sum += d * d;
                num /= 10;
            }
            return sum;
        };
        
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};
