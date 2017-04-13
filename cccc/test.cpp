#include <iostream>
#include <cstring>
using namespace std;
char pre[50] = "ABDHLEKCFG";        //前序序列
  char mid[50] = "HLDBEKAFCG";        //中序序列
  char post[50] = "LHDKEBFGCA";        //后序序列

  typedef struct _Node
  {
      char v;
     struct _Node *left;
      struct _Node *right;
  }Node, *PNode;

  void PostTravelTree(PNode pn);        //树的后序递归遍历
  void PreTravelTree(PNode pn);        //树的前序递归遍历
  void PreMidCreateTree(PNode &pn, int i, int j, int len);        //利用前序中序序列创建树
  void PostMidCreateTree(PNode &pn, int i, int j, int len);        //利用后序中序序列创建树
  int Position(char c);                //确定c在中序序列mid中的下标,假设树的各个节点的值各不相同


  int main()
  {
      PNode root1 = NULL, root2= NULL;

      PreMidCreateTree(root1, 0, 0, strlen(mid));
        PostTravelTree(root1); cout<<endl;
      //PostMidCreateTree(root2, strlen(post)-1, 0, strlen(mid));
      //PreTravelTree(root2); cout<<endl;

      return 0;
  }


  int Position(char c)
  {
      return strchr(mid,c)-mid;
  }



  void PreMidCreateTree(PNode &pn, int i, int j, int len)
  {
      if(len <= 0)
          return;

      pn = new Node;
      pn->v = pre[i];
      int m = Position(pre[i]);
      PreMidCreateTree(pn->left, i+1, j, m-j);            //m-j为左子树字符串长度
      PreMidCreateTree(pn->right, i+(m-j)+1, m+1, len-1-(m-j));    //len-1-(m-j)为右子树字符串长度
  }



  void PostMidCreateTree(PNode &pn, int i, int j, int len)
  {
      if(len <= 0)
          return;

      pn = new Node;
      pn->v = post[i];
      int m = Position(post[i]);
      PostMidCreateTree(pn->left, i-1-(len-1-(m-j)), j, m-j);//注意参数:m-j左子树的长度,len-1-(m-j)右子树的长度
      PostMidCreateTree(pn->right, i-1, m+1, len-1-(m-j));
  }


  void PostTravelTree(PNode pn)        //后序递归遍历
  {
      if(pn)
      {
          PostTravelTree(pn->left);
          PostTravelTree(pn->right);
          cout<<pn->v<<" ";
      }
  }


  void PreTravelTree(PNode pn)        //前序递归遍历
  {
      if(pn)
     {
         cout<<pn->v<<" ";
         PreTravelTree(pn->left);
         PreTravelTree(pn->right);
     }
 }
