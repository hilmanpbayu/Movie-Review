#include "fungsional.h"

List_M LM;
List_R LR;
List_U LU;
addressM M;
addressR R;
addressU U;
char cek;

void header() {
    cout << "--------------------------------------------------" << endl;
    cout << "             Tubes STD Movie Reviewer             " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;
}

void LoginAdmin() {
    string user, pass;
    int pilih;

    system("CLS");
    header();
    cout<<"Selamat Datang Admin\nSilahkan Login...\n"<<endl;
    cout<<"==============LOGIN=============="<<endl;
    cout<<"Masukkan Username : "; cin>>user;
    cout<<"Masukkan Password : "; cin>>pass;
    cout<<"================================="<<endl;

    if(user != "Kimoy" && pass != "6969"){
        cout<<"\nGagal Masuk, Password atau Username Anda Salah!!"<<endl;
        getch();
    } else {
        cout<<"\nPassword dan Username Anda Cocok\nAnda Berhasil Masuk"<<endl;
        getch();
        do {
            system("CLS");
            header();
            cout<< "Selamat Datang, Admin (" << user << ")" << endl;
            cout<< endl;
            cout<<"|==================MENU=================|"<<endl<<
            " 1. Insert Data Movie"<<endl<<
            " 2. View Data Movie"<<endl<<
            " 3. Update Data Movie"<<endl<<
            " 4. Delete Data Movie"<<endl<<
            " 5. View Data Reviewer"<<endl<<
            " 6. Delete Data Reviewer"<<endl<<
            " 7. View Total Ulasan Movie"<<endl<<
            " 0. Logout"<<endl<<
            "Input Menu : ";
            cin >> pilih;
            cin.ignore(); cout<<endl;
            switch(pilih) {
                case 1 : InsertFilm(); break;
                case 2 : ViewFilm(); break;
                case 3 : UpdateFilm(); break;
                case 4 : DeleteFilm(); break;
                case 5 : ViewReview(); break;
                case 6 : DeleteReview(); break;
                case 7 : ViewUlasTotal(); break;
                case 0 : LogoutAdmin(); break;
                default : cout<<"Wrong Input!!"<<endl; break;
            }
            cout<<"\npress enter..."; getch();
            cout<<endl;
        }
        while (pilih != 0);
    }
}

void LogoutAdmin() {
    cout << "Anda Berhasil Logout!!" << endl;
    getch();
    goMenu();
}

void LoginReview(List_R LR) {
    string user, pass;
    int pilih;

    system("CLS");
    header();
    cout<<"Selamat Datang Reviewer\nSilahkan Login...\n"<<endl;
    cout<<"==============LOGIN=============="<<endl;
    cout<<"Masukkan USERNAME : "; getline(cin, user);
    cout<<"Masukkan PASSWORD : "; getline(cin, pass);
    cout<<"================================="<<endl;
    addressR Q = LogReview(LR, user, pass);
    if (Q == NULL) {
        cout << "   \nGagal Masuk, Password Atau Username Anda Salah!!     " << endl;
        getch();
        goMenu();
    } else {
        cout << " \n\nPASSWORD dan USERNAME Anda Cocok\nAnda Berhasil Masuk!!     " << endl;
        getch();
        do {
            system("CLS");
            header();
            cout<< "Anda Login sebagai (" << info(Q).username << ")" << endl;
            cout<< endl;
            cout<<"    ===MENU===   "<<endl<<
            " 1. Input Ulasan Movie"<<endl<<
            " 2. Hapus Ulasan Movie"<<endl<<
            " 3. View Movie Yang Sudah DiUlas"<<endl<<
            " 4. View Movie Yang Belum DiUlas"<<endl<<
            " 5. Update Akun"<<endl<<
            " 0. Logout"<<endl<<
            "Input Menu : ";
            cin >> pilih;
            cin.ignore(); cout<<endl;
            switch(pilih) {
                case 1 : inputUlasan(Q); break;
                case 2 : DeleteUmovie(); break;
                case 3 : ViewUlas(Q); break;
                case 4 : ViewNoUlas(); break;
                case 5 : UpdateAkun(Q); break;
                case 0 : LogoutReview(); break;
                default : cout<<"Wrong Input!!"<<endl; break;
            }
            cout<<"\npress enter..."; getch();
            cout<<endl;
        }
        while (pilih != 0);
    }
}

void LogoutReview() {
    cout << "Anda Berhasil Logout!!" << endl;
    getch();
    goMenu();
}

