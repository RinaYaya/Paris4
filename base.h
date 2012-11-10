#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define vrai (0==0)
#define faux (!vrai)
typedef int Nat;
typedef Nat Bool;
typedef int Ent;
typedef float Reel;
typedef float Rat;
typedef char Car;
typedef Car * Chaine;
#define SIZEOF(x) ((Nat) (sizeof(x))
#define MALLOC(t) ((t*) malloc(sizeof(t)))
#define MALLOCN(n,t) ((t*)malloc((n)*sizeof(t)))
#define FREE(t) free(t)
#endif // BASE_H_INCLUDED
