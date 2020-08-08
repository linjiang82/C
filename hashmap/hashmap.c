#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SIZE 20

typedef struct item{
 int key;
 int val;
 struct item * next;
}item_t;


typedef struct {
 item_t * hash_table[SIZE];
}hashtable_t;

int hash(int key){
 return key%SIZE;
}
void init_ht(hashtable_t * ht){
 for(int i=0;i<SIZE;i++){
   ht->hash_table[i]=NULL;
 }
}

void show_ht(hashtable_t * ht){

 for(int i=0;i<SIZE;i++){
   item_t ** tracer = &(ht->hash_table[i]);
  while(*tracer!=NULL){
  printf("%d--%d-->",(*tracer)->key,(*tracer)->val);
  tracer=&(*tracer)->next;
  }
 printf("NULL\n");
 }
}



//insert to hashtable, if found same key in table, overwrite it, otherwise append to the end;
bool insert_ht(hashtable_t * ht, item_t * item){
  int index = hash(item->key);
  item_t ** tracer=&(ht->hash_table[index]);
  while(*tracer!=NULL)
  if((*tracer)->key!=item->key){
    tracer=&((*tracer)->next);
  }
  else{
  item->next = (*tracer)->next;
  *tracer=item;
    return 1;
  }
  *tracer=item;
}

item_t * delete_ht(hashtable_t * ht, int key){
  int index = hash(key);
  item_t ** tracer = &(ht->hash_table[index]);
  while(*tracer!=NULL){
    if((*tracer)->key!=key){
      tracer = &(*tracer)->next;
    }
    else{
      item_t * temp = *tracer;
      *tracer=(*tracer)->next;
      return temp;
    }
  }
  return NULL;

  }
  
item_t * lookup_ht(hashtable_t * ht, int key){
  int index=hash(key);
  item_t ** tracer=&(ht->hash_table[index]);
  while(*tracer!=NULL){
    if((*tracer)->key!=key)
    tracer=&(*tracer)->next;
  else {
    printf("%d--%d\n",(*tracer)->key,(*tracer)->val);
    return *tracer;
  }
  }
    printf("The item not in the table!\n");
    return NULL;
}
int main(int argc,char* argv[]){
 hashtable_t * ht = (hashtable_t *)malloc(sizeof(hashtable_t));
 init_ht(ht);
 item_t item1 = {.key=123, .val=88, .next=NULL};
 item_t item5 = {.key=123, .val=78, .next=NULL};
 item_t item6 = {.key=223, .val=98, .next=NULL};
 item_t item2 = {.key=125, .val=40, .next=NULL};
 item_t item3 = {.key=126, .val=46, .next=NULL};
 item_t item7 = {.key=26, .val=46, .next=NULL};
 item_t item4 = {.key=129, .val=56, .next=NULL};
 insert_ht(ht, &item1);
 insert_ht(ht, &item2);
 insert_ht(ht, &item3);
 insert_ht(ht, &item4);
 insert_ht(ht, &item6);
 insert_ht(ht, &item5);
 insert_ht(ht, &item7);
 item_t * ret = delete_ht(ht,123);
 printf("%d,%d\n",ret->key, ret->val);
 lookup_ht(ht,124);
 lookup_ht(ht,129);
 lookup_ht(ht,123);
 show_ht(ht);
 free(ht);
}
