#include <stdio.h>
#include <string.h>

#define MAX 25

struct flags {
    int activation_flag;
};

struct user {
    char username[MAX];
    char password[MAX];
    struct flags user_flags;
};

void register_user(struct user *u) {
    printf("Register\n");
    printf("Enter username: ");
    scanf("%s", u->username);
    printf("Enter password: ");
    scanf("%s", u->password);


    printf("Set activation flag (1 for true, 0 for false): ");
    scanf("%d", &u->user_flags.activation_flag);
}

int login(struct user *u) {
    char username[MAX], password[MAX];

    printf("Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, u->username) == 0 && strcmp(password, u->password) == 0) {
        return u->user_flags.activation_flag;
    } else {
        return 0;
    }
}

int main() {
    struct user u;
    register_user(&u);

    if (login(&u)) {
        printf("Login successful\n");

        if (u.user_flags.activation_flag) {
            printf("User is active\n");
        } else {
            printf("User is inactive\n");
        }
    } else {
        printf("Login failed\n");
    }

    return 0;
}
