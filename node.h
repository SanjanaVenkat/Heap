#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(int n);
  ~Node();
  Node* getNext();
  int getNum();
  void setNext(Node* newnext);
 private:
  Node* next;
  int number;
};


class TreeNode {
 public:
  TreeNode(char* t);
  ~TreeNode();
  TreeNode* getLeft();
  void setLeft(TreeNode* newleft);
  TreeNode* getRight();
  void setRight(TreeNode* newright);
  TreeNode* getUp();
  void setUp(TreeNode* newup);
  char* getOp();
 private:
  TreeNode* left;
  TreeNode* right;
  TreeNode* up;
  char treenum[1000];
};
