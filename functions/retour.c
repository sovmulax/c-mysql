#include "sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	retour(int a)
{
	sqlite3	*db;
	char	*err_msg;
	char	*sql;
	size_t	sz;
	int		rc;
	int		price;
	char	*type;


	err_msg = 0;
	//requete
	sz = snprintf(NULL, 0, "DELETE FROM emprunt WHERE id = %d", a);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "DELETE FROM emprunt WHERE id = %d", a);
	
	//work
	rc = sqlite3_open("./bible.db", &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return (1);
	}

	printf("✅ %s\n", sql);

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return (1);
	}

	sqlite3_close(db);
		
	return (0);
}