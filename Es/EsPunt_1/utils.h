#ifndef UTILS_H
#define UTILS_H
//parte I
void print_string(const char s[]);
//parte II
int length_string(const char s[]);
//parte III
void reverse_string(char s[]);
//parte IV
char* copy_string(const char s[]);
//parte V
char* concat_string(const char s[], const char s2[]);
//parte VI
const char* token_string(const char t[], const char pat[]);
//parte VII
const char* sub_string(const char t[],const char  pat[]);
//parte VII v2
const char* sub_string2(const char t[], const char pat[], const char newPat[]);
#endif
