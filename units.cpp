#include <bits/stdc++.h>

using namespace std;

class OptimizedUnits
{
private:
    vector<int> units;
    vector<vector<int>> dp;

public:
    OptimizedUnits(vector<int> &units)
    {
        this->units = units;
        dp = vector<vector<int>>(100, vector<int>(101, -1));
    }

    int getCoins(int amt, int i, vector<int> &units)
    {
        if (amt == 0)
            return 0;
        if (amt < 0 || i >= units.size())
            return INT_MAX;

        if (dp[i][amt] != -1)
            return dp[i][amt];

        int take = INT_MAX;
        int sol = getCoins(amt - units[i], i, units);
        if (sol != INT_MAX && sol + 1 >= 0)
            take = sol + 1;

        int skip = getCoins(amt, i + 1, units);

        return dp[i][amt] = min(take, skip);
    }

    double findAverage()
    {
        int numCoins = 0;
        for (int amt = 1; amt <= 99; ++amt)
        {
            int result = getCoins(amt, 0, units);
            numCoins += (result == INT_MAX) ? 0 : result;
        }
        dp = vector<vector<int>>(100, vector<int>(101, -1));
        return static_cast<double>(numCoins) / 99;
    }
};

int main()
{
    vector<int> units = {1, 2, 5, 10, 20, 50};
    OptimizedUnits res(units);
    cout << fixed << setprecision(4);
    cout << "Average coins used: " << res.findAverage() << endl;
    return 0;
}
