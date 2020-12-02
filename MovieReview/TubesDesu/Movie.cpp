#include "Movie.h"

void createList(List_M &L) {
    first(L) = NULL;
}

addressM alokasiM(addressM &P, string judul, string durasi, string genre, string umur) {
    infotypeM X;
    X.judul = judul;
    X.durasi = durasi;
    X.genre = genre;
    X.umur = umur;
    P = new elmlist_Movie;
    info(P) = X;
    next(P) = NULL;

    return P;
}

void dealokasi(addressM &P) {
    next(P) = NULL;
    delete P;
}

void insertLast(List_M &L, addressM P) {
    if (first (L) == NULL) {
        first (L) = P;
        next (P) = P;
    } else {
        addressM Q = first(L);
        while (next(Q) != first (L)) {
            Q = next (Q);
        }
        next (P) = first (L);
        next (Q) = P;
    }
}

void deleteFirst(List_M &L, addressM &P) {
    if (next(first(L)) == first (L)) {
        P = first (L);
        next (P) = NULL;
        first (L) = NULL;
    } else {
        addressM Q = first (L);
        while (next(Q) != first (L)) {
            Q = next (Q);
        }
        P = first (L);
        next(Q) = next (P);
        first (L) = next (P);
        next (P) = NULL;
    }
}

void deleteTengah(List_M &L, addressM &P) {
    addressM Q = first (L);
    while (next (Q) != P) {
        Q = next (Q);
    }
    next (Q) = next (P);
    next (P) = NULL;
}

void deleteLast(List_M &L, addressM &P) {
    addressM Q;
    if (first(L) != NULL) {
        P = first(L);
        if(next(P) == NULL) {
            dealokasi(P);
            first(L) = NULL;
        } else {
            while(next(P) != NULL) {
                Q = P;
                P = next(P);
            }
            dealokasi(P);
            next(Q) = NULL;
        }
    }
}

void printInfo(List_M L) {
    int i = 1;
    addressM P = first(L);
    if(first(L)!= NULL) {
        do {
            cout << "Movie ke-" <<i<< endl;
            cout << "Judul  : "<< info(P).judul << endl;
            cout << "Durasi : "<< info(P).durasi << endl;
            cout << "Genre  : "<< info(P).genre << endl;
            cout << "Usia   : "<< info(P).umur << endl;
            cout << endl;
            P = next(P);
            i++;
        } while (P != first(L));
    } else {
        cout << "     Data Movie Kosong!!     " << endl;
    }
}

addressM findElm(List_M L, string cariJudul) {
    if(first(L) != NULL) {
        addressM Q = first(L);
        while((next(Q) != NULL) && (info(Q).judul != cariJudul)) {
            Q = next(Q);
        }
        if(info(Q).judul == cariJudul) {
            return Q;
        } else {
            /* Not Found */
            return NULL;
        }
    } else {
        /* List Kosong */
        return NULL;
    }
}




















