#pragma once

#include "common.h"

using namespace std;

int getTaskId(string question){
  int idAnswer;
  printw("%s", (question).c_str() );
  idAnswer = getch();
  return idAnswer;
}

string updatedTask(string question_1){
  char answer[100];
  printw("%s",(question_1).c_str() );
  getstr(answer);
  return answer;
}

int updateFromDb(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char* data = "";

   /* Open database */
   rc = sqlite3_open("tasks.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\r\n");
   }

   /* Create merged SQL statement */
   char selectedId[20]={getTaskId("Type here the taskid: ")};
   getch();
   string updateTask = updatedTask("\nType the change here: ");
   char sql[500];
   snprintf(sql,500, "UPDATE tasks set task='%s' where taskId=%i;",(updateTask).c_str(),atoi(selectedId));
   //sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";

   getch();

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, stdCallback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\r\n");
   }
   sqlite3_close(db);
   return 0;
}

int main(){
  initscr();
  int input=getch();
  keypad(stdscr,true);
  if(input!=KEY_F(5)){
    selectFromDb();
  }
  updateFromDb();
  getch();
  getch();
  endwin();
  return 0;
}