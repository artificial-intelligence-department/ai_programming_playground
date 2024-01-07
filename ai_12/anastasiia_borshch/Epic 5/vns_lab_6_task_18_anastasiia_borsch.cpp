#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char s[256];
  char words[256][256]; 
  int count = 0;  
  printf("Enter string: ");
  fgets(s, sizeof(s), stdin);
  s[strcspn(s, "\n")] = '\0'; 

  char *p = s;
  while (*p) {
    if (isdigit(*p)) {
      char *w = p;
      while (*p && !isspace(*p)) {
        p++;
      }
      strncpy(words[count], w, p - w);  
      words[count][p - w] = '\0';
      count++;
    }
    p++;
  }
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (strcmp(words[i], words[j]) < 0) {
        char temp[256];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]); 
        strcpy(words[j], temp); 
      }
    }
  }
  for (int i = 0; i < count; i++) {
    puts(words[i]);
  }

  return 0;
}

