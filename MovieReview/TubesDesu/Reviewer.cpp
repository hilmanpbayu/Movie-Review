#include "Reviewer.h"

void createList(List_R &L) {
    first(L) = NULL;
}

addressR alokasiR(addressR &P, string user, string nama, string pass, string email, string umur ) {
    infotypeR X;
    X.username = user;
    X.nama = nama;
    X.pass = pass;
    X.email = email;
    X.umur = umur;
    P = new elmlist_Review;
    info(P) = X;
    next(P) = NULL;

    return P;
}

void dealokasi(addressR &P) {
    next(P) = NULL;
    delete P;
}

void insertFirst(List_R &L, addressR P) {
    addressR Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void deleteFirst(List_R &L, addressR &P) {
    if (next(first(L)) == first (L)) {
        P = first (L);
        next (P) = NULL;
        first (L) = NULL;
    } else {
        addressR Q = first (L);
        while (next(Q) != first (L)) {
            Q = next (Q);
        }
        P = first (L);
        next(Q) = next (P);
        first (L) = next (P);
        next (P) = NULL;
    }
}

void deleteLast(List_R &L, addressR &P) {
    addressR Q;
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

void deleteTengah(List_R &L, addressR &P) {
    addressR Q = first (L);
    while (next (Q) != P) {
        Q = next (Q);
    }
    next (Q) = next (P);
    next (P) = NULL;
}

void printInfo(List_R L) {
    int i = 1;
    addressR P = first(L);
    if(first(L) != NULL) {
        do {
            cout << "Reviewer ke-" <<i<< endl;
            cout << "Username  : "<< info(P).username << endl;
            cout << "Nama      : "<< info(P).nama << endl;
            cout << "Umur      : "<< info(P).umur << endl;
            cout << "Email     : "<< info(P).email << endl;
            cout << endl;
            P = next(P);
            i++;
        } while(P != first(L));
    } else {
        cout << "     Data Reviewer Kosong!!     " << endl;
    }
}

addressR findElm(List_R L, string cariUser) {
    if(first(L) != NULL) {
        addressR Q = first(L);
        while((next(Q) != NULL) && (info(Q).username != cariUser)) {
            Q = next(Q);
        }
        if(info(Q).username == cariUser) {
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

addressR LogReview(List_R L, string cariUser, string cariPass) {
    if(first(L) != NULL) {
        addressR Q = first(L);
        while((next(Q) != NULL) && (info(Q).username != cariUser) && (info(Q).pass != cariPass)) {
            Q = next(Q);
        }
        if ((info(Q).username == cariUser) && (info(Q).pass == cariPass)) {
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












































