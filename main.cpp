#include <stdio.h>
// подключение языка
#include <locale.h>
// подключение текста
//#include <string>
// созданная библиотека
#include "Smat.h"
#include <time.h>
#include <stdlib.h>
// + ф. stringcut
#include <string.h>
// + ф. для перевода символы в числа
#include <stdlib.h>

// указатель на структуры тифа пайл
FILE *f;


//структуры данных
struct fraction
{
    int integer;
    int divisible;
    int divider;
};
typedef struct fraction Fraction; //переименование для вызова достаточно будет написать Fraction
// ф. ссылающаяся на структуру данных
void FRprint (Fraction f) //будет вызываться та f (f1 or f2) которая будет указанна привызове ф.
{
    if (f.divisible == 0)
        printf("%3d",f.integer);
    else if (f.integer == 0)
        printf("     ""%d/%d",f.divisible,f.divider);
    else
        printf("%3d & %d/%d",f.integer,f.divisible,f.divider);
}
// перевод дроби в простой вид (не работет если вызывать не через указатели)
void FRdes (Fraction* f)    // ф. вызова структуры данных -> указатель на внешнии структуры снутри ф. f-> доступ к полям внутри указателей на структуры
{
    if (f->integer < 0)
        f->divisible = (f->divider * f->integer - f->divisible);
    else
        f->divisible = (f->divider * f->integer + f->divisible);
    f->integer = 0;
}
// восстановление целого числа
void FRint (Fraction* f)
{
    f->integer = f->divisible / f->divider;     //вычисление целого
    f->divisible = f->divisible % f->divider;   //вычисление нового делимого
    if (f->divisible < 0)                       //проверка на "-"
        f->divisible *= -1;
}

void FRsum (Fraction f1, Fraction f2, Fraction * r)
{
    FRdes(&f1);     // вызов ф. & - т.к. в ф. FRdes вызывам через указатель
    FRdes(&f2);
    //FRprint(f1);
    //FRprint(f2);
    r->divisible = f1.divisible * f2.divisible;     // r c ->,а  f1. и f2. так как подтягиваються из мэина, а r это указатель
    r->divider = f1.divider * f2.divider;
    if ((r->divisible > r->divider) or ((r->divisible * -1) > r->divider))  // проверка на перевод в вид с целым числом
        FRint(r); //указатель на указатель

}


//строковая ф. приветствия
void hellFun(char *name, char *out)
{
    char wellc[255] = "Hi, ";
    if (strcmp("Hitler", name) == 0 ) //сравнение текста
    {
        strcpy(name, "shit");
        //name = "shit";
    }
    strcat(wellc, name); //склеивание
    strcpy(out, wellc);   //копирование текста в out копируем переменную wellc
}

// функция связанная с массивом
void prArr (int *arr, int end)
{
    for(int i = 0; i < end; i++)
        printf("%d ", arr[i]);
}
//пример пердачи адреса в функцию a и b передаються измэина а *a и *b возвращаються, так как это указатели
int Fun1(int a, int b, int *a1, int *b1)
{
    int res;
    res = a + b;
    *a1 = b;
    *b1 = a;
    return res;
}
void Fun2(int a, int b,int *a2, int *b2)
{
    *a2 = a +1;
    *b2 = b +1;
}

// первый вариан с доп первыми строками
/*void TabPif (int y, int x)
{
    int tab[y][x] = {0};
    printf("  ", tab[0][0]);
    for (int i = 1; i < x; i++)
    {
        tab[0][i] = tab[0][i - 1] + 1;
        printf("%4d", tab[0][i]);
    }
    for(int iy = 1; iy < y-1 + 1; iy++)
    {
        tab[iy][0] = tab[iy-1][0] +1;
        printf("\n%2d",tab[iy][0]);
        for(int ix = 1; ix < x; ix++)
        {
            tab[iy][ix] = tab[0][ix] * iy;
            printf("%4d", tab[iy][ix]);
        }
    }
}*/
void TabPif(int y, int x)
{
    int tab[y][x] = {0};
    printf("    ");
    for(int i = 1; i <= x; i++)
        printf("%4d",i);
    printf("\n");
    for(int iy = 0; iy < y; iy++)
    {
        printf("%4d", iy+1);
        for(int ix = 0; ix < x; ix++)
        {
            tab[iy][ix] = (ix+1) * (iy+1);
            printf("%4d", tab[iy][ix]);
        }
        if(iy < y-1)
            printf("\n");
    }
}
// 2 вариан без доп строк
void TabPif2(int y, int x)
{
    int tab[y][x] = {0};
    for(int iy = 0; iy < y; iy++)
    {
        for(int ix = 0; ix < x; ix++)
        {
            tab[iy][ix] = (ix+1) * (iy+1);
            printf("%4d", tab[iy][ix]);
        }
        if(iy < y-1)
            printf("\n");
    }
}

float average(int *arr, int end)
{
    float result = 0;
    for(int i = 0;i < end; i++)
        result += *(arr +i);/*обращение к АДРЕСУ массива +i - обращение к начальному адрусу сассива со смщением на i бит*/
    result = result / end;
    return result;
}


// функции из сторонего файла
int sum(int a, int b);  /*суммирование*/
int um(int a, int b);   /*умножение*/
int st(int a, int b); /*степень*/
int prch(int a);        /*простые числа*/
/*//пример функции сложения
//сложение
int sum(int a, int b)
{
    return a + b;
}
//умножение
int um(int a, int b)
{
    return a * b;
}
//степень
int st(int a, int b)
{
    int aa = a;
    for(int i = 1; i < b; i++)
        a *= aa;
    return a;
}
//простые числа
int prch(int a)
{
    int b = 0;
    for(int i =1; i <= a; i++)
    {
        if(a % i == 0)
             b++;
        else
            continue;
        if( b == 3)
            return 0;
    }
    return (b < 3) ? 1: 0;
}*/

//изменение переменных через адреса void=пустота т.к. ф. не возвращает никакого значения
void swapP(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

using namespace std;

int main()
{
    // поддержка русскаго языка
    setlocale(0,"Russian");
    printf("Дарова ворлд\n");
    // объявление переменной а
   /* int a = 2;
    //printf("адрес a:%p\n", &a);
    // вывод на экран
    printf("a = %d\n",a);
    // простые мат операции
    a = a +1;
    printf("a = a + 1\n");
    printf("a = %d\n",a);
    a ++;
    printf("a ++\n");
    printf("a = %d\n",a);
    a += 4;
    printf("a += 4\n");
    printf("a = %d\n",a);
    a = a/4;
    printf("a = a/4\n");
    printf("a = %d\n",a);
    // определение переменной с точкой
    float b = 5;
    // вывод переменной с 3 знакоми после .
    printf("b = %.2f\n",b);
    printf("b = b/2\n");
    b = b/2;
    printf("b = %.2f",b);*/
    // пример ввода значения
    //int i;
    //printf("Ввод значения ");
    //scanf("%d", &i);
    //printf("Введенное число: %d\n", i);
    //printf("адрес хранения:%p\n", &i);*/
    // текстовые пременные
    //char an /*= 'ЫЫЫ'*/;
    /*printf(" 1 или 2 ");
    scanf("\n%c", &an);
    // условие с текстовыми переменными
    /*if (an == '1')
    {
        printf("Ы");
    }
    else if (an == '2')
    {
        printf("ЫЫ");
    }
    else
    {
        printf("Чо?");
    }
    //printf("%c", an);*/
    // сравнение
    /*int a;
    int b;
    int c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d",&b);
    // легкая форма записи
    //если a>b то с = а, иначе с = b
    //c = (a > b) ? a : b;
    //printf("c = %d",c);
    // сравнение внутри опратора printf с последующим выводом
    //printf("%s", (a > b) ? "a больше" : "b больше");
    if(a > b)
        printf("а больше");
    else if(a < b)
        printf("ь больше");
    else
        printf("Числа равны");*/
    // условие с логикой
    /*int a;
    int ost;
    printf("Введите число от 0 до 10\n");
    scanf("%d",&a);
    // взятие отстатка от деления
    ost = a % 2;
    // проврека на четность
    if(a >= 0 && a <= 10)
        printf("%s", (ost ==0) ? "Четное" : "Нечетное");
    else
        printf("Написано было от 0 ло 10!!!!1111адынадын");*/
    // цикл
    /*long long int a;
    int aa;
    int b;
    int i = 1;
    //printf("число:");
    // диапазон ввода
    do{
        printf("число:");
        scanf("%lli",&a);
        if(a > 10000)
            printf("Вне диапазона \n");
    }while(a > 10000);
    aa = a;
    do{
        printf("степень:");
        scanf("%d",&b);
        if(b > 100)
            printf("Вне диапазона \n");
    }while(b > 100);
    printf("^%d ",i);
    printf("%lli\n",a);
    while(i < b)
    {
        a = a * aa;
        //i++;
        //printf("^%d ",i);
        // другой вариант записи без i++
        //printf("^%d ",i++);
        //printf("%li\n",a);
        //запись в 1 строку
        printf("^%d %li\n",++i,a);
        //прекращение цикла при переполнении переменной а
        if (a >= 100000000)
        {
                printf("Вне диапазона");
                break;
        }

    }*/
    //цикл for
    /*int a;
    for (a = 0; a < 5; a++)
    {
        printf("%d\n", a);
    }*/
    // оператор switch
    /*char a;
    printf("a = ");
    scanf("%s", &a);
    switch (a)
    {
    //если строка нужно '', если число то не нужно
    case '1':
        printf("111");
        break;
    case '2':
        printf("222");
        break;
    default:
        printf("123456");
    }*/
    /*int a;
    int b;
    printf("КалькулятЫр\n");
    printf("Первое число: ");
    scanf("%d", &a);
    printf("Второе число: ");
    scanf("%d", &b);
    printf("%d+%d=%d\n", a , b, sum(a,b));
    printf("%d*%d=%d\n", a , b, um(a,b));
    printf("%d^%d=%d", a, b, st(a,b));*/

    // простые числа на диапазоне от 1 до а
    /*int a;
    //int b = 0;
    int c = 0;
    //printf("Простые числа на промежутке от 1 до: ");
    scanf("%d", &a);
    //printf("%s", (prch(a) == 1) ? "Простое" : "Не простое");
    for(int i = 1; i < (a +1 ); i++)
    {
       //printf("Число %d %s\n", i, (prch(i) == 1) ? "простое" : "не простое");
        if (prch(i) == 1)
            printf(" число %d простое \n",i);
    }*/
    // работа с укащзателями
    /*int a = 11;
    int b = 22;
    //printf("a = %d\n",a);
    //printf("Адрес а: %p\n",&a);
    //определение указателья (* - указатель )
    //int * addres;
    // присвоение
    //addres = &a;
    //printf("значенеи указателя: %p\n", addres);
    //printf("адресс указателя %p\n", &addres);
    //printf("указатель указывает на: %d\n", *addres);
    //мат операция через указатель
    //*addres += 10;
    //printf("новое значение: %d\n",a);
    //обращение к ф. через указатели
    printf("a=%d b=%d\n",a,b);
    swapP(&a,&b);
    printf("a=%d b=%d\n",a,b);*/
    //МАССИВЫ
    //оюявление
    /*int arr[4];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    //2 вариант объявлнения
    int arr2[5] = {1, 2, 3, 4, 5};
    //int a = 4;
    //for( int i = 0; i < a ; i++)
        //printf("%d\n", arr[i]);
    //генератор случайных чисел
    srand(time(NULL));
    //printf("%d", (rand() % 100/*разрядность случайного числа*///));

    //массивы
    /*int arr[5] = {2, 3, 5, 7, 9};
    //int arr[2][2] = {
        {1, 2,}
        {3, 4 }};   // пример заподнения 2Д массива
    prArr(arr, 5);
    printf("\n%2.1f", average(arr, 5));*/
    //таб умножения
    /*int x;
    int y;
    char esc;
    int a;
    do{
        printf("\n");
        printf("Количество строк: ");
        scanf("%d",&x);
        printf("количество столбцов: ");
        scanf("%d",&y);
        TabPif(y+1,x+1);
        printf("\nПовторить (y/n)");
        scanf("%s",&esc);
    }while(esc != 'n');*/
    /*int x = 4;
    int y = 3;
    char ds;
    printf("Доп строки (y/n)");
    scanf("%s",&ds);
    printf("Количество строк: ");
    scanf("%d",&x);
    printf("количество столбцов: ");
    scanf("%d",&y);
    if(ds == 'y')
        TabPif(y,x);
    else if(ds == 'n')
        TabPif2(y,x);
    else
        printf("неверный ввод");*/

    // массив из строк в виде ссылок
    //char * stringArr[3] = {"Пыщ", "Пыщ", "тро ло ло"};
    //printf("%s", stringArr[1]);
    //пример обмена дынных с функциями в адресной форме
    /*int a = 1;
    int b = 2;
    int c;
    int a1, a2;
    int b1, b2;
    c = Fun1(a,b,&a1,&b1);
    Fun2(a,b,&a2,&b2);
    printf("a=%d b=%d c=%d a1=%d b1=%d\n",a,b,c,a1,b1);
    printf("a2=%d b2=%d",a2,b2);*/

    //операции с текстом
    /*char name[255];
    char result[255];
    gets(name); //получение имяни
    //puts(name); //вывод имени
    hellFun(name, result); //вызов функции
    printf("%s\n",result);
    /*char wellc[255] = "Hi, ";
    strcat(wellc, name); //склеивание
    printf("%s\n", wellc);
    strcpy(result, wellc);   //копирование текста
    printf("%s\n", result);*/
    // пример перевода строкового значения в числовое
    /*char a[64];
    gets(a);
    int b = atoi(a);
    printf("%d",b * 2);*/
    /*Fraction f1, f2, result;
    f1.integer = -1; //целое
    f1.divisible = 1; //делимое
    f1.divider = 5;  //делитель
    f2.integer = 1;
    f2.divisible = 1;
    f2.divider = 5;
    result.integer = 0;
    result.divisible = 0;
    result.divider =0;
    // вывод
    /*if (f1.integer != 0)
        printf("%3d & %d/%d\n",f1.integer, f1.divisible, f1.divider);
    else
        printf("      ""%d/%d\n", f1.divisible,f1.divider);
    printf("%3d & %d/%d\n",f2.integer, f2.divisible, f2.divider);*/
    // вывод через ф.
    /*FRprint(f1);
    printf("\n");
    FRprint(f2);
    printf("\n");
    FRsum(f1,f2,&result);
    FRprint(result);*/


    //перевод в простой вид
    /*if (f1.integer < 0)
        f1.divisible = (f1.divider * f1.integer - f1.divisible); // вычисление числителя
    else
        f1.divisible = (f1.divider * f1.integer + f1.divisible);
    f1.integer = 0;
    printf("     ""%2d/%d\n",f1.divisible,f1.divider);
    // возврат в вид записи с целым
    if ((f1.divisible > f1.divider) or ((f1.divisible * -1) > f1.divider))
    {
        f1.integer = f1.divisible / f1.divider;     //вычисление целого
        f1.divisible = f1.divisible % f1.divider;   //вычисление нового делимого
        if (f1.divisible < 0)                       //проверка на "-"
            f1.divisible *= -1;
        printf("%3d & %d/%d",f1.integer,f1.divisible,f1.divider);
    }*/
    // файловая система
    f = fopen("File1.txt", "w");
    if (f == 0); // файл не содался
    fprintf(f, "Новая запись в файл,  Ура!");  // запись в файл
    fclose(f);                                  // закрытие файла
    f = fopen("File1.txt", "r");
    char word[256];
    while(!feof(f)) // пока не достигнут конец файла feof(f) == 1 если конец файла не достигнут, feof(f) == 0, если конец файла достигнут
    {
        fscanf(f, "%s", word);
        printf("%s_", word);
    }
    /*do{

    }while();*/
    //fscanf(f, "%s", word);
    //printf("%s", word);
    fclose(f);



    return 0;
}
