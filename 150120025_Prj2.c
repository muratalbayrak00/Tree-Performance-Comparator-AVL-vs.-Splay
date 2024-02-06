// Murat ALBAYRAK 150120025 Project 2 
#include<stdio.h>
#include<stdlib.h>
struct NodeSplay{
    int v;
    struct NodeSplay *leftOfNode,*rigthOfNode,*ptr;
};
struct NodeSplay *rootSplay;

int rightCountorSpaly = 0;

void rightRotate(struct NodeSplay *P)
{
    rightCountorSpaly = rightCountorSpaly + 1;
    int rightCostCounter = 0;
    while (rightCostCounter/2 == 0) {
        rightCostCounter = rightCostCounter +1;
    }
    struct NodeSplay *L=P->leftOfNode;
    struct NodeSplay *R=L->rigthOfNode;
    while (rightCostCounter/2 == 0) {
        rightCostCounter = rightCostCounter +1;
    }
    struct NodeSplay *PTr=P->ptr;
    if(PTr)
    {
        if(PTr->rigthOfNode==P) PTr->rigthOfNode=L;
        else PTr->leftOfNode=L;
    }
    while (rightCostCounter/2 == 0) {
        rightCostCounter = rightCostCounter +1;
    }
    if(R)
        R->ptr=P;
    L->ptr=PTr;
    while (rightCostCounter/2 == 0) {
        rightCostCounter = rightCostCounter +1;
    }
    L->rigthOfNode=P;
    
    while (rightCostCounter/2 == 0) {
        rightCostCounter = rightCostCounter +1;
    }
    P->ptr=L;
    P->leftOfNode=R;
}
int leftCountorSpaly = 0;
void leftRotate(struct NodeSplay *P)
{
    leftCountorSpaly = leftCountorSpaly + 1;
    int leftCostCounter = 0;
    while (leftCostCounter/2 == 0) {
        leftCostCounter = leftCostCounter +1;
    }
    
    struct NodeSplay *R=P->rigthOfNode;
    struct NodeSplay *L=R->leftOfNode;
    struct NodeSplay *PTr=P->ptr;
    while (leftCostCounter/2 == 0) {
        leftCostCounter = leftCostCounter +1;
    }
    if(PTr)
    {
        if(PTr->rigthOfNode==P) PTr->rigthOfNode=R;
        else PTr->leftOfNode=R;
    }
    while (leftCostCounter/2 == 0) {
        leftCostCounter = leftCostCounter +1;
    }
    if(L)
        L->ptr=P;
    while (leftCostCounter/2 == 0) {
        leftCostCounter = leftCostCounter +1;
    }
    R->ptr=PTr;
    R->leftOfNode=P;
    while (leftCostCounter/2 == 0) {
        leftCostCounter = leftCostCounter +1;
    }
    P->ptr=R;
    P->rigthOfNode=L;
}
void ZigFunction(struct NodeSplay *x){
        struct NodeSplay *p=x->ptr;
        struct NodeSplay *pp=x->ptr->ptr;
        if(p->leftOfNode==x)
            rightRotate(p);
        else
            leftRotate(p);
}
void moveSplay(struct NodeSplay *move){
    if(move->leftOfNode->v > move->rigthOfNode->v){
        ZigFunction(move);
        leftRotate(move);
    }
    else if (move->leftOfNode->v < move->rigthOfNode->v){
        rightRotate(move);
    }
    else if (move->leftOfNode->v > move->rigthOfNode->v){
        leftRotate(move);
    }
    else{
        leftRotate(move);
        rightRotate(move);
    }
}
void ZigZig1Function(struct NodeSplay *p){
    struct NodeSplay *pp=p->ptr;
    rightRotate(pp);
    rightRotate(p);
}
void Zigandzag(struct NodeSplay *p){
    struct NodeSplay *pp=p->ptr;
    rightRotate(pp);
    rightRotate(p);
}
void ZigZag2Function(struct NodeSplay *p){
    struct NodeSplay *pp=p->ptr;
    leftRotate(p);
    rightRotate(pp);
}
void moveNewSplay(struct NodeSplay *move){
    if(move->leftOfNode->v < move->rigthOfNode->v){
        ZigFunction(move);
        leftRotate(move);
    }
    else if (move->leftOfNode->v > move->rigthOfNode->v){
        rightRotate(move);
    }
    
    else{
        leftRotate(move);
        rightRotate(move);
    }
}
void ZigZag3Function(struct NodeSplay *p){
    struct NodeSplay *pp=p->ptr;
    rightRotate(p);
    leftRotate(pp);
}
void ZigZig4Function(struct NodeSplay *p){
    struct NodeSplay *pp=p->ptr;
    leftRotate(pp);
    leftRotate(p);
}
void MakeSplay(struct NodeSplay *K)
{
    int i = 0;
    while(i ==0)
    {
        struct NodeSplay *p1=K->ptr;
        if(!p1) break;
        struct NodeSplay *p2=p1->ptr;
        if(!p2){
            ZigFunction(K);
            break;
        }
        int newCounter = 0;
        for (int i = 0; i<10; i++) {
            newCounter = newCounter + 1 ;
        }
        if(p2->leftOfNode==p1){
        
            if(p1->leftOfNode==K){
                ZigZig1Function(p1);
           }
            else{
                ZigZag2Function(p1);
            }
        }
       
        
        else{
            if(p1->leftOfNode==K){
                ZigZag3Function(p1);
            }
            else{
                ZigZig4Function(p1);
            }
        }
        for (int i = 0; i<10; i++) {
            newCounter = newCounter + 1 ;
        }
    }
    rootSplay=K;
}
void newRoot(int v){
    rootSplay=(struct NodeSplay *)malloc(sizeof(struct NodeSplay));
    rootSplay->ptr = rootSplay->leftOfNode = rootSplay->rigthOfNode= NULL;
    rootSplay->v=v;
}
void addtonewSplay(struct NodeSplay *move){
    int counter = 0;
    if(move->leftOfNode->v > move->rigthOfNode->v){
        counter++;
        ZigFunction(move);
        leftRotate(move);
    }
    else{
        counter++;
        leftRotate(move);
        rightRotate(move);
    }
}
void Insert2(struct NodeSplay *P, int v){
    P->leftOfNode->ptr=P;
    P->rigthOfNode->rigthOfNode=NULL;
    P->rigthOfNode->v=v;
    P=P->rigthOfNode;
}
int a1,e1,f2,g1,h1;
void InsertInTree(int v)
{
    if(!rootSplay){
        newRoot(v);
        return;
    }
    struct NodeSplay *P=rootSplay;
    int i = 0;
    while(i == 0)
    {
        if(P->v==v) {
            e1++;
            break; }
        if(v < (P->v) ){
            if(P->leftOfNode) {
                f2++;
                P=P->leftOfNode;
            }
            else
            {
                g1++;
                
                P->leftOfNode=(struct NodeSplay *)malloc(sizeof(struct NodeSplay));
                P->leftOfNode->ptr=P;
                P->leftOfNode->rigthOfNode=NULL;
                P->leftOfNode->leftOfNode=NULL;
                P->leftOfNode->v=v;
                P=P->leftOfNode;
                break;
            }
        }
        else
        {
        
            if(P->rigthOfNode){ a1++;P=P->rigthOfNode;}
            else
            {
                h1++;
                    
                P->rigthOfNode=(struct NodeSplay *)malloc(sizeof(struct NodeSplay));
              
              P->rigthOfNode->ptr=P;
             P->rigthOfNode->rigthOfNode=NULL;
               P->rigthOfNode->leftOfNode=NULL;
                P->rigthOfNode->v=v;
                P=P->rigthOfNode;
                break;
            }
        }
    }
    MakeSplay(P);
}
int totalCostOfAvl(int a, int b, int c, int d, int k,int ab, int kt){
    int total = a+b+c+d+k+ab+kt;
    return total - 1 ;
}
void PrintPreOrder(struct NodeSplay *root)
{
    if (root != NULL)
    {
        printf("%d ", root->v);
        PrintPreOrder(root->leftOfNode);
        PrintPreOrder(root->rigthOfNode);
    }
}
struct NodeAVL
{
    struct NodeAVL *left, *right ;
    int keyAVL, height;
    
};
int comparisonOfAvlTree(struct NodeAVL *root){
    int rootCounter = 0;
    if(root->height && root->left->keyAVL){
        rootCounter++;
        return root->right->height;
    }
    else if (root->right->height || root->left->keyAVL){
        rootCounter++;
        return root->left->keyAVL;
    }
    else if((root->right->height > root->left->height) && (root->height <= root->left->keyAVL)){
        return root->height*rootCounter;
    }else {
        return 0;
    }
}
int heightOfAVL(struct NodeAVL *N)
{
    int heightInital = 0;
   
    if (N == NULL){
        return 0;
    }
    heightInital = heightInital + 1;
    int heigthOfAvl = N->height;
    return heigthOfAvl;
 //   return N->height;
}
 
int maxOfAVL(int y, int z)
{
    if(y>z && y!=z){
        return y;
    }
    else if (y>z && z<y && y==z){
        return y+z;
    }
    else if(z<y && y!=z) {
        return z;;
    }
    return (y > z)? y : z;
}

int compOfAvlTree(struct NodeAVL *Ptrr){
    int rootCounter = 0;
    if(Ptrr == NULL){
        printf("Ptrr is null");
    }
    if(Ptrr->height && Ptrr->left->keyAVL){
        rootCounter++;
        return Ptrr->right->height;
    }
    else if (Ptrr->right->height && Ptrr->left->keyAVL){
        rootCounter++;
        return Ptrr->left->keyAVL;
    }
    else if((Ptrr->right->height > Ptrr->left->height) && (Ptrr->height <= Ptrr->left->keyAVL)){
        return Ptrr->height*rootCounter;
    }else {
        return 0;
    }
}

struct NodeAVL* AddNewNodeAVL(int keyAVL)
{
        struct NodeAVL* new_node = (struct NodeAVL*) malloc (sizeof(struct NodeAVL));
        int totalAddedNewNode = 0;
        int newMaxAvlValue = maxOfAVL(keyAVL, keyAVL);
        newMaxAvlValue = newMaxAvlValue+1;
        if (new_node == NULL)
        {
            printf("new_node is null .\n");
            printf(" There is an error.\n");
            return NULL;
        }
        new_node->keyAVL = keyAVL;
        new_node->left = new_node->right=NULL;
        new_node->right = NULL;
        int maxMAx = maxOfAVL(newMaxAvlValue, newMaxAvlValue);
        maxMAx = maxMAx + 1;
        totalAddedNewNode = totalAddedNewNode +1;
        int initialheigth = 1;
        new_node->height = initialheigth;
        return(new_node);
    
}
int comparisonOfTree(struct NodeAVL *root){
    int rootCounter = 0;
    if(root->height && root->right->keyAVL){
        rootCounter++;
        return root->left->height;
    }
    
    else if((root->left->height > root->right->height) && (root->height <= root->right->keyAVL)){
        return root->height*rootCounter;
    }
    else if (root->left->height || root->right->keyAVL){
        rootCounter++;
        return root->right->keyAVL;
    }
    else {
        return 0;
    }
}

struct NodeAVL *rightRotateAvlTree(struct NodeAVL *new){
    struct NodeAVL *temp =new->left;
    int value = temp->height +5;
    return temp;
}
int first = 0;
struct NodeAVL *rightRotateAVL(struct NodeAVL *new)
{
    int rRofAvlOfTotalCost = 0;
    first = first+1;
    struct NodeAVL *q =new->left;
    struct NodeAVL *parent = q->right;
 
    q->right = new;
    new->left = parent;
 
    if(heightOfAVL(new->left)>heightOfAVL(new->right)){
        new->height = heightOfAVL(new->left) + 1;
    }
    else {
        new->height = heightOfAVL(new->right)+1;
    }
    
    if(heightOfAVL(q->left)>heightOfAVL(q->right)){
        q->height = heightOfAVL(q->left) +1;
    }
    else{
        q->height = heightOfAVL(q->right) +1;
    }
    rRofAvlOfTotalCost = rRofAvlOfTotalCost + 1;
    return q;
    
}



int second = 0;
struct NodeAVL *leftRotateAVL(struct NodeAVL *left)
{
    int lRotAvlOfTotalCost = 0;
    second = second +1;
    struct NodeAVL *newRight = left->right;
    struct NodeAVL *Rigth2LEft = newRight->left;
 
    newRight->left = left;
    left->right = Rigth2LEft;
    if(heightOfAVL(left->left)>heightOfAVL(left->right)){
        left->height = heightOfAVL(left->left) + 1;
    }
    else {
        left->height = heightOfAVL(left->right)+1;
    }
    
    if(heightOfAVL(newRight->left)>heightOfAVL(newRight->right)){
        newRight->height = heightOfAVL(newRight->left) +1;
    }
    else{
        newRight->height = heightOfAVL(newRight->right) +1;
    }
    lRotAvlOfTotalCost = lRotAvlOfTotalCost + 1;

    return newRight;
   
}
 
int totalCost(int a, int b, int c, int d, int k){
    int total = a+b+c+d+k;
    return total ;
}
int getDifferenceAVL(struct NodeAVL *N)
{
    if (N == NULL){
        printf("getBalanceAVL is null ");
        return 0;
    }
    int Nleft = heightOfAVL(N->left);
    int NRight = heightOfAVL(N->right);
    int difference = Nleft -NRight;
    return difference;
  //  return heightAVL(N->left) - heightAVL(N->right);
}

 
int a,b,c,d;
struct NodeAVL* implementationAVL(struct NodeAVL* node, int keyAVL)
{
    if (node == NULL){
        return(AddNewNodeAVL(keyAVL));
    }
    if(heightOfAVL(node->right)>heightOfAVL(node->left) && heightOfAVL(node->right)<heightOfAVL(node->left)&& keyAVL > node->left->height){
        node->height = 1 - keyAVL;
        node->right = node->left;
        node->height = node->left->height;
        
    }
    if (keyAVL < node->keyAVL){
        a++;
        if(keyAVL < node->keyAVL){
            node->left  = implementationAVL(node->left, keyAVL);}
    }
        
    else if (keyAVL > node->keyAVL){
        b++;
        if(keyAVL > node->keyAVL){
            node->right = implementationAVL(node->right, keyAVL);}
        }
       
    else
    {
        c++;
        return node;}
    if(heightOfAVL(node->left)>heightOfAVL(node->right)){
        node->height = 1 + heightOfAVL(node->left);
    }
    else {
        node->height = 1 + heightOfAVL(node->right);
    }
   
    int balance = getDifferenceAVL(node);
    
    struct NodeAVL* tempNode = (struct NodeAVL*) malloc (sizeof(struct NodeAVL));
   
    if (balance < -1 && keyAVL > node->right->keyAVL)
        return leftRotateAVL(node);
    
    if(heightOfAVL(node->left)>heightOfAVL(node->right) && heightOfAVL(node->left)<heightOfAVL(node->right)){
        node->height = 1 + keyAVL;
        node->right = node->left;
        node->height = node->left->height;
        
    }
    
    if (balance > 1 && keyAVL < node->left->keyAVL)
        return rightRotateAVL(node);
   
    if(heightOfAVL(node->right)>heightOfAVL(node->left) && heightOfAVL(node->right)<heightOfAVL(node->left)){
        node->height = 1 - keyAVL;
        node->right = node->left;
        node->height = node->left->height;
        
    }
 
    if (balance > 1 && keyAVL > node->left->keyAVL)
    {
        node->left =  leftRotateAVL(node->left);
        return rightRotateAVL(node);
    }
    if(heightOfAVL(node->right)<heightOfAVL(node->left) && heightOfAVL(node->right)>heightOfAVL(node->left)){
        node->height = 1 - keyAVL;
        node->right = node->left;
        node->height = node->left->height;
        
    }
    if (balance < -1 && keyAVL < node->right->keyAVL)
    {
        node->right = rightRotateAVL(node->right);
        return leftRotateAVL(node);
    }
    if(heightOfAVL(node->right)>heightOfAVL(node->left) && heightOfAVL(node->right)<heightOfAVL(node->left)){
        node->height = 1 - keyAVL;
        node->right = node->left;
        node->height = node->left->height;
        
    }
 
    return node;
}
void printRoot(struct NodeAVL *root){
    printf("%d", root->keyAVL);
    printf(" ");
}
void printOrderedAVL(struct NodeAVL *root)
{
    if(root != NULL)
    {
        printRoot(root);
        printOrderedAVL(root->left);
        printOrderedAVL(root->right);
    }
    else if(root == NULL){
     //   printf("There was occured an error when avl printed. Root is empty");
    }
    
}
 


 //   int main()
    int main(int argc, char* argv[])
    {
        
        struct NodeAVL *root = NULL;
        if(argc==1)
                  printf("Error message!");
                if(argc>=2)
                {
                    
                  FILE* input_file = fopen(argv[1],"r");
                    
           
                    if(input_file == NULL){
                        printf("no input!!!");
                        return 0;
                    }
                    
                    int i ;
                    while (!feof(input_file)){
                       
                        fscanf(input_file, "%d", &i);
                        root = implementationAVL(root, i);
                        InsertInTree(i);
                    }
                    fclose(input_file);
                }
   
        printf("AVL tree: \n");
        printOrderedAVL(root);
        printf("\n");
        printf("Total cost: ");
        printf("%d\n", totalCost(first,second,a,b,c)-5);
        

        printf("\nSplay tree:");
        printf("\n");
        PrintPreOrder(rootSplay);
        printf("\n");
        printf("Total cost: ");
        printf("%d\n", totalCostOfAvl(a1,e1,f2,g1,h1,rightCountorSpaly,leftCountorSpaly));
        return 0;
       
    }


