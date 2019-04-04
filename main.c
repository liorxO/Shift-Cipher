#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shiftCipher (char m[], int shift);
void bruteShift(char* c);

int main() {
    char m[] = "HELLOMYNAMEISLIOR";
    char *c = shiftCipher(m, 19);
    printf("c in main: %s\n", c);
    bruteShift(c);
    return 0;
}

char* shiftCipher(char m[], int shift) {
    char *q = m;
    char *p = (char*)malloc(strlen(m));
    printf("M = %s\n",m);
    while (*q != '\0') {
        *p = ((((*q - 'A') + shift)) % 26) + 'A' ;
        p++; q++;
    }
    *p = '\0';
    p-=strlen(m);
    printf("c = %s\n", p);
    return p;
}

void bruteShift(char* c) {
    char *p = c;
    int i;
    printf("\nCipher String = %s, Brute Forcing:\n", c);
    for (i = 0; i < 26; i++) {
        printf("%d: ",i);
        while (*p != '\0') {
            printf("%c",((((*p - 'A') - i) + 26) % 26) + 'A');
            p++;
        }
        printf("\n");
        p = c;
    }
}



