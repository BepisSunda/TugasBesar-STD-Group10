#ifndef RENTAL_H_INCLUDED
#define RENTAL_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next
#define nextBar(P) P->nextBar
#define nextRel(P) P->nextRel
#define first(L) L.first

//====================================//

typedef string infotype;

typedef struct barang *adrBarang;
struct barang{
    infotype info;
    adrBarang next;
};

struct listBarang{
    adrBarang first;
};

//====================================//

typedef struct relation *adrRelation;
struct relation{
    adrBarang nextBar;
    adrRelation next;
};

//====================================//

struct Renter{
    int NoKTP;
    string nama;
};

typedef Renter infotypeRenter;

typedef struct penyewa *adrPenyewa;
struct penyewa{
    infotypeRenter info;
    adrPenyewa next;
    adrRelation nextRel;
};

struct listPenyewa{
    adrPenyewa first;
};

//====================================//

void createListPenyewa(listPenyewa &L);
adrPenyewa newElmPenyewa(infotypeRenter x);
void insertLastPenyewa(listPenyewa &L, infotypeRenter x);
adrPenyewa searchPenyewa(listPenyewa L, infotypeRenter x);
void showSearchPenyewa(listPenyewa L, infotypeRenter x);
void showAllPenyewa(listPenyewa L);
void deleteFirstPenyewa(listPenyewa &L, adrPenyewa P);
void deleteLastPenyewa(listPenyewa &L, adrPenyewa P);
void deleteAfterPenyewa(listPenyewa &L, adrPenyewa Prec, adrPenyewa P);

//====================================//

void createListBarang(listBarang &L);
adrBarang newElmBarang(infotype x);
void insertLastBarang(listBarang &L, infotype x);
adrBarang searchBarang(listBarang L, infotype x);
void showSearchBarang(listBarang L, infotype x);
void showAllBarang(listBarang L);
void deleteFirstBarang(listBarang &L, adrBarang P);

//====================================//

adrRelation newRelation();
void insertRelation(adrPenyewa &P, adrBarang B);
void showAllRelation(listPenyewa LP);

//====================================//

void searchRentalItems(listPenyewa LP, infotypeRenter x);
void countRentalItems(listPenyewa LP, infotypeRenter x);
void deleteAllRelation(listPenyewa LP, adrRelation &P, infotypeRenter x);
void deleteAllData(listPenyewa &LP, listBarang &LB, infotypeRenter x);
int selectionMenu();

#endif // RENTAL_H_INCLUDED
