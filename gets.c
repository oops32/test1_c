#include <stdio.h>
#include <unistd.h>

// Uncalled secret function
// 00000000004005b6
void secretFunction()
{
    printf("Congratulations!\n");
    printf("You have entered in the secret function!\n Here is you JWT Token : eyJhbGciPiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c\n");

    return;
}

// Vulnerable function
int vuln() {
    // Define variables
    char array[400];

    // Grab user input
    printf("Enter some text:\n");
    // fgets(array, 400, stdin);
    gets(array);

    // Print user input
    printf("You entered: %s\n", array);

    // Return success
    return 0;
}

int main(int argc, char *argv[]) {
    vuln();

    return 0;
}

// cat /proc/sys/kernel/randomize_va_space 
// echo 0 > /proc/sys/kernel/randomize_va_space
// gcc -fno-stack-protector -z execstack -mpreferred-stack-boundary=4 -o example -ggdb example.c