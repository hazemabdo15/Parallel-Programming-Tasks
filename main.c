#include <stdio.h>
#include <string.h>

#define MAX 25

struct user {
    char username[MAX];
    char password[MAX];
};

void register_user(struct user *u) {
    printf("Register\n");
    printf("Enter username: ");
    scanf("%s", u->username);
    printf("Enter password: ");
    scanf("%s", u->password);
}

int login(struct user *u) {
    char username[MAX], password[MAX];

    printf("Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, u->username) == 0 && strcmp(password, u->password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct user u;
    register_user(&u);

    if (login(&u)) {
        printf("Login successful\n");
    } else {
        printf("Login failed\n");
    }

    return 0;
}
