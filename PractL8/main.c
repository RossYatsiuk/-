#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 14


long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}


long long countAnagrams(char *word) {
    int n = strlen(word);
    int char_count[26] = {0};  
    
    for (int i = 0; i < n; ++i) {
        char_count[word[i] - 'a']++;
    }
    
    long long denominator = factorial(n);
    
    
    for (int i = 0; i < 26; ++i) {
        if (char_count[i] > 1) {
            denominator /= factorial(char_count[i]);
        }
    }
    
    return denominator;
}

int main() {
    char word[MAX_LENGTH + 1];  
    printf("Введіть слово: ");
    scanf("%s", word);
    
    
    long long anagrams_count = countAnagrams(word);
    
    printf("Кількість анаграм \"%s\": %lld\n", word, anagrams_count);
    
    return 0;
}
