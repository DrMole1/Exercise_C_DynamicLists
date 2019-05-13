#include "logique.h"
#include "donnee.h"
#include "vue.h"


//Implémentation
//BUT : Création d'une liste dynamique et la coder avec la SDL
//ENTREE : L'environnement
//SORTIE : Une fenêtre
/*Enoncé 1 : création d'une liste dynamique (FIFO) de type tActor
Enonce 2 : utiliser la SDL afin de coder la vue*/
int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO); // Démarrage de la SDL (ici : chargement du système vidéo)



    //Partie déclarations des variables
    //====================================================================
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    bool blCont=true;
    Liste *liste = NULL;
    int nCpt=0;
    tActor *tempDonnee = NULL;
    SDL_Surface *Image = NULL;
    //====================================================================

    if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
        return -1;
    if ((tempDonnee = (tActor *) malloc (sizeof (tActor))) == NULL)
        return -1;

    printf("chargement...\n");
    initialisation(liste);
    printf("Liste initialisee\n");

    pWindow = SDL_CreateWindow("TP TDA",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(pWindow, -1, 0);

    if( pWindow ) // Dès que la fenêtre est créée
    {
        while(blCont == true)  // Tant que le jeu continue
        {
            while (SDL_PollEvent(&event)) // Stockage des événements :
            {
                switch(event.type)
                {
                    case SDL_QUIT:  // Pour fermer la fenêtre
                        blCont = false;
                        break;
                }
            }


            // Boucle de jeu :
            // La boucle POUR suivante peut recevoir plusieurs autres conditionnelles pour autant d'images à stocker dans la liste
            for(nCpt=0;nCpt<2;nCpt++)
            {
                if (nCpt == 0)
                {
                    //Initialisation des données ENTIER
                    tempDonnee->height = 189;
                    tempDonnee->width = 280;
                    tempDonnee->Vect.nX = 20;
                    tempDonnee->Vect.nY = 20;
                    //Chargement de l'image depuis le dossier du projet, c'est une surface
                    Image = SDL_LoadBMP("Strikovic.bmp");
                    //On affecte la texture créée à partir de la surface à la donnée
                    tempDonnee->txActor = SDL_CreateTextureFromSurface(renderer,Image);
                    //On libère la surface, on n'en a plus besoin
                    SDL_FreeSurface(Image);

                    //Appelle de la fonction d'insertion dans une liste vide (car nCpt = 0)
                    insListeVide(liste, tempDonnee);
                    printf("Element 1 insere\n");
                }

                else if (nCpt == 1)

                {
                    //pour insérer à la fin de la liste, toutes les images suivantes devront être implémentées dans la liste avec cette méthode
                    insListe (liste,&renderer);
                    printf("Element 2 insere\n");
                }
            }

            //Méthode pour copier toutes les images de la liste dans le rendu
            renduListe(&renderer, liste);
            // Affichage du rendu final
            SDL_RenderPresent(renderer);

            SDL_Delay(DELAI);
            blCont = false;


        }
    }

    SDL_DestroyWindow(pWindow); // Destruction de la fenêtre
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)
    return 1;
}


