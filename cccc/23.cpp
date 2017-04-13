#include "cstdio"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
using namespace std;
int pre[300];
int mid[300];

struct Node
{
  struct Node* left;
  struct Node* right;
  int  v;
};

Node* creat(int* inorder, int* preorder, int length)
{
    if(length == 0)
    {
      return NULL;
    }
  Node* node = new Node;
  node->v = *preorder;
  int rootIndex = 0;
  for(;rootIndex < length; rootIndex++)
    {
      if(inorder[rootIndex] == *preorder)
      break;
    }
  node->left = creat(inorder, preorder +1, rootIndex);
  node->right = creat(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
  return node;
}
void dfs(Node * u)
{
    if(u==NULL)
        return ;
    if(u->left==NULL && u->right==NULL){
        return;
    }
    Node * tep;
    dfs(u->left);
    dfs(u->right);
    tep=u->left;
    u->left=u->right;
    u->right=tep;
}
int main ()
{
    Node * root;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&mid[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);

    root=creat(mid,pre,n);
    dfs(root);
    queue<Node *> qu;
    qu.push(root);
    vector<int> re;
    while(!qu.empty()){
        Node * cur=qu.front();
        qu.pop();
        re.push_back(cur->v);
        if(cur->left!=NULL)
            qu.push(cur->left);
        if(cur->right!=NULL){
            qu.push(cur->right);
        }

    }
    for(int i=0;i<re.size();i++){
        cout<<re[i];
        if(i<re.size()-1)
            cout<<" ";
    }
    return 0;
}
