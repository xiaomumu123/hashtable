
#include "test.h"
 
 
hashTable::hashTable(int Size){
    size = Size;
	sizemask = Size - 1;
	hashtable = (node **)malloc(sizeof(node *) * size);
	for(int i = 0;i < size;i++)
	{
		hashtable[i] = NULL;
	}
	
}

hashTable::~hashTable(void){
	node *np,*tmp;
    for(int i=0;i < size; ++i)
    {
        if(hashtable[i] != NULL)
        {
            np = hashtable[i];
            while(np != NULL)
            {
                tmp = np->next;
                free(np);
                np = tmp;
            }
        }
    }
	free(hashtable);
	hashtable = NULL;
}
 
/* unsigned int hashTable::hash(const string& s)
{//哈希函数
    unsigned int h=0;
    for(string::interator i = s.begin();i !=s.end();s++)
        h=*s+h*31;//将整个字符串按照特定关系转化为一个整数，然后对hash长度取余
    return h%size;
} */


unsigned int hashTable::hash(char* str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}

unsigned int hashTable::Index(char* str)
{	
	unsigned int hashvalue = hash(str);
	return hashvalue&sizemask;
}
 
node* hashTable::lookup(char* str)
{
    //unsigned int hashvalue = hash(str);
	unsigned int index = Index(str);
    node* np = hashtable[index];
    for( ; np!=NULL; np = np->next)
    {
        if(!strcmp(np->name, str))
            return np;
    }
    return NULL;
}
 
 
node* hashTable::malloc_node(char* name)
{
    node *np=new node;
    if(np == NULL)
        return NULL;
    np->name = name;
    np->next = NULL;
    return np;
}
 
int hashTable::insert(char* name)
{
    unsigned int index;
    index = Index(name);
    //头插法
    node* np = malloc_node(name);
    if (np == NULL) return 0;
    np->next = hashtable[index];
    hashtable[index] = np;
    return 1;
}
 
 
 
int main()
{
    char* names[]={"First Name","Last Name","address","phone","k101","k110"};
    hashTable test(6);
    for(int i=0; i < 6; ++i)
        test.insert(names[i]);
	node* test_node;
	test_node = test.lookup(names[3]);
	cout << test_node->name << endl;
	
	system("pause");
 
    return 0;
}