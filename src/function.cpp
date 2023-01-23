#include <iostream>
using namespace std;
void asciiArt(){
    cout<<"_______  _   ___         _______  _______  __   __  _______    _______  _______  ___      __   __  _______  ______  " << endl;
    cout<<"|       || | |   |       |       ||   _   ||  |_|  ||       |  |       ||       ||   |    |  | |  ||       ||    _ |  "<<endl;
    cout<<"|____   || |_|   | ____  |    ___||  |_|  ||       ||    ___|  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  "<<endl;
    cout<<" ____|  ||       ||____| |   | __ |       ||       ||   |___   | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ "<<endl;
    cout<<"| ______||___    |       |   ||  ||       ||       ||    ___|  |_____  ||  |_|  ||   |___ |       ||    ___||    __  |"<<endl;
    cout<<"| |_____     |   |       |   |_| ||   _   || ||_|| ||   |___    _____| ||       ||       | |     | |   |___ |   |  | |"<<endl;
    cout<<"|_______|    |___|       |_______||__| |__||_|   |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|"<<endl;
    cout << "Hallo Selamat Datang Di 24GameSolver" << endl;
}
double evaluate(double value1, double value2, char operasi){
    if(operasi == '+'){
        return value1+value2;}
    else if(operasi == '-'){
        return value1-value2;}
    else if(operasi == '*'){
        return value1*value2;}
    else if(operasi == '/'){
        return value1/value2;}}
void printRandom(double nilai[], int i){
    if(nilai[i] == 1){
        cout << "As" << endl;}
    else if(nilai[i] == 11){
        cout << "J" << endl;}
    else if (nilai[i] == 12){
        cout << "Q" << endl;}
    else if(nilai[i] == 13){
        cout << "K" << endl;}
    else{
        cout << nilai[i] << endl;}}
void inputPegguna(double value[])
{
    for(int i = 0; i < 4; i ++){
        string sementara;
        cout << "Masukkan input anda : " << endl;
        cin >> sementara;
        if(sementara == "As")
        {
            value[i] = 1;}
        else if(sementara == "J")
        {value[i] = 11;}
        else if(sementara == "Q"){
            value[i] = 12;}
        else if(sementara == "K"){
            value[i] = 13;}
        else if(sementara == "2"){
            value[i] = 2;}
        else if(sementara == "3"){
            value[i] = 3;}
        else if(sementara == "4"){
                value[i] = 4;}
        else if(sementara == "5"){
            value[i] = 5;}
        else if(sementara == "6"){
            value[i] = 6;}
        else if(sementara == "7"){
            value[i] = 7;}
        else if(sementara == "8"){
            value[i] = 8;}
        else if(sementara == "9"){
            value[i] = 9;}
        else if(sementara == "10"){
            value[i] = 10;}
        else{
        while(sementara != "As" && sementara != "2" && sementara != "3" && sementara != "4" && sementara != "5" && sementara != "6" && 
        sementara != "7" && sementara != "8" && sementara != "9" && sementara != "10" && sementara != "J" && sementara != "Q" && sementara != "K"){
            cout << "input anda salah, Mohon input ulang Jawaban anda" << endl;
            cin >> sementara;}
            if(sementara == "As"){
                value[i] = 1;}
            else if(sementara == "J"){
                value[i] = 11;}
            else if(sementara == "Q"){
                value[i] = 12;}
            else if(sementara == "K"){
                value[i] = 13;}
            else if(sementara == "2"){
                value[i] = 2;}
            else if(sementara == "3"){
                value[i] = 3;}
            else if(sementara == "4"){
                value[i] = 4;}
            else if(sementara == "5"){
                value[i] = 5;}
            else if(sementara == "6"){
                value[i] = 6;}
            else if(sementara == "7"){
                value[i] = 7;}
            else if(sementara == "8"){
                value[i] = 8;}
            else if(sementara == "9"){
                value[i] = 9;}
            else if(sementara == "10"){
                value[i] = 10;}}}}
int countSolution(double penyimpan[24][4], double value[], char operation[])
{
    int hasil = 24; int count = 0; int a = 0; bool benar;
    //Untuk jumlah Di Awal
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
                                                if(evaluate((evaluate(evaluate(value[i],value[j],operation[a]),value[k],operation[b])),value[l],operation[c])-hasil == 0)
                                                {count++;}
                                                if(evaluate(evaluate(value[i],evaluate(value[j],value[k],operation[b]),operation[a]),value[l],operation[c])-hasil==0)
                                                {count++;}
                                                if(evaluate(evaluate(value[i],value[j],operation[a]),evaluate(value[k],value[l],operation[c]),operation[b])-hasil == 0)
                                                {count++;}
                                                if(evaluate(value[i],evaluate(evaluate(value[j],value[k],operation[b]),value[l],operation[c]),operation[a])-hasil == 0)
                                                {count++;}
                                                if(evaluate(value[i],evaluate(value[j],evaluate(value[k],value[l],operation[c]),operation[b]),operation[a])-hasil == 0)
                                                {count++;}}}}}}}}}}}}
                                                return count;}