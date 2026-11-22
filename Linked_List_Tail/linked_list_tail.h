typedef struct Linked_List Linked_List;

Linked_List* ll_new_node(int data); //Returns new node
void insert_node(Linked_List* node);
void insert_node_index(Linked_List* node, int index); 
void insert_node_sorted(Linked_List* node);

//On success, return Node. On failure return NULL
Linked_List* pop_node(); //Return removed Node
Linked_List* pop_last_node();
Linked_List* remove_node(Linked_List* node);
Linked_List* remove_node_index(int index);
Linked_List* remove_node_data(int data);



int get_list_size();
void print_list();

void free_nodes();