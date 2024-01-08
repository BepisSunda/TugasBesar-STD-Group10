#include "Rental.h"

int main()
{
    //====================================//

    listPenyewa LP;
    createListPenyewa(LP);
    adrPenyewa pP;
    infotypeRenter dataPenyewa;

    //====================================//

    listBarang LB;
    createListBarang(LB);
    adrBarang bP;
    infotype dataBarang;

    //====================================//

    adrRelation rP;

    char YN;

    int input = selectionMenu();
    while(input != 0){
        switch(input){
        case 1:
            cout<<"Input No.KTP penyewa: ";
            cin>>dataPenyewa.NoKTP;
            cout<<"Input nama penyewa: ";
            cin>>dataPenyewa.nama;
            insertLastPenyewa(LP, dataPenyewa);
            cout<<endl;
            break;
        case 2:
            cout<<"input nama barang: ";
            cin>>dataBarang;
            insertLastBarang(LB, dataBarang);
            cout<<endl;
            break;
        case 3:
            cout<<"No.KTP Penyewa: ";
            cin>>dataPenyewa.NoKTP;
            cout<<"Barang yang disewa: ";
            cin>>dataBarang;
            pP = searchPenyewa(LP, dataPenyewa);
            bP = searchBarang(LB, dataBarang);
            insertRelation(pP, bP);
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            showAllPenyewa(LP);
            cout<<endl;
            break;
        case 5:
            cout<<endl;
            showAllBarang(LB);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            showAllRelation(LP);
            cout<<endl;
            break;
        case 7:
            cout<<"Masukkan No.KTP penyewa yang dicari: ";
            cin>>dataPenyewa.NoKTP;
            showSearchPenyewa(LP, dataPenyewa);
            cout<<endl;
            break;
        case 8:
            cout<<"Masukkan nama barang yang dicari: ";
            cin>>dataBarang;
            showSearchBarang(LB, dataBarang);
            cout<<endl;
            break;
        case 9:
            cout<<"Masukkan No.KTP penyewa yang ingin dicari data sewaannya: ";
            cin>>dataPenyewa.NoKTP;
            cout<<endl;
            searchRentalItems(LP, dataPenyewa);
            cout<<endl;
            break;
        case 10:
            cout<<"Masukkan No.KTP penyewa yang ingin dihitung banyak sewaannya: ";
            cin>>dataPenyewa.NoKTP;
            cout<<endl;
            countRentalItems(LP, dataPenyewa);
            cout<<endl;
            break;
        case 11:
            cout<<"Masukkan No.KTP penyewa yang ingin dihapus semua relasi(barang)nya: ";
            cin>>dataPenyewa.NoKTP;
            cout<<endl;
            deleteAllRelation(LP, rP, dataPenyewa);
            cout<<endl;
            break;
        case 12:
            cout<<"Masukkan No.KTP penyewa yang ingin dihapus semua data(Penyewa-Relasi-Barang)nya: ";
            cin>>dataPenyewa.NoKTP;
            cout<<endl;
            deleteAllData(LP, LB, dataPenyewa);
            cout<<endl;
            break;
        }
        input = selectionMenu();
    }
    return 0;
}
