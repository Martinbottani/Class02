#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct
{
    int id;
    char name[33];
    char email[65];
}User;

User* user_new(void);
User* user_newParametros(char* name, char* email);
void user_delete(User* this);
int user_setName(User* this, char* name);
int user_getName(User* this, char* name);
int user_setEmail(User* this, char* email);
int user_getEmail(User* this, char* email);
int user_compareName(User* thisA, User* thisB);
void user_print(User* this);

#endif // USER_H_INCLUDED
