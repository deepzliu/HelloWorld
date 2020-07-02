class Solution {
private:
    vector<vector<int> > res;
    vector<int> one; 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int depth)
    {
        res.push_back(one);
        for(int i = depth; i < nums.size(); i++)
        {
            one.push_back(nums[i]);
            dfs(nums, i+1);
            one.pop_back();
        }
    }
};
