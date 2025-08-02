typedef struct node{
    int data;
    struct node* next;
} Node;

Node* new_node(int data); //Returns new node
void insert_node(Node* node);
void insert_node_index(Node* node, int index); 
void insert_node_sorted(Node* node);

//On success, return Node. On failure return NULL
Node* pop_node(); //Return removed Node
Node* remove_node(Node* node);
Node* remove_node_index(int index);
Node* remove_node_data(int data);
Node* pop_last_node();


int get_list_size();
void print_list();

void free_nodes();