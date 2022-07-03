#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Єгипетський метод множення двох натуральних чисел
int multiply(int n,int m);

// Функція для отримання цілого числа з клавіатури
int get_int(int i);

int main(void) {
  int n,m;
  // m n - натуральні
  printf("\n\tЄгипетське множення\n");
  n = get_int(1);
  m = get_int(2);
  printf("\nПеремножити числа %d та %d\n", n,m);
  multiply(n,m);
  return 0;
}

int multiply(int n,int m){
  int result=0;
  if (n%2!=0){
    result = m;
  }
  while (n>=1){
    printf("\n%7d || %5d", n,m);
    if (n%2!=0){
      printf("    (+%d)", m);
    }
    n = round(n/2);
    m = m*2;
    if ((n==1)||(n%2!=0)){
      result+=m;
    }
  }
  printf("\n\nРезультат перемноження: %3d\n",result);
  return result;
}

int get_int(int i){
int number,res=0;
while(res==0){
printf("\nВкажіть натуральне число номер %d: ",i);
char input[20];
scanf("%s",input);
while ((getchar()) != '\n');
number = atoi(input);
  if(number<0||number>999){
    printf("\n! Вкажіть ціле число з проміжку (0;999)");
    }
  else
  {
    res++;}
    }
    return number;}