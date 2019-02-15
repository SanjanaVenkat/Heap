#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;


int main() {
 TreeNode* treeroot = NULL;
 char doneentering[] = "DONE";
 char response[1000];
 int counter = 0;
 while (strcmp(doneentering, response) != 0) {
   if (counter != 100) {
   int newnum = 0;
   cout << "Enter a number" << endl;
   cin >> newnum;
   cout << "Enter 'c' if you want to continue adding numbers or 'DONE' to finish adding" << endl;
   cin >> response;
   counter++;
     }
 }
  return 0;
}
