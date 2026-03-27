#include<stdio.h>
#include<string.h>

int main() {
    char name[50];
    int age;
    char email[100];
    char phone[20];
    char address[200];

    printf("=== Personal Information Form ===\n\n");

    // Name (non-empty check)
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    if (name[0] == '\0') {
        printf("Error: Name cannot be empty.\n");
        return 1;
    }

    // Age (validate scanf return + range check)
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1 || age <= 0 || age > 150) {
        printf("Error: Invalid age entered.\n");
        return 1;
    }
    getchar(); // consume leftover newline

    // Email (non-empty check)
    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    if (email[0] == '\0') {
        printf("Error: Email cannot be empty.\n");
        return 1;
    }

    printf("Enter your phone number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = 0;

    // Summary
    printf("\n=== Form Summary ===\n");
    printf("Name    : %s\n", name);
    printf("Age     : %d\n", age);
    printf("Email   : %s\n", email);
    printf("Phone   : %s\n", phone);
    printf("Address : %s\n", address);

    printf("\nForm submitted successfully!\n");

    return 0;
}