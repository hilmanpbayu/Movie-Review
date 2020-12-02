#ifndef REVIEWER_H_INCLUDED
#define REVIEWER_H_INCLUDED

#include <iostream>
using namespace std;
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct dataReview {
    string username, nama, pass, email, umur;
};

typedef struct dataReview infotypeR;
typedef struct elmlist_Review *addressR;

struct elmlist_Review {
    infotypeR info;
    addressR next;
};

struct List_R {
    addressR first;
};

void createList(List_R &L);
void insertFirst(List_R &L, addressR P);
void deleteFirst(List_R &L, addressR &P);
void deleteLast(List_R &L, addressR &P);
void deleteTengah(List_R &L, addressR &P);

addressR alokasiR(addressR &P, string user, string nama, string pass, string email, string umur );
void dealokasi(addressR &P);
addressR findElm(List_R L, string cariUser);
addressR LogReview(List_R L, string cariUser, string cariPass);
void printInfo(List_R L);


#endif // REVIEWER_H_INCLUDED
