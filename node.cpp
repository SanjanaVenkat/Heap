#include <iostream>
#include <cstring>
#include "node.h"

TreeNode::TreeNode(char* t) {
  left = NULL;
  right = NULL;
  up = NULL;
  strcpy(treenum, t);
}

TreeNode::~TreeNode() {
  left = NULL;
  right = NULL;
  up = NULL;
}

void TreeNode::setLeft(TreeNode* newleft) {
  left = newleft;
}

void TreeNode::setRight(TreeNode* newright) {
  right = newright;
}

void TreeNode::setUp(TreeNode* newup) {
  up = newup;
}

TreeNode* TreeNode::getLeft() {
  return left;
}

TreeNode* TreeNode::getRight() {
  return right;
}

TreeNode* TreeNode::getUp() {
  return up;
}

char* TreeNode::getOp() {
  return treenum;
}
