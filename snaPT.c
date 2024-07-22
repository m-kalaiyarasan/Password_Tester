#include <stdio.h>
#include "password.c"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *pass;
    pass = getpass("Enter a password: ");
    printf("Password: %s\n", pass);
    int strength = check_password(pass);
    printf("Password Strength: %d", strength);
}
