#include "common.h"


int main(int argc, char* argv[]) {
  initscr();

  writeToDb();
  getch();
  selectFromDb();
  getch();
  endwin();
  return 0;
}
