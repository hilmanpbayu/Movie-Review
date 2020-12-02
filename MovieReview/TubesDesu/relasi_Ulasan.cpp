#include "relasi_Ulasan.h"

void createList(List_U &L) {
    first(L) = NULL;
}

addressU alokasiU(addressM P, addressR C, infotypeU X) {
    addressU Q = new elmlist_Ulasan;
    review(Q) = C;
    movie(Q) = P;
    info(Q) = X;
    next(Q) = NULL;
    return Q;
}

void dealokasi(addressU &P) {
    movie(P) = NULL;
    review(P) = NULL;
    delete P;
    P = NULL;
}

void insertFirst(List_U &L, addressU P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List_U L) {
    if(first(L) != NULL) {
        addressU P = first(L);
        while(P != NULL) {
            cout << "Reviewer : "<< info(review(P)).nama << endl;
            cout << endl;
            cout << "Judul  : "<< info(movie(P)).judul << endl;
            cout << "Durasi : "<< info(movie(P)).durasi << endl;
            cout << "Genre  : "<< info(movie(P)).genre << endl;
            cout << "Usia   : "<< info(movie(P)).umur << endl;
            cout << endl;
            cout << "Ulasan : "<< info(P) <<endl;
            cout << endl;
            P = next(P);
        }
    } else {
        cout << "     View Kosong, Ulas Terlebih Dahulu!!     " << endl;
    }
}

addressU findNoUlas(List_U L) {
    if(first(L) != NULL) {
        addressU Q = first(L);
        while((next(Q) != NULL) && (info(Q) != "")) {
            Q = next(Q);
        }
        if(info(Q) == "") {
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

void printNoUlas(List_U L) {
    int i = 1;
    addressU Q = findNoUlas(L);
    if (first(L) != NULL) {
        do {
            cout << "Movie ke-" <<i<< endl;
            cout << "Judul  : "<< info(movie(Q)).judul << endl;
            cout << "Durasi : "<< info(movie(Q)).durasi << endl;
            cout << "Genre  : "<< info(movie(Q)).genre << endl;
            cout << "Usia   : "<< info(movie(Q)).umur << endl;
            cout << endl;
            Q = next(Q);
            i++;
        } while (Q != first(L));
    } else {
        cout << "     Tidak Ada Movie Yang Belum DiUlas!!     " << endl;
    }
}

addressU findElm(List_U L, addressM P, addressR C) {
    addressU Q = first(L);
    while(Q != NULL) {
        if(movie(Q)==P && review(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void printUlas(List_U L, addressR &P) {
    addressU U;
    addressU Q = first(L);
    U = Q;
    if (first(L) != NULL) {
        while (U != NULL) {
            Q = U;
            U = next(U);
            if (review(Q) == P) {
                /*while(Q != NULL) {
                    cout << "Reviewer : "<< info(review(Q)).nama << endl;
                    cout << endl;
                    cout << "Judul  : "<< info(movie(Q)).judul << endl;
                    cout << "Durasi : "<< info(movie(Q)).durasi << endl;
                    cout << "Genre  : "<< info(movie(Q)).genre << endl;
                    cout << "Usia   : "<< info(movie(Q)).umur << endl;
                    cout << endl;
                    cout << "Ulasan : "<< info(Q) <<endl;
                    cout << endl;
                    P = next(P);
                }*/
                printInfo(L);
            }
        }
    } else {
        cout << "     Tidak Ada Movie Yang DiUlas!!     " << endl;
    }
}

void deleteUlasan(List_U &L, addressU &P) {
    if (P != NULL) {
        if (first (L) == P) {
            first(L) = next (P);
            next(P) = NULL;
            dealokasi(P);
        } else {
            addressU Q = first(L);
            while ((Q != NULL) && (next(Q) != P)) {
                Q = next(Q);
            }
            next(Q) = next(P);
            dealokasi(P);
        }
    } else {
        cout << "     RELASI NOT FOUND!!     "<<endl;
    }
}

void deleteUlasanMovie(List_U &L, addressM P) {
    addressU U;
    addressU Q = first(L);
    U = Q;
    if (first(L) != NULL) {
        while (U != NULL) {
            Q = U;
            U = next (U);
            if (movie(Q) == P)
                deleteUlasan(L,Q);
        }
    }
}

void deleteRelasiReview(List_U &L, addressR P) {
    addressU U;
    addressU Q = first(L);
    U = Q;
    if (first(L) != NULL) {
        while (U != NULL) {
            Q = U;
            U = next(U);
            if (review(Q) == P)
                deleteUlasan(L,Q);
        }
    }
}




















































