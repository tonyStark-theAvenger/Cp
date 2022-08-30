#include <stdio.h>
int main()
{
    char ch, s[9], sen[15];
    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", sen); //to take input whole sentence
    printf("%c \n%s", ch, s);
    printf("\n%s", sen);
    return 0;
}