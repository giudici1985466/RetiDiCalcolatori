#include "string.h"
#include "stdlib.h"
#include "database.h"



void insert_n(IndexNodeString* root,Persona* persona){
    if(root==NULL){
        char* string=(char*)malloc(20);
        IndexNodeString* node=(IndexNodeString*)malloc(sizeof(IndexNodeString));
        strncpy(string,persona->name,20);
        node->value=string;
        node->left=NULL;
        node->right=NULL;
        node->record=persona;
        return;
    }else{
        if(strcmp(persona->name,root->value)<=0){
            insert_n(root->left,persona->name);
        }else{
            insert_n(root->right,persona->name);
        }
    }

}
void insert_c(IndexNodeString* root,Persona* persona){
    if(root==NULL){
        char* string=(char*)malloc(50);
        IndexNodeString* node=(IndexNodeString*)malloc(sizeof(IndexNodeString));
        strncpy(string,persona->surname,50);
        node->value=string;
        node->left=NULL;
        node->right=NULL;
        node->record=persona;
        return;
    }else{
        if(strcmp(persona->surname,root->value)<=0){
            insert_n(root->left,persona->surname);
        }else{
            insert_n(root->right,persona->surname);
        }
    }


}
void insert_i(IndexNodeString* root,Persona* persona){
    if(root==NULL){
        char* string=(char*)malloc(100);
        IndexNodeString* node=(IndexNodeString*)malloc(sizeof(IndexNodeString));
        strncpy(string,persona->address,100);
        node->value=string;
        node->left=NULL;
        node->right=NULL;
        node->record=persona;
        return;
    }else{
        if(strcmp(persona->address,root->value)<=0){
            insert_n(root->left,persona->address);
        }else{
            insert_n(root->right,persona->address);
        }
    }


}
void insert_e(IndexNodeInt* root,Persona* persona){
    if(root==NULL){
        
        IndexNodeInt* node=(IndexNodeInt*)malloc(sizeof(IndexNodeInt));
        node->value=persona->age;
        node->left=NULL;
        node->right=NULL;
        node->record=persona;
        return;
    }else{
        if(persona->age<=root->value){
            insert_n(root->left,persona->age);
        }else{
            insert_n(root->right,persona->age);
        }
    }

}


void findByString_aux(IndexNodeString* root,char* str,Persona** addr){
    if(root==NULL){
        return;
    }
    if(strcmp(root->value,str)==0){
        *addr=root->record;
    }
    if(strcmp(root->value,str)<0){
        findByAddress_aux(root->right,str,addr);
    }
    if(strcmp(root->value,str)>0){
        findByAddress_aux(root->left,str,addr);
    }

}

void findByInt_aux(IndexNodeInt* root,int num,Persona** addr){
    if(root==NULL){
        return;
    }
    if(num==root->value){
        *addr=root->record;
    }
    if(num>root->value){
        findByInt_aux(root->right,num,addr);
    }
    if(num<root->value){
        findByInt_aux(root->left,num,addr);
    }

}


void insert(Database * database, struct Persona * persona){
 
 //inserimento nome
 insert_n(database->name,persona);

 //inserimento cognome
 insert_c(database->surname,persona);

 //inserimento indirizzo
 insert_i(database->address,persona);

 //inserimento età
 insert_e(database->age,persona);

}


struct Persona* findByName(Database * database, char * name){
    Persona* result;
    findByString_aux(database->name,name,&result);
    return result;
}

struct Persona* findBySurname(Database * database, char * surname){
    Persona* result;
    findByString_aux(database->surname,surname,&result);
    return result;
}

struct Persona* findByAddress(Database * database, char * address){
    Persona* result;
    findByString_aux(database->address,address,&result);
    return result;
}

struct Persona* findByAge(Database * database, int age){
    Persona* result;
    findByInt_aux(database->age,age,&result);
    return result;
}
