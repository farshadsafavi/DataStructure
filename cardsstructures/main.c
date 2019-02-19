#include <stdio.h>
#include <stdlib.h>
struct card{
    int face;
    int shape;
    int colour;
};

struct deck{
    struct card card[52]
};
int main()
{
    printf("Hello world!\n");
    struct deck d;
    int i = 0;
    for(i = 0; i < 52; i++){
        d.card[i].shape = (i%4) + 1;
        d.card[i].face = (i%12) + 1;
        d.card[i].colour = (i%2) + 1;
    }
    printf("%d", d.card[11].face);
    return 0;
}
