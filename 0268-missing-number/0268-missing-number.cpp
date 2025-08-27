class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (size*(size+1))/2;
        int i = 0;
        while(i<size){
            sum-=nums[i];
            i++;
        }

        return sum;
    }
};