#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define STRING_MAX 20

#define VISITED 1
#define NOT_VISITED 0

#include <stdbool.h>

#define STACK_MAX MAX

typedef struct {
    int items[STACK_MAX];
    int top;
} Stack;

typedef struct{
	int que[MAX];
	int front;
	int end;
}Queue;

typedef char String[STRING_MAX];

typedef struct {
    String name;
} DATA;

typedef struct {
    int count;
    int max;
    DATA *data;
} Ray;

typedef struct {
    String key;
    Ray raybond;
} Dictionary, *DictPtr;

void initList(DictPtr *dict);
void addVertex(DictPtr *dict, String item);
void addEdge(DictPtr *dict, String key, String item);
void deleteEdge(DictPtr *dict, String key,String item);
void deleteVertex(DictPtr *dict, String key);

void DFS(DictPtr *dict,String start);
void BFS(DictPtr *dict,String start);

int hash(char name[], Dictionary *dict);
void visualizeDictionary(DictPtr dict);

int main() {
    DictPtr dict;
    initList(&dict);

    addVertex(&dict, "Tokyo");
    addVertex(&dict, "New York");
    addVertex(&dict, "London");
    addVertex(&dict, "Philippines");
    addVertex(&dict, "Hong Kong");
    addVertex(&dict, "Singapore");
    addVertex(&dict, "Canada");
    addVertex(&dict, "Thailand");
    addVertex(&dict, "Sweden");

    addEdge(&dict, "Tokyo", "New York");
    addEdge(&dict, "Tokyo", "London");
    addEdge(&dict, "London", "New");
    addEdge(&dict, "London", "Philippines");
      addEdge(&dict, "New York", "Hong Kong");
        addEdge(&dict, "Singapore", "Sweden");
      addEdge(&dict, "Canada", "Philipines");
      addEdge(&dict, "Thailand", "Tokyo");

    
    
   // deleteEdge(&dict,"Tokyo","New York");
//	deleteVertex(&dict,"Philippines");
	
	visualizeDictionary(dict);
    
    printf("DFS traversal: ");
    DFS(&dict,"Tokyo");
    printf("\n");
    
    printf("BFS: ");
    BFS(&dict,"Tokyo");
     printf("\n");

//	addVertex(&dict, "A");
//	addVertex(&dict, "B");
//    addVertex(&dict, "C");
//    addVertex(&dict, "D");
//    addVertex(&dict, "E");
//    addVertex(&dict, "F");
//    
//    addEdge(&dict,"A","B");
//    addEdge(&dict,"A","C");
//    addEdge(&dict,"B","D");
//    addEdge(&dict,"C","E");
//    addEdge(&dict,"D","E");
//    addEdge(&dict,"D","F");
//    addEdge(&dict,"E","F");
    
//    visualizeDictionary(dict);
//    
//    printf("DFS traversal: ");
//    DFS(&dict,"A");
//    printf("\n");
    
   

    return 0;
}

void initList(DictPtr *dict) {
    int i;

    *dict = malloc(sizeof(Dictionary) * MAX);
    for (i = 0; i < MAX; ++i) {
        strcpy((*dict)[i].key, "EMPTY");
        (*dict)[i].raybond.count = 0;
        (*dict)[i].raybond.max = 5;

        (*dict)[i].raybond.data = malloc(sizeof(DATA) * 5);
    }
}

int hash(char name[], Dictionary *dict) {
    return (name[0] + 31) % MAX;
}

void addVertex(DictPtr *dict, String item) {
    int dex = hash(item, *dict);

    if (strcmp((*dict)[dex].key, "EMPTY") == 0) {
        strcpy((*dict)[dex].key, item);
    } else {
        //linear probing
        int initialDex = dex;
        do {
            dex = (dex + 1) % MAX; // Move to the next slot
        } while (strcmp((*dict)[dex].key, "EMPTY") != 0 && dex != initialDex);

        if (strcmp((*dict)[dex].key, "EMPTY") == 0) {
            strcpy((*dict)[dex].key, item);
        } else {
            printf("Hash table is full, cannot add %s\n", item);
           
        }
    }
}

void addEdge(DictPtr *dict, String key, String item) {
    int dex = hash(key, *dict);
    int dex2 = hash(item, *dict);
    
//////////// Search for the key in the hash table
    while (strcmp((*dict)[dex].key, key) != 0 && strcmp((*dict)[dex].key, "EMPTY") != 0) {
        dex = (dex + 1) % MAX;
    }
    
     while(strcmp((*dict)[dex2].key, item)!=0 && strcmp((*dict)[dex2].key, "EMPTY") != 0 ){
    	dex2=(dex2 + 1) % MAX;
	}

    if (strcmp((*dict)[dex].key, key) == 0 && strcmp((*dict)[dex2].key,item)==0) {
    //// Key found, add data to the Ray structure
        if ((*dict)[dex].raybond.count < (*dict)[dex].raybond.max) {
            strcpy((*dict)[dex].raybond.data[(*dict)[dex].raybond.count].name, item);
            (*dict)[dex].raybond.count++;
            printf("Added '%s' to '%s'\n", item, key);
        } else {
            printf("Cannot add '%s' to '%s', Ray is full\n", item, key);
        }
    } else {
        printf("\nOne of vetices is not found therefore cannot add edge\n");
    }
    
 
    
   
	if(strcmp((*dict)[dex2].key,item)==0){
		if ((*dict)[dex2].raybond.count < (*dict)[dex2].raybond.max){
			strcpy((*dict)[dex2].raybond.data[(*dict)[dex2].raybond.count].name,key);
			(*dict)[dex2].raybond.count++;
		}else{
			 printf("Cannot add '%s' to '%s', Ray is full\n", key, item);
		}
	}else{
	    printf("\nOne of vetices is not found therefore cannot add edge\n");
	}
}

void deleteEdge(DictPtr *dict, String key, String item) {
    int dex = hash(key, *dict);
    int dex2 = hash(item, *dict);

    // Check if key exists
    while (strcmp((*dict)[dex].key, key) != 0 && strcmp((*dict)[dex].key, "EMPTY") != 0) {
        dex = (dex + 1) % MAX;
    }
    if (strcmp((*dict)[dex].key, key) != 0) {
        printf("Key '%s' not found in the hash table\n", key);
        return;
    }
    // Check if item exists
    while (strcmp((*dict)[dex2].key, item) != 0 && strcmp((*dict)[dex2].key, "EMPTY") != 0) {
        dex2 = (dex2 + 1) % MAX;
    }
    if (strcmp((*dict)[dex2].key, item) != 0) {
        printf("Item '%s' not found in the hash table\n", item);
        return;
    }

///// Remove the edge by deleting data from the Ray structures
    int foundEdge = 0;
	int i,j;
    // Delete item from key vertex
    for (i = 0; i < (*dict)[dex].raybond.count; i++) {
        if (strcmp((*dict)[dex].raybond.data[i].name, item) == 0) {
            // Shift elements to overwrite the data to be deleted
            for (j = i; j < (*dict)[dex].raybond.count - 1; j++) {
                strcpy((*dict)[dex].raybond.data[j].name, (*dict)[dex].raybond.data[j + 1].name);
            }
            (*dict)[dex].raybond.count--;
            foundEdge = 1;
            break;
        }
    }

    if (foundEdge) {
        printf("Edge between '%s' and '%s' deleted\n", key, item);
    } else {
        printf("Edge between '%s' and '%s' not found\n", key, item);
    }

    // Delete key from item vertex
    foundEdge = 0;
    for (i = 0; i < (*dict)[dex2].raybond.count; i++) {
        if (strcmp((*dict)[dex2].raybond.data[i].name, key) == 0) {
            // Shift elements to overwrite the data to be deleted
            for (j = i; j < (*dict)[dex2].raybond.count - 1; j++) {
                strcpy((*dict)[dex2].raybond.data[j].name, (*dict)[dex2].raybond.data[j + 1].name);
            }
            (*dict)[dex2].raybond.count--;
            foundEdge = 1;
            break;
        }
    }

    if (foundEdge) {
        printf("Edge between '%s' and '%s' deleted\n", item, key);
    } else {
        printf("Edge between '%s' and '%s' not found\n", item, key);
    }
}

void deleteVertex(DictPtr *dict, String key) {
    int dex = hash(key, *dict);
    int i,j,k;

    // Check if the vertex exists
    while (strcmp((*dict)[dex].key, key) != 0 && strcmp((*dict)[dex].key, "EMPTY") != 0) {
        dex = (dex + 1) % MAX;
    }
    if (strcmp((*dict)[dex].key, key) != 0) {
        printf("Vertex '%s' not found in the hash table\n", key);
        return;
    }

    // Delete the vertex and its edges
    strcpy((*dict)[dex].key,"DELETED"); 
    (*dict)[dex].raybond.count = 0; 

    // Remove any edges that point to this vertex
    for (i = 0; i < MAX; i++) {
        if (strcmp((*dict)[i].key, "EMPTY") != 0) {
            for (j = 0; j < (*dict)[i].raybond.count; j++) {
                if (strcmp((*dict)[i].raybond.data[j].name, key) == 0) {
                    // Shift elements in data
                    for (k = j; k < (*dict)[i].raybond.count - 1; k++) {
                        strcpy((*dict)[i].raybond.data[k].name, (*dict)[i].raybond.data[k + 1].name);
                    }
                    (*dict)[i].raybond.count--;
                    break;
                }
            }
        }
    }

    printf("Vertex '%s' deleted along with all its edges\n", key);
}



void visualizeDictionary(DictPtr dict) {
	int i,j;
    printf("Hash Table Visualization:\n");
    printf("=========================\n");
    printf("Index\t| Vertex \t| Edge\n");
    printf("----------------------------\n");

    for (i = 0; i < MAX; ++i) {
        printf("%d\t| %s \t| ", i, dict[i].key);

        if (strcmp(dict[i].key, "EMPTY") != 0) {
            for (j = 0; j < dict[i].raybond.count; ++j) {
                printf("-%s -", dict[i].raybond.data[j].name);
            }
        }
        printf("\n");
    }
    printf("=========================\n");
}

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isStackFull(Stack *stack) {
    return stack->top == STACK_MAX - 1;
}

void push(Stack *stack, int item) {
    if (!isStackFull(stack)) {
        stack->items[++stack->top] = item;
    }
}

int pop(Stack *stack) {
    if (!isStackEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1;
}

void DFS(DictPtr *dict,String start) {
 
Stack stack;
bool visited[MAX] ;
int i;

    int startDex=hash(start,*dict);
    
    initStack(&stack);
    push(&stack,startDex);
    visited[startDex] = true;
    
    
   while(stack.top!=-1){
   	    int vertex = pop(&stack);
        printf("%s ", (*dict)[vertex].key);
        
    	for(i=0;i<(*dict)[vertex].raybond.count;i++){
        char *adjVertexName=(*dict)[vertex].raybond.data[i].name;
        int adjVertex = hash(adjVertexName,*dict);
        
        
        while(strcmp((*dict)[adjVertex].key,adjVertexName)!=0 && strcmp((*dict)[adjVertex].key,"EMPTY")!=0){
        	adjVertex=(adjVertex + 1);
		}
        
       if(visited[adjVertex]!=true){
        push(&stack,adjVertex);
        visited[adjVertex]=true;	
		}
      
        
	}
 }
}
 
void enqueue(Queue *cue,int vertex){
	cue->end=(cue->end+1) % MAX;
	
	cue->que[cue->end]=vertex;
	
}

int dequeue(Queue *cue){
	int retVal=cue->que[cue->front];
	
	cue->front= (cue->front + 1) % MAX;
	
	return retVal;
		
}
 
void BFS(DictPtr *dict,String start){
	int i;
	
	bool visited[MAX];
	Queue cue;
	
	cue.front=0;
	cue.end=-1;
	
	int startVertex=hash(start,*dict);
	enqueue(&cue,startVertex);
	visited[startVertex]=true;
	
	while((cue.end + 1) % MAX != cue.front){
		int vert=dequeue(&cue);
		printf("%s ",(*dict)[vert].key);
		
		for(i=0;i<(*dict)[vert].raybond.count;++i){
			char *adjVertexName = (*dict)[vert].raybond.data[i].name;
			int adjVertex = hash(adjVertexName,*dict);
			
			while(strcmp((*dict)[adjVertex].key,adjVertexName)!=0 && strcmp((*dict)[adjVertex].key,"EMPTY")!=0){
				adjVertex=(adjVertex + 1);
			}
		
			if(visited[adjVertex]!=true){
				enqueue(&cue,adjVertex);
				visited[adjVertex]=true;
			}
		}
	}
	
	

	
	
}






