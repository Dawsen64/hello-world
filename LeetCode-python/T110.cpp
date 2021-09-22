/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class resB{
public:
    int depth;
    bool balance;
    resB()
    {
        depth = 0;
        balance = true;
    }
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //终止条件：节点为空
        //做什么事：判断左右子树是否是平衡的，并且自己是否是平衡的
        //返回值：返回本树的高度，和自己是否是平衡树
        return isBalanced2(root).balance;
    }


    resB isBalanced2(TreeNode* root)
    {
        //终止条件：节点为空
        //做什么事：判断左右子树是否是平衡的，并且自己是否是平衡的
        //返回值：返回本树的高度，和自己是否是平衡树
        if (root == nullptr)
        {
            resB ans = resB();
            return ans;
        }
        else
        {
            resB left = isBalanced2(root->left);
            resB right = isBalanced2(root->right);
            
            if (left.balance == true && right.balance == true && abs(left.depth - right.depth) <= 1)
            {
                resB ans = resB();
                ans.depth = max(left.depth, right.depth) + 1;
                return ans;
            }
            else
            {
                resB ans = resB();
                ans.balance = false;
                return ans;
            }
        }   
    }
};

//上一个的版本代码是没问题的，但是调用递归时太频繁了，会导致超时，代码如下：
class resB {
public:
    int depth;
    bool balance;
    resB()
    {
        depth = 0;
        balance = true;
    }
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //终止条件：节点为空
        //做什么事：判断左右子树是否是平衡的，并且自己是否是平衡的
        //返回值：返回本树的高度，和自己是否是平衡树
        return isBalanced2(root).balance;
    }


    resB isBalanced2(TreeNode* root) {
        //终止条件：节点为空
        //做什么事：判断左右子树是否是平衡的，并且自己是否是平衡的
        //返回值：返回本树的高度，和自己是否是平衡树
        if (root == nullptr)
        {
            resB ans = resB();
            return ans;
        }
        else//就是这个else语句，疯狂的调用自身递归，应该使用几个临时变量，就不会超时
        {
            if (isBalanced2(root->left).balance == false || isBalanced2(root->right).balance == false)
            {
                resB ans = resB();
                ans.balance = false;
                return ans;
            }
            else
            {
                if (abs(isBalanced2(root->left).depth - isBalanced2(root->right).depth) <= 1)
                {
                    resB ans = resB();
                    ans.depth++;
                    return ans;
                }
                else
                {
                    resB ans = resB();
                    ans.balance = false;
                    return ans;
                }
            }
        }
    }
};
