#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(char original[], char contido[]);

int main()
{
    char string1[100001];
    char string2[101];
    int n;
    int q;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", string1);
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            scanf("%s", string2);
            printf(check(string1, string2) ? "Yes\n" : "No\n");
        }

    }

    return 0;
}

bool check(char original[], char contido[])
{
    int i = 0;
    int j = 0;

    while (i < strlen(original)) {
        if (original[i] == contido[j]) {
            j++;
        }
        i++;
    }

    return (j == strlen(contido));
}