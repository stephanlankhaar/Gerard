#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <ncurses.h>
#include <string>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){
  int i;
  fprintf(stderr, "%s: ", (const char*)data);
   
  for(i = 0; i<argc; i++){
     printf("%s = %s\r\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
   
  printf("\r\n");
  return 0;
}

int selectFromDb(){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;
  const char* data = "Callback function called";

  /* Open database */
  rc = sqlite3_open("tasks.db", &db);
  
  if( rc ) {
     fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
     return(0);
  } else {
     fprintf(stderr, "Opened database successfully\r\n");
  }

  /* Create SQL statement */
  sql = "SELECT * from TASKS";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
  
  if( rc != SQLITE_OK ) {
     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
     sqlite3_free(zErrMsg);
  } else {
     fprintf(stdout, "Operation done successfully\r\n");
  }
  sqlite3_close(db);
  return(0);
}

string getUserInput(string question){
  char answer[100];
  printw("%s", (question).c_str() );
  getstr(answer);
  return answer;
}

int writeToDb(){
  string newTask = getUserInput("Type your new task here: ");
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  /* Open database */
  rc = sqlite3_open("tasks.db", &db);
  
  if( rc ) {
    fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
    return(0);
  } else {
    fprintf(stderr, "Opened database successfully\r\n");
  }

  /* Create SQL statement */
  int taskId=1;
  char sql[500];
  snprintf(sql,500 ,"INSERT INTO tasks(taskId,TASK) " \
        "VALUES (%d, '%s');",taskId, (newTask).c_str());
  //sql=strcat(strcat("INSERT INTO tasks(taskId,TASK) VALUES (1, '", newTask), "');");
  //sql = "INSERT INTO tasks(taskId,TASK) "  \
        "VALUES (1, '" + newTask + "'); ";

        cout << "test";
/*
 * INSERT INTO TASKS(ID, TASK) 
 * VALUES(1, "Test");
 *
 * printf("test");
 *
 */
  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  
  if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
     sqlite3_free(zErrMsg);
  } else {
     fprintf(stdout, "Records created successfully\r\n");
  }
  sqlite3_close(db);
  return 0;
}

int main(int argc, char* argv[]) {
  initscr();

  writeToDb();
  selectFromDb();

  getch();
  endwin();
  return 0;
}
