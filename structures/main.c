#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    int length;
    int breadth;
};

int main()
{
    printf("Hello world!\n");
    struct Rectangle r;
    r.length = 10;
    r.breadth = 20;
    printf("%d and %d\n", r.length, r.breadth);

    struct Rectangle r2 = {18, 23};
    printf("%d and %d\n", r2.length, r2.breadth);
    r2.length = 80;
    r2.breadth = 90;
    printf("%d and %d\n", r2.length, r2.breadth);

    return 0;
}
