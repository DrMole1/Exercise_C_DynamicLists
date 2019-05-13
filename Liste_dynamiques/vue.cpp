#include "vue.h"


//Impl�mentation de la m�thode
//BUT : Copier chaque �l�ment de la liste dans le rendu
//ENTREE : La liste et le rendu
//SORTIE : La rendu
extern void renduListe(SDL_Renderer **renderer, Liste *liste)
{
    //d�claration des variables
    SDL_Rect position;
    Element *courant;

    //La valeur courante est initialis�e au d�but de la liste
    courant = liste->debut;

    //Tant que la valeur courante n'est pas NULL :
    while (courant != NULL)
    {
        //Affectation des diff�rentes variables ENTIERES au SDL_Rect position
        position.x = courant->donnee->Vect.nX;
        position.y = courant->donnee->Vect.nY;
        position.w = courant->donnee->width;
        position.h = courant->donnee->height;

        //Copie dans le rendu, de la dimension Z la plus �lev�e � la moins �lev�e
        SDL_RenderCopy(*renderer,courant->donnee->txActor,NULL,&position);

        //On va � la valeur courante suivante
        courant = courant->suivant;
    }
}
