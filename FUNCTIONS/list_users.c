#include "sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void finish_with_error(MYSQL *conn)
{
  fprintf(stderr, "%s\n", mysql_error(conn));
  mysql_close(conn);
  exit(1);
}

int	list_users()
{
	MYSQL *conn;

	if ((conn = mysql_init(NULL)) == NULL)
	{
		fprintf(stderr, "Could not init DB\n");
		return (EXIT_FAILURE);
	}

	if (mysql_real_connect(conn, "localhost", "root", "root",
			"bibliotheque", 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "DB Connection Error\n");
		return (EXIT_FAILURE);
	}

	if (mysql_query(conn, "SELECT * FROM adherent"))
	{
		finish_with_error(conn);
	}

	MYSQL_RES *result = mysql_store_result(conn);

	if (result == NULL)
	{
		finish_with_error(conn);
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;

	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}

		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(conn);

	return 0;
}