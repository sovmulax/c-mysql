#include "sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char choix[100];
	char nom[100];
	char prenom[100];
	char livre[100];
	char auteur[100];
	int boo = 1;

	while (boo == 1)
	{
		printf("🔢 Menu : \n");
		printf("1️⃣ - Ajout d'adherent : \n");
		printf("2️⃣ - Liste des adherents : \n");
		printf("3️⃣ - Ajout de livre : \n");
		printf("4️⃣ - Liste des livres : \n");
		printf("5️⃣ - Emprunté un livre : \n");
		printf("6️⃣ - Retourné un livre : \n");
		printf("7️⃣ - Les emprunts en cour: \n");
		printf("➡️ ");
		scanf("%s", choix);

		switch (atoi(choix))
		{
		case 1:
			printf("Le nom de l'adhérent\n");
			printf("➡️ ");
			scanf("%s", nom);
			printf("Le prenom de l'adhérent\n");
			printf("➡️ ");
			scanf("%s", prenom);

			ajout_user(nom, prenom);
			break ;
		case 2:
			list_adh();
			break ;
		
		case 3:
			printf("L'intitulé du \n");
			printf("➡️ ");
			scanf("%s", livre);
			printf("Le nom de l'auteur\n");
			printf("➡️ ");
			scanf("%s", auteur);
			ajout_livre(livre, auteur);
			break ;

		case 4:
			list_lives();
			break ;

		case 5:
			printf("Le nom de l'utilisateur \n");
			printf("➡️ ");
			scanf("%s", nom);
			printf("L'intitulé du livre\n");
			printf("➡️ ");
			scanf("%s", auteur);
			emprunts(nom, auteur);
			break ;

		case 6:
			printf("Le nom de l'adhérent\n");
			printf("➡️ ");
			scanf("%s", livre);
			break ;

		case 7:
			list_emprunt();
			break ;
		}

		printf(" ⚠️ Voulez-vous continuer ? (0 ou 1) \n");
		printf("➡️ ");
		scanf("%d", &boo);

		if(boo == 0){
			return 0;
		}
	}
	return (0);
}