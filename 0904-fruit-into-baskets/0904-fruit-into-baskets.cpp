class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>basket;
        int i=0,count=0;
        int n=fruits.size();
        for(int j=0;j<n;j++)
        {
            basket[fruits[j]]++;
            while(basket.size()>2 and i<j){
                basket[fruits[i]]--;
            if(basket[fruits[i]]==0)
                basket.erase(fruits[i]);
            i++;
            }
            count=max(count,j-i+1);
        }
        return count;
    }
};