#include "common.h"


int main(int argc, char* argv[]) {
  /* int userInput;
   * do{
   *   cout << "keuze 1" << endl << "keuze 2";
   *   cin >> userInput;
   *
   *   switch(userInput){
   *    case keypressed:
   *      iets
   *      getch();
   *      break;
   *   }
   * }
   * while(userInput!=27);
   *
   *
   *
   */






  initscr();
  // Make menu window named menu.
  printw("Welcome to Gerard, press f9 to open the menu and f8 to update homescreen");
  keypad(stdscr,true);

  // Get userinput and if <F9> is pressed open the menu.
  int userInput=wgetch(stdscr);
  do{
    switch(userInput){
      case KEY_F(9):
        clear();
        mvprintw(0,0,"You've opened the menu yesss!");
        getch();
        break;
      case KEY_F(8):
        move(1,0);
        selectFromDb();
        break;
      case KEY_F(5):
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
  getch();
  endwin();
  return 0;
}
