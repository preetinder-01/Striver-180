class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x=prices[0];
        int profit=0;
        int pro=0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(x>prices[i])x=prices[i];
            else
            profit=max(profit,)
        }
    }
};