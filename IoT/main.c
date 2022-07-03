#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "database.h"

int main(){
    setlocale(LC_ALL, "");
    interface();
    struct DEVICE devices[50];
    struct SENSOR sensors[250];
    int devices_number;
    int sensors_number;
    devices_number = devices_base(devices);
    sensors_number = sensors_base(sensors);
    int programm = 0;
    while(programm==0)
    {
        int choice;
        choice = menu();
        if (choice==1){
          system("@cls||clear");
          printf("\n\tДІЗНАЙТЕСЬ, ЯКІ ПРИСТРОЇ ЗНАХОДЯТЬСЯ В ШУКАНІЙ КІМНАТІ\n");
          search_by_room(devices,devices_number);
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==2){
          system("@cls||clear");
          printf("\n\tДІЗНАЙТЕСЬ, ЯКІ ПРИСТРОЇ ЗНАХОДЯТЬСЯ В РОБОЧОМУ СТАНІ\n");
          turned_on(devices,devices_number);
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==3){
          system("@cls||clear");
          printf("\n\tДОДАЙТЕ НОВИЙ СЕНСОР ДО ВАШОЇ БАЗИ\n");
          add_sensor(devices,sensors,devices_number,sensors_number); 
          sensors_number++;
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==4){
          system("@cls||clear");
          printf("\n\tПОШУК ПРИСТРОЮ ЗА ІДЕНТИФІКАТОРОМ\n");
          search_by_id(devices,sensors,devices_number,sensors_number); 
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==5){
          system("@cls||clear");
          printf("\n\tДОДАЙТЕ НОВИЙ ПРИСТРІЙ ДО ВАШОЇ БАЗИ\n");
          add_device(devices,devices_number);
          devices_number++;
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==6){
          system("@cls||clear");
          printf("\n\tВИДАЛИТИ ПРИСТРІЙ З БАЗИ\n");
          delete_device(devices,devices_number);
          printf("\n\n\n\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==7){
          system("@cls||clear");
          instructions();
          printf("\n\n\n\t\t\t\t Натисніть будь-яку клавішу, щоб продовжити...");
          getchar();
        }
        else if (choice==8){
          system("@cls||clear");
          int ending=0;
          while(ending==0){
          int res1,res2;
          res1 = create_new_devices_base(devices,devices_number);
          res2 = create_new_sensors_base(sensors,sensors_number);
            if(res1==res2==1){
              ending++;
              }
          }
          printf("\n\n\t База успішно оновлена");
          end();
          programm++;
        }
    }
    return 0;
}