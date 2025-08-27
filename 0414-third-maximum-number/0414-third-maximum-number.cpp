class Solution {
public:
    int thirdMax(vector<int>& nums) {
      long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for (int num : nums) {
        // Skip if num is already one of the three largest distinct numbers
        if (num == first || num == second || num == third) {
            continue;
        }

        // Update the largest three numbers
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        }
    }

    // If the third number doesn't exist, return the largest (first)
    return third == LONG_MIN ? first : third;


    }
};