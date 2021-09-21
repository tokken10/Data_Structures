#include<stdio.h>

void rec2(int x)
{
    if (x==0)
        return; //this breaking condition will result in poping the function call stack

    rec2(x-1);

    printf("%d  ", x); //this line is kept in the stack for each call of rec(x-1) in the above line

}


void rec1(int x)
{
    printf("--%d--", x);
    if (x==0)
        return;

    printf("%d  ", x);
    rec1(x-1);

}

int main()
{
    printf("Calling rec1: ");
    rec1(10);

   // printf("\nCalling rec2: ");
    //rec2(10);

}

