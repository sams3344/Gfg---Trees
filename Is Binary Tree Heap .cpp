// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isHeap(struct Node * tree);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isHeap(root)<< endl;
  }
  return 0;
}

// } Driver Code Ends


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
int cntree(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return (1+cntree(root->left) + cntree(root->left) );
    }
}
    
bool isComplete(Node* root, int index, int count){
    if(root == NULL){
        return true;
    }
    else{
        if(index > count){
            return false;
        }
    }
     return (isComplete(root->left, 2*index + 1, count) && 
            isComplete(root->right, 2*index + 2, count)); 
} 

bool isHeap1( Node* root) 
{ 
    if (root->left == NULL && root->right == NULL) 
        return (true); 
   
    //  node will be in second last level 
    if (root->right == NULL) 
    { 
        return (root->data  >= root->left->data); 
    } 
    else
    {  
        if (root->data >= root->left->data && 
            root->data >= root->right->data) 
            return ((isHeap1(root->left)) && 
                    (isHeap1(root->right))); 
        else
            return (false); 
    } 
} 
   
   bool isHeap(struct Node* root) 
{ 
    // These two are used in isCompleteUtil() 
    unsigned int count = cntree(root); 
    unsigned int index = 0; 
   
    if (isComplete(root, index, count) && isHeap1(root)) 
        return true; 
    return false; 
} 
