#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <ncurses.h>
#include <string>

using namespace std;

static int idCallback(void *data, int argc, char**argv, char **azColName){
  int i;
  fprintf(stderr,"%s:", (const char*)data);

  for(i=0;i<argc;i++){
    printf("%i\r\n",atoi(argv[i]));
  }
  int taskId=atoi(argv[0]);
  printf("%i\r\n",taskId);
  return 0;
}

static int stdCallback(void *data, int argc, char **argv, char **azColName){
  int i;
  fprintf(stderr, "%s: ", (const char*)data);
   
  for(i = 0; i<argc; i++){
     printf("%s = %s\r\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  int taskId=atoi(argv[0]);
  printf("\r\n");
  return 0;
}
int getTaskId(){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;
  const char* data = "stdCallback function called";
  int taskId=0;

  /* Open database */
  rc = sqlite3_open("tasks.db", &db);
  
  if( rc ) {
     fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
     return(0);
  } else {
     fprintf(stderr, "Opened database successfully\r\n");
  }

  /* Create SQL statement */
  sql = "SELECT MAX(taskId) FROM tasks";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, idCallback, (void*)data, &zErrMsg);
  
  if( rc != SQLITE_OK ) {
     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
     sqlite3_free(zErrMsg);
  } else {
     fprintf(stdout, "Operation done successfully\r\n");
  }
  sqlite3_close(db);
  return taskId;
}

int selectFromDb(){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;
  const char* data = "stdCallback function called";

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
  rc = sqlite3_exec(db, sql, stdCallback, (void*)data, &zErrMsg);
  
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
  int taskId=6;
  char sql[500];
  snprintf(sql,500, "INSERT INTO tasks(`task`)"\
                    "VALUES('%s');",(newTask).c_str());
  //snprintf(sql,500 ,"INSERT INTO tasks(taskId,TASK) " \
        "VALUES (%d, '%s');",taskId, (newTask).c_str());
  //sql=strcat(strcat("INSERT INTO tasks(taskId,TASK) VALUES (1, '", newTask), "');");
  //sql = "INSERT INTO tasks(taskId,TASK) "  \
        "VALUES (1, '" + newTask + "'); ";

/*
 * INSERT INTO TASKS(ID, TASK) 
 * VALUES(1, "Test");
 *
 * printf("test");
 *
 */
  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, stdCallback, 0, &zErrMsg);
  
  if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
     sqlite3_free(zErrMsg);
  } else {
     fprintf(stdout, "Records created successfully\r\n");
  }
  return 0;
}

int main(int argc, char* argv[]) {
  initscr();

  writeToDb();
  getch();
  selectFromDb();
  getch();
  endwin();
  return 0;
}
