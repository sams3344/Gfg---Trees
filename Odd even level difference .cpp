// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int getLevelDiff(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        cout<<getLevelDiff(root);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
   //Your code here
   if (!root) 
        return 0; 
  
    // create a queue for 
    // level order traversal 
    queue<Node*> q; 
    q.push(root); 
  
    int level = 0; 
    int evenSum = 0, oddSum = 0; 
  
    // traverse until the 
    // queue is empty 
    while (!q.empty())  
    { 
        int size = q.size(); 
        level += 1; 
  
        // traverse for  
        // complete level 
        while(size > 0) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
  
            // check if level no. 
            // is even or odd and 
            // accordingly update 
            // the evenSum or oddSum 
            if(level % 2 == 0) 
                evenSum += temp->data; 
            else
                oddSum += temp->data; 
          
            // check for left child 
            if (temp->left)  
            { 
                q.push(temp->left); 
            } 
              
            // check for right child 
            if (temp->right) 
            { 
                q.push(temp->right); 
            } 
            size -= 1; 
        }  
    } 
      
    return (oddSum - evenSum); 
} 


