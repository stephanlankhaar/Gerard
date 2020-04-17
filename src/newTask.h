#pragma once

#include "common.h"

using namespace std;
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
