#include </usr/local/mysql/include/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	MYSQL *conn;
	/*char *Titre = argv[0];
	char *Auteur = argv[1];*/

	char sql1[100] = "INSERT INTO emprunt(idAdht, idLivre, retourné) VALUES(";
	char sql2[] = "'Geoffroy'";
	strcat(sql1, sql2);
	char sql3[100] = ",";
	strcat(sql1, sql3);
	char sql4[100] = "'les tulipes', '0'";
	strcat(sql1, sql4);
	char sql5[100] = ")";
	strcat(sql1, sql5);

	if ((conn = mysql_init(NULL)) == NULL)
	{
		fprintf(stderr, "Could not init DB\n");
		return (EXIT_FAILURE);
	}

	if (mysql_real_connect(conn, "localhost", "root", "2001ageo",
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