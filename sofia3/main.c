#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comptage(char chaine[]);
int suppression(char chaine[],char chaineNettoyee[]);
int inversion(char chaine[],char chaineTemporaire[]);
int* positionPremierDernierIndice(char chaine[]);
int positionPremierDernierIndice2(char chaine[],int* indicePremier,int* indiceDernier);
int  placersouschaine(char chaine[],char souschaine[], char nouveaumot[],int indice);

int main()

{


    char chaine[81]; // pas besoin de vider la chaine car le gets remplace le contenu precedent
    char sschaine[81];// idem
    char motassemble[81];
    char string_indice[81];
    char chaineDeRemplacement[81]="";
    char chaineInversee[81]="";
    int compt=0;
    int b=0;
int indice;
    int premier;
    int dernier;

    int* tab;

    while (b==0)
    {
        puts("\nsaisir une chaine de caractere\n\n");
        gets(chaine);

        compt=comptage(chaine);// car compteru est une variable interne à la fonction, dc utilisable seulement dans fonction. On doit donc recuperer la valeur

        printf("nombre de e = %d \n\n",compt);

        suppression(chaine,chaineDeRemplacement);

        puts(chaineDeRemplacement);

        inversion(chaineDeRemplacement,chaineInversee);

        puts(chaineInversee);

        positionPremierDernierIndice2(chaineInversee,&premier,&dernier);// on a declare des int pour stocker et on donne les adresse pour que la fonction puisse modifier le contenu
        tab = positionPremierDernierIndice(chaineInversee);

        printf("premier %d dernier %d \n\n",premier,dernier); // car printf ne prend pas d'adresse en valeur donc on ajoute * pour avoir le contenu car premier et dernçier ont ete declares en adresse
        printf("premier %d dernier %d \n\n",tab[0],tab[1]);

        puts("\nsaisir la sous chaine de caractere\n\n");
        gets(sschaine);

                puts("\nsaisir l'indice\n\n");
                gets(string_indice);

            indice=atoi(string_indice);// transforme une chaine de car en int

         placersouschaine(chaine,sschaine,motassemble,indice);

         printf("\nle mot est : %s",motassemble);



    }

    return 0;

}




int comptage(char chaine[])

{

    int compteur=0;// compteur et pointeurchar sont des variables locales car on n'a besoin de ne donner que la chaine � la fonction et ensuite elle comptera
    char* pointeurChar;

    pointeurChar=strchr(chaine,'e');

    while (pointeurChar!=0)// car la fonction renvoie un pointeur null si la fonction n'a pas trouvé de caractere e
    {
        compteur++;
        pointeurChar++;// on incremente l'adresse pour que la fonction cherche dans la suite
        pointeurChar=strchr(pointeurChar,'e');
    }

    return compteur;
}

// AUTRE SOLUTION


int comptage2(char chaine[])

{

    int compteur=0;// compteur et pointeurchar sont des variables locales car on n'a besoin de ne donner que la chaine � la fonction et ensuite elle comptera
    char* pointeurChar;

    do
    {
        pointeurChar=strchr(chaine,'e');
        compteur++;
        pointeurChar++;// on incremente l'adresse pour que la fonction cherche dans la suite
    }
    while (pointeurChar!=0);// car la fonction renvoie un pointeur null si la fonction n'a pas trouvé de caractere e


    return compteur-1; // car même s'il y a 0 e, on passera toujours par compteur ++ avant le while à cause du do, donc on doit enlever une fois de trop
}



int suppression(char chaine[],char chaineNettoyee[])
{
    int i=0;
    int j=0;

    for (i=0; i<strlen(chaine); i++)
    {
        if (chaine[i]!='e')
        {
            chaineNettoyee[j]=chaine[i] ;
            j++;
        }
    }
    return 0;
}


int inversion(char chaine[],char chaineTemporaire[])
{
    int a=0;
    int b=0;

    for (a=strlen(chaine)-1; a>=0; a--)
    {
        chaineTemporaire[b]=chaine[a];
        b++;
    }
    return 0;
}

//AUTRE SOLUTION

int inversion2(char chaine[],char chaineTemporaire[])
{
    int a=0;
    int n=strlen(chaine)-1;
    for (a=n; a>=0; a--)
    {
        chaineTemporaire[n-a]=chaine[a];

    }
    return 0;
}

/* EX: si n=strlen(chaine)-1 et n=a POUR LA 1ERE ITERATION IE POINT DE DEPART QUI NE BOUGE PAS. si strlen=7
    a=6 et n=6 => n-a=0
    a-- => a=5 et n=6 => n-a=1
    ect*/




int* positionPremierDernierIndice(char chaine[])
{

    int indicePremier;
    int indiceDernier;

    // int tab[2] , ne marcherait pas car il s'agit d'une var local donc quand la fonction se termine, le contenu est efface et l'espace memoire est libere
    //donc l'acces est interdit dans le main
    //donc il faut allouer soi meme de l'espace memoire, qui ne sera jms libere à moins de faire un free
    int* tab;
    tab = (int*)calloc(2,8);


    indiceDernier=strlen(chaine)-1;// on initialise en enlevant le dernier caract�re qui est 0, m�me si il y a des blancs avant
    while (chaine[indiceDernier]==' ')
    {
        indiceDernier--; // on part de la fin
    }
    indicePremier=0; // on part du debut
    while (chaine[indicePremier]==' ')
    {
        indicePremier++;
    }
    indiceDernier++;// pour que l'indice 0 s'affiche comme premier caractère car 0eme indice est incomprehensible
    indicePremier++; // idem


    tab[1]=indiceDernier;
    tab[0]=indicePremier;

    return tab;// adresse du tableau tab[2]
}



//AUTRE SOLUTION
/*
La fonction cherche le premier et dernier caractere non blanc dans chaine et stocke les indices aux adresses indicepremier et indicedernier.
*/
int positionPremierDernierIndice2(char chaine[],int* indicePremier,int* indiceDernier)
{

    *indiceDernier=strlen(chaine)-1;// on a initialise indice en adresse donc si on veur travailler sur le ontenu, on doit ajoutrer *
    while (chaine[*indiceDernier]==' ')
    {
        (*indiceDernier)--; // on part de la fin
    }

    (*indicePremier)=0; // on part du debut

    while (chaine[*indicePremier]==' ')
    {
        (*indicePremier)++;
    }

    (*indiceDernier)++;// pour que l'indice 0 s'affiche comme premier caractère car 0eme indice est incomprehensible
    (*indicePremier)++; // idem


    return 0;
}




int placersouschaine(char chaine[],char souschaine[], char nouveaumot[],int indice)
{
    int i;
    int j=0;



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

    return 0;
}
