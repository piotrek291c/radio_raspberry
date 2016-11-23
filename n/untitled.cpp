#include <stdio.h> 
#include <wiringPi.h> 
 
int main(int argc, char **argv) 
{ 
    printf("Program testowy WiringPi!\n"); 
 
    if (wiringPiSetup() == -1) 
    { 
        printf("Nie mozna wystartowac wiringPi!\n"); 
        return 1; 
    } 
 
    printf("Poprawnie wystartowano biblioteke wiringPi!\n"); 
    return 0; 
}
