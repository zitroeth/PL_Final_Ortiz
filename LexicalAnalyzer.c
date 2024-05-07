#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int analyzeString(char* statement);
void print_result(int value);

#define MAX_NAME_SZ 256
// (^(int|char|float|double)\\s+[_|[:alpha:]][[:alnum:]]*\\s*;\\s*\n$)|                               int 4;
// (^(char)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:alpha:]]\\s*;\\s*\n$)|                            char dsadsa = d;
// (^(int)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:digit:]]+\\s*;\\s*\n$)                             int dasdsa = 21321;
// (^(float|double)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:digit:]]+(.[[:digit:]]+)?\\s*;\\s*\n$)    float dsad = 55.4;
// (^[_|[:alpha:]][[:alnum:]]*\\s*(\\+=|-=|\\*=|/=|%=)\\s*([[:digit:]]+(.[[:digit:]]+)?)|([_|[:alpha:]][[:alnum:]]*)\\s*;\\s*\n$) float dsadsa += dsads; float dsadsa += 432423.6546;
// (^[_|[:alpha:]][[:alnum:]]*\\s*(\\+\\+|--);\\s*\n$)                                                dsadsa++;
int main(){
    regex_t reegex;
    char *statement = malloc(MAX_NAME_SZ);
    char regex_pattern[] = "(^(int|char|float|double)\\s+[_|[:alpha:]][[:alnum:]]*\\s*;\\s*\n$)|(^(char)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:alpha:]]\\s*;\\s*\n$)|(^(int)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:digit:]]+\\s*;\\s*\n$)|(^(float|double)\\s+[_|[:alpha:]][[:alnum:]]*\\s*=\\s*[[:digit:]]+(.[[:digit:]]+)?\\s*;\\s*\n$)|(^[_|[:alpha:]][[:alnum:]]*\\s*(\\+=|-=|\\*=|/=|%=)\\s*([[:digit:]]+(.[[:digit:]]+)?)|([_|[:alpha:]][[:alnum:]]*)\\s*;\\s*\n$)|(^[_|[:alpha:]][[:alnum:]]*\\s*(\\+\\+|--);\\s*\n$)";

    int value = regcomp(&reegex, regex_pattern, REG_EXTENDED);

    while(1){
        (void)printf("\nEnter statement to be checked: ");
        (void)fgets(statement, MAX_NAME_SZ, stdin);
        (void)printf("\nStatement = %s", statement);
        print_result(regexec( &reegex, statement, 0, NULL, 0));
    }

    return 0;
}

void print_result(int value){
    // If pattern found
    if (value == 0) {
        (void)printf("Pattern found.\n");
    }
    // If pattern not found
    else if (value == REG_NOMATCH) {
        (void)printf("Pattern not found.\n");
    }
    // If error occurred during Pattern matching
    else {
        (void)printf("An error occurred.\n");
    }
}