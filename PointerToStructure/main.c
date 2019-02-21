#include <stdio.h>
#include <stdlib.h>
struct Rectangle{
    int length;
    int breadth;
};
int main()
{
    printf("Pointer to structure:\n");
    struct Rectangle r = {10, 15};
    printf("The length is %d and breadth is %d\n", r.length, r.breadth);
    struct Rectangle *p;
    p = &r;
    p->length = 18;
    p->breadth = 31;
    printf("The length is %d and breadth is %d\n", (*p).length, p ->breadth);
    struct Rectangle *p2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p2->length = 1;
    // Or we can use pointer notation
    (*p2).breadth= 2;
    printf("The length is %d and breadth is %d\n", (*p2).length, p2 ->breadth);
    return 0;
}
