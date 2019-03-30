#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int findNumberOfCharacter(char *word){
    int i =0;
    for( i = 0 ; word[i] != '\0';i++){
    }
    printf("The length is %d\n", i);
    return i;
}

char* lowecase(char *word){
    int i;
    for(i = 0; word[i] != '\0'; i++){
        if(word[i]>= 'A' && word[i] <='Z'){
            word[i] += 32;
        }
    }
    return word;
}

char* toggle(char *word){
    int i;
    for(i = 0; word[i] != '\0'; i++){
        if(word[i]>= 'A' && word[i] <='Z'){
            word[i] += 32;
        } else if(word[i]>= 'a' && word[i] <='z'){
            word[i] -= 32;
        }
    }
    return word;
}

int numberOfVowels(char *word){
    int i =0;
    int n = 0;
    for( i = 0 ; word[i] != '\0';i++){
        if(word[i] == 'a' ||
           word[i] == 'e' ||
           word[i] == 'o' ||
           word[i] == 'i' ||
           word[i] == 'y' ||
           word[i] == 'A' ||
           word[i] == 'E' ||
           word[i] == 'O' ||
           word[i] == 'I'){
               n++;
        }
    }
    printf("number of vowels %d\n", n);
    return n;
}



int numberOfConsonants(char *word){
    int i =0;
    int n = 0;
    for( i = 0 ; word[i] != '\0';i++){
        if(word[i] == 'a' ||
           word[i] == 'e' ||
           word[i] == 'o' ||
           word[i] == 'i' ||
           word[i] == 'y' ||
           word[i] == 'A' ||
           word[i] == 'E' ||
           word[i] == 'O' ||
           word[i] == 'I'){
        } else if((word[i]>= 'a' && word[i] <= 'z') ||
                  (word[i]>= 'A' && word[i] <= 'Z')){
            n++;
        }
    }
    printf("number of consonants %d\n", n);
    return n;
}

int numberOfWords(char *word){
    int i =0;
    int n = 1;
    for( i = 1 ; word[i] != '\0';i++){
        if(word[i] == ' ' && word[i - 1] != ' '){
           n++;
        }
    }
    printf("number of words %d\n", n);
    return n;
}

char* reverseString(char word[]){
    int i =0;
    int n = 0;
    for( i = 0 ; word[i] != '\0';i++){
        n++;
    }
    int j = 0;
    char temp;
    printf("Length %d\n", n);
    for(i = 0, j = n - 1; i < j;i++, j--){
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    return word;
}

void reverseString2(char *word){
    int i =0;
    for( i = 0 ; word[i] != '\0';i++){
    }
    int j = i - 1;
    printf("Length %d\n", i);
    char reverse[i];
    i = 0;
    while(j >= -1){
        reverse[i++] = word[j--];
    }
    reverse[i - 1] = '\0';
    printf("%s\n", reverse);
}

bool validString(char *word){
    int i =0;
    bool valid = false;
    for( i = 0 ; word[i] != '\0';i++){
        valid = (word[i] >= 'a' && word[i] <= 'z') ||
                (word[i] >= 'A' && word[i] <= 'Z') ||
                (word[i] >= '1' && word[i] <= '9');
    }
    if (valid)
        printf("Valid\n");
    else
        printf("Not valid\n");
    return valid;
}

void compareStrings(char *word1, char *word2){
    int i = 0;
    int j = 0;
    printf("start comparing:\n");
    for(i = 0, j = 0; word1[i] !='\0' && word2[j] != '\0'; i++, j++){
        printf("%c and %c\n", word1[i],word2[j]);
        if(word1[i] != word2[j]){
            break;
        }
    }
    if(word1[i] == word2[j]) printf("Equal!\n");
    else if(word1[i] > word2[j]) printf("Greater!\n");
    else printf("Smaller!\n");

}

bool palindrome(char *word){
    int i = 0;
    int j = 0;
    int n = 0;
    bool palindrom = true;
    for(n = 0; word[n] != '\0';n++){
    }
    for( i = 0, j = n - 1 ; i < j;i++, j--){
        if(word[i] != word[j]) return false;
    }

    return palindrom;
}

void findDuplicate(char word[]){
    int i = 0;
    int n;
    for(n = 0; word[n] != '\0';n++){
    }
    printf("%d", n);

    int j = 0;
    for(i = 0; i < n - 1;i++){
        int count = 1;
        printf("%c\n",word[i]);
        if(word[i] != 0){
            for(j = i + 1; j < n; j++){
                if(word[i] == word[j]){
                    word[j] = 0;
                    count++;
                }
            }
            printf("%c is repeated %d times.\n", word[i], count);
        }
    }

}

void findDuplicate2(char word[]){
    int i = 0;
    int n = 0;
    char H[26];
    for(i = 0; i < 26; i++){
        H[i] = 0;
    }
    for(n = 0; word[n] != '\0';n++){
        H[word[n] - 'a'] += 1;
    }

    for(i = 0;i < 26; i++){
        if(H[i] > 1)
            printf("%c is repeated %d times.\n", i + 'a', H[i]);
    }

}

void findDuplicate3(char word[]){
    int i = 0;
    long int H = 0, x;
    for(i = 0; word[i] != '\0'; i++){
        x = 1;
        x = x << word[i] - 'a';
        if(H & x > 0){
            printf("duplicate letter is %c\n", word[i]);
        } else{
            H = H | x;
        }
    }
}

int main()
{
    /*
    printf("Strings\n");
    printf("%c is %d\n", 'A', 'A');
    printf("%c is %d\n", 'Z', 'Z');

    printf("%c is %d\n", 'a', 'a');
    printf("%c is %d\n", 'z', 'z');

    printf("%c is %d\n", '0', '0');
    printf("%c is %d\n", '9', '9');

    //printf("Ascii code are from 0-127. Total 1 byte(256 bits) representation in memory!");

    char temp;
    temp = 'A';
    printf("temp contains %d which is %c\n", temp, temp);

    char x[5];
    printf("x contains %s\n", x);
    char y[5] = {'A', 'B','\0'};
    printf("y contains %s\n", y);
    char z[] = {'A','B','C','D','E','\0'};
    printf("z contains %s\n", z);
    char m[] = {66, 67, 68, 69, '\0'};
    printf("m contains %s\n", m);


    // create string
    char n[] = "Farshad";
    printf("n contains %s\n", n);
    char o[] = "Farshad Safavi";
    printf("o contains %s\n", o);

    char *str = "Alireza Amini";
    printf("str contains %s\n", str);
    printf("str address is %d\n", str);

    char name[10];
    printf("Enter the name:");
    scanf("%s", name);
    printf("The name you typed is: %s\n", name);
    getchar();

    char *complete_name;
    printf("Enter the first name and last name:");
    gets(complete_name);
    printf("The complete name is: %s\n", complete_name);
    findNumberOfCharacter(complete_name);

    complete_name = toggle(complete_name);
    printf("The complete name toggles is: %s\n", complete_name);
    complete_name = lowecase(complete_name);
    printf("The complete name is: %s\n", complete_name);
    complete_name = toggle(complete_name);
    printf("The complete name toggles is: %s\n", complete_name);
    numberOfVowels(complete_name);
    numberOfConsonants(complete_name);
    numberOfWords(complete_name);
    validString(complete_name);
    printf(reverseString(complete_name));
    printf("\n");
    reverseString2(complete_name);

    char *name1 = "painting";
    char *name2 = "painted";
    compareStrings(name1, name2);

    char name3[] = "Salama";
    compareStrings("Salama", reverseString(name3));

    compareStrings(name1, name2);
    char *name5 = "madam";
    printf("%d\n", palindrome(name5));
    */
    char name6[] = "abbccbba";
    //printf("%d\n", palindrome(name6));
    //findDuplicate(name6);
    //findDuplicate2(name6);
    findDuplicate3(name6);
    return 0;
}
