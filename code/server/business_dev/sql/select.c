#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int myfunc(void *p, int argc, char **argv, char **argvv)
{
	int i;
	*(int *)p = 0;
	for(i =0; i < argc; i++)
	{
		printf("%s = %s ", argvv[i], argv[i] ? argv[i] :"NULL");
	}
	putchar('\n');
	return 0;
}

int main(int argc, char *argv[])
{
	sqlite3 *db;
	char *err =0;
	int ret =0;
	int empty =1;

	// 实际路径请使用时配置
	ret = sqlite3_open("/home/wxw/Downloads/sqlite-autoconf-3071700/student", &db);
	if(ret != SQLITE_OK)
	{
		fputs("\n", stderr);
		exit(1);
	}
	else 
	    printf("open student successfully!\n");
	
	ret = sqlite3_exec(db, "select * from user;", myfunc, &empty, &err);

	if(ret != SQLITE_OK)
	{
		fputs(err,stderr);
		fputs("\n",stderr);
		sqlite3_close(db);
		exit(1);
	}

	if(empty)
	{
		fputs("table student is empty\n", stderr);
		exit(1);
	}

	sqlite3_close(db);

	return 0;
}
