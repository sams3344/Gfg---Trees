// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* Node)
{
    if (Node == NULL)
    return;

    printInorder (Node->left);
    printf("%d ", Node->data);
    printInorder (Node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
    return NULL;

    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}


Node*  binaryTreeToBST (Node *root);

 // } Driver Code Ends


//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/
int countNodes( Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    return (countNodes(root->left) + countNodes(root->right) + 1); 
} 

void storeInorder( Node* Node, int inorder[], int* i) 
{ 
    // Base Case 
    if (Node == NULL) 
        return; 
 
    storeInorder(Node->left, inorder, i); 
  
    inorder[*i] = Node->data;           //making it *i changes the value dynamically
    (*i)++;                         // increase index for next entry 

    storeInorder(Node->right, inorder, i); 
} 

void arrayToBST(int* arr,  Node* root, int* index_ptr) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr); 
  
    /* Now update root's data and increment index */
    root->data = arr[*index_ptr]; 
    (*index_ptr)++; 
  
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr); 
} 


Node *binaryTreeToBST (Node *root)
{
    if (root == NULL) 
        return root; 
  
    int n = countNodes(root);    // 1. get count
  
    int arr[n] ; 
    int i = 0; 
    storeInorder(root, arr, &i); 
  
    sort(arr, arr+n); 
  
    i = 0; 
    arrayToBST(arr, root, &i);  //Copy array elements back to Binary Tree 
  
   // delete[] arr; 
    
    return root;
} 


// { Driver Code Starts.


int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Node *res = binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
