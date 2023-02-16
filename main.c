#include "./FUNCTIONS/header.h"
#include </usr/local/mysql/include/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int choix;
	char nom[100];
	char livre[100];
	char auteur[100];
	char id[100];
	printf("Menu : \n");
	printf("1 - Liste de livre : \n");
	printf("2 - Liste des adhérents : \n");
	printf("3 - Ajout de livre : \n");
	printf("4 - Emprunt de livre : \n");
	printf("5 - Retour de livre : \n");

	switch (choix)
	{
	case 1:
		list_book();
		break ;
	case 2:
		list_users();
		break ;
	case 3:
        scanf("Livre %s", livre);
        scanf("Auteur %s", auteur);
		add_book(livre, auteur);
		break ;
	case 4:
        scanf("nom %s", nom);
        scanf("Livre %s", livre);
		emprunt_book(nom, livre);
		break ;
	case 5:
        scanf("id du retour %s", id);
		back_book(id);
		break ;
	}
}