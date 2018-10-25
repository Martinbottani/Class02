#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct
{
    int id;
    char name[33];
    char surname[65];
}User;

User* user_new(void);
User* user_newParametros(char* name, char* surname, char* id);
void user_delete(User* this);
int user_setName(User* this, char* name);
int user_getName(User* this, char* name);
int user_setSurname(User* this, char* surname);
int user_getSurname(User* this, char* surname);
int user_compareName(User* thisA, User* thisB);
int user_setId(User* this, char* idUser);
int user_getId(User* this, char* idUser);


#endif // USER_H_INCLUDED
