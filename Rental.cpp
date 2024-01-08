#include "Rental.h"

//====================================//

void createListPenyewa(listPenyewa &L){
    first(L) = NULL;
}

adrPenyewa newElmPenyewa(infotypeRenter x){
    adrPenyewa P = new penyewa;
    info(P) = x;
    next(P) = NULL;
    nextRel(P) = NULL;
    return P;
}

void insertLastPenyewa(listPenyewa &L, infotypeRenter x){
    adrPenyewa P = newElmPenyewa(x);
    adrPenyewa Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrPenyewa searchPenyewa(listPenyewa L, infotypeRenter x){
    adrPenyewa P = first(L);
    while(next(P) != NULL && info(P).NoKTP != x.NoKTP){
        P = next(P);
    }
    if(info(P).NoKTP == x.NoKTP){
        return P;
    }else{
        return NULL;
    }
}

void showSearchPenyewa(listPenyewa L, infotypeRenter x){
    adrPenyewa P = searchPenyewa(L, x);
    if(P != NULL){
        cout<<"`Penyewa dengan No. KTP "<<info(P).NoKTP<<" ditemukan`"<<endl;
    }else{
        cout<<"`Penyewa dengan No. KTP "<<x.NoKTP<<" tidak ditemukan`"<<endl;
    }
}

void showAllPenyewa(listPenyewa L){
    adrPenyewa P = first(L);
    int i = 1;
    cout<<"=======DATA PENYEWA======="<<endl;
    while(P != NULL){
        cout<<i<<". No.KTP: "<<info(P).NoKTP<<endl;
        cout<<"   Nama: "<<info(P).nama<<endl;
        P = next(P);
        i++;
    }
    cout<<"=========================="<<endl;
}

void deleteFirstPenyewa(listPenyewa &L, adrPenyewa P){
    adrPenyewa Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada penyewa`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastPenyewa(listPenyewa &L, adrPenyewa P){
    if(first(L) == NULL){
        cout<<"`Tidak ada penyewa`"<<endl;
    }else{
        adrPenyewa Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfterPenyewa(listPenyewa &L, adrPenyewa Prec, adrPenyewa P){
    if(first(L) == NULL){
        cout<<"`Tidak ada penyewa`"<<endl;
    }else{
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

//====================================//

void createListBarang(listBarang &L){
    first(L) = NULL;
}

adrBarang newElmBarang(infotype x){
    adrBarang P = new barang;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastBarang(listBarang &L, infotype x){
    adrBarang P = newElmBarang(x);
    adrBarang Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrBarang searchBarang(listBarang L, infotype x){
    adrBarang P = first(L);
    while(next(P) != NULL && info(P) != x){
        P = next(P);
    }
    if(info(P) == x){
        return P;
    }else{
        return NULL;
    }
}

void showSearchBarang(listBarang L, infotype x){
    adrBarang P = searchBarang(L, x);
    if(P != NULL){
        cout<<"`"<<info(P)<<" ditemukan`"<<endl;
    }else{
        cout<<"`Barang "<<x<<" tidak ditemukan`"<<endl;
    }
}

void showAllBarang(listBarang L){
    adrBarang P = first(L);
    int i = 1;
    cout<<"=======DATA BARANG======="<<endl;
    while(P != NULL){
        cout<<i<<". "<<info(P)<<endl;
        P = next(P);
        i++;
    }
    cout<<"========================="<<endl;
}

void deleteFirstBarang(listBarang &L, adrBarang P){
    adrBarang Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada barang`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

//====================================//

adrRelation newRelation(){
    adrRelation P = new relation;
    nextBar(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertRelation(adrPenyewa &P, adrBarang B){
    adrRelation R = newRelation();
    if(nextRel(P) == NULL){
        nextRel(P) = R;
        nextBar(R) = B;
    }else{
        adrRelation Q = nextRel(P);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = R;
        nextBar(R) = B;
    }
}

void showAllRelation(listPenyewa LP){
    cout<<"=======BARANG YANG DISEWA ORANG======="<<endl;
    if(first(LP) == NULL){
        cout<<"`Tidak ada orang yang menyewa barang`"<<endl;
    }else{
        adrPenyewa pP = first(LP);

        int i = 1;
        while(pP != NULL){
            cout<<i<<". No.KTP: "<<info(pP).NoKTP<<endl;
            cout<<"   Nama: "<<info(pP).nama<<endl;
            adrRelation rP = nextRel(pP);
            while(rP != NULL){
                cout<<"   -"<<info(nextBar(rP))<<endl;
                rP = next(rP);
            }
            i++;
            pP = next(pP);
            cout<<endl;
        }
    }
    cout<<"======================================"<<endl;
}

//====================================//

void searchRentalItems(listPenyewa LP, infotypeRenter x){
    adrPenyewa pP = searchPenyewa(LP, x);
    if(pP != NULL){
        int i = 1;
        adrRelation rP = nextRel(pP);
        cout<<"Barang yang disewa oleh "<<info(pP).nama<<" dengan No.KTP: "<<info(pP).NoKTP<<": "<<endl;
        while(rP != NULL){
            cout<<i<<". "<<info(nextBar(rP))<<endl;
            i++;
            rP = next(rP);
        }
    }else{
        cout<<"`Orang yang ingin dicari barang sewaannya tidak ditemukan`"<<endl;
    }
}

void countRentalItems(listPenyewa LP, infotypeRenter x){
    adrPenyewa pP = searchPenyewa(LP, x);
    if(pP != NULL){
        int i = 0;
        adrRelation rP = nextRel(pP);
        while(rP != NULL){
            i++;
            rP = next(rP);
        }
        cout<<"`Banyak barang yang disewa oleh "<<info(pP).nama<<" dengan No.KTP: "<<info(pP).NoKTP<<": "<<i<<"`"<<endl;
    }else{
        cout<<"`Orang yang ingin dihitung banyak barang sewaannya tidak ditemukan`"<<endl;
    }
}

void deleteAllRelation(listPenyewa LP, adrRelation &P, infotypeRenter x){
    adrPenyewa pP = searchPenyewa(LP, x);;
    if(pP != NULL){
        adrRelation rP = nextRel(pP);
        if(rP == NULL){
            cout<<"`Penyewa dengan No.KTP: "<<info(pP).NoKTP<<" tidak menyewa barang apapun`"<<endl;
        }else if(next(rP) == NULL){
            nextRel(pP) = NULL;
        }else{
            while(rP != NULL){
                P = rP;
                next(P) = NULL;
                rP = next(rP);
            }
            nextRel(pP) = NULL;
        }
        cout<<"`Semua barang yang disewa oleh "<<info(pP).nama<<" dengan No.KTP: "<<info(pP).NoKTP<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Orang yang ingin dihapus semua relasi(barang)nya tidak ditemukan`"<<endl;
    }
}

void deleteAllData(listPenyewa &LP, listBarang &LB, infotypeRenter x){
    adrPenyewa pP = searchPenyewa(LP, x);
    if(pP != NULL){
        adrBarang P, Prec;
        adrRelation rP = nextRel(pP);
        if(rP == NULL){
            cout<<"`Penyewa dengan No.KTP: "<<info(pP).NoKTP<<" tidak memiliki relasi`"<<endl;
        }else{
            while(rP != NULL){
                P = nextBar(rP);
                deleteFirstBarang(LB, P);
                rP = next(rP);
            }
        }
        adrRelation R;
        deleteAllRelation(LP, R, x);
        adrPenyewa J, Grec;
        J = first(LP);
        while(next(J) != NULL){
            J = next(J);
        }
        if(pP == first(LP)){
            deleteFirstPenyewa(LP, pP);
        }else if(pP == J){
            deleteLastPenyewa(LP, pP);
        }else{
            deleteAfterPenyewa(LP, Grec, pP);
        }
        cout<<"`Penyewa dengan nama "<<info(pP).nama<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Penyewa yang ingin dihapus semua datanya (Penyewa-Relasi-Barang) tidak ditemukan`"<<endl;
    }
}

int selectionMenu(){
    cout<<"================ INFORMATION ================"<<endl;
    cout<<"1. Membuat data penyewa"<<endl;
    cout<<"2. Membuat data barang"<<endl;
    cout<<"3. Memambahkan data barang yang disewa"<<endl;
    cout<<"4. Menampilkan semua data penyewa"<<endl;
    cout<<"5. Menampilkan semua data barang"<<endl;
    cout<<"6. Menampilkan semua data penyewa beserta barang yang disewa"<<endl;
    cout<<"7. Mencari dan menampilkan data penyewa"<<endl;
    cout<<"8. Mencari dan menampilkan data barang"<<endl;
    cout<<"9. Mencari dan menampilkan data barang yang disewa oleh orang tertentu"<<endl;
    cout<<"10. Menghitung dan menampilkan banyaknya barang yang disewa oleh orang tertentu"<<endl;
    cout<<"11. Mengahapus semua relasi (barang) yang digunakan oleh orang tertentu"<<endl;
    cout<<"12. Mengahapus semua data penyewa (Penyewa-Relasi-Barang)"<<endl;
    cout<<"0. Selesai"<< endl;
    cout<<"Pilih menu: ";
    int input = 0;
    cin>>input;
    return input;
}
