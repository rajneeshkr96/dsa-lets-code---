#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>

class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;
    treeNode(T data){
        this->data = data;
    }
    ~treeNode(){
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
        
    }
};

void printTree(treeNode<int>* node){
    cout<<node->data<<":";
    for (int i = 0; i < node->children.size(); i++)
    {
        cout<<node->children[i]->data<<",";
    }
    cout<<endl;
    for (int i = 0; i < node->children.size(); i++)
    {
        printTree(node->children[i]);
    }
    
    
};

treeNode<int>* takeInput(){
    cout<<"enter your data"<<endl;
    int data;
    cin>>data;
    treeNode<int>* node = new treeNode<int>(data);
    cout<<"enter number of children for "<<data<<endl;
    int children;
    cin>>children;
    for (int i = 0; i < children; i++)
    {
        cout<<"enter children for "<<data<<endl;
        treeNode<int>* child = takeInput();
        node->children.push_back(child);
    }
    return node;
    
};

void printTreeLevel(treeNode<int>* node){
    queue<treeNode<int>*> children;
    children.push(node);
    while (!children.empty())
    {
        treeNode<int>* data = children.front();
        children.pop();
        cout<<"root: "<<data->data <<" children: ";
    for (int i = 0; i < data->children.size(); i++)
    {
        cout<<data->children[i]->data<<",";
        children.push(data->children[i]);
    }

    cout<<endl;
    }



}

treeNode<int>* treeTakeInput(){
    cout<<"Enter Root ";
    int rootData;
    cin >> rootData;
    treeNode<int>* root = new treeNode<int>(rootData);
    queue<treeNode<int>*> pending;
    pending.push(root);
    while (!pending.empty())
    {
       treeNode<int>* child = pending.front();
       pending.pop();
       cout<<"Number of child for "<<child->data<<" ";
       int childCount;
       cin>>childCount;
       for (int i = 0; i < childCount; i++)
       {
        cout<<"Enter "<<i+1<<" child for "<<child->data<<endl;
        int rtchild;
        cin>>rtchild;
        treeNode<int>* childNode = new treeNode<int>(rtchild); 
        child->children.push_back(childNode);
        pending.push(childNode);
       }
      
    }
    return root;
};

int numOfNode(treeNode<int>* node){
    int count = 1;
    for (int i = 0; i < node->children.size(); i++)
    {
        count+= numOfNode(node->children[i]);
    }
    return count;
    
};

int nodeSum(treeNode<int>* node){
    double sum = node->data;
    for (int i = 0; i < node->children.size(); i++)
    {
        sum  += nodeSum(node->children[i]);
    }
    return sum;
    
};

int maxValue(treeNode<int>* node){
    if(node == NULL) return 0;
    int max = node->data;
    for (int i = 0; i < node->children.size(); i++)
    {
        int child = maxValue(node->children[i]);
        if (child > max){ 
            max = child;
            }
        
    }
    return max;
}

int treeHeight(treeNode<int>* node){
    if(node == NULL) return 0;
    int height = 0;
    for (int i = 0; i < node->children.size(); i++)
    {
       int max = treeHeight(node->children[i]);
       if(max > height) height = max;

    }
    return height+1;
    
};

void printLevelTree(treeNode<int>* node,int k){
    if(node == NULL) return;
    if (k == 0) {
        cout<<node->data<<"";
        return;
    };

    for (int i = 0; i < node->children.size(); i++)
    {
        printLevelTree(node->children[i],k-1);
    }
    
};

int leafCount(treeNode<int>* node){
    if(node == NULL) return 0;
    int leaf = 0;
    if (node->children.empty())
    {
        return leaf+1;
    }
    for (int i = 0; i < node->children.size(); i++)
    {
        leaf = leaf + leafCount(node->children[i]);
    }
    return leaf;
};

void preOrderTriversal(treeNode<int>* node){
    cout<<node->data<<" ";
    for (int i = 0; i < node->children.size(); i++)
    {
        preOrderTriversal(node->children[i]);
    }
    
}

void postOrderTriversal(treeNode<int>* node){
    if(node == NULL) return;
    for (int i = 0; i < node->children.size(); i++)
    {
        postOrderTriversal(node->children[i]);
    }
    cout<<node->data<<" ";
}

void deleteNode(treeNode<int>* node){
    if(node == NULL) return;
    for (int i = 0; i < node->children.size(); i++)
    {
        deleteNode(node->children[i]);
    }
    delete node;
};

//input = 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

int main()
{
    // treeNode<int>* node = takeInput();
    treeNode<int>* node = treeTakeInput();
    // printTreeLevel(node);
    // printTree(node);
    // cout<<"level printed"<<endl;
    // printLevelTree(node,1);
    // int NumNode = numOfNode(node);
    // int sumofNode = nodeSum(node);
    // int max = maxValue(node);
    // int height = treeHeight(node);
    // int leaf = leafCount(node);
    // cout<<"number of node:"<<NumNode<<endl;
    // cout<<"sum of node:"<<sumofNode<<endl;
    // cout<<"height of a tree:"<<leaf<<endl;

    // preOrderTriversal(node);
    postOrderTriversal(node);
    // deleteNode(node);

    return 0;
}