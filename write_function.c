#include <stdio.h>
#include <unistd.h>
#include <string.h>

 int len_char(char *str)
{
   int len = 0;
 
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
int main()
{
    int len = len_char("A");
    write(1, "A", len);
    return 0;
}
