#include<bits/stdc++.h>
using namespace std;

   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
TreeNode<int> *build(vector<int> &inorder, int inS, int inE, map<int, int> &mp,
                     vector<int> &postorder, int postS, int postE) {
  if (postS > postE || inS > inE)
    return nullptr;
  TreeNode<int>* root = new TreeNode<int>(postorder[postE]);

  int inInd=mp[root->data];
  int left=inInd - inS;

  root->left=build(inorder, inS, inInd-1, mp, postorder, postS,postS+left-1);
  root->right=build(inorder, inInd+1, inE, mp, postorder, postS+left,postE-1);

  return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	// Write your code here.
     //    Write your code here
  map<int, int> mp;
  for (int i = 0; i < inOrder.size(); i++) {
    mp[inOrder[i]] = i;
  }

  TreeNode<int> *root = build(inOrder, 0, inOrder.size() - 1, mp, postOrder, 0,
                              postOrder.size() - 1);
    return root;
}


int main(){
    int n;
    cin >> n;
    vector<int> in(n), post(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    TreeNode<int> *root = getTreeFromPostorderAndInorder(post, in);



    // Print level wise
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        cout << f->data << ":";
        if (f->left)
        {
            cout << "L:" << f->left->data << ",";
            q.push(f->left);
        }
        else
        {
            cout << "L:" << -1 << ",";
        }
        if (f->right)
        {
            cout << "R:" << f->right->data;
            q.push(f->right);
        }
        else
        {
            cout << "R:" << -1;
        }
        cout << endl;
    }   
    return 0;
}