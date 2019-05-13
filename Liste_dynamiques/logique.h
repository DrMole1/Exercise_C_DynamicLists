#ifndef LOGIQUE_H_INCLUDED
#define LOGIQUE_H_INCLUDED
#pragma once

//Impl�mentation des biblioth�ques
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tVector{
    int nX;
    int nY;
}tVector;

typedef struct tActor{
    SDL_Texture* txActor;
    tVector Vect;
    int height;
    int width;
}tActor;

typedef struct ElementListe {
    tActor *donnee;
    struct ElementListe *suivant;
}Element;

typedef struct ListeRepere {
    Element *debut;
    Element *fin;
    int taille;
}Liste;



//D�claration des constantes



//Prototype des m�thodes

#endif // LOGIQUE_H_INCLUDED
