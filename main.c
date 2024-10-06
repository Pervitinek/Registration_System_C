#include <stdio.h>
#include <string.h>

struct User {
    char firstName[30];
    char lastName[30];
    char email[90];
};

void addUser(struct User users[], int *userCount, int max) {
    if (*userCount >= max) {
        printf("Dosahli jste maximalniho poctu uzivatelu\n");
    } else {
        struct User newUser;
        printf("Zadejte jmeno: ");
        scanf("%s", newUser.firstName);
        printf("Zadejte prijmeni: ");
        scanf("%s", newUser.lastName);
        printf("Zadejte email: ");
        scanf("%s", newUser.email);

        users[*userCount] = newUser;
        (*userCount)++;
    }
};

void removeUser(struct User users[], int *userCount, int max) {
    if (*userCount == 0) {
        printf("Nemate zaregistrovane uzivatele\n");
    } else {
        int x = 0;
        printf("Zadejte cislo uzivatele (1-%d): ", *userCount);
        scanf("%d", &x);
        if (x > 0 && x <= *userCount) {
            for (int i = x - 1; i < *userCount - 1; i++) {
                users[i] = users[i + 1];
            }
            (*userCount)--;
        } else {
            printf("Chyba v indexu");
        }
    }
}

void listUsers(struct User users[], int userCount) {
    if (userCount == 0) {
        printf("Nemate zaregistrovane uzivatele\n");
    } else {
        for (int i = 0; i < userCount; i++) {
            printf("Uzivatel %d: %s %s, Email: %s\n", i + 1, users[i].firstName, users[i].lastName, users[i].email);
        }
    }
}

int main() {
    int userCount = 0;
    int max = 30;

    struct User users[max];

    int choice = 5;

    while (choice != 4) {
        printf("\n--- Registracni system ---\n");
        printf("1. Pridat uzivatele\n");
        printf("2. Odebrat uzivatele\n");
        printf("3. Vypsat vsechny uzivatele\n");
        printf("4. Konec\n");
        printf("Vyberte si jednu z moznosti ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &userCount, max);
                break;
            case 2:
                removeUser(users, &userCount, max);
                break;
            case 3:
                listUsers(users, userCount);
                break;
            case 4:
                printf("Konec programu");
                break;
            default:
                printf("Neplatna moznost.\n");
        }
    }

    return 0;
}