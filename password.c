#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int check_password(char *password);
int test_pass_length(char *password);
int test_pass_upper(char *password);
int test_pass_lower(char *password);
int test_pass_symbol(char *password);
int test_pass_sequential(char *password);

int check_password(char *password) {
    int score = 0;
    score = score + test_pass_length(password);
    score = score + test_pass_upper(password);
    score = score + test_pass_lower(password);
    score = score + test_pass_symbol(password);
    score = score + test_pass_sequential(password);
    return score;
}

/**
 * Returns a score for password length
 * Takes password and minimum length. Returns 1 if conditions satisty.
 */
int test_pass_length(char *password){
    if(strlen(password) < 8){
        return 0;
    } else {
        return 1;
    }
}

/**
 * Checks if the password has uppercase character. Returns score 1 when it finds first occurance of upper case.
 */
int test_pass_upper(char *password){
    for(int i=0; i<strlen(password); i++){
        if(isupper(password[i])){
            return 1;
        }
    }
    return 0;
}


/**
 * Checks if there are a total of 3 lower case characters are in the password.
 * Returns score 2 if conditions satisfy.
 */ 
int test_pass_lower(char *password){
    int counter = 0;
    for(int i=0; i<strlen(password); i++){
        if(islower(password[i])){
            counter++;
        }
        if(counter >= 3){
            return 2;
        }
    }
    return 0;
}

/**
 * Checks if the password has punctuation character. Returns score 2 when it finds first occurance of symbol.
 */
int test_pass_symbol(char *password){
    for(int i=0; i<strlen(password); i++){
        if(ispunct(password[i])){
            return 1;
        }
    }
    return 0;
}

int test_pass_sequential(char *password) {
    int counter = 0;
    int score = 1;
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            counter++; //total number of digits
        }
    }

    if(counter >= 3){
        score = 1;
    }

    //checking for sequential numbers
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            int d1 = password[i];
            if(isdigit(password[i+1])){
                int d2 = password[i+1];
                if(abs(d2 - d1) == 1){
                    if(isdigit(password[i+2])){
                        int d3 = password[i+2];
                        if(abs(d3 - d2) == 1){
                            score = score + 0;
                        } else {
                            score = score + 2;
                        }
                    }
                    else {
                        continue;
                    }
                } else {
                    continue;
                }
                
            } else {
                continue;
            }
        }
    }
    return score;
}