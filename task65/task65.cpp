/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {
    if(!root) {
        return nullptr;
    }

    return new Tree(root->val, solve(root->right), solve(root->left));
}