class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
            
            for(int i = -(n-1)/2; i<(n+1)/2;i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i = -(n)/2;i<(n+2)/2;i++){
                if(i!=0){
                    ans.push_back(i);
                }
            }
        }

        return ans;
        
    }
};