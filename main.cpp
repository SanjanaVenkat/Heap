#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void printTree1(int numarray[], int numofnum);
void insert(int numarray[], int numofnum);
void siftup (int index, int heaparray[], int level, int numofnum);
void siftdown (int index, int heaparray[], int level, int numofnum);
int getParentIndex(int index); 
void extract (int heaparray[], int numofnum);
int getLeftChildIndex(int index);
int getRightChildIndex(int index);

void printTree1(int numarray[], int numofnum) {
  int treelength = 0;
  

  if (/*numofnum <= 1&&*/ numofnum > 0) {
    for (int i = 0; i < 1; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
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



void insert (int numarray[], int heaparray[], int numofnum) {
  int level = 0;
  int index = 0;
  int i = 0;
  printTree1(numarray, numofnum);
  while (i < numofnum) {
    if (level == 0) {
      heaparray[index] = numarray[i];
      index++;
      i++;
      level++;
      
    }
    else {
      heaparray[index] = numarray[i];
      siftup(index, heaparray, level, numofnum);
      index++;
      i++;
      if (index == 3 || index == 7 || index == 15 || index == 31 || index == 63) {
	level++;
      }
    }
  }
  cout << "Printing tree" << endl;
  printTree1(heaparray, numofnum);

}


void siftup(int index, int heaparray[], int level, int numofnum) {
  
  int pindex = getParentIndex(index);
  if (heaparray[pindex] < heaparray[index]) {
    if (level == 1) {
      int s1 = heaparray[pindex];
      int l1 = heaparray[index];

      heaparray[index] = s1;
      heaparray[pindex] = l1;

       return;
    }
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

void extract (int heaparray[], int numofnum) {
  int index = 0;
  int level = 0;
  while (index < numofnum) {
    cout << "Root " << heaparray[0] << endl;
    numofnum = numofnum - 1;
    heaparray[0] = heaparray[numofnum];
    siftdown(index, heaparray, level, numofnum);
    //    cout << "Tree" << endl;
    //printTree1(heaparray, numofnum);
    
  }
}

void siftdown (int index, int heaparray[], int level, int numofnum) {

  int lindex = getLeftChildIndex(index);
  int rindex = getRightChildIndex(index);

  if (heaparray[rindex] > heaparray[lindex] && heaparray[rindex] > heaparray[index] && rindex < numofnum) {
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

  else if (heaparray[lindex] > heaparray[rindex] && heaparray[lindex] > heaparray[index] && lindex < numofnum) {
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



/*
void siftdown(int index, int heaparray[], int level, int numofnum) {
  while (numofnum > 0) {
  cout << "Root " << heaparray[0] << endl;
  numofnum = numofnum - 1;
   heaparray[0] = heaparray[numofnum];
   // printTree1(heaparray, numofnum);
  
  int lcindex = getLeftChildIndex(0);
    int rcindex = getRightChildIndex(0);
    bool done1 = true;
    bool done2 = true;
    int lcfirst = 0;
    int rcfirst = 0;

    if (lcindex <= numofnum) {
      if (lcfirst != 1) {
      if (heaparray[0] < heaparray[lcindex]) {
	int s1 = heaparray[0];
      int l1 = heaparray[lcindex];
      heaparray[0] = l1;
      heaparray[lcindex] = s1;
      lcfirst = 1;
      }
      done1 = true;
      while (done1 != false) {
	int lc = getLeftChildIndex(lcindex);
	if (lc <= numofnum) {
	  if (heaparray[lcindex] < heaparray[lc]) {
	    int s3 = heaparray[lcindex];
	    int l3 = heaparray[lc];
	      heaparray[lcindex] = l3;
	      heaparray[lc] = s3;
	      lcindex = lc;
	      done1 = true;
	  }
	  done1 = false;
	}
	done1 = false;
      }   
      }
      
      }
       

    if (rcindex <= numofnum) {
      if (rcfirst != 1) {
      if (heaparray[0] < heaparray[rcindex]) {
	int s2 = heaparray[0];
	int l2 = heaparray[rcindex];
	heaparray[0] = l2;
	heaparray[rcindex] = s2;
	rcfirst = 1;
      }
	done2 = true;
      while (done2 != false) {
        int rc = getRightChildIndex(rcindex);
        if (rc <= numofnum) {
          if (heaparray[rcindex] < heaparray[rc]) {
            int s4 = heaparray[rcindex];
            int l4 = heaparray[rc];
              heaparray[rcindex] = l4;
              heaparray[rc] = s4;
              rcindex = rc;
              done2 = true;
          }
          done2 = false;
        }
        done2 = false;
      }
       
      }
    }
    
  }  

    printTree1(heaparray, numofnum);
    

}

*/

int getParentIndex(int index) {
  int pindex;
  if (index == 1 || index == 2) {
    pindex = 0;
  }
  else if (index % 2 == 1) {
    pindex = (index - 1) / 2;
  }
  else if (index % 2 == 0) {
    pindex = (index-2) / 2;
  }
  return pindex;
}

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
  cout << "Enter 1 for command line and 2 for file" << endl;
  cin >> r;
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
  else if (r==2) {
    ifstream inData;
    cout << "Enter how many numbers you are entering" << endl;
  cin >> numofnum;
  cout << "Enter file name" << endl;
  cin >> filename;
  inData.open(filename);
  while (inData >> num) {
    numarray[i] = num;
    i++;
  }
  }
    insert(numarray, heaparray, numofnum);
    extract(heaparray, numofnum);
  return 0;
}
