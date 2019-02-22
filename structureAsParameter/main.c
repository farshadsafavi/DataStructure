#include <stdio.h>
#include <stdlib.h>
struct Rectangle{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r){
    return r.breadth*r.length;
}
void changeLength(struct Rectangle *r, int l){
    r->length = l;
}

int main()
{
    printf("Structure as parameter:\n");
    struct Rectangle r;
    initialize(&r, 10, 5);
    printf("length: %d and breadth: %d\n", area(r));
    printf("area: %d\n", area(r));
    changeLength(&r, 120);
    printf("length: %d\n", r.length);
    return 0;
}
