// insert.c
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main( void )
{
sqlite3 *db=NULL;
char *zErrMsg = NULL;
char *sql = NULL;
int rc;
rc = sqlite3_open("student", &db); //打开指定的数据库文件,如果不存在将创建一个同名的数据库文件
if( rc )
{
fprintf(stderr, "Can't open database: %s", sqlite3_errmsg(db));
sqlite3_close(db);
exit(1);
}
else printf("open student successfully!\n");

sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

//插入数据
sql = "INSERT INTO \"user\" VALUES( 111 , 'internet', 'passwd0011' );" ;
sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
sqlite3_close(db); //关闭数据库
return 0;
}