void SignUp() {
    string user, nama, pass, email, umur;
    system("CLS");
    header();
    cout << "---------------SIGN UP---------------";
    cout << endl;
    cout << "Masukkan Username : ";
    getline(cin, user);
    cout << "Masukkan Nama     : ";
    getline(cin, nama);
    cout << "Masukkan Umur     : ";
    getline(cin, umur);
    cout << "Masukkan Email    : ";
    getline(cin, email);
    cout << "Masukkan Password : ";
    getline(cin, pass);
    cout << endl;
    R = alokasiR(R, user, nama, pass, email, umur);
    insertFirst(LR, R);
    cout << "          *SIGN UP BERHASIL*\n          " << endl;
    if (first(LU) != NULL) {
        printInfo(LU);
    } else {
        cout << "View Film Beserta Ulasannya" << endl;
    }
    getch();
}

void InsertFilm() {
    string judul, durasi, genre, umur;
    system("CLS");
    header();
    cout << "-----TAMBAH DATA MOVIE-----" << endl;
    cout << endl;
    cout << "Masukkan Judul  : ";
    getline(cin, judul);
    cout << "Masukkan Durasi : ";
    getline(cin, durasi);
    cout << "Masukkan Genre  : ";
    getline(cin, genre);
    cout << "Masukkan Batas Umur : ";
    getline(cin, umur);
    cout << endl;
    M = alokasiM(M, judul, durasi, genre, umur);
    insertLast(LM,M);
    cout << "     *DATA TELAH DIMASUKKAN*     " << endl;
    getch();
}

void ViewFilm() {
    system("CLS");
    header();
    printInfo(LM);
}

void UpdateFilm() {
    system("CLS");
    header();
    if (first(LM) != NULL) {
        printInfo(LM);
        cout<<endl;
        cout<<"-----UPDATE DATA MOVIE-----\n"<<endl;
        cout << "Anda Yakin(y/n)?"; cin >> cek;
        cin.ignore();
        cout << endl;
        if (cek == 'y') {
            string cariJudul;
            cout<<"Masukkan Judul Movie yang ingin di Edit : ";
            getline(cin, cariJudul);
            addressM Q = findElm(LM, cariJudul);

            if (Q != NULL) {
                cout<<endl<<"Judul Movie Ditemukan"<<endl;
                cout << "Masukkan Judul  : ";
                getline(cin, info(Q).judul);
                cout << "Masukkan Durasi : ";
                getline(cin, info(Q).durasi);
                cout << "Masukkan Genre  : ";
                getline(cin, info(Q).genre);
                cout << "Masukkan Batas Umur : ";
                getline(cin, info(Q).umur);
                cout << endl;
                cout << "     *UPDATE MOVIE BERHASIL*     " << endl;
            } else {
                cout<<"     JUDUL MOVIE TIDAK DITEMUKAN!!     "<<endl;
            }
        } else {
             cout << "Kembali ke menu..." << endl;
        }
    } else {
        cout<<"     TIDAK ADA MOVIE YANG BISA DIEDIT!!     "<<endl;
    }
    getch();
}

void DeleteFilm() {
    string cariJudul;
    system("CLS");
    header();
    if (first(LM) != NULL) {
        printInfo(LM);
        cout<<endl;
        cout<<"-----DELETE DATA FILM-----\n"<<endl;
        cout << "Anda Yakin(y/n)?"; cin >> cek;
        cin.ignore();
        cout << endl;
        if (cek == 'y') {
            cout<<"Masukkan Judul Movie yang ingin di Hapus : ";
            getline(cin, cariJudul);
            addressM Q = findElm(LM, cariJudul);
            cout << endl;
            if (Q == NULL) {
                cout<<"     JUDUL MOVIE TIDAK DITEMUKAN!!     "<<endl;
                cout<<endl;
            } else if (Q == first(LM)) {
                deleteFirst(LM, Q);
                deleteUlasanMovie(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!     "<<endl;
            } else if (next(Q) == first(LM)) {
                deleteLast(LM, Q);
                deleteUlasanMovie(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!     "<<endl;
            } else {
                deleteTengah(LM, Q);
                deleteUlasanMovie(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!      "<<endl;
            }
        } else {
            cout << "Kembali ke menu..." << endl;
        }
    } else {
        cout<<"     TIDAK ADA MOVIE YANG BISA DIHAPUS!!\n     "<<endl;
    }
    getch();
}

void ViewReview() {
    system("CLS");
    header();
    printInfo(LR);
}

void DeleteReview() {
    string cariUser;
    system("CLS");
    header();
    if (first(LR) != NULL) {
        printInfo(LR);
        cout<<endl;
        cout<<"-----DELETE DATA REVIEWER-----\n"<<endl;
        cout << "Anda Yakin(y/n)?"; cin >> cek;
        cin.ignore();
        cout << endl;
        if (cek == 'y') {
            cout<<"Masukkan User Reviewer yang ingin di Hapus : ";
            getline(cin, cariUser);
            addressR Q = findElm(LR, cariUser);
            cout << endl;
            if (Q == NULL) {
                cout<<"     USER TIDAK DITEMUKAN!!     "<<endl;
                cout<<endl;
            } else if (Q == first(LR)) {
                deleteFirst(LR, Q);
                deleteRelasiReview(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!     "<<endl;
            } else if (next(Q) == first(LR)) {
                deleteLast(LR, Q);
                deleteRelasiReview(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!     "<<endl;
            } else {
                deleteTengah(LR, Q);
                deleteRelasiReview(LU, Q);
                cout<<"     !!DATA TELAH DIHAPUS!!      "<<endl;
            }
        } else {
            cout << "Kembali ke menu..." << endl;
        }
    } else {
         cout<<"     TIDAK ADA REVIEWER YANG BISA DIHAPUS!!\n     "<<endl;
    }
    getch();
}

void inputUlasan(addressR &P) {
    system("CLS");
    header();
    string nMovie, ulas;
    if (first(LM) != NULL) {
        printInfo(LM);
        cout<< "Masukkan Nama Movie : ";
        getline(cin, nMovie);
        addressM M = findElm(LM, nMovie);
        if (M == NULL) {
            cout<<"     JUDUL MOVIE TIDAK ADA!!     "<<endl;
            cout<<endl;
        } else {
            cout << "Isi Ulasan : ";
            getline(cin, ulas);
            U = alokasiU(M, P, ulas);
            insertFirst(LU, U);
            cout<<endl;
            cout<<"         MOVIE BERHASIL DIULAS!!    "<<endl;
        }
    } else {
        cout<<"     TIDAK ADA MOVIE YANG BISA DIULAS!!\n     "<<endl;
    }
    getch();
}

void ViewUlasTotal() {
    system("CLS");
    header();
    printInfo(LU);
}

void ViewUlas(addressR &P) {
    system("CLS");
    header();
    printUlas(LU, P);
}

void ViewNoUlas() {
    system("CLS");
    header();
    printNoUlas(LU);
}

void DeleteUmovie() {
    string cariJudul;
    system("CLS");
    header();
    printInfo(LR);
    cout<<endl;
    cout<<"-----DELETE ULASAN MOVIE-----"<<endl;
    cout << "Anda Yakin(y/n)?"; cin >> cek;
    cin.ignore();
    cout << endl;
    if (cek == 'y') {
        cout<<"Masukkan Judul Movie : ";
        getline(cin, cariJudul);
        addressM Q = findElm(LM, cariJudul);
        cout << endl;
        if (Q == NULL) {
            cout << "JUDUL MOVIE TIDAK DITEMUKAN!!" << endl;
            cout << endl;
        } else {
            deleteUlasanMovie(LU, Q);
            cout << "     ULASAN TELAH DIHAPUS!!     " << endl;
        }
    } else {
        cout << "Kembali ke menu..." << endl;
    }
    getch();
}

void UpdateAkun(addressR &P) {
    system("CLS");
    header();
    cout << "-----UPDATE AKUN-----\n" << endl;
    cout << "Username  : "<< info(P).username << endl;
    cout << "Nama      : "<< info(P).nama << endl;
    cout << "Umur      : "<< info(P).umur << endl;
    cout << "Email     : "<< info(P).email << endl;
    cout <<endl;
    cout <<"-----UPDATE AKUN-----\n"<<endl;
    cout << "Anda Yakin(y/n)?"; cin >> cek;
    cin.ignore();
    cout << endl;
    if (cek == 'y') {
        cout << "Masukkan Username : ";
        getline(cin, info(P).username);
        cout << "Masukkan Nama     : ";
        getline(cin, info(P).nama);
        cout << "Masukkan Umur     : ";
        getline(cin, info(P).umur);
        cout << "Masukkan Email    : ";
        getline(cin, info(P).email);
        cout << "Masukkan Password : ";
        getline(cin, info(P).pass);
        cout << endl;
        cout << "     *UPDATE AKUN BERHASIL*     " << endl;
    } else {
        cout << "Kembali ke menu..." << endl;
    }
    getch();
}

void thankyou() {
    cout << endl;
    cout << "TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI" << endl;
}

void goMenu() {
    int pilihan;
    List_M LM;
    List_R LF;
    List_U LU;

    createList(LM);
    createList(LF);
    createList(LU);

    do {
        system("CLS");
        header();
        cout << "============================" << endl;
        cout << "PROGRAM MENGELOLA DATA MOVIE" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "=====MENU=====" <<endl<<
        " 1. Login Admin" <<endl<<
        " 2. Login Reviewer" <<endl<<
        " 3. Sign Up" <<endl<<
        " 0. Exit" <<endl<<
        "Input Menu : ";
        cin >> pilihan;
        cin.ignore();
        switch(pilihan) {
            case 1 : LoginAdmin(); break;
            case 2 : LoginReview(LR); break;
            case 3 : SignUp(); break;
            case 0 : thankyou(); break;
            default : cout<<"Wrong Input"<<endl; break;
        }
        cout << endl;
    }while (pilihan != 0);
}
