#include "common.h"


int main(int argc, char* argv[]) {
  initscr();

  const char *menuItems[]={"New Task","Update Task","Delete Task","Update homescreen"};
  int y=1;
  int choice;
  int highlight;
  
  printw("Welcome to Gerard, press f9 to open the menu and f8 to update homescreen. If you're done with the program press f5!");
  keypad(stdscr,true);

  // Get userinput and if <F9> is pressed open the menu.
  int userInput=wgetch(stdscr);
  do{
    switch(userInput){
      // Make a simple menu with the menuItems, and let the user select an item of the list
      case KEY_F(9):
        for(int i=0; i < 3; i++){
          if(i == highlight){
            wattron(stdscr,A_REVERSE);
            mvwprintw(stdscr,i+1,1,menuItems[i]);
            wattroff(stdscr, A_REVERSE);
          }
        }
        choice=wgetch(stdscr);
        switch(choice){
          case KEY_UP:
            highlight--;
            break;
          case KEY_DOWN:
            highlight++;
            break;
          default:
            break;
        }
        if (choice == 10){
          break;
        }
        clear();
        printw("You've selected %s",menuItems[highlight]);
        break;
      case KEY_F(8):
        // Print the database
        move(1,0);
        selectFromDb();
        getch();
        break;
      case KEY_F(5):
        // End the program
        clear();
        printw("Thanks for nothing");
        getch();
        endwin();
        return 0;
      default:
        break; 
  }
  }
  while(userInput!=KEY_F(5));
  //writeToDb();
  //getch();
  //getch();
  //endwin();
  //return 0;
}
