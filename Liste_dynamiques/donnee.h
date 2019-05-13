#ifndef DONNEE_H_INCLUDED
#define DONNEE_H_INCLUDED
#pragma once

#include "logique.h"


//Déclaration des constantes
#define DELAI 6000

//Prototype des méthodes
extern void initialisation (Liste *liste);
extern int insListeVide (Liste *liste, tActor *donnee);
extern int insListe (Liste *liste, SDL_Renderer **renderer);

#endif // DONNEE_H_INCLUDED
