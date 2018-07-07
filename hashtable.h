#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;
typedef struct node{
    char *name;//字段名
    struct node *next;
}node;
 
class hashTable
{
public:
	hashTable(int Size);
	~hashTable(void);
	unsigned int hash(char* str);
	unsigned int Index(char* str);
	node* lookup(char* str);
	node* malloc_node(char* name);
	int insert(char* name);


	
private:
	int size;
	int sizemask;
	node **hashtable;
};

 

