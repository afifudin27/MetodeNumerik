#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.000001
#define max 30
#define zero_divisor 0.0000001

double absolute(double x){
    if (x<0){
        return -x;
    }
    return x;
}

double input(char name[100]){
    double x;
    printf("%s", name); scanf("%lf", &x);
    return x;
}

double fx(double x){
    return exp(x) - 5*(x*x);
    //return x*x - 7*x - 7;
}

double fx_aksen(double x){
    return exp(x) - 10*x;
    //return 2*x - 7;
}

void print_table_row(double a, double b, int i){
    printf("%d||%.8lf \t%.8lf\n", i, a, b);
}

void newton_rapshon(double x){
    double x_before, x_now = x;
    int i=0;
    
    if(absolute(fx_aksen(x_now)) < zero_divisor){
            printf("Silahkan gunakan metode lain\n");
    } else{
        printf("%d||%.1lf \t\t-\n", i, x_now);
        i++;
        for(i; i<max; ++i){
            x_before = x_now;
            x_now = x_now - (fx(x_now)/fx_aksen(x_now));
            if(absolute(x_now - x_before) < epsilon){
                break;
            } else{
                print_table_row(x_now, absolute(x_now-x_before), i);
            }
        }
        if(i == 30){
            system("cls");
            printf("=================\n");
            printf("\nDIVERGEN\n");
            printf("\n=================");
        } else{
            print_table_row(x_now, absolute(x_now-x_before), i);
            printf("====================================================================================\n");
            printf("Nilai akar adalah\t: %.8lf", x_now);
            printf("\nToleransi\t\t: %.8lf", absolute(x_now-x_before));
            printf("\n====================================================================================\n");
        }
    }

    
}



int main(){
    system("cls");
    printf("=================================================\n");
    printf("METODE NEWTON RAPSHON\n");
    printf("Muhammad Afifudin (20081010187)\n");
    printf("=================================================\n");
    double a = input("Masukkan nilai awal pencarian: ");
    printf("=================================================\n");
    newton_rapshon(a);
}
