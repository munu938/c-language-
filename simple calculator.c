#include <stdio.h>
#include <math.h>
#include <ctype.h>

// ── individual operation functions ──────────────────────────────────────────

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("  Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

double power(double base, double exp) {
    return pow(base, exp);
}

double percentage(double a, double b) {
    // returns b% of a  →  e.g. percentage(200, 15) = 30
    return (a * b) / 100.0;
}

double modulus(double a, double b) {
    if ((int)b == 0) {
        printf("  Error: Modulus by zero is not allowed.\n");
        return 0;
    }
    return fmod(a, b);
}

// ── display menu ─────────────────────────────────────────────────────────────

void show_menu() {
    printf("\n╔══════════════════════════════╗\n");
    printf("║       Simple Calculator      ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("║  +   Addition                ║\n");
    printf("║  -   Subtraction             ║\n");
    printf("║  *   Multiplication          ║\n");
    printf("║  /   Division                ║\n");
    printf("║  ^   Exponentiation (a^b)    ║\n");
    printf("║  %%   Percentage  (b%% of a)   ║\n");
    printf("║  m   Modulus (remainder)     ║\n");
    printf("║  q   Quit                    ║\n");
    printf("╚══════════════════════════════╝\n");
}

// ── main ──────────────────────────────────────────────────────────────────────

int main() {
    double num1, num2, result;
    char op;
    int need_second; // some ops need a second number

    printf("\n  Welcome to the C Calculator!\n");

    while (1) {
        show_menu();

        // ── get operator ──
        printf("\n  Choose an operator: ");
        scanf(" %c", &op);          // space before %c skips whitespace/newline

        if (op == 'q' || op == 'Q') {
            printf("\n  Goodbye!\n\n");
            break;
        }

        // validate operator early
        if (op != '+' && op != '-' && op != '*' && op != '/' &&
            op != '^' && op != '%' && op != 'm' && op != 'M') {
            printf("  Error: Unknown operator '%c'. Try again.\n", op);
            continue;
        }

        // ── get first number ──
        printf("  Enter first number  : ");
        if (scanf("%lf", &num1) != 1) {
            printf("  Error: Invalid number. Try again.\n");
            while (getchar() != '\n'); // flush bad input
            continue;
        }

        // ── get second number ──
        printf("  Enter second number : ");
        if (scanf("%lf", &num2) != 1) {
            printf("  Error: Invalid number. Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        // ── calculate ──
        switch (op) {
            case '+':
                result = add(num1, num2);
                printf("\n  %.6g + %.6g = %.6g\n", num1, num2, result);
                break;

            case '-':
                result = subtract(num1, num2);
                printf("\n  %.6g - %.6g = %.6g\n", num1, num2, result);
                break;

            case '*':
                result = multiply(num1, num2);
                printf("\n  %.6g × %.6g = %.6g\n", num1, num2, result);
                break;

            case '/':
                if (num2 == 0) {
                    printf("\n  Error: Cannot divide by zero.\n");
                } else {
                    result = divide(num1, num2);
                    printf("\n  %.6g ÷ %.6g = %.6g\n", num1, num2, result);
                }
                break;

            case '^':
                result = power(num1, num2);
                printf("\n  %.6g ^ %.6g = %.6g\n", num1, num2, result);
                break;

            case '%':
                result = percentage(num1, num2);
                printf("\n  %.6g%% of %.6g = %.6g\n", num2, num1, result);
                break;

            case 'm':
            case 'M':
                if ((int)num2 == 0) {
                    printf("\n  Error: Modulus by zero is not allowed.\n");
                } else {
                    result = modulus(num1, num2);
                    printf("\n  %.6g mod %.6g = %.6g\n", num1, num2, result);
                }
                break;
        }

        printf("  ─────────────────────────────\n");
    }

    return 0;
}