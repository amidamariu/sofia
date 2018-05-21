#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chaine[81];
    char souschaine [81];
    char nouveaumot[81]="";
    int i;
    int b=1;
    int j=0;
    int indice;

    while (b==1)
    {
        printf("saisir une chaine de caractere \n");
        gets(chaine);

        printf("saisir une sous chaine \n");
        gets(souschaine);

        printf("saisir une position \n");
        scanf("%d",&indice);


        for (i=0; i<indice-1; i++) //jusqu'a la lettre avantr la position inseree, les lettres sont copiees dans un nouveau tableau
        {
            nouveaumot[j]=chaine[i];
            j++;
        }
        for (i=0; i<strlen(souschaine); i++) //la ss chaine est copiee en j ire le j eme caractere est le i eme caractere de ss chaine. ici, on ne prend pas en compte l'indice donne car ce for ne fait que copier la ss chaine
        {
            nouveaumot[j]=souschaine[i];
            j++;
        }
        for (i=indice-1; i<strlen(chaine); i++) //on recupere la fin de la chaine a partir de la position de copier de la ss chaine.
        {
            nouveaumot[j]=chaine[i];
            j++;
        }

        printf("\nla chaine est : %s \n",nouveaumot);
        puts(nouveaumot);
    }
    return 0;

}
