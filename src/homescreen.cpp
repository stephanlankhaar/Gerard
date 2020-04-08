#include<ncurses.h>
#include<iostream>
#include<sqlite3.h>
#include<string>

using namespace std;

int main(){
  initscr();
  cbreak();

  WINDOW * homescreen = newwin(20,50,0,0);
  box(homescreen,0,0);
  refresh();
  wrefresh(homescreen);
  keypad(homescreen,true);

  string choices[]={"task 1", "task 2", "task 3", "task 4"};
  int choice;
  int highlight;

  while(1){
    for(int i=0; i<3; i++){
      if(i==highlight){
        wattron(homescreen,A_REVERSE);
        mvprintw(i+1,1,choices[i].c_str());
        wattroff(homescreen,A_REVERSE);
      }
    }
    choice=wgetch(homescreen);
    switch(choice){
      case KEY_UP:
        highlight--;
        if(highlight ==-1){
          highlight=0;
        } 
        break;
      case KEY_DOWN:
        highlight++;
        if(highlight == 4){
          highlight =2;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  clear();

  printw("You've selected %s", choices[highlight].c_str());

  getch();
  endwin();
}
