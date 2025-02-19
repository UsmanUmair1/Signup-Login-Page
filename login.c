#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int valid_email(const char *username){
    return strchr(username, '@') != NULL;
}

void create_new_account(int option, char firstName, char lastName, const char *username){

    printf("Welcome to Bank Portal\n");
    printf("Signup~1 or Login~0: ", option);
    scanf("%d", &option);
    getchar();
    if(option==0){

        FILE * ptr;
    ptr = fopen("info.txt", "w");
    if(ptr==NULL){
        printf("File is Empty!");
    return 1;
        }

    char ch;
    char pass[20];
    char username[20];

    do{
        printf("Enter Username: ");
        fgets(username, 20, stdin);
        username[strcspn(username, "\n")] = 0;

        if(!valid_email(username)){
                printf("email must contain '@', Try Again\n");
            }
    }while(!valid_email(username));
        fprintf(ptr, "EMAIL: %s\n", username);

    while(1){
    printf("Enter Password: ");
    int i=0;

    while(1){
        ch = getch();
    if(ch==13){
        pass[i]='\0';
        break;
    }else if(ch==8 && i>0){
        i--;
        printf("\b \b");
    }else if(i<19){
        pass[i++]=ch;
        printf("*");
    }
   }
    fprintf(ptr, "Password: %s", pass);
    printf("\nLogin Successfully\n");
    break;
    }
    }else{
        FILE * ptr;
    ptr = fopen("info.txt", "w");
    if(ptr==NULL){
        printf("File is Empty!");
    return 1;
        }

        char firstName[20];
        do{
            printf("Enter Your First Name: ");
            fgets(firstName,20,stdin);

            firstName[strcspn(firstName, "\n")] = 0;
            if(strlen(firstName)>20){
                printf("Please Try Again\n");
            }
        }while(strlen(firstName)>20);
        fprintf(ptr, "First Name: %s\n", firstName);

        char lastName[20];
        do{
            printf("Enter Your First Name: ");
            fgets(lastName,20,stdin);

            lastName[strcspn(lastName, "\n")] = 0;
            if(strlen(lastName)>20){
                printf("Please Try Again\n");
            }
        }while(strlen(lastName)>20);
        fprintf(ptr, "Last Name: %s\n", lastName);

        char email[20];
        do{
        printf("Enter Your Email: ");
        fgets(email, 20, stdin);
        email[strcspn(email, "\n")] = 0;

        if(!valid_email(email)){
                printf("email must contain '@', Try Again\n");
            }
    }while(!valid_email(email));
        fprintf(ptr, "Email: %s\n", email);

        while(1){
    printf("Enter Password: ");
    int i=0;

    char ch;
    char pass[20];

    while(1){
        ch = getch();
    if(ch==13){
        pass[i]='\0';
        break;
    }else if(ch==8 && i>0){
        i--;
        printf("\b \b");
    }else if(i<19){
        pass[i++]=ch;
        printf("*");
    }
   }
    fprintf(ptr, "Password: %s", pass);
    fclose(ptr);
    printf("\nSignup Successfully\n");
    break;
    }
    }
    }
int main(){
    int option;
    char firstName, lastName, username;

    create_new_account(option, firstName, lastName, username);
    return 0;
}
