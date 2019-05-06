#include "logique.h"
#include "donnee.h"
#include "vue.h"



//Implémentation
//BUT : Jeu défis
//ENTREE : L'environnement
//SORTIE : Une fenêtre
int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO); // Démarrage de la SDL (ici : chargement du système vidéo)



    //Partie déclarations des variables
    //====================================================================
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    bool blCont=true;
    //====================================================================

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





            SDL_RenderPresent(renderer);


        }
    }

    SDL_DestroyWindow(pWindow); // Destruction de la fenêtre
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)
    return 1;
}

