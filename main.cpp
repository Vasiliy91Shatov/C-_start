#include <stdio.h>
// ����������� �����
#include <locale.h>
// ����������� ������
//#include <string>
// ��������� ����������
#include "Smat.h"
#include <time.h>
#include <stdlib.h>
// + �. stringcut
#include <string.h>
// + �. ��� �������� ������� � �����
#include <stdlib.h>

// ��������� �� ��������� ���� ����
FILE *f;


//��������� ������
struct fraction
{
    int integer;
    int divisible;
    int divider;
};
typedef struct fraction Fraction; //�������������� ��� ������ ���������� ����� �������� Fraction
// �. ����������� �� ��������� ������
void FRprint (Fraction f) //����� ���������� �� f (f1 or f2) ������� ����� �������� ��������� �.
{
    if (f.divisible == 0)
        printf("%3d",f.integer);
    else if (f.integer == 0)
        printf("     ""%d/%d",f.divisible,f.divider);
    else
        printf("%3d & %d/%d",f.integer,f.divisible,f.divider);
}
// ������� ����� � ������� ��� (�� ������� ���� �������� �� ����� ���������)
void FRdes (Fraction* f)    // �. ������ ��������� ������ -> ��������� �� ������� ��������� ������ �. f-> ������ � ����� ������ ���������� �� ���������
{
    if (f->integer < 0)
        f->divisible = (f->divider * f->integer - f->divisible);
    else
        f->divisible = (f->divider * f->integer + f->divisible);
    f->integer = 0;
}
// �������������� ������ �����
void FRint (Fraction* f)
{
    f->integer = f->divisible / f->divider;     //���������� ������
    f->divisible = f->divisible % f->divider;   //���������� ������ ��������
    if (f->divisible < 0)                       //�������� �� "-"
        f->divisible *= -1;
}

void FRsum (Fraction f1, Fraction f2, Fraction * r)
{
    FRdes(&f1);     // ����� �. & - �.�. � �. FRdes ������� ����� ���������
    FRdes(&f2);
    //FRprint(f1);
    //FRprint(f2);
    r->divisible = f1.divisible * f2.divisible;     // r c ->,�  f1. � f2. ��� ��� �������������� �� �����, � r ��� ���������
    r->divider = f1.divider * f2.divider;
    if ((r->divisible > r->divider) or ((r->divisible * -1) > r->divider))  // �������� �� ������� � ��� � ����� ������
        FRint(r); //��������� �� ���������

}


//��������� �. �����������
void hellFun(char *name, char *out)
{
    char wellc[255] = "Hi, ";
    if (strcmp("Hitler", name) == 0 ) //��������� ������
    {
        strcpy(name, "shit");
        //name = "shit";
    }
    strcat(wellc, name); //����������
    strcpy(out, wellc);   //����������� ������ � out �������� ���������� wellc
}

// ������� ��������� � ��������
void prArr (int *arr, int end)
{
    for(int i = 0; i < end; i++)
        printf("%d ", arr[i]);
}
//������ ������� ������ � ������� a � b ����������� ������� � *a � *b �������������, ��� ��� ��� ���������
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

// ������ ������ � ��� ������� ��������
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
// 2 ������ ��� ��� �����
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
        result += *(arr +i);/*��������� � ������ ������� +i - ��������� � ���������� ������ ������� �� �������� �� i ���*/
    result = result / end;
    return result;
}


