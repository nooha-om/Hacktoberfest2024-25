class Solution {
    public:
    bool ispossible(vector<int> nums,int mid,int k)
    {
        int n=nums.size();
        int totalk=1;
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
           if(sum+nums[i]<=mid)
           {
            sum+=nums[i];
           }
           else
           {
            totalk++;
            sum=nums[i];
           }
        }
        if(totalk<=k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    int splitArray(vector<int>& nums, int k) 
    {
       int n=nums.size();
       int minimum=INT_MIN;
       int sum=0;
       for(int i=0;i<n;i++)
       {
        minimum=max(minimum,nums[i]);
        sum+=nums[i];
       }   

       int low=minimum;
       int high=sum;
       int ans=1;
       while(low<=high)
       {
        int mid=(low+high)/2;
        if(ispossible(nums,mid,k)==true)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
       } 
       return ans;
    }
};
