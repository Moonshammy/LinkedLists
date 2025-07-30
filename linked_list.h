typedef struct node{
    int data;
    struct node* next;
} Node;

Node* new_node(int data); //Returns new node
void insert_node(Node* node);
void insert_node_index(Node* node, int index); 
void insert_node_data(int data);


int get_list_size();
void print_list();

//On success, return Node. On failure return NULL
Node* remove_node(Node* node);
Node* remove_node_index(int index);
Node* remove_node_data(int data);
Node* remove_first_node(); //Return removed Node

Node* free_nodes();