#include <iostream>
#include <cstring>

using namespace std;

void printTree1(int numarray[], int numofnum);
void insert(int numarray[], int numofnum);
void siftup (int index, int heaparray[], int level, int numofnum);
int getParentIndex(int index); 

void printTree1(int numarray[], int numofnum) {
  if (/*numofnum <= 1&&*/ numofnum > 0) {
    for (int i = 0; i < 1; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 3 && */numofnum > 1) {
    for (int i = 1; i < 3; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 7 && */numofnum > 3) {
    for (int i = 3; i < 7; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 15 && */numofnum > 7) {
    for (int i = 7; i < 15; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 31 && */numofnum > 15) {
    for (int i = 15; i < 31; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 63 && */numofnum >31) {
    for (int i = 31; i < 63; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }
  if (/*numofnum <= 100 && */numofnum > 63) {
    for (int i = 63; i < 100; i++) {
      cout << numarray[i] << " ";
    }
    cout << endl;
  }

}

/*
void insert (int numarray[], int heaparray[], int numofnum) {
  if (numofnum <= 1 && numofnum > 0) {
    for (int i = 0; i < 1; i++) {
      heaparray[i] = numarray[i];
    }
  }
  if (/*numofnum <= 3 && numofnum > 1) {
    for (int i = 1; i < 3; i++) {
      heaparray[i] = numarray[i];
      if (heaparray[i] > heaparray[0]) {
	int largernum = heaparray[i];
	int smallernum = heaparray[0];
	heaparray[0] = largernum;
	heaparray[i] = smallernum;
      }
    }
  }
  if (/*numofnum <= 7 && numofnum > 3) {
    for (int i = 3; i < 7; i++) {
      for (int j = 1; j < 2; j++) {
	if (heaparray[i] > heaparray[j]) {
	  int l1 = heaparray[i];
	  int s1 = heaparray[j];
	  heaparray[j] = l1;
	  heaparray[i] = s1;
	}
      }
       if (heaparray[i] > heaparray[0]) {
        int largernum = heaparray[i];
        int smallernum = heaparray[0];
        heaparray[0] = largernum;
        heaparray[i] = smallernum;
      }
    }
  }
  
  cout << "Print new tree" << endl;
  printTree1(heaparray, numofnum);

}
*/


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


int main() {
  int numarray[100];
  int heaparray[100];
  bool done = false;
  int num;
  int numofnum;
  int i = 0;
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
  //printTree1(numarray, numofnum);
    insert(numarray, heaparray, numofnum);
  
  return 0;
}
