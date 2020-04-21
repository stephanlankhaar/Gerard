#include "common.h"


int main(int argc, char* argv[]) {
  initscr();
  
  mvprintw(100,0,"Welcome to Gerard, press f9 to open the menu and f8 to update homescreen. If you're done with the program press f5!");
  keypad(stdscr,true);

  // Get userinput and if <F9> is pressed open the menu.
  int userInput = getTaskId("\nMenu: ");
  do{
    switch(userInput){
      // Make a simple menu with the menuItems, and let the user select an item of the list
      case 49:
        clear();
        menu();
      case 57:
        clear();
        mvprintw(0,0,"Thanks for nothing!");
        getch();
        endwin();
        return 0;
      default:
        selectFromDb();
        getch();
        switch(userInput){
          case 57:
            clear();
            mvprintw(0,0,"Thanks for nothing!");
            getch();
            endwin();
            return 0;
          default:
            clear();
            menu();
        }
        break; 
    }
  }
  while(userInput!=57);
}
