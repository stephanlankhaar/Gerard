#include<iostream>
#include<ncurses.h>
#include<fstream>
#include<string>
#include<array>
using namespace std;

int readLargestIdFromFile(){
  int largestId = 0;
  string tmp;

  ifstream taskRead;
  taskRead.open("tasks.txt");

  /*
   * While tasks.txt is not at its end: store the lines in tmp.
   * Find the : in tmp.
   * Store the beginning of the line untill : in digits.
   * Convert string digits to int num.
   */
   while(!taskRead.eof()){
     taskRead >> tmp;

     int i = tmp.find(":");
     string digits = tmp.substr(0, i);
     int num = stoi(digits);

     if (largestId < num) largestId = num;
   }
   taskRead.close();
   return largestId;
}

int taskIdCounter(int setId){
  static int taskId=1; 
  if(setId){
    taskId=setId;
  }
  return taskId++;
}

int taskIdCounter(){
  return taskIdCounter(0);
}

string getUserInput(string question){
  char answer[100];
  printw("%s", (question).c_str() );
  getstr(answer);
  return answer;
}

void writeTaskToFile(){
  string newTask = getUserInput("Type your new task here: ");

  ofstream taskWrite("tasks.txt",ios_base::app); 
  taskWrite << taskIdCounter() << ":" << newTask << ":" << endl;
  taskWrite.close();
  taskIdCounter();
}

int main(){
  initscr();
  cbreak();

  taskIdCounter(readLargestIdFromFile()); // Check the largest id from the task file, and increase it with 1.
  writeTaskToFile();

  getch();
  endwin();
  return 0;
}
