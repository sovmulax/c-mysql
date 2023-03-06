#include "sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	emprunt_book(char a[200], char b[200]){
	MYSQL *conn;
	/*char *Titre = argv[0];
	char *Auteur = argv[1];*/

	char sql1[100] = "INSERT INTO emprunt(idAdht, idLivre, retourné) VALUES('";
	char *sql2 = a;
	strcat(sql1, sql2);
	char sql3[100] = "','";
	strcat(sql1, sql3);
	char *sql4 = b;
	strcat(sql1, sql4);
	char sql5[100] = "', '0')";
	strcat(sql1, sql5);

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

	printf("%s", sql1);

	if (mysql_query(conn, sql1) != 0)
	{
		fprintf(stderr, "Query Failure\n");
		return (EXIT_FAILURE);
	}
	mysql_close(conn);

	return 0;
}