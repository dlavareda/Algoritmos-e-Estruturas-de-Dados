#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    int cod;
    char nome;
};

typedef struct item Item;

struct node{
    Item item;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *treeInitialize(){ //uma árvore inicializada é nula
    return NULL;
}

Item itemCreate (int cod){ //,char nome
    Item item;
    item.cod = cod;
    //strcpy(item.nome, nome);
    return item;
}

Node *treeInsert(Node *root, Item x){ //inserir elemento na arvore
    if(root == NULL){
        Node *aux  = (Node *) malloc(sizeof(Node));
        aux->item  = x;
        aux->left  = NULL;
        aux->right = NULL;
        return aux;
    }else{
        if(x.cod > root->item.cod){
            root->right = treeInsert(root->right, x);
        }else if(x.cod < root->item.cod){
            root->left  = treeInsert(root->left, x);
        }
    }
    return root;
}

void treePrint(Node *root){
    if(root != NULL){
        printf("%d ", root->item.cod);
        if(root->left == NULL || root->left == NULL)
            printf("NULO ");
        treePrint(root->left);
        treePrint(root->right);
        
    }
}

void treeFree(Node *root){
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

Node *treeSearch(Node *root, int cod){ //procurar elemento na arvore
    if(root != NULL){
        if(root->item.cod == cod)
                return root;
        else{
        if(cod > root->item.cod)
                return treeSearch(root->right, cod);
        if(cod < root->item.cod)
                return treeSearch(root->left, cod);
        }
    }
    return NULL;
}

/*Node *treeSearchName(Node *root, char *nome){ //procurar elemento na arvore por nome que nao e criterio de ordenacao
    if(root != NULL){
        if(strcmp(root->item.nome,nome))
                return root;
        else{
                return ((treeSearchName(root->right, nome)) && (treeSearchName(root->left, nome)));
        }
    }
    return NULL;
}*/

Node *treeMin(Node *root){
    if(root != NULL){
        Node *aux = root;
        while(aux->left != NULL){
            aux = aux->left;
        }
        return aux;
    }
    return NULL;
}
Node *treeRemove(Node *root, int cod){
    if(root!=NULL){
        if(cod > root->item.cod){

            root->right = treeRemove(root->right, cod);

        }else if(cod < root->item.cod){

            root->left  = treeRemove(root->left, cod);

        } else { //encontrou o elemento a ser removido

            if(root->left == NULL && root->right == NULL){
                
                free(root);

                return NULL; //se removemos, ele passa a ser nulo, entao temos de retornar o que vai passar a ocupar o lugar desse nodo
            
            } else if(root->left == NULL && root->right != NULL){ //só tem um filho à direita
               
                Node *aux = root->right;
                
                free(root);
                
                return(aux);

            } else if(root->left != NULL && root->right == NULL){ //só tem um filho à esquerda
                
                Node *aux = root->left;
                
                free(root);
                
                return(aux);

            } else{ //imaginemos que queremos remover a raiz que é o 10. temos de ir buscar a menor folha na maior subarvore e remover e substituir na raiz
               
                Node *aux = treeMin(root->right); //procura a menor folha na maior subarvore
               
                Item itemAux = aux->item; //copia do 15 para uma caixa fora da arvore
                
                root = treeRemove(root, itemAux.cod); //remove o 15
               
                root->item = itemAux; //tiramos o 10 e colocamos o 15 na raiz
               
                
            }

        }
        return root;
    }
        return NULL;
}

int treeSorted(Node *root){ //ver se a arvore esta bem ordenada
    if(root->left == root->right) //se é folha
        return (1);
        if(root->right == NULL) // se só tem filho esquerdo
            if(root->left->item.cod < root->item.cod){ // se tem dois filhos
            treeSorted(root->left);
            }else return (0);

        if(root->left == NULL) // se só tem filho direito
            if(root->right->item.cod > root->item.cod){
            treeSorted(root->right);
            }else return (0);

        if((root->left->item.cod < root->item.cod) && (root->right->item.cod > root->item.cod)){ //se tem os dois filhos
               return(treeSorted(root->right) && treeSorted(root->left));
            }else return (0);
}


int main(){
    Node *root = treeInitialize();
    root = treeInsert(root, itemCreate(0));
    root = treeInsert(root, itemCreate(1));
    root = treeInsert(root, itemCreate(2));
    root = treeInsert(root, itemCreate(1));
    root = treeInsert(root, itemCreate(4));
    root = treeInsert(root, itemCreate(5));
    root = treeInsert(root, itemCreate(6));
    root = treeInsert(root, itemCreate(7));
    root = treeInsert(root, itemCreate(8));
    root = treeInsert(root, itemCreate(9));
    /*printf(">> Antes de remover: ");
    treePrint(root);
    root = treeRemove(root, 10);
    printf(">> Depois de remover: ");
    treePrint(root);
    Node *tmp = treeSearch(root, 13);
    if(tmp == NULL){
        printf(">> Elemento nao encontrado!\n");
    }else{
        printf(">> Elemento encontrado!\n");
    }*/ 
    treePrint(root);
    printf("\n");
    treeFree(root);
    return 0;
}