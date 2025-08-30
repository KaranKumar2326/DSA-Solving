class Solution {
private:
    bool isPalindromic(string r) {
        string s = r;
        reverse(r.begin(), r.end());
        return s == r;
    }

private:
    string convertBase(int n, int base) {
        string out;
        while (n > 0) {
            if (n % base != 0) out += to_string(n % base);
            else out += "0";
            n /= base;
        }
        return out;
    }

public:
    bool isStrictlyPalindromic(int n) {
        string s;
        for (int i = 2; i <= n-2; i++) {
            s = convertBase(n, i);
            if (!isPalindromic(s)) return false;
        }
        return true;
    }
};