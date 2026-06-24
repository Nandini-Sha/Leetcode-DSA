class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int>subset;
        combination2(candidates,target,res,subset,0);

        return res;
    }

    void combination2(vector<int>& candidates,int target,vector<vector<int>> &res,vector<int> subset,int index)
    {
        if(target == 0)
        {
            res.push_back(subset);
        }
        for(int i = index;i<candidates.size() && target>=candidates[i];i++)
        {
            if(i==index || candidates[i]!=candidates[i-1])
            {
                subset.push_back(candidates[i]);
                combination2(candidates,target-candidates[i],res,subset,i+1);
                subset.pop_back();
            }
        }
    }
};