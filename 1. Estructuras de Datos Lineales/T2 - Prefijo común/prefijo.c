
#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 21

int main(void) {
    int n;
    char words[MAX_STRINGS][MAX_LENGTH];
    int prefixLength = 0;
    int isCommon;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%20s", words[i]);
    }

    while (words[0][prefixLength] != '\0') {
        isCommon = 1;

        for (int i = 1; i < n; i++) {
            if (words[i][prefixLength] == '\0' ||
                words[i][prefixLength] != words[0][prefixLength]) {

                isCommon = 0;
                break;
            }
        }

        if (!isCommon) {
            break;
        }

        prefixLength++;
    }

    if (prefixLength == 0) {
        printf("-\n");
    } else {
        for (int i = 0; i < prefixLength; i++) {
            printf("%c", words[0][i]);
        }
        printf("\n");
    }

    return 0;
}
