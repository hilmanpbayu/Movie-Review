#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <iostream>
using namespace std;
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct dataMovie {
    string judul, durasi, genre, umur;
};

typedef struct dataMovie infotypeM;
typedef struct elmlist_Movie *addressM;

struct elmlist_Movie {
    infotypeM info;
    addressM next;
};

struct List_M {
    addressM first;
};

void createList(List_M &L);
void insertLast(List_M &L, addressM P);
void deleteFirst(List_M &L, addressM &P);
void deleteLast(List_M &L, addressM &P);
void deleteTengah(List_M &L, addressM &P);

addressM alokasiM(addressM &P, string judul, string durasi, string genre, string umur);
void dealokasi(addressM &P);
addressM findElm(List_M L, string cariJudul);
void printInfo(List_M L);


#endif // MOVIE_H_INCLUDED
