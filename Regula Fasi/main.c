#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// header() untuk mencetak nama dan NPM
void header(double npm, char nama[25], char kelas[15]);
// input(), alternatif fungsi scanf
double input(char name[50]);

// fx(), fungsi yang akan dicari akarnya
double fx(double x);
// meng-absolutkan bilangan
double absolute(double x);

// fungsi untuk menghitung regula falsi
void regulaFalsi(double a, double b, int max_iter);

// fungsi untuk mencetak table head
void print_table_head();
// fungsi untuk mencetak baris tabel, biar lebih rapi
void print_row(double a, double b, double c, int i);

int main(){
    header(20081010187, "Muhammad Afifudin", "Metnum-F081");
    double a, b;
    int i = 10;
    a = input("batas bawah");
    b = input("batas atas");
    regulaFalsi(a, b, i);
    return 0;
}

double fx(double x){
    return exp(-x) - (x);
}

void header(double npm, char nama[25], char kelas[15]){
    system("cls"); // buat cls
    printf("====================================================================================");
    printf("\n\t\t\t\tMETODE REGULA FALSI");
    printf("\n====================================================================================");
    printf("\n\t\t\tNPM\t: %.0lf", npm);
    printf("\n\t\t\tNama\t: %s", nama);
    printf("\n\t\t\tKelas\t: %s", kelas);
    printf("\n====================================================================================");
    printf("\n\t\tMencari akar persamaan dari f(x) = e^(-x) - x\n");
}

double input(char name[50]){
    double x;
    printf("Masukkan %s !: ", name); scanf("%lf", &x);
    return x;
}

double absolute(double x){
    if(x < 0){
        return -x;
    } else{
        return x;
    }
}


void regulaFalsi(double a, double b, int max_iter){
    int i;
    double c, epsilon = 0.0001;
    print_table_head();
    for(i=0;i<max_iter;i++){
        c = ((a*fx(b)) - (b * fx(a))) / (fx(b) - fx(a));
        
        print_row(a, b, c, i);
        if (fx(c) == 0 || absolute(fx(c))<epsilon){
            break;
        } else if(fx(c) * fx(a) < 0){
            b = c;
        } else{
            a = c;
        }  
    }
    printf("====================================================================================\n");
    printf("Nilai akar adalah\t: %.10lf", c);
    printf("\nToleransi\t\t: %.10lf", absolute(fx(c)));
    printf("\n====================================================================================\n");

}


void print_row(double a, double b, double c, int i){
    printf("%d||%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", i+1, a, b, c, fx(a), fx(b), fx(c));
}

void print_table_head(){
    printf("\n\n====================================================================================\n");
    printf("i||\ta \t      b \t   c \t      f(a) \t    f(b) \t   f(c)\n");
    printf("====================================================================================\n");
}