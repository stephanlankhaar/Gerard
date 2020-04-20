#pragma once

#include "common.h"

using namespace std;

const char *menuItems[]={"1: New Task","2: Update Task","3: Delete Task","4: Update homescreen\n"};
int y=0;

void menu(){
    clear();
    for(int i = 0; i<4; i++){
        mvprintw(y++,0,menuItems[i]);
    }
    refresh();
    int choice = getTaskId("Select a number from the menu: ");
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
    default:
        break;
    }
}