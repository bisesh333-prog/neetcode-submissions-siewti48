class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, p=0;
        int b=0,s=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[s]){
                ans=max(ans,prices[s]-prices[b]);
                if(prices[b]>prices[i]) b=i;
                s=i;
            }
            else s=i;
        }
        ans=max(ans,prices[s]-prices[b]);
        return ans;
    }
};
