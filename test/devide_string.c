#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "apple,banana,orange";
    const char delimiter[] = ",";

    char *token = strtok(input, delimiter); // Initial call

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiter); // Subsequent calls
    }

    return 0;
}
