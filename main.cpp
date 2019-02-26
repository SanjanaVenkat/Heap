//Sanjana Venkat
//2.26.19
//heap, creates tree with children always smaller than parent, prints numbers from tree greatest to least by extracting highest number from tree
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
//functions
void printTree1(int numarray[], int numofnum);
void insert(int numarray[], int numofnum);
void siftup (int index, int heaparray[], int level, int numofnum);
void siftdown (int index, int heaparray[], int level, int numofnum);
int getParentIndex(int index); 
void extract (int heaparray[], int numofnum);
int getLeftChildIndex(int index);
int getRightChildIndex(int index);

//prints tree
void printTree1(int numarray[], int numofnum) {
  int treelength = 0;
  
  //row one
  if (/*numofnum <= 1&&*/ numofnum > 0) {
    for (int i = 0; i < 1; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  //row two
  if (numofnum < 3) {
    treelength = numofnum;
  }
  else {
    treelength = 3;
  }
  
  if (/*numofnum <= 3 && */numofnum > 1) {
    for (int i = 1; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  //row three
if (numofnum < 7) {
    treelength = numofnum;
  }
  else {
    treelength = 7;
  }

  
  if (/*numofnum <= 7 && */numofnum > 3) {
    for (int i = 3; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  //row four
  if (numofnum < 15) {
    treelength = numofnum;
  }
  else {
    treelength = 15;
  }

  if (/*numofnum <= 15 && */numofnum > 7) {
    for (int i = 7; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  //row five
  if (numofnum < 31) {
    treelength = numofnum;
  }
  else {
    treelength = 31;
  }

  if (/*numofnum <= 31 && */numofnum > 15) {
    for (int i = 15; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }

  //row six
  if (numofnum < 63) {
    treelength = numofnum;
  }
  else {
    treelength = 63;
  }

  if (/*numofnum <= 63 && */numofnum >31) {
    for (int i = 31; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  //row seven
  if (numofnum < 100) {
    treelength = numofnum;
  }
  else {
    treelength = 100;
  }

  if (/*numofnum <= 100 && */numofnum > 63) {
    for (int i = 63; i < treelength; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }

}


//inserts numbers into tree where appropriate
void insert (int numarray[], int heaparray[], int numofnum) {
  int level = 0;
  int index = 0;
  int i = 0;
  //  printTree1(numarray, numofnum);
  //prints root of tree
  while (i < numofnum) {
    if (level == 0) {
      heaparray[index] = numarray[i];
      index++;
      i++;
      level++;
      
    }
    //adds numbers to the rest of the tree
    else {
      heaparray[index] = numarray[i];
      //moves numbers
      siftup(index, heaparray, level, numofnum);
      index++;
      i++;
      //moves down to next level as needed
      if (index == 3 || index == 7 || index == 15 || index == 31 || index == 63) {
	level++;
      }
    }
  }
  //prints tree
  cout << "Printing tree" << endl;
  printTree1(heaparray, numofnum);

}

//swaps number so that parent is always greater than children
void siftup(int index, int heaparray[], int level, int numofnum) {
  //gets index of parent node based on child node added to bottom of tree
  int pindex = getParentIndex(index);
  //if child is greater
  if (heaparray[pindex] < heaparray[index]) {
    //if child is new root, swaps and returns
    if (level == 1) {
      int s1 = heaparray[pindex];
      int l1 = heaparray[index];

      heaparray[index] = s1;
      heaparray[pindex] = l1;

       return;
    }
    //else swaps and continues to next level, recursive
    else {

       int s2 = heaparray[pindex];
      int l2 = heaparray[index];

      heaparray[index] = s2;
      heaparray[pindex] = l2;
       
siftup(pindex, heaparray, level - 1 , numofnum);
    }
  } 
    else if (heaparray[pindex] >= heaparray[index]) {
      
      return;
      }

  

}
//removes highest number from tree and prints it
void extract (int heaparray[], int numofnum) {
  int index = 0;
  int level = 0;
  cout << "Numbers from highest to lowest, printed from tree: " << endl;
  while (index < numofnum) {
    //prints root of tree (highest number)
    cout << heaparray[0]  << " ";
    numofnum = numofnum - 1;
    heaparray[0] = heaparray[numofnum];
    //makes root the highest number by swapping numbers
    siftdown(index, heaparray, level, numofnum);
    //    cout << "Tree" << endl;
    //printTree1(heaparray, numofnum);
    
  }
}
//moves highest number up, recursive to reorder tree
void siftdown (int index, int heaparray[], int level, int numofnum) {
  //gets children indexes of parent
  int lindex = getLeftChildIndex(index);
  int rindex = getRightChildIndex(index);
  //performs swap, right child 
  if (heaparray[rindex] >= heaparray[lindex] && heaparray[rindex] >= heaparray[index] && rindex < numofnum) {
    int s1 = heaparray[index];
    int l1 = heaparray[rindex];
    heaparray[index] = l1;
    heaparray[rindex] = s1;
  int li1 = getLeftChildIndex(rindex);
  int ri1 = getRightChildIndex(rindex);
  if (li1 > numofnum && ri1 > numofnum) {
    return;
  }
  else {
    siftdown (rindex, heaparray, level, numofnum);
  }
  }
  //performs swap, left child
  else if (heaparray[lindex] >= heaparray[rindex] && heaparray[lindex] >= heaparray[index] && lindex < numofnum) {
    int s2 = heaparray[index];
    int l2 = heaparray[lindex];
    heaparray[index] = l2;
    heaparray[lindex] = s2;
 int li2 = getLeftChildIndex(lindex);
  int ri2 = getRightChildIndex(lindex);
  if (li2 > numofnum && ri2 > numofnum) {
    return;
  }
  else {
    siftdown (lindex, heaparray, level, numofnum);
  }

  }
  else {
    return;
  }

}


//gets parent index from index of child
int getParentIndex(int index) {
  int pindex;
  //level 1
  if (index == 1 || index == 2) {
    pindex = 0;
  }
  //parents for other levels
  else if (index % 2 == 1) {
    pindex = (index - 1) / 2;
  }
  else if (index % 2 == 0) {
    pindex = (index-2) / 2;
  }
  return pindex;
}

//gets left child from parent index
int getLeftChildIndex(int index) {
  int lcindex;
  if (index == 0) {
    lcindex = 1;
  }
  else {
    lcindex = (index * 2) + 1;
  }
  return lcindex;
}

//gets right child from parent index
int getRightChildIndex(int index) {
  int rcindex;
  if (index == 0) {
    rcindex = 2;
  }
  else {
    rcindex = (index * 2) + 2;
  }
  return rcindex;
}



int main() {
  int numarray[100];
  int heaparray[100];
  bool done = false;
  int num;
  int numofnum;
  int i = 0;
  int response;
  char filename[1000];
  int r = 0;
  //call for file or command line entry of numbers
  cout << "You can enter numbers through the command line, or have a file that stores the numbers. You can have up to 100 numbers entered/stored. You will need to enter how many numbers you are going to be entering or have stored in the file." << endl;
  cout << endl;
  cout << "Enter 1 for command line and 2 for file" << endl;
  cin >> r;
  //command line
  if (r == 1) {
  cout << "Enter how many numbers you are entering" << endl;
  cin >> numofnum;
  cout << "Enter numbers" << endl;
  while (done == false) {
    cin >> num;
    numarray[i] = num;
    i++;
    if (i == 100 || i == numofnum) {
      done = true;
    }
  }
  cout << "Done reading numbers" << endl;
  }
  //file entry
  else if (r==2) {
    ifstream inData;
    cout << "Enter how many numbers are in the file" << endl;
  cin >> numofnum;
  cout << "Enter file name" << endl;
  cin >> filename;
  inData.open(filename);
  while (inData >> num) {
    numarray[i] = num;
    i++;
  }
  }

  //inserts numbers from either source
    insert(numarray, heaparray, numofnum);
    //reverse print from search tree
    extract(heaparray, numofnum);
  return 0;
}
