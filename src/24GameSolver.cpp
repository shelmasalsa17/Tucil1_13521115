#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "function.cpp"
using namespace std;
//Inisiasi Awal
char operation[4];
double value[4];
double penyimpan[24][4];
//Program Utama
int main(int argc, char const *argv[]){
    asciiArt();
    bool exit = false;
    while(!exit){
        int input;
        int start;
        cout << "****Tekan 1 untuk bermain, atau 2 keluar dari 24Game Solver ini ****" << endl;
        cout << "1.Main" << endl;
        cout << "2.Keluar" << endl;
        cin >> start; 
        if(start == 1)
        {
            cout << "Hallo berikan input 4 angka pada 24GameSolver" << endl; 
            cout << "Pilih jenis Inputan yang kamu inginkan : " << endl;
            cout << "1. Random " << endl;
            cout << "2. Input Sendiri" << endl;
            cin >> input;
            srand(time(0));
            if(input == 1){
                for(int i = 0; i < 4; i++){
                    value[i] = (rand()%12) + 1;}
                for(int i = 0; i < 4; i++){
                    cout << "Bilangan random " << i+1 << ":" << endl;
                    printRandom(value,i);}}
            else if(input == 2){
                inputPegguna(value);}
            int output;
            cout << "Hallo pilih keluaran yang kamu inginkan" << endl;
            cout << "1.Terminal" << endl; 
            cout << "2.Text" << endl;
            cin >> output;
            clock_t startTime = clock();
            //Mengcover jika output pengguna ingin ditampilkan di file
            ofstream myFile;
            int hasil = 24;
            if(output == 2){
                string namaFile;
                string file;
                cout << "Masukkan nama file : " << endl;
                cin >> namaFile;
                file = "../test/" + namaFile;
                myFile.open(file);}
            //Assign nilai-nilai array operator
            operation[0] = '+';
            operation[1] = '-';
            operation[2] = '*';
            operation[3] = '/';
            //Untuk jumlah di awal
            if (countSolution(penyimpan, value, operation) == 0){
                if(output == 1){
                    cout << "Maaf tidak ditemukan solusi" << endl << endl;}
                else if(output == 2){
                    myFile << "Maaf tidak ditemukan solusi" << endl << endl;}}
            else{
                if(output == 1){
                    cout <<"Banyaknya solusi sebanyak : " << countSolution(penyimpan, value, operation) << endl << endl;}
                else if(output == 2){
                    myFile <<"Banyaknya solusi sebanyak : " << countSolution(penyimpan, value, operation) << endl << endl;}}
            //Seluruh rangkaian pemeriksaan permutasi
            int a = 0; bool benar;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(j != i){
                        for(int k = 0; k < 4; k++){
                            if(k != i && k != j){
                                for(int l = 0; l < 4; l++){
                                    if(l != i && l != j && l != k){
                                        penyimpan[a][0] = value[i];
                                        penyimpan[a][1] = value[j];
                                        penyimpan[a][2] = value[k];
                                        penyimpan[a][3] = value[l];
                                        benar = false;
                                        for(int m = 0; m < a; m++){
                                            for(int n = 0; n < 4; n++){
                                                if(n<3){
                                                    if(penyimpan[m][n] != penyimpan[a][n]){
                                                        break;}}
                                                else{
                                                    if(penyimpan[m][n] == penyimpan[a][n]){
                                                        benar = true;}}}
                                            if(benar == true){
                                                break;}}
                                        if(benar == false){
                                            a++;
                                            for(int a = 0; a < 4; a++){
                                                for(int b = 0; b < 4; b++){
                                                    for(int c = 0; c < 4; c++){
                                                        if(evaluate((evaluate(evaluate(value[i],value[j],operation[a]),value[k],operation[b])),value[l],operation[c])-hasil == 0){
                                                            if(output == 1){
                                                                cout << "((" << value[i] << operation[a] << value[j] << ")" << operation[b] << value[k] << ")" << 
                                                                operation[c] << value[l] << endl; }
                                                            else if(output == 2){
                                                                myFile << "((" << value[i] << operation[a] << value[j] << ")" << operation[b] << value[k] << ")" << 
                                                                operation[c] << value[l] << endl;}}
                                                        if(evaluate(evaluate(value[i],evaluate(value[j],value[k],operation[b]),operation[a]),value[l],operation[c])-hasil==0){
                                                            if(output == 1){
                                                                cout << "(" << value[i] << operation[a] << "(" << value[j] << operation[b] << value[k] << "))" << 
                                                                operation[c] << value[l] << endl;}
                                                            else if(output == 2){
                                                                myFile << "(" << value[i] << operation[a] << "(" << value[j] << operation[b] << value[k] << "))" << 
                                                                operation[c] << value[l] << endl;}}
                                                        if(evaluate(evaluate(value[i],value[j],operation[a]),evaluate(value[k],value[l],operation[c]),operation[b])-hasil == 0){
                                                            if(output == 1){
                                                                cout << "(" << value[i] << operation[a] << value[j] << ")" << operation[b] << "(" << value[k] << operation[c] 
                                                                << value[l] << ")" << endl;}
                                                            else if (output == 2){
                                                                myFile << "(" << value[i] << operation[a] << value[j] << ")" << operation[b] << "(" << value[k] 
                                                                << operation[c] << value[l] << ")" << endl;}}
                                                        if(evaluate(value[i],evaluate(evaluate(value[j],value[k],operation[b]),value[l],operation[c]),operation[a])-hasil == 0){
                                                            if(output == 1){
                                                                cout << value[i] << operation[a] << "((" << value[j] << operation[b] << value[k] << ")" << operation[c] << 
                                                                value[l] << ")" << endl;}
                                                            else if(output == 2){
                                                                myFile << value[i] << operation[a] << "((" << value[j] << operation[b] << value[k] << ")" << operation[c] << 
                                                                value[l] << ")" << endl;}}
                                                        if(evaluate(value[i],evaluate(value[j],evaluate(value[k],value[l],operation[c]),operation[b]),operation[a])-hasil == 0){
                                                            if(output == 1){
                                                                cout << value[i] << operation[a] << "(" << value[j] << operation[b] << "(" << value[k]  << operation[c] << value[l] << "))" << endl;}
                                                            else if(output == 2){
                                                                myFile << value[i] << operation[a] << "(" << value[j] << operation[b] << "(" << value[k]  << operation[c] << 
                                                                value[l] << "))" << endl;}}}}}}}}}}}}}
            if(output==1){
                cout << "Waktu eksekusi program : " << endl;
                cout << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;}
            else if(output==2){
                myFile << "Waktu eksekusi program : " << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;
                myFile.close();}}
        else if(start == 2)
        {
            exit = true;}}
    return 0;}
