/*Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
using namespace std;
/*
 * Definition for binary tree*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode* p1 = NULL;
        TreeNode* p2 = NULL;
        TreeNode* prev = NULL;
        this->inOrder(root, p1, p2, prev);

        printf("p1: %d, p2: %d \n", p1->val, p2->val);
        if (p1 != NULL && p2 != NULL)
        {
            printf("%d, %d \n", p1->val, p2->val);
            int temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;
        }

         printf("p1: %d, p2: %d \n", p1->val, p2->val);
    }

    void inOrder(TreeNode* root, TreeNode* &p1, TreeNode* &p2, TreeNode* &prev)
    {
        if (root == NULL)
            return;
        inOrder(root->left, p1, p2, prev);

        if (prev == NULL)
        {
            prev = root;

        }
        else
        {
            if (prev->val > root->val)
            {
                printf("Found inverse\n");
                if (!p1)
                    p1 = prev;
                p2 = root;
            }
            prev = root;
        }

        inOrder(root->right, p1, p2, prev);
    }

    void inOrderPrint(TreeNode* root){
        if (root == NULL) return;
        inOrderPrint(root->left);
        printf("%d ", root->val);
        inOrderPrint(root->right);
    }
};


int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node0(3);

    node0.left = &node1;
    node0.right = &node2;
    Solution sl;
     sl.inOrderPrint(&node0);
     printf("\n");
    sl.recoverTree(&node0);

    sl.inOrderPrint(&node0);
    return 0;
}


/*!
	The idea is that the in order traversal always give a increased array. We traverse the BST in order, find out if there is any inversion in the traversal.
	If there is any inversion, we mark them down. For two elements swapped by mistake, we should have two set of inversions typically.
	Two pointers are needed, one record previous element and the ohter records the current element during traversal. We compare the previous with current element.
	If preivous > current, that means an inversion occurs. For the first set of inversion, we record the previous element, i.e. the bigger one.
	For the second set of inversion, we record the current element, the smaller one. We swap the value of the two recorded nodes.
	
	There could be only one inversion two. In this case, only one recording is happenning. The first pointer will not be updated once assigned with a valid node, i.e. a non-NULL node
*/

