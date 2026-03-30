class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxm = 0, l=0, n=prices.size();
        if(n==1) return 0;
        for(int r=1;r<n;r++){
            if(prices[r]>prices[l]){
                maxm = max(maxm, prices[r]-prices[l]);
            }
            else{
                l=r;
            }
        }
        return maxm;
    }
};
