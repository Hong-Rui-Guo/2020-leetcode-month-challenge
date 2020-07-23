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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same_check = true;

        if(p == NULL || q == NULL)
        {
            if(p == NULL && q == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            preorder(p,q,same_check);   //VLR
        }

        return same_check;
    }

private:
    void preorder(TreeNode *curr_p, TreeNode *curr_q, bool &same_check){
        if(curr_p != NULL && curr_q != NULL)
        {
            if(curr_p->val != curr_q->val)  //V
            {
                same_check = false;
                return;
            }
            
            if(curr_p->left == NULL || curr_q->left == NULL)                //L
            {
                //note : after checking left, we have to check right, not return directly
                if(curr_p->left != NULL)
                {
                    same_check = false;
                    return;
                }
                else if(curr_q->left != NULL)
                {
                    same_check = false;
                    return;
                }
            }
            else
            {
                preorder(curr_p->left, curr_q->left, same_check);
            }
            

            if(same_check == false)
            {
                return;
            }

            if(curr_p->right == NULL || curr_q->right == NULL)                //R
            {
                if(curr_p->right == NULL && curr_q->right == NULL)
                {
                    return;
                }
                else
                {
                    same_check = false;
                    return;
                }
            }
            else
            {
                preorder(curr_p->right, curr_q->right, same_check);
            }
        }
    }


};