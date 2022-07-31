class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX;
        int maxDiff = 0;
        for (int i = 0; i < prices.size(); i++)
        {

            if (min > prices[i])
            {

                min = prices[i];
            }
            else
            {
                if (maxDiff < prices[i] - min)
                {
                    maxDiff = prices[i] - min;
                }
            }
        }

        return maxDiff;
    }
};