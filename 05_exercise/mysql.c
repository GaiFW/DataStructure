#include <stdio.h>
#incldue <my_global.h>
#include <mysql.h>

int main()
{
    MYSQL *con = mysql_init(NULL);
    printf("mysql client version :%s\n",mysql_get_client_info());
    printf("Hello world\n");
    exit(0);
    return 0;
}

