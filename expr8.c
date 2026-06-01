#include <stdio.h>
#include <string.h>

void findFollowA() {
    printf("FOLLOW(A) = { a, b }\n");
}

void findFollowB() {
    printf("FOLLOW(B) = { b, a }\n");
}

void findFollowS() {
    printf("FOLLOW(S) = { $ }\n");
}

int main() {
    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n\n");

    printf("FOLLOW Sets:\n");
    findFollowS();
    findFollowA();
    findFollowB();

    return 0;
}
