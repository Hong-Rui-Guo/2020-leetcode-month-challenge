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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        vector<TreeNode*> level;
        root->val = 1;
        level.push_back(root);
        int maxWidth = 0;
        levelOrder(level, maxWidth);
        return maxWidth;


        /*
        struct TreeNode *a = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        struct TreeNode *b = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        
        struct TreeNode test(5,a,b);
        
        printf("val:%d\n",test.val);
        printf("left:%p\n",test.left);
        printf("right:%p\n",test.right);
        
        
        return root->val;
        */

    }


private:
    void levelOrder(vector<TreeNode*> level, int& maxWidth) {
        maxWidth = max(maxWidth, level[level.size() - 1]->val - level[0]->val + 1);
        vector<TreeNode*> nextLevel;
        for(int i = 0; i < level.size(); i++) {
            TreeNode* current = level[i];
            if(current) {
                if(current->left) {
                    current->left->val = current->val * 2 - 1;
                    nextLevel.push_back(current->left);
                }
                if(current->right) {
                    current->right->val = current->val * 2;
                    nextLevel.push_back(current->right);
                }
            }
        }
        if(!nextLevel.empty()) {
            levelOrder(nextLevel, maxWidth);
        }
    }    
};