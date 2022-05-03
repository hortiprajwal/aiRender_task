//Prajwal Horti

#include<iostream>
#define SPACE 10

using namespace std;

//Structure of a Tree Node
class TreeNode {
    public:
    int value;
    TreeNode *left;
    TreeNode *right;

    //Constructor-> Initalize a New TreeNode with value = 0
    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }

    //Parametrized Constructor-> Initalize a New TreeNode with given value
    TreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

//Structure of AVL Tree
class AVLTree {
    public:
    TreeNode *root;

    //Constructor-> Initialize AVL Tree with root as null
    AVLTree() {
        root = NULL;
    }

    //Check if Tree is Empty
    bool isTreeEmpty() {
        if(root == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    //Get the Height of the AVL Tree using recursion
    int height(TreeNode *root) {
        if(root == NULL)
            return -1;

        //Compute the height of each subtree
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        return (leftheight > rightheight)? (leftheight+1):(rightheight+1);
    }

    //Get Balance Factor of the given Node
    int getBalanceFactor(TreeNode *root) {
        if(root == NULL)
            return -1;
        
        return height(root->left) - height(root->right);
    }

    //Do Right Rotate Operation at the given Node
    TreeNode *rightRotate(TreeNode *oldParent) {
        TreeNode *newParent = oldParent->left;
        TreeNode *newParentRightNode = newParent->right;

        //Perform Rotation
        newParent->right = oldParent;
        oldParent->left = newParentRightNode;

        return newParent;
    }

    //Do Left Rotate Operation at the given node
    TreeNode *leftRotate(TreeNode *oldParent) {
        TreeNode *newParent = oldParent->right;
        TreeNode *newParentLeftNode = newParent->left;

        //Perform Rotation
        newParent->left = oldParent;
        oldParent->right = newParentLeftNode;

        return newParent;
    }

    //Insert Node into an AVL Tree
    TreeNode *insert(TreeNode *root,TreeNode *newNode) {
        if(root == NULL){
            root = newNode;

            cout<<"Value inserted !"<<endl;
            return root;
        }

        if(newNode->value < root->value){
            root->left = insert(root->left,newNode);
        }
        else if(newNode->value > root->value){
            root->right = insert(root->right,newNode);
        }
        else{
            cout<<"No duplicate values allowed!"<<endl;
            return root;
        }

        int balanceFactor = getBalanceFactor(root);

        //Left Left Case
        if(balanceFactor > 1 && newNode->value < root->left->value){
            return rightRotate(root);
        } 

        //Right Right Case
        if(balanceFactor < -1 && newNode->value > root->right->value){
            return leftRotate(root);
        }

        //Left Right Case
        if(balanceFactor > 1 && newNode->value > root->left->value){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //Right Left Case
        if(balanceFactor < -1 && newNode->value < root->right->value){
            root->right = rightRotate(root);
            return leftRotate(root);
        }

        return root;
    }

    //Find the min value node in the AVL Tree
    TreeNode *minValueNode(TreeNode *node){
        TreeNode *currentNode = node;

        //Left-most leaf would have min value => property of BST
        while(currentNode->left != NULL){
            currentNode = currentNode->left;
        }

        return currentNode;
    }

    //Delete a Node in the AVL Tree
    TreeNode *deleteNode(TreeNode *root,int val) {
        if(root == NULL){
            return NULL;
        }
        //If key to be deleted is less than root value
        else if(val < root->value){
            root->left = deleteNode(root->left,val);
        }
        //If key to be deleted is greater than root value
        else if(val > root->value){
            root->right = deleteNode(root->right,val);
        }
        //If key is same as the root value
        else{
            if(root->left == NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                TreeNode * temp = minValueNode(root -> right);

                // Copy the inorder successor's content to this node 
                root -> value = temp -> value;

                // Delete the inorder successor 
                root -> right = deleteNode(root -> right, temp -> value);

                //deleteNode(r->right, temp->value); 
            }
        }

        int balanceFactor = getBalanceFactor(root);

        //Right Rotation or left left imbalance case
        if(balanceFactor == 2 && getBalanceFactor(root->left) >= 0){
            return rightRotate(root);
        }

        //LR Rotation or left Right imbalance case
        else if(balanceFactor == 2 && getBalanceFactor(root->left) == -1){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //Left Rotation or right right imbalance case
        else if(balanceFactor == -2 && getBalanceFactor(root->right) <= 0){
            return leftRotate(root);
        }

        //RL Rotation or right left imbalance case
        else if(balanceFactor == -1 && getBalanceFactor(root->right) == -1){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    //Print the AVL Tree horizontally
    void printTree(TreeNode *root, int space){
        if(root == NULL){
            return;
        }

        //Increase distance between the levels
        space += SPACE;

        printTree(root->right, space);

        cout<<endl;

        for(int i=SPACE;i<space;i++){
            cout<<" ";
        }

        cout<< root->value <<"\n";

        printTree(root->left, space);
    }

    //Print PreOrder(NLR) Traversal of AVL Tree
    void printPreorder(TreeNode *root){
        if(root == NULL)
            return;
        
        cout<<root->value<<" ";
        //recursion on left subtree
        printPreorder(root->left);
        //recursion on right subtree
        printPreorder(root->right);
    }

    //Print Inorder(LNR) Traversal of AVL Tree
    void printInorder(TreeNode *root){
        if(root == NULL)
            return;

        //recur on left subtree
        printInorder(root->left);
        cout<<root->value<<" ";
        //recur on right subtree
        printInorder(root->right);
    }

    //Print PostOrder(LRN) Traversal of AVL Tree
    void printPostorder(TreeNode *root){
        if(root == NULL)
            return;
        
        //recur on left subtree
        printPostorder(root->left);
        //recur on right subtree
        printPostorder(root->right);
        cout<<root->value<<" ";
    }

    //Print nodes at given level
    void printGivenLevel(TreeNode *root,int level){
        if(root == NULL)
            return;
        else if(level == 0)
            cout<<root->value<<" ";
        else{
            printGivenLevel(root->left,level - 1);
            printGivenLevel(root->right,level - 1);
        }
    }

    //Print levelorder Breadth First Search
    void printLevelOrderBFS(TreeNode *root){
        int ht = height(root);

        for(int i=0;i<=ht;i++){
            printGivenLevel(root,i);
        }
    }

    //Search function: Iterative
    TreeNode *iterativeSearch(int val){
        if(root == NULL){
            return NULL;
        }
        else{
            TreeNode *temp = root;

            while(temp != NULL){
                if(val == temp->value){
                    return temp;
                }
                else if(val < temp->value){
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    
    //Search function: Recursion
    TreeNode *recursiveSearch(TreeNode *root,int val){
        if(root == NULL || root->value == val)
            return root;
        
        else if(val < root->value)
            return recursiveSearch(root->left,val);

        else
            return recursiveSearch(root->right,val);
    } 
};

//User Defined Main Function
int main(){
    AVLTree avl;
    int option, val;

    do{
        cout<<"Select the Operation that you want to Perform?"<<endl;
        cout<<"1.Insert Node"<<endl;
        cout<<"2.Search Node(Iterative)"<<endl;
        cout<<"3.Search Node(Recursive)"<<endl;
        cout<<"4.Delete Node"<<endl;
        cout<<"5.Print AVL Tree"<<endl;
        cout<<"6.Height of Tree"<<endl;
        cout<<"7.Clear Screen"<<endl;
        cout<<"0.Exit Program"<<endl;

        cin>> option;

        TreeNode *newNode = new TreeNode();

        switch(option){
            case 0: break;
            case 1: cout<<"Enter the vaue of the Node to insert in AVL Tree: ";
                    cin>>val;
                    newNode->value = val;
                    avl.root = avl.insert(avl.root,newNode);
                    cout<<endl;
                    break;
            case 2: cout<<"Enter the value of the Node to Search in AVL Tree: ";
                    cin>>val;
                    newNode = avl.iterativeSearch(val);

                    if(newNode != NULL){
                        cout<<"Value Found"<<endl;
                    }
                    else{
                        cout<<"Value Not Found"<<endl;
                    }
                    break;
            case 3: cout<<"Enter the value of the Node to Search in AVL Tree: ";
                    cin>>val;
                    newNode = avl.recursiveSearch(avl.root,val);

                    if(newNode != NULL){
                        cout<<"Value Found"<<endl;
                    }
                    else{
                        cout<<"Value Not Found"<<endl;
                    }
                    break;
            case 4: cout<<"Enter the value of the Node to Delete in AVL Tree: ";
                    cin>>val;
                    newNode = avl.recursiveSearch(avl.root,val);

                    if(newNode != NULL){
                        avl.root = avl.deleteNode(avl.root,val);
                        cout<<"Value Deleted"<<endl;
                    }
                    else{
                        cout<<"Value Not Found"<<endl;
                    }
                    break;
            case 5: cout<<"AVL Tree(Horizontal View): "<<endl;
                    avl.printTree(avl.root,5);
                    cout<<endl;

                    cout<<"Level Order BFS: ";
                    avl.printLevelOrderBFS(avl.root);
                    cout<<endl;
                    
                    cout<<"Postorder Traversal: ";
                    avl.printPostorder(avl.root);
                    cout<<endl;

                    cout<<"Preorder Traversal: ";
                    avl.printPreorder(avl.root);
                    cout<<endl;

                    cout<<"Inorder Traversal: ";
                    avl.printInorder(avl.root);
                    cout<<endl;
                    break;
            case 6: cout<<"Tree Height: "<<avl.height(avl.root)<<endl;
                    break;
            case 7: system("cls");
                    break;
            default: cout<<"Incorrect Option Number Selected!"<<endl;
        }
        cout<<endl;
    }while(option != 0);

    return 0;
}