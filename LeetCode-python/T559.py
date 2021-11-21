/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int maxdepth = 0;
            vector <Node*> c = root->children;
            for (auto child: c)
            {
                int ans = maxDepth(child);
                maxdepth = max(maxdepth, ans);
            }
            return maxdepth + 1;
        }
    }
};
