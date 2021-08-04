class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> getPath(TreeNode *root, int sum, vector<int> path)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
            {
                path.push_back(root->val);
                res.push_back(path);
            }
        }
        if (root->left != NULL)
        {
            path.push_back(root->val);
            getPath(root->left, sum - root->val, path);
            path.pop_back();
        }
        if (root->right != NULL)
        {
            path.push_back(root->val);
            getPath(root->right, sum - root->val, path);
            path.pop_back();
        }
        return res;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        if (root == NULL)
        {
            return res;
        }

        return getPath(root, targetSum, path);
    }
};