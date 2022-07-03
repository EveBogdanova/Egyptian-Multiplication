#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include "functions.h"

struct DEVICE{
    char name[30];
    char room[30];
    char state[20];
    int id;
    int deleted;
};

struct SENSOR{
    int device_id;
    char room[30];
    char type[30];
    double data; 
};

int devices_base(struct DEVICE devices[]);
int sensors_base(struct SENSOR sensors[]);
void search_by_id(struct DEVICE devices[],struct SENSOR sensors[],int size_dev,int size_sens);
void search_by_room(struct DEVICE devices[],int size);
void turned_on(struct DEVICE devices[],int size);
void add_sensor(struct DEVICE devices[],struct SENSOR sensors[],int size_dev,int size_sens);
void add_device(struct DEVICE devices[],int size_dev);
void delete_device(struct DEVICE devices[],int size_dev);
int create_new_devices_base(struct DEVICE devices[],int size_dev);
int create_new_sensors_base(struct SENSOR sensors[],int size_sens);


int devices_base(struct DEVICE devices[]){
  int size=0;
  FILE *devs = fopen("devices.csv","r");
  if (devs==NULL)
    {printf("\n\n\t\t\tПомилка при відкритті файлу\n");
    exit(1);}
  else{
    int read = 0;
    int records = 0;
    do{
        if (records==0){fscanf(devs, "%*[^\n]");}
      read = fscanf(devs, "%29[^,],%29[^,],%19[^,],%d",devices[records].name,devices[records].room,devices[records].state,&devices[records].id);
      devices[records].deleted=0;
      if (read==4){records++;}
      if(read != 4 && !feof(devs)){
        printf("\n! Формат файлу не дозволяє правильно зчитати данi\n");
        exit(1);}
      if(ferror(devs)){
        printf("\nПомилка при зчитуванні даних\n");
        exit(1);} 
    }while(!feof(devs));
    fclose(devs);
        size=records;
      }
      return size;
    }


int sensors_base(struct SENSOR sensors[]){
  int size = 0;
  FILE *sens = fopen("sensor.csv","r");
  if (sens==NULL)
    {printf("\n\n\t\t\tПомилка при відкритті файлу\n");
    exit(1);}
  else{
    int read = 0;
    int records = 0;
    do{
        if (records==0){fscanf(sens, "%*[^\n]");}
      char data_char[10];
      read = fscanf(sens, "%d,%29[^,],%29[^,], %9[^\n]\n",&sensors[records].device_id,sensors[records].room,sensors[records].type,data_char);
      for(int i=0;i<10;i++)
        {
        if (data_char[i] == '.') 
        data_char[i] = ',';
        }
      sensors[records].data = strtod(data_char,NULL);
      if (read==4){records++;}
      if(read != 4 && !feof(sens)){
        printf("\n! Формат файлу не дозволяє правильно зчитати данi\n");
        exit(1);}
      if(ferror(sens)){
        printf("\nПомилка при зчитуванні даних\n");
        exit(1);} 
    }while(!feof(sens));
    fclose(sens);
    size=records;
        }
      return size;
    }


void search_by_room(struct DEVICE devices[],int size){
  char *key;
  int count=0;
  key = (char*) calloc(40,sizeof(char));
  if (key==NULL) { printf("\nПомилка виділення памяті"); exit(1); }
  printf("\n\n\tВведіть кімнату для пошуку: ");
  scanf("%s",key);
  while(getchar()!='\n');
  for(int i=0; i<size;i++){
    if((compare(key,devices[i].room)==0)&&(devices[i].deleted==0)){
      if (count==0){
        printf("\n______________________________________________________________\n");
        printf("\n\t%s \t\t\t\t%s \t\t%s \t\t%s\n", "НАЗВА", "КІМНАТА", "СТАН", "ID");
      }
      printf("\n______________________________________________________________");
      printf("\n%s \t\t\t%s \t\t%s \t\t%d", devices[i].name, devices[i].room, devices[i].state,devices[i].id);
      count++;
    }
  }
  if (count==0){
    printf("\n\n\tЖодного пристрою в кімнаті %s\n",key);
  }
  printf("\n______________________________________________________________");
  free(key);
};


void turned_on(struct DEVICE devices[],int size){
  int count = 0;
  for(int i=0; i<size;i++){
  if((strcmp(devices[i].state," ON")==0)&&(devices[i].deleted==0)){
      if (count==0){
        printf("\n______________________________________________________________\n");
        printf("\n\t%s \t\t\t\t%s \t\t%s\n", "НАЗВА", "КІМНАТА", "ID");
        }
      printf("\n______________________________________________________________");
      printf("\n%s \t\t\t%s \t\t%d", devices[i].name, devices[i].room,devices[i].id);
      count++;
      }
    }
  if (count==0){
    printf("\n\n\tЖодного ввімкненого пристрою\n");
    }
  printf("\n______________________________________________________________");
};

void search_by_id(struct DEVICE devices[],struct SENSOR sensors[],int size_dev,int size_sens){
  int key;
  int count=0;
  printf("\n\n\tВведіть ID пристрою для пошуку: ");
  scanf("%d",&key);
  while(getchar()!='\n');
  for(int i=0; i<size_dev;i++){
    if((key==devices[i].id)&&(devices[i].deleted==0)){
      printf("\n\n\tІНФОРМАЦІЯ ПРО ПРИСТРІЙ\n");
      printf("\n______________________________________________________________");
      printf("\n\n\t%s \t\t\t\t%s \t\t%s\n", "НАЗВА", "КІМНАТА", "СТАН");
      printf("\n______________________________________________________________");
      printf("\n%s \t\t\t%s \t\t%s", devices[i].name, devices[i].room, devices[i].state);
      printf("\n______________________________________________________________");
      count++;
      }}
  for(int i=0; i<size_sens;i++){
    if(key==sensors[i].device_id){
      printf("\n\n\n\tПІД’ЄДНАНІ СЕНСОРИ\n");
      printf("\n______________________________________________________________");
      printf("\n\n\t%s \t\t\t\t%s \t\t%s\n", "КІМНАТА", "ТИП", "ДАНІ");
      printf("\n______________________________________________________________");
      printf("\n%s \t\t\t%s \t\t%.2f", sensors[i].room, sensors[i].type, sensors[i].data);
      printf("\n______________________________________________________________");
      count++;
      }}
  if (count==0){
    printf("\n\nЖодного пристрою з ідентифікатором %d\n",key);
  }
};

void add_sensor(struct DEVICE devices[],struct SENSOR sensors[],int size_dev,int size_sens){
  int device_id;
  char room[30];
  char type[30];
  double data;
  printf("\n\t1) Введіть ID девайсу, до якого буде під’єднаний сенсор: ");
  scanf(" %d",&device_id);
  while(getchar()!='\n');
  int res=0;
  for(int j=0;j<size_dev;j++){
    if((device_id==devices[j].id)&&(devices[j].deleted==0))
      res++;
  }
  if (res!=0){
    printf("\n\t2) Введіть кімнату, в якій розміщено сенсор: ");
    scanf("%s",room);
    while(getchar()!='\n');
    printf("\n\t3) Введіть тип сенсору (які параметри фіксує сенсор): ");
    scanf("%s",type);
    while(getchar()!='\n');
    printf("\n\t4) Введіть перші зафіксовані дані: ");
    scanf("%lf",&data);
    while(getchar()!='\n');
    printf("\n\n\n\tДОДАТИ НОВИЙ СЕНСОР\n");
    printf("\n______________________________________________________________");
    printf("\n\n\t%s \t\t\t\t%s \t\t%s\t\t%s\n", "КІМНАТА", "ТИП", "ДАНІ","ID ПРИСТРОЮ");
    printf("\n______________________________________________________________");
    printf("\n%s \t\t\t%s \t\t%.2f\t\t%d", room, type, data, device_id);
    printf("\n______________________________________________________________");
    char ok;
    printf("\n\n\tПідвердіть додавання сенсору (так = 1): ");
    scanf(" %c",&ok);
    while(getchar() != '\n');
    if(ok=='1'){
      strcpy(sensors[size_sens].room,room);
      strcpy(sensors[size_sens].type,type);
      sensors[size_sens].data = data;
      sensors[size_sens].device_id = device_id;
      printf("\n\n* Зміни підтверджено");
    }
    else{
      printf("\n\n! Зміни скасовано");
    }
  }
  else
    printf("\n\n\tПристрою з ідентифікатором %d не знайдено",device_id);
}

void add_device(struct DEVICE devices[],int size_dev){
  int id;
  char name[30];
  char room[30];
  char state[20];
  int res=0;
  printf("\n\t1) Введіть ID девайсу: ");
  scanf(" %d",&id);
  while(getchar()!='\n');
  for(int i=0;i<size_dev;i++){
    if(devices[i].id==id&&devices[i].deleted==0)
      res++;
    }
  if (res == 0){
    printf("\n\t2) Введіть назву пристрою: ");
    scanf("%s",name);
    while(getchar()!='\n');
    printf("\n\t3) Введіть кімнату, в якій розташований пристрій: ");
    scanf("%s",room);
    while(getchar()!='\n');
    printf("\n\t4) Введіть стан, в якому знаходиться пристрій (ON/OFF): ");
    scanf("%s",state);
    while(getchar()!='\n');
    printf("\n\n\n\tДОДАТИ НОВИЙ ПРИСТРІЙ З ID %d\n",id);
    printf("\n______________________________________________________________");
    printf("\n\n\t%s \t\t\t\t%s \t\t%s\n", "НАЗВА", "КІМНАТА", "СТАН");
    printf("\n______________________________________________________________");
    printf("\n%s \t\t\t%s \t\t%s", name, room, state);
    printf("\n______________________________________________________________");
    char ok;
    printf("\n\n\tПідвердіть додавання пристрою (так = 1): ");
    scanf(" %c",&ok);
    while(getchar() != '\n');
    if(ok=='1'){
      strcpy(devices[size_dev].name,name);
      strcpy(devices[size_dev].room,room);
      strcpy(devices[size_dev].state,state);
      devices[size_dev].id = id;
      devices[size_dev].deleted=0;
      printf("\n\n* Зміни підтверджено");
    }
    else{
      printf("\n\n! Зміни скасовано");
    }
  }
  else
    printf("\n\n\tПристрій з ідентифікатором %d вже існує",id);
}

void delete_device(struct DEVICE devices[],int size_dev){
  int delete_index;
  int delete_id; 
  int search=0;
  printf("\n\tВведіть ID пристрою, який ви хочете видалити: ");
  scanf(" %d",&delete_id);
  while(getchar()!='\n');
  for(int i=0;i<size_dev;i++){
    if(devices[i].id==delete_id)
    {search++;
      delete_index=i;
      }
    }
  if (search != 0){
    char ok;
    printf("\n______________________________________________________________\n");
    printf("\n\t%s \t\t\t\t%s \t\t%s\n", "НАЗВА", "КІМНАТА", "ID");
    printf("\n______________________________________________________________");
    printf("\n%s \t\t\t%s \t\t%d", devices[delete_index].name, devices[delete_index].room,devices[delete_index].id);
    printf("\n______________________________________________________________");
    printf("\n\n\n\tПідвердіть видалення пристрою %d (так = 1): ",delete_id);
    scanf(" %c",&ok);
    while(getchar() != '\n');
    if(ok=='1'){
      devices[delete_index].deleted=1;
      printf("\n\n* Пристрій видалено");
    }
    else{
      printf("\n\n! Зміни скасовано");
    }
  }
  else
    printf("\n\n\tПристрою з ідентифікатором %d не знайдено",delete_id);
}

int create_new_devices_base(struct DEVICE devices[],int size_dev){
  char *filename;
  int name=0;
  while(name==0){
    filename = (char*) calloc(30,sizeof(char));
    if (filename==NULL) { printf("\nПомилка виділення памяті"); exit(1); }
    printf("\nВведіть назву файлу 1 (нова база пристроїв): ");
    scanf("%123s",filename);
    char ok;
    printf("\n\nСтворити файл з назвою '%s.csv' ?\nПідтвердження (так=1): ",filename);
    scanf(" %c",&ok);
    if (ok=='1'){
      name++;
    }
    else{
      free(filename);
    }
    }
  strcat(filename,".csv");
  FILE *new_devices_base;
  new_devices_base=fopen(filename,"w");
  if (new_devices_base==NULL){
    printf("\nТрапилася помилка при відкритті файлу");
    return 0;
    }
  fprintf(new_devices_base,"NAME, ROOM, STATE, ID");
  for(int i=0; i<size_dev;){
    if(devices[i].deleted==1){
      i++;
      }
    else{
      if((i>=0&&i<size_dev-1)&&(devices[i+1].name[0]=='\n'))
        fprintf(new_devices_base,"%s,%s,%s,%d",devices[i].name,devices[i].room,devices[i].state,devices[i].id);
      else
        fprintf(new_devices_base,"%s,%s,%s,%d\n",devices[i].name,devices[i].room,devices[i].state,devices[i].id);
      i++;
      }
  }
  free(filename);
  fclose(new_devices_base);
  return 1;
  }


int create_new_sensors_base(struct SENSOR sensors[],int size_sens){
  char *filename;
  int name=0;
  while(name==0){
    filename = (char*) calloc(30,sizeof(char));
    if (filename==NULL) { printf("\nПомилка виділення памяті"); exit(1); }
    printf("\nВведіть назву файлу 2 (нова база сенсорів): ");
    scanf("%123s",filename);
    char ok;
    printf("\n\nСтворити файл з назвою '%s.csv' ?\nПідтвердження (так=1): ",filename);
    scanf(" %c",&ok);
    if (ok=='1'){
      name++;
    }
    else{
      free(filename);
    }
    }
  strcat(filename,".csv");
  FILE *new_sensors_base;
  new_sensors_base=fopen(filename,"w");
  if (new_sensors_base==NULL){
    printf("\nТрапилася помилка при відкритті файлу");
    return 0;
    }
  fprintf(new_sensors_base,"ID, ROOM, TYPE, DATA\n");
  for(int i=0; i<size_sens;i++){
    fprintf(new_sensors_base,"%d,%s,%s,%lf\n",sensors[i].device_id,sensors[i].room,sensors[i].type,sensors[i].data);  
  }
  free(filename);
  fclose(new_sensors_base);
  return 1;
}