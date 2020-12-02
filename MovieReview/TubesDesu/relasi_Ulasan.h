#ifndef RELASI_ULASAN_H_INCLUDED
#define RELASI_ULASAN_H_INCLUDED

#include "relasi_Ulasan.h"
#include "Movie.h"
#include "Reviewer.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define movie(P) P->movie
#define review(P) P->review
#define info(P) P->info

typedef string infotypeU;
typedef struct elmlist_Ulasan *addressU;

struct elmlist_Ulasan{
    infotypeU info;
    addressU next;
    addressM movie;
    addressR review;
};

struct List_U{
    addressU first;
};

void createList(List_U &L);
void insertFirst(List_U &L, addressU P);
void deleteUlasan(List_U &L, addressU &P);
void deleteUlasanMovie(List_U &L, addressM P);
void deleteRelasiReview(List_U &L, addressR P);

addressU alokasiU(addressM P, addressR C, infotypeU X);
void dealokasi(addressU &P);
addressU findElm(List_U L, addressM P, addressR C);
addressU findNoUlas(List_U L);
void printInfo(List_U L);
void printUlas(List_U L, addressR &P);
void printNoUlas(List_U L);

#endif // RELASI_ULASAN_H_INCLUDED
