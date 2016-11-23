#include <wiringPi.h>           //WiringPi headers
#include <lcd.h>                //LCD headers from WiringPi
#include <stdio.h>              //Needed for the printf function below
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
int lcd;

void przycisk_1_push(int button, int *key)
{
	printf("jestem w przycisk_1_push\n"); 
	printf("Wartosc pinu 9 : %i\n",digitalRead(9)); 
	if(button == 0 )
	{
		delay(80);
	}
	if(button == 0 )
	{
		if(*key==1)
		*key=0;
		else
		*key=1;

	}
	
}


void przycisk_1_push_on_off(int button, int *key)
{
	printf("jestem w przycisk_1_push\n"); 
	printf("Wartosc pinu 9 : %i\n",digitalRead(9)); 
	
	if(button == 0 )
	{
	
		*key=0;
	}
	if(button == 1 )
	{

		*key=1;

	}
	
}

void wypisz_LCD(char *nazwa_stacji,char *status,char *stan,char *lista,char *volume)
{
	lcdPosition(lcd,0,0);           //Position cursor on the first line in the first column
    lcdPuts(lcd, nazwa_stacji);
    lcdPosition(lcd,0,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, status);
    lcdPosition(lcd,6,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, stan);
    lcdPosition(lcd,7,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, lista);
    char znak1[]={"/9"};
    lcdPosition(lcd,8,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, znak1);
    lcdPosition(lcd,11,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, "<");
    lcdPosition(lcd,12,1);           //Position cursor on the first line in the first column
    lcdPuts(lcd, volume);
    lcdPosition(lcd,15,1);           //Position cursor on the first line in the first column
    char znak[]={"%"};
    lcdPuts(lcd, znak);
}


int backlight = 0;
string status = "stopped";
int channel_pos = 0;
string channelLink[2] ={ "http://31.192.216.7:8000/rmf_maxxx", "http://mp3.streampower.be/stubru-high.mp3"};
string channelName[2] = {"Q-Music BE", "Studio Brussel"} ;







//Pin numbers below are the WiringPi pin numbers
 
#define LCD_RS  25               //Register select pin
#define LCD_E   24              //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  30               //Data pin 7




int main()
{
	
    //system("mpc stop");
    system("mpc clear");   
   // system("mpc add http://31.192.216.7:8000/rmf_maxxx");
   // system("mpc play");   
system("mpc add http://31.192.216.7:8000/rmf_maxxx");
system("mpc add http://mp3.streampower.be/stubru-high.mp3");

char stacja[]={"rmf_maxxx"}; 
//char stat[]={"play"};
char stan[]={">"};
char lista[]={"1"}; 
char volume[]={"90"}; 


    if (wiringPiSetup() == -1) 
    { 
        printf("Nie mozna wystartowac wiringPi!\n"); 
        return 1; 
    } 
    
        if ((lcd = lcdInit (2, 16,4, LCD_RS, LCD_E ,LCD_D4 , LCD_D5, LCD_D6,LCD_D7,0,0,0,0)==1)){
            printf ("lcdInit failed! \n");
            return -1 ;
    }
    
    lcdPosition(lcd,0,0);           //Position cursor on the first line in the first column
    lcdPuts(lcd, "RADIO NET");  //Print the text on the LCD at the current cursor postion
    
 
    pinMode(7,OUTPUT);
    pinMode(9,INPUT);
    pullUpDnControl(9,PUD_UP);
    pinMode(8,INPUT);
    pullUpDnControl(8,PUD_UP);
    pinMode(0,INPUT);
    pullUpDnControl(0,PUD_UP);
    pinMode(2,INPUT);
    pullUpDnControl(2,PUD_UP);
    pinMode(3,INPUT);
    pullUpDnControl(3,PUD_UP);
    int key1=1;
    int key2=1;
    int key3=1;
    int key4=1;
    int key5=1;

    
    
     for(;;)
   {

przycisk_1_push(digitalRead(9), &key1);
przycisk_1_push_on_off(digitalRead(8), &key3);
przycisk_1_push_on_off(digitalRead(0), &key2);
przycisk_1_push_on_off(digitalRead(2), &key4);
przycisk_1_push_on_off(digitalRead(3), &key5);

        if (key1==0 ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio nie jest odtwarzane
        {

            delay(100); //eliminacja drgania styków
            status = "play";
            //char * tablica = new char[status.size()+1];
            //strcpy(tablica,status.c_str());
            char * tablica = new char[status.size()+1];
			tablica = (char *)status.c_str();          
            system("mpc play");
            wypisz_LCD(stacja,tablica,stan,lista,volume);
            digitalWrite(7,1); //zaświeć diodę LED na gpio7
        }

        if (key1==1  ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio jest odtwarzane
       {

            delay(100);
            status = "stopped";
            system("mpc pause");
          // system("mpc clear");
            digitalWrite(7,0); //wygaś diodę LED na gpio7
        }
       if (key2==0  ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio jest odtwarzane
       {
            delay(100);
            status = "prev";
            system("mpc prev");
            digitalWrite(7,0); //wygaś diodę LED na gpio7
        }
       if (key3==0  ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio jest odtwarzane
       {
            delay(100);
            status = "next";
            system("mpc next");
            digitalWrite(7,1); //wygaś diodę LED na gpio7
        }
       if (key4==0  ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio jest odtwarzane
       {
            delay(100);
            status = "volume -10";
            system("mpc volume -10");
            digitalWrite(7,1); //wygaś diodę LED na gpio7
        }
       if (key5==0  ) //jeśli przycisk naciśnięty i pamięć naciśnięcia pusta i radio jest odtwarzane
       {
            delay(100);
            status = "volume +10";
            system("mpc volume +10");
            digitalWrite(7,1); //wygaś diodę LED na gpio7
        }
    }


    return 0;

}
