#include<iostream>
//#include<ncurses>
#include<fstream>
#include<string>
#include<algorithm>
#include<array>
using namespace std;
int Array(int arraySize, int newSize){
  arraySize=1;
  newSize=arraySize++;
  newSize++;

  return newSize;
}

int main(){
  int newSize = Array();
  cout << newSize;
  //int taskId[10];
  //int sizeTaskId=sizeof(taskId)/sizeof(taskId[0]);
  //string task[10];

  //ifstream taskData("tasks.txt");
  //for (int i=0; i<sizeTaskId;i++){
  //  taskData>>taskId[i]>>task[i];
  //  cout << taskId[i] << " " << task[i] << endl;
  //}

  //int max= *max_element(taskId,taskId+sizeTaskId);

  //cout << sizeTaskId << " " << max << endl;
  //initscr();
  //cbreak();


}
