#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "dictionary.txt"
#define WORDLENGTH 30
#define NUMOFWORDS 62000

int substring(char shortstr[], char longstr[]);     
int subsquence(char shortstr[], char longstr[]);    
int matchScore(char str1[], char str2[]);           
int permutation(char str1[], char str2[]);          
void bubbleSort(char str[][WORDLENGTH], int n);     
int search(char str[][WORDLENGTH], int n, char s[]);

int main(){
    char *lineBuf = NULL;
    size_t lineBufSize = 0;
    int lineCount = 0;
    ssize_t lineSize;
    FILE *fp = fopen(FILENAME, "r");
    char wordInput[WORDLENGTH], wordFromFile[NUMOFWORDS][WORDLENGTH], wordInp[WORDLENGTH], choice = 'y';

    printf("Welcome to the Spell Checker!\n");
    if(!fp){
        printf("Cannot read file %s\n", FILENAME);
    }
    else
        printf("The dictionary has been loaded!\n");

    lineSize = getline(&lineBuf, &lineBufSize, fp);

    while(lineSize >= 0){
        lineCount++;

        strcpy(wordFromFile[lineCount], lineBuf);
        lineSize = getline(&lineBuf, &lineBufSize, fp);
    }

    lineCount++;

    while(choice == 'y'){
        printf("Please enter the word you would like checked.\n");
        gets(wordInput);
        strcpy(wordInp,wordInput);
        strcat(wordInput,"\n");

        if(search(wordFromFile, lineCount, wordInput) == 1){

            printf("Great, %s is in the dictionary!\n", wordInp);
        }
        else{
            printf("Here are the possible words you could have meant:\n");
            for(int i = 0; i < lineCount; i++){
                if(substring(wordFromFile[i], wordInput) == 1
                    || subsquence(wordFromFile[i], wordInput) == 1
                    || (matchScore(wordFromFile[i], wordInput) < 3 && matchScore(wordFromFile[i], wordInput) >= 0)
                    || permutation(wordFromFile[i], wordInput) == 1)
                    printf("%s", wordFromFile[i]);
            }
        }

        fflush(stdin);
        printf("Would you like to enter another word? (yes/no)\n");
        scanf("%c", &choice);
    }
    free(lineBuf);
    lineBuf = NULL;

    getchar();
    return 0;
}

int substring(char shortstr[], char longstr[]){
    char *p1, *p2, *p3;
    int i = 0, j = 0, flag = 0, lenShort = strlen(shortstr), lenLong = strlen(longstr);

    p1 = longstr;
    p2 = shortstr;

    if(lenShort > lenLong)
        return 0;

    for(i = 0; i < lenLong; i++){
        if(*p1 == *p2){
            p3 = p1;

            for(j = 0; j < lenShort; j++){
                if(*p3 == *p2){
                    p3++; p2++;
                }
                else break;
            }

            p2 = shortstr;

            if(j == lenShort){
                flag = 1;
            }
        }

        p1++;
    }

    return flag;
}

int subsquence(char shortstr[], char longstr[]){
    int i = 0, j = 0;

    if(strlen(shortstr) > strlen(longstr))
        return 0;

    while(shortstr[i] != '\0'){
        while(shortstr[i] != longstr[j] && longstr[j] != '\0')
            j++;
        if(longstr[j] == '\0')
            break;
        j++; i++;
    }

    return shortstr[i] == '\0' ? 1 : 0;
}

int matchScore(char str1[], char str2[]){
    int len1 = strlen(str1), len2 = strlen(str2), count = 0;

    if(len1 != len2)
        return -1;
    
    for(int i = 0; i < len1; i++){
        if(str1[i] != str2[i])
            count++;
    }

    return count;
}

int permutation(char str1[], char str2[]){
    int len1 = strlen(str1), len2 = strlen(str2), i;
    int count[26] = {0};

    if(len1 != len2)
        return 0;
    
    for(i = 0; str1[i] && str2[i]; i++){
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }

    for(i = 0; i < 26; i++)
        if(count[i])
            return 0;
    
    return 1;
}

void bubbleSort(char str[][WORDLENGTH], int n){
    char temp[WORDLENGTH];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(strcmp(str[j - 1], str[j]) > 0){
                strcpy(temp, str[j - 1]);
                strcpy(str[j - 1], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

int search(char str[][WORDLENGTH], int n, char s[]){
    for(int i = 0; i < n; i++){
        if(strcmp(str[i], s) == 0)
            return 1;
    }

    return 0;
}
