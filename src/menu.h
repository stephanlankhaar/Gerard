#pragma once

#include "common.h"

using namespace std;

const char *menuItems[]={"1: New Task\n","2: Update Task\n","3: Delete Task\n","4: Update homescreen\n" "5: Exit\n"};
int y=0;

void menu(){
    clear();
    for(int i = 0; i<5; i++){
        printw(menuItems[i]);
    }
    int choice = getTaskId("Select a number from the menu: ");
    do{
    switch (choice)
    {
    case 49:
        getch();
        newTask();
        break;
    case 50:
        getch();
        updateTask();
        break;
    case 51:
        getch();
        deleteTask();
        break;
    case 52:
        getch();
        selectFromDb();
        getch();
        break;
    case 53:
        clear();
        printw("See ya!");
        getch();
        endwin();
        break;
    default:
        refresh();  
    }
    }
    while(choice!=53);
}
