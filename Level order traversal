vector<int> levelOrder(Node* root)
{
    //you cant use a stack 
    vector<int> v;
    
     if(!root)   return v;
     
     queue<Node*> q;
     q.push(root);
     
     while(!q.empty()){
         Node* node = q.front();
         v.push_back(node->data);
         q.pop();
         
         //enqueue left child
         if(node->left){
            q.push(node->left);
         }
            
         if(node->right){
            q.push(node->right);
         }
            
     }
     return v;
    
}
