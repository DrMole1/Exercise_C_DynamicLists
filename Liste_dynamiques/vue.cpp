#include "vue.h"


//Implémentation de la méthode
//BUT : Copier chaque élément de la liste dans le rendu
//ENTREE : La liste et le rendu
//SORTIE : La rendu
extern void renduListe(SDL_Renderer **renderer, Liste *liste)
{
    //déclaration des variables
    SDL_Rect position;
    Element *courant;

    //La valeur courante est initialisée au début de la liste
    courant = liste->debut;

    //Tant que la valeur courante n'est pas NULL :
    while (courant != NULL)
    {
        //Affectation des différentes variables ENTIERES au SDL_Rect position
        position.x = courant->donnee->Vect.nX;
        position.y = courant->donnee->Vect.nY;
        position.w = courant->donnee->width;
        position.h = courant->donnee->height;

        //Copie dans le rendu, de la dimension Z la plus élevée à la moins élevée
        SDL_RenderCopy(*renderer,courant->donnee->txActor,NULL,&position);

        //On va à la valeur courante suivante
        courant = courant->suivant;
    }
}
