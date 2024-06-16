class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //generating all sums
        /*
        ref:    https://leetcode.com/problems/patching-array/solutions/5321946/why-not-you-tried-prefix-sum-greedy-approach-o-logn/
        */

        //assume i get sum 3
        //and i want to add a element 4
        //then then i can add 4 to each sum to get
        //1+4=5
        //2+4=6
        //3+4=7
        //4 itslef

        //but with sum 3 if i want to add 5

        /*
        then sum i can get is 
        5 itslef
        1+5=6
        2+5 =7
        3+5=8
        
        */

        /*
           conclusion : nums[i]<=sum+1 to get 
        */

        #define ll long long
        ll ans=0,sum=0;
        for(ll i=0;i<nums.size();){
            if(sum>=n)break;
            if(i<n&&nums[i]<=sum+1){
                sum+=nums[i];
                i++;
            }
            else{
                ans++;
                sum+=sum+1;
            }
        }   
        //i used all elements,yet sum if left
        while(sum<n){
            ans++;sum+=sum+1;
        }
        return ans;
    }
};