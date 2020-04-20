#pragma once

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
  fprintf(stderr, "%s", (const char*)data);    
    
  for(i = 0; i<argc; i++){    
     printf("%s = %s\r\n", azColName[i], argv[i] ? argv[i] : "NULL");    
  }    
  int taskId=atoi(argv[0]);    
  printf("\r\n");    
  return 0;    
}    

