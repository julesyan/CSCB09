#include <stdio.h>

int y = -1;

struct test{
    struct test *next;
    int i;
};

struct test *first;

void insert()
{
    struct test *this;

    this = first;
    if ((this = this->next))
        y = this->i;
}

int main ()
{
    /*extern void insert();
    struct test a;
    first = &a;
    a.i = 1;
    a.next = NULL;
    sec.i = 2;
    sec.next = &third;
    third.i = 3;
    third.next = NULL;
    insert();
    printf("%i\n", y);
    return(0);*/
    if (0)
        printf("0\n");
    else if (1)
        printf("1\n");
}
