class Solution
{
    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {

            vector<vector < int>> res;
            vector<int> perm;
            unordered_map<int, int> umap;
            for (int num: nums)
            {
                umap[num]++;
            }

            function < void() > dfs =[& ]()
            {
                if (perm.size() == nums.size())
                {
                    res.push_back(perm);
                    return;
                }

                for (auto &it: umap)
                {
                    if (it.second > 0)
                    {
                        perm.push_back(it.first);
                        it.second--;

                        dfs();
                        it.second++;
                        perm.pop_back();
                    }
                }
            };
            dfs();
            return res;
        }
};
