#pragma once

//int selectFromDb(){
//  sqlite3 *db;
//  char *zErrMsg = 0;
//  int rc;
//  const char *sql;
//  const char* data = "stdCallback function called";
//                                 
//  /* Open database */
//  rc = sqlite3_open("tasks.db", &db);
//                                  
//  if( rc ) {
//     fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
//     return(0);
//  } else {
//     fprintf(stderr, "Opened database successfully\r\n");
//  }
//                                 
//  /* Create SQL statement */
//  sql = "SELECT * from TASKS";
//                                 
//  /* Execute SQL statement */
//  rc = sqlite3_exec(db, sql, stdCallback, (void*)data, &zErrMsg);
//                                  
//  if( rc != SQLITE_OK ) {
//     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
//     sqlite3_free(zErrMsg);
//  } else {
//     fprintf(stdout, "Operation done successfully\r\n");
//  }
//  sqlite3_close(db);
//  return(0);
//}

int selectFromDb(){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;
  const char* data = "";
                                 
  /* Open database */
  rc = sqlite3_open("tasks.db", &db);
                                  
  if( rc ) {
     fprintf(stderr, "Can't open database: %s\r\n", sqlite3_errmsg(db));
     return(0);
  } else {
     fprintf(stderr, "\r\n");
  }
                                 
  /* Create SQL statement */
  sql = "SELECT * from TASKS";
                                 
  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, stdCallback, (void*)data, &zErrMsg);
                                  
  if( rc != SQLITE_OK ) {
     fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
     sqlite3_free(zErrMsg);
  } else {
     fprintf(stdout, "\r\n");
  }
  sqlite3_close(db);
  return(0);
}
