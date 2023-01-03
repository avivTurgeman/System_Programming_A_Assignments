#include<stdio.h>
#include<string.h>

#define LINE 256
#define WORD 30

char string_received[(256*250) + 1] =  "";

/**
 * @brief this method counts the number of lines in char string_received[]
 * 
 * @param s copying the string_received into s
 * @return int the number of lines
 */
int getLine(char s[]){
    int counter = 0;
    for(int i = 0; string_received[i] !='\0'; i++){
        s[i] = string_received[i];
        if(string_received[i] == '\n' || string_received[i] == '\0'){
            counter++;
        }
    }
    return counter;
}

/**
 * @brief this method counts the number of words in char string_received[]
 * 
 * @param w copying the string_received into w
 * @return int the number of words 
 */
int getword(char w[]){
    int counter = 0;
    for(int i = 0; string_received[i] !='\0'; i++){
        w[i] = string_received[i];
        if(string_received[i] == '\n' || string_received[i] == '\t' || string_received[i] == ' ' || string_received[i] == '\0'){
            counter++;
        }
    }
    return counter;
}

/**
 * @brief Checking if *str2 is a subString of *str1
 * 
 * @param str1 the main String
 * @param str2 the subString
 * @return int 1 if true, 0 if false
 */
int substring( char * str1, char * str2){
    int str1Len = strlen(str1); // sizeof(char) = 1
    int str2Len = strlen(str2); // sizeof(char) = 1
    int sub;
    
    if(str1Len < str2Len){
        return 0;
    }

    for(int i = 0; i <= str1Len - str2Len; i++){
        sub = 1;
        for(int j = 0; j < str2Len; j++){
            if(*(str1 + i + j) != *(str2 + j)){
                sub = 0;
            }
        }
        if(sub == 1){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Checks if possible to converte String *s into String *t by deleting n chars out of s 
 * 
 * @param s String to convert
 * @param t the wanted outcome String
 * @param n the number of chars to delete
 * @return int 1 if true, 0 if false
 */
int similar (char *s, char *t, int n){
    int sLen = strlen(s); // sizeof(char) = 1
    int tLen = strlen(t); // sizeof(char) = 1
    int ctr_chars = 0;
    int tPointer = 0;

    if(sLen < tLen){
        return 0;
    }

    if(n == 0){
        if(sLen != tLen){
            return 0;
        }
        for(int i = 0; i < sLen; i++){
            if(*(s + i) != *(t + i)){
                return 0;
            }
        }
        return 1;
    }

    for(int i = 0; i < sLen; i++){
        if(*(s + i) != *(t + tPointer)){
            ctr_chars++;
        }
        else{
            tPointer++;
        }
    }

    if( (tPointer == tLen) && (ctr_chars == n)){
        return 1;
    }
    return 0;
}

/**
 * @brief this method looks for all of the lines that include the String *str in char string_received[] and prints them
 * 
 * @param str the String to look
 */
void print_lines(char * str){
    char line[LINE + 1] = "";
    char word_per_line[WORD + 1] = "";
    int line_index = 0;
    int word_index = 0;
    int flag = 0;
    int bsnTimes = 0; //bsn := back slash n ( "\n" )

    for(int i = 0; i < strlen(string_received); i++){
        while(bsnTimes < 2){
            if(string_received[i] == '\n'){
                bsnTimes++;
                i++;
            }
            else{
                i++;
            }
        }        
        memset(line, 0, sizeof(line));

        while((string_received[i] != '\0') && (string_received[i] != '\n')){ 
            line[line_index] = string_received[i];                
            i++;
            line_index++;        
        }
        for(int j = 0; j < strlen(line); j++){
            memset(word_per_line, 0, sizeof(word_per_line));
            
            while((line[j] != ' ') && (line[j] != '\t') && (line[j] != '\n') && (line[j] != '\0')){
                word_per_line[word_index] = line[j];
                j++;
                word_index++;
            }
            word_per_line[word_index] = '\0';
            if(similar(word_per_line,str, 1) || similar(word_per_line,str,0)){
                flag = 1;
            }
            word_index = 0;
        }
        line_index = 0;
        if(flag){
            printf("%.*s\n", (int)strlen(line), line);
        }
        flag = 0;
    }
}

/**
 * @brief this method look for all the words in char string_received[] thats different from String *str up to 1 char
 * 
 * @param str the String to look
 */
void print_similar_words(char * str){
    char buffer[WORD + 1] = "";
    int buffer_index = 0;
    int bsnTimes = 0; //bsn := back slash n ( "\n" )

    for(int i = 0; i < strlen(string_received); i++){
        while(bsnTimes < 2){
            if(string_received[i] == '\n'){
                bsnTimes++;
                i++;
            }
            else{
                i++;
            }
        }    
        memset(buffer, 0, sizeof(buffer));
        
        while((string_received[i] != ' ') && (string_received[i] != '\t') && (string_received[i] != '\n') && (string_received[i] != '\0') ){ 
            if(string_received[i] == ' '){
            }
            buffer[buffer_index] = string_received[i];                
            i++;
            buffer_index++;        
        }
        buffer[buffer_index] = '\0';
        if(similar(buffer, str, 1)){
            printf("%.*s\n",(int)strlen(buffer), buffer);
        }
        else if(similar(buffer, str, 0)){
            printf("%.*s\n",(int)strlen(buffer), buffer);
        }
        buffer_index = 0;
    }

}

int main(int argc, char **argv) {
    char line[LINE];
    char cases;
    char compare[WORD] = "";
    int index = 0;

    // Read the input from stdin line by line and store it in string_received
    while (fgets(line, LINE, stdin)) {
        strcat(string_received, line);
    }

    for(index; index < LINE; index++){
        if((string_received[index] != ' ') && (string_received[index] != '\t')){
            compare[index] = string_received[index];
        }
        else{
            index++;
            break;
        }
    }



    cases = string_received[index];

    if(cases == 'a'){
        print_lines(compare);
    }
    else if(cases == 'b'){
        print_similar_words(compare);
    }
    else{
        printf("invalid char case input!\n");
    }

    return 0;
}