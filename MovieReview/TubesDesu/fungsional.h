#ifndef FUNGSIONAL_H_INCLUDED
#define FUNGSIONAL_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

#include "Movie.h"
#include "Reviewer.h"
#include "relasi_Ulasan.h"

void header();
void LoginAdmin();
void LoginReview(List_R LR);
void SignUp();
void InsertFilm();
void ViewFilm();
void UpdateFilm();
void DeleteFilm();
void ViewReview();
void DeleteReview();
void inputUlasan(addressR &P);
void ViewUlasTotal();
void ViewUlas(addressR &P);
void ViewNoUlas();
void DeleteUmovie();
void UpdateAkun(addressR &P);
void LogoutAdmin();
void LogoutReview();
void thankyou();
void goMenu();

#endif // FUNGSIONAL_H_INCLUDED
