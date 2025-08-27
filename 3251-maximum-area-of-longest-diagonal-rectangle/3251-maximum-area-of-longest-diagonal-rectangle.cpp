class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diagonal = -1;
        int size = dimensions.size();
        int area = -1;
        int i = 0;
        while(i<size){
            if(sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1])>diagonal||(sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1])==diagonal&&dimensions[i][0]*dimensions[i][1]>area)){
                diagonal = sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
                area = dimensions[i][0]*dimensions[i][1];
            }
            
            i++;
        }

        return area;
    }
};