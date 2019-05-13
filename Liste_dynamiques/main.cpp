#include "logique.h"
#include "donnee.h"
#include "vue.h"


//Impl�mentation
//BUT : Cr�ation d'une liste dynamique et la coder avec la SDL
//ENTREE : L'environnement
//SORTIE : Une fen�tre
/*Enonc� 1 : cr�ation d'une liste dynamique (FIFO) de type tActor
Enonce 2 : utiliser la SDL afin de coder la vue*/
int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO); // D�marrage de la SDL (ici : chargement du syst�me vid�o)



    //Partie d�clarations des variables
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

    if( pWindow ) // D�s que la fen�tre est cr��e
    {
        while(blCont == true)  // Tant que le jeu continue
        {
            while (SDL_PollEvent(&event)) // Stockage des �v�nements :
            {
                switch(event.type)
                {
                    case SDL_QUIT:  // Pour fermer la fen�tre
                        blCont = false;
                        break;
                }
            }


            // Boucle de jeu :
            // La boucle POUR suivante peut recevoir plusieurs autres conditionnelles pour autant d'images � stocker dans la liste
            for(nCpt=0;nCpt<2;nCpt++)
            {
                if (nCpt == 0)
                {
                    //Initialisation des donn�es ENTIER
                    tempDonnee->height = 189;
                    tempDonnee->width = 280;
                    tempDonnee->Vect.nX = 20;
                    tempDonnee->Vect.nY = 20;
                    //Chargement de l'image depuis le dossier du projet, c'est une surface
                    Image = SDL_LoadBMP("Strikovic.bmp");
                    //On affecte la texture cr��e � partir de la surface � la donn�e
                    tempDonnee->txActor = SDL_CreateTextureFromSurface(renderer,Image);
                    //On lib�re la surface, on n'en a plus besoin
                    SDL_FreeSurface(Image);

                    //Appelle de la fonction d'insertion dans une liste vide (car nCpt = 0)
                    insListeVide(liste, tempDonnee);
                    printf("Element 1 insere\n");
                }

                else if (nCpt == 1)

                {
                    //pour ins�rer � la fin de la liste, toutes les images suivantes devront �tre impl�ment�es dans la liste avec cette m�thode
                    insListe (liste,&renderer);
                    printf("Element 2 insere\n");
                }
            }

            //M�thode pour copier toutes les images de la liste dans le rendu
            renduListe(&renderer, liste);
            // Affichage du rendu final
            SDL_RenderPresent(renderer);

            SDL_Delay(DELAI);
            blCont = false;


        }
    }

    SDL_DestroyWindow(pWindow); // Destruction de la fen�tre
    SDL_Quit(); // Arr�t de la SDL (lib�ration de la m�moire)
    return 1;
}


