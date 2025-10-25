class Solution {
public:
    int totalMoney(int n) {
        int weekcount = (n - n%7)/7;
        int remainday = n%7;
        int sum = 0;
        for(int i = 0; i<weekcount;++i){
            sum = sum + ((7+i)*(7+1+i))/2 - ((i*(i+1))/2);
        }

        sum = sum + ((weekcount+remainday)*(weekcount+remainday+1))/2 - (weekcount*(weekcount+1))/2;




        return sum;
    }
};