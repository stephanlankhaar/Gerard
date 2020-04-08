#include<ncurses.h>
#include<iostream>
#include<sqlite3.h>

using namespace std;

int main(){
  initscr();
  cbreak();

  char const * tasks[]={"Task 1", "Task 2", "Task 3"};
  WINDOW*menu=newwin(10,100,0,0);
  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu,true);

  int choise;
  int highlight;
  int y=1;
  for(int i=0; i < 3; i++){
    mvwprintw(menu, y,1,tasks[i]);
    y++;
  }

  int userInput=wgetch(menu);
  switch(userInput){
    case KEY_F(9):
      clear();
      mvprintw(0,0,"You've opened the menu Yay!");
      break;
    default:
      break;
  }

  wrefresh(menu);
  getch();
  endwin();
}
