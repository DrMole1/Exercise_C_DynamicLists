#include "donnee.h"


//Implémentation de la méthode
//BUT : Initialiser une liste chainée
//ENTREE : La liste
//SORTIE : La liste initialisée
extern void initialisation (Liste *liste)
{
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}


//Implémentation de la méthode
//BUT : Ajouter un élément dans une liste vide
//ENTREE : La liste et l'actor
//SORTIE : La liste
extern int insListeVide (Liste *liste, tActor *donnee)
{
    Element *nouveau_element;
    if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
        return -1;
    if ((nouveau_element->donnee = (tActor *) malloc (50 * sizeof (tActor))) == NULL)
        return -1;
    nouveau_element->donnee = donnee;

    nouveau_element->suivant = NULL;
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;
    return 0;
}


//Implémentation de la méthode
//BUT : Ajouter un élément à la fin de la liste
//ENTREE : La liste, son élément courant et l'actor
//SORTIE : La liste
extern int insListe (Liste *liste, SDL_Renderer **renderer)
{
    SDL_Surface *Image = NULL;

    Element *nouveau_element;
    if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
        return -1;
    if ((nouveau_element->donnee = (tActor *) malloc (sizeof (tActor))) == NULL)
        return -1;
    nouveau_element->donnee->height = 500; //189
    nouveau_element->donnee->width = 375; //280
    nouveau_element->donnee->Vect.nX = 1; //20
    nouveau_element->donnee->Vect.nY = 1;

    //Chargement de l'image depuis le dossier du projet, c'est une surface
    Image = SDL_LoadBMP("hello.bmp");
    //On affecte la texture créée à partir de la surface à la donnée
    nouveau_element->donnee->txActor = SDL_CreateTextureFromSurface(*renderer,Image);
    //On libère la surface, on n'en a plus besoin
    SDL_FreeSurface(Image);


    nouveau_element->suivant = liste->debut;
    liste->debut = nouveau_element;
    liste->taille++;
    return 0;
}
