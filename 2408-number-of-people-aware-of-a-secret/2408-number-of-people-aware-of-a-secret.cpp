class Solution {
public:
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
    const int MOD = 1'000'000'007;
    vector<long long> newPeople(n + 2, 0);
    newPeople[1] = 1;

    long long sharers = 0;

    for (int day = 2; day <= n; ++day) {
        if (day - delay >= 1) {
            sharers = (sharers + newPeople[day - delay]) % MOD;
        }
        if (day - forget >= 1) {
            sharers = (sharers - newPeople[day - forget] + MOD) % MOD;
        }
        newPeople[day] = sharers;
    }

    long long ans = 0;
    for (int day = max(1, n - forget + 1); day <= n; ++day) {
        ans = (ans + newPeople[day]) % MOD;
    }
    return (int)ans;
}

};