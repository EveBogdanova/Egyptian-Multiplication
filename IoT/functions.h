#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <time.h>


void interface(void);
void end(void);
int menu(void);
int compare(char* s1,char* s2);
void instructions(void);


void interface(void)
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t         ________________________________________");
    printf("\n\t\t\t        |                                        |");
    printf("\n\t\t\t        |                  ВІТАЮ                 |");
    printf("\n\t\t\t        |              ВАС В ПРОГРАМІ            |");
    printf("\n\t\t\t        |                 МЕНЕДЖЕР               |");
    printf("\n\t\t\t        |               СИСТЕМИ IoT              |");
    printf("\n\t\t\t        |                                        |");
    printf("\n\t\t\t        |________________________________________|");
    printf("\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Натисніть будь-яку клавішу, щоб продовжити...");
    getchar();
}

int menu(void){
    time_t t = time(NULL);
    struct tm *tim = localtime(&t);
    int menu=0;
    while(menu==0){
    system("@cls||clear");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\tДата: %s",(asctime(tim)));
    printf("\n\t\t\t         _________________________________________");
    printf("\n\t\t\t        |                  МЕНЮ                   |");
    printf("\n\t\t\t        |  1) КІМНАТИ                             |");
    printf("\n\t\t\t        |  2) УВІМКНЕНІ ПРИСТРОЇ                  |");
    printf("\n\t\t\t        |  3) ДОДАТИ СЕНСОР                       |");
    printf("\n\t\t\t        |  4) ПОШУК ПРИСТРОЮ                      |");
    printf("\n\t\t\t        |  5) ДОДАТИ ПРИСТРІЙ                     |");
    printf("\n\t\t\t        |  6) ВИДАЛИТИ ПРИСТРІЙ                   |");
    printf("\n\t\t\t        |  7) ІНСТРУКЦІЯ КОРИСТУВАЧА              |");
    printf("\n\t\t\t        |  8) ВИХІД З ПРОГРАМИ                    |");
    printf("\n\t\t\t        |_________________________________________|");
    printf("\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\tВаш вибір: ");
    char choice;
    scanf(" %c",&choice);
    while(getchar() != '\n');
    int res = 0;
    if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8'){
    system("@cls||clear");
    printf("\n\t\t\t         ________________________________________");
    printf("\n\t\t\t        |                                        |");
    printf("\n\t\t\t        |            !!! ПОМИЛКА !!!             |");
    printf("\n\t\t\t        |         ЗАДАНОГО ПУНКТУ НЕМАЄ          |");
    printf("\n\t\t\t        |                В МЕНЮ                  |");
    printf("\n\t\t\t        |________________________________________|");
    printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
    getchar();
    }
    else{
        res=atoi(&choice);
        menu++;
        return res;
        }
    } 
}

int compare(char* s1,char* s2){
  int res=0;
  char* temp = (char*) calloc(40,sizeof(char));
  for(int i=0;i<strlen(s2);){
    for(int j=0;j<=strlen(s2);){
    if(s2[j]!=' '){
      temp[i]=s2[j];
      i++;
      j++;}
    else  
      j++;
  }}
  res=strcmp(s1,temp);
  free(temp);
  return res;
}


void end(void)
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t         ____________________________________");
    printf("\n\t\t\t        |                                    |");
    printf("\n\t\t\t        |          ***  ДЯКУЮ  ***           |");
    printf("\n\t\t\t        |           ЗА ПРИДІЛЕНИЙ            |");
    printf("\n\t\t\t        |                ЧАС                 |");
    printf("\n\t\t\t        |____________________________________|");
    printf("\n\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
}

void instructions(void){
    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t         _______________________________________________________________");
    printf("\n\t\t\t        |                  ІНСТРУКЦІЯ КОРИСТУВАЧА                       |");
    printf("\n\t\t\t        |                                                               |");
    printf("\n\t\t\t        |  1) У розділі 'Кімнати' ви можете дізнатися інформацію про    |");
    printf("\n\t\t\t        |  всі пристрої, які знаходяться в заданій кімнаті              |");
    printf("\n\t\t\t        |  2) У розділі 'Увімкнені пристрої' ви можете перевірити,      |");
    printf("\n\t\t\t        |  які пристрої зараз знаходяться в активному стані             |");
    printf("\n\t\t\t        |  3) У розділі 'Додати сенсор' ви можете додати в існуючу      |");
    printf("\n\t\t\t        |  базу сенсорів новий сенсор для відстежування                 |");
    printf("\n\t\t\t        |  4) У розділі 'Пошук пристрою' ви можете дізнатися додаткову  |");
    printf("\n\t\t\t        |  інформацію про пристрій, знаючи його ID-номер                |");
    printf("\n\t\t\t        |  5) У розділах 'Додати/видалити пристрій' ви можете додати    |");
    printf("\n\t\t\t        |  в базу пристроїв новий пристрій (видалити необхідний з бази) |");
    printf("\n\t\t\t         _______________________________________________________________");
}