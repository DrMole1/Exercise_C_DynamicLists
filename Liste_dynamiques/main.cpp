#include "logique.h"
#include "donnee.h"
#include "vue.h"



//Impl�mentation
//BUT : Jeu d�fis
//ENTREE : L'environnement
//SORTIE : Une fen�tre
int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO); // D�marrage de la SDL (ici : chargement du syst�me vid�o)



    //Partie d�clarations des variables
    //====================================================================
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    bool blCont=true;
    //====================================================================

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





            SDL_RenderPresent(renderer);


        }
    }

    SDL_DestroyWindow(pWindow); // Destruction de la fen�tre
    SDL_Quit(); // Arr�t de la SDL (lib�ration de la m�moire)
    return 1;
}

