#ifndef LOGIQUE_H_INCLUDED
#define LOGIQUE_H_INCLUDED
#pragma once

//Implémentation des bibliothèques
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



//Déclaration des constantes



//Prototype des méthodes

#endif // LOGIQUE_H_INCLUDED
