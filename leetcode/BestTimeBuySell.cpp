class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPr = 1e5, maxProf=0;
        for(int i=0;i<prices.size();++i){
            if(minPr > prices[i]) minPr=prices[i];
            else if(prices[i]-minPr > maxProf) maxProf = prices[i]-minPr;
        }
        return maxProf;
    }
};