// ������� �� ��������� �����
int sum(int a, int b);  /*������������*/
int um(int a, int b);   /*���������*/
int st(int a, int b); /*�������*/
int prch(int a);        /*������� �����*/
/*//������ ������� ��������
//��������
int sum(int a, int b)
{
    return a + b;
}
//���������
int um(int a, int b)
{
    return a * b;
}
//�������
int st(int a, int b)
{
    int aa = a;
    for(int i = 1; i < b; i++)
        a *= aa;
    return a;
}
//������� �����
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

//��������� ���������� ����� ������ void=������� �.�. �. �� ���������� �������� ��������
void swapP(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

using namespace std;

int main()
{
    // ��������� �������� �����
    setlocale(0,"Russian");
    printf("������ �����\n");
    // ���������� ���������� �
   /* int a = 2;
    //printf("����� a:%p\n", &a);
    // ����� �� �����
    printf("a = %d\n",a);
    // ������� ��� ��������
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
    // ����������� ���������� � ������
    float b = 5;
    // ����� ���������� � 3 ������� ����� .
    printf("b = %.2f\n",b);
    printf("b = b/2\n");
    b = b/2;
    printf("b = %.2f",b);*/
    // ������ ����� ��������
    //int i;
    //printf("���� �������� ");
    //scanf("%d", &i);
    //printf("��������� �����: %d\n", i);
    //printf("����� ��������:%p\n", &i);*/
    // ��������� ���������
    //char an /*= '���'*/;
    /*printf(" 1 ��� 2 ");
    scanf("\n%c", &an);
    // ������� � ���������� �����������
    /*if (an == '1')
    {
        printf("�");
    }
    else if (an == '2')
    {
        printf("��");
    }
    else
    {
        printf("��?");
    }
    //printf("%c", an);*/
    // ���������
    /*int a;
    int b;
    int c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d",&b);
    // ������ ����� ������
    //���� a>b �� � = �, ����� � = b
    //c = (a > b) ? a : b;
    //printf("c = %d",c);
    // ��������� ������ �������� printf � ����������� �������
    //printf("%s", (a > b) ? "a ������" : "b ������");
    if(a > b)
        printf("� ������");
    else if(a < b)
        printf("� ������");
    else
        printf("����� �����");*/
    // ������� � �������
    /*int a;
    int ost;
    printf("������� ����� �� 0 �� 10\n");
    scanf("%d",&a);
    // ������ �������� �� �������
    ost = a % 2;
    // �������� �� ��������
    if(a >= 0 && a <= 10)
        printf("%s", (ost ==0) ? "������" : "��������");
    else
        printf("�������� ���� �� 0 �� 10!!!!1111��������");*/
    // ����
    /*long long int a;
    int aa;
    int b;
    int i = 1;
    //printf("�����:");
    // �������� �����
    do{
        printf("�����:");
        scanf("%lli",&a);
        if(a > 10000)
            printf("��� ��������� \n");
    }while(a > 10000);
    aa = a;
    do{
        printf("�������:");
        scanf("%d",&b);
        if(b > 100)
            printf("��� ��������� \n");
    }while(b > 100);
    printf("^%d ",i);
    printf("%lli\n",a);
    while(i < b)
    {
        a = a * aa;
        //i++;
        //printf("^%d ",i);
        // ������ ������� ������ ��� i++
        //printf("^%d ",i++);
        //printf("%li\n",a);
        //������ � 1 ������
        printf("^%d %li\n",++i,a);
        //����������� ����� ��� ������������ ���������� �
        if (a >= 100000000)
        {
                printf("��� ���������");
                break;
        }

    }*/
    //���� for
    /*int a;
    for (a = 0; a < 5; a++)
    {
        printf("%d\n", a);
    }*/
    // �������� switch
    /*char a;
    printf("a = ");
    scanf("%s", &a);
    switch (a)
    {
    //���� ������ ����� '', ���� ����� �� �� �����
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
    printf("�����������\n");
    printf("������ �����: ");
    scanf("%d", &a);
    printf("������ �����: ");
    scanf("%d", &b);
    printf("%d+%d=%d\n", a , b, sum(a,b));
    printf("%d*%d=%d\n", a , b, um(a,b));
    printf("%d^%d=%d", a, b, st(a,b));*/

    // ������� ����� �� ��������� �� 1 �� �
    /*int a;
    //int b = 0;
    int c = 0;
    //printf("������� ����� �� ���������� �� 1 ��: ");
    scanf("%d", &a);
    //printf("%s", (prch(a) == 1) ? "�������" : "�� �������");
    for(int i = 1; i < (a +1 ); i++)
    {
       //printf("����� %d %s\n", i, (prch(i) == 1) ? "�������" : "�� �������");
        if (prch(i) == 1)
            printf(" ����� %d ������� \n",i);
    }*/
    // ������ � ������������
    /*int a = 11;
    int b = 22;
    //printf("a = %d\n",a);
    //printf("����� �: %p\n",&a);
    //����������� ���������� (* - ��������� )
    //int * addres;
    // ����������
    //addres = &a;
    //printf("�������� ���������: %p\n", addres);
    //printf("������ ��������� %p\n", &addres);
    //printf("��������� ��������� ��: %d\n", *addres);
    //��� �������� ����� ���������
    //*addres += 10;
    //printf("����� ��������: %d\n",a);
    //��������� � �. ����� ���������
    printf("a=%d b=%d\n",a,b);
    swapP(&a,&b);
    printf("a=%d b=%d\n",a,b);*/
    //�������
    //���������
    /*int arr[4];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    //2 ������� �����������
    int arr2[5] = {1, 2, 3, 4, 5};
    //int a = 4;
    //for( int i = 0; i < a ; i++)
        //printf("%d\n", arr[i]);
    //��������� ��������� �����
    srand(time(NULL));
    //printf("%d", (rand() % 100/*����������� ���������� �����*///));

    //�������
    /*int arr[5] = {2, 3, 5, 7, 9};
    //int arr[2][2] = {
        {1, 2,}
        {3, 4 }};   // ������ ���������� 2� �������
    prArr(arr, 5);
    printf("\n%2.1f", average(arr, 5));*/
    //��� ���������
    /*int x;
    int y;
    char esc;
    int a;
    do{
        printf("\n");
        printf("���������� �����: ");
        scanf("%d",&x);
        printf("���������� ��������: ");
        scanf("%d",&y);
        TabPif(y+1,x+1);
        printf("\n��������� (y/n)");
        scanf("%s",&esc);
    }while(esc != 'n');*/
    /*int x = 4;
    int y = 3;
    char ds;
    printf("��� ������ (y/n)");
    scanf("%s",&ds);
    printf("���������� �����: ");
    scanf("%d",&x);
    printf("���������� ��������: ");
    scanf("%d",&y);
    if(ds == 'y')
        TabPif(y,x);
    else if(ds == 'n')
        TabPif2(y,x);
    else
        printf("�������� ����");*/

    // ������ �� ����� � ���� ������
    //char * stringArr[3] = {"���", "���", "��� �� ��"};
    //printf("%s", stringArr[1]);
    //������ ������ ������ � ��������� � �������� �����
    /*int a = 1;
    int b = 2;
    int c;
    int a1, a2;
    int b1, b2;
    c = Fun1(a,b,&a1,&b1);
    Fun2(a,b,&a2,&b2);
    printf("a=%d b=%d c=%d a1=%d b1=%d\n",a,b,c,a1,b1);
    printf("a2=%d b2=%d",a2,b2);*/

    //�������� � �������
    /*char name[255];
    char result[255];
    gets(name); //��������� �����
    //puts(name); //����� �����
    hellFun(name, result); //����� �������
    printf("%s\n",result);
    /*char wellc[255] = "Hi, ";
    strcat(wellc, name); //����������
    printf("%s\n", wellc);
    strcpy(result, wellc);   //����������� ������
    printf("%s\n", result);*/
    // ������ �������� ���������� �������� � ��������
    /*char a[64];
    gets(a);
    int b = atoi(a);
    printf("%d",b * 2);*/
    /*Fraction f1, f2, result;
    f1.integer = -1; //�����
    f1.divisible = 1; //�������
    f1.divider = 5;  //��������
    f2.integer = 1;
    f2.divisible = 1;
    f2.divider = 5;
    result.integer = 0;
    result.divisible = 0;
    result.divider =0;
    // �����
    /*if (f1.integer != 0)
        printf("%3d & %d/%d\n",f1.integer, f1.divisible, f1.divider);
    else
        printf("      ""%d/%d\n", f1.divisible,f1.divider);
    printf("%3d & %d/%d\n",f2.integer, f2.divisible, f2.divider);*/
    // ����� ����� �.
    /*FRprint(f1);
    printf("\n");
    FRprint(f2);
    printf("\n");
    FRsum(f1,f2,&result);
    FRprint(result);*/


    //������� � ������� ���
    /*if (f1.integer < 0)
        f1.divisible = (f1.divider * f1.integer - f1.divisible); // ���������� ���������
    else
        f1.divisible = (f1.divider * f1.integer + f1.divisible);
    f1.integer = 0;
    printf("     ""%2d/%d\n",f1.divisible,f1.divider);
    // ������� � ��� ������ � �����
    if ((f1.divisible > f1.divider) or ((f1.divisible * -1) > f1.divider))
    {
        f1.integer = f1.divisible / f1.divider;     //���������� ������
        f1.divisible = f1.divisible % f1.divider;   //���������� ������ ��������
        if (f1.divisible < 0)                       //�������� �� "-"
            f1.divisible *= -1;
        printf("%3d & %d/%d",f1.integer,f1.divisible,f1.divider);
    }*/
    // �������� �������
    /*f = fopen("File1.txt", "w");
    if (f == 0); // ���� �� �������
    fprintf(f, "����� ������ � ����,  ���!");  // ������ � ����
    fclose(f);                                  // �������� �����
    f = fopen("File1.txt", "r");
    char word[256];
    while(!feof(f)) // ���� �� ��������� ����� ����� feof(f) == 1 ���� ����� ����� �� ���������, feof(f) == 0, ���� ����� ����� ���������
    {
        fscanf(f, "%s", word);
        printf("%s_", word);
    }
    //fscanf(f, "%s", word);
    //printf("%s", word);
    fclose(f);*/

    // ��������� ������
    //int * area = malloc(123); //��������� ������ ��� 123 ����
    //int * area = (int*) malloc(123); //��������� ������ ��� 123 ���� c ���������
    //printf("%lu", sizeof(int)); // ������� ������ � ������ ���� ������ int
    const int stop = 10;
    int * array1 = (int*) malloc(sizeof(int) * 10);   //��������� ������ ��� 10 ���������� ���� int �� ����� �� �������� ������
    int * array2 = (int*) calloc(stop, sizeof(int));  //�������� ������ � ������� � ����������, ���������� ������� ������� ��������� � �� ������
    for (int i = 0; i < stop; i++){
        *(array1 + i) = i * 10;
        printf("%d ", *(array1 + i));
    }
    //free(array1);    //������������ ������
    printf("\n");
    for (int i = 0; i < stop; i++){
        *(array2 + i) = i * 10;
        printf("%d ", *(array2 + i));
    }
    free(array2);
    printf("\n");
    const int newstop = 20;
    array1 = (int*) realloc(array1, newstop * sizeof(int)); //��������� ������� ������
    for (int i = 0; i < newstop; i++){
        *(array1 + i) = i * 10;
        printf("%d ", *(array1 + i));
    }
    free(array1);

    return 0;
}
