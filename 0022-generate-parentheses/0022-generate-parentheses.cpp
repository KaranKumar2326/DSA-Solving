class Solution {
public:
    void recur(vector<string> & ans, string &pat, int left, int counter, int n){
        if(left == 0){
            if(counter == 0){
                ans.push_back(pat);
            }
            return;
        }

        if(counter == 0){
            pat.push_back('(');
            recur(ans, pat, left - 1, counter + 1, n);
            pat.pop_back();
        }
        else if(counter > 0 && counter < n){
            pat.push_back('(');
            recur(ans, pat, left - 1, counter + 1, n);
            pat.pop_back();

            pat.push_back(')');
            recur(ans, pat, left - 1, counter - 1, n);
            pat.pop_back();
        }
        else{
            pat.push_back(')');
            recur(ans, pat, left - 1, counter - 1, n);
            pat.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string pat;

        recur(ans, pat, 2 * n, 0, n);
        
        return ans;
    }
};