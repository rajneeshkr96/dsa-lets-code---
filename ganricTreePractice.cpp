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

bool checkValue(treeNode<int>* root,int value){
    if(root == NULL) return false;
    if (root->data == value) return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        checkValue(root->children[i],value);
    }
    return false;
}

int greaterNodes(treeNode<int>* root,int value){
    if(root == NULL) return 0;
    int count = 0;
    if (root->data > value){
         count++;
         }
    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + greaterNodes(root->children[i],value);       
    }
    return count;
    
};

int heightSum(treeNode<int> *root){
     if(root == NULL) return -1;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    return sum;

}

int nodeWithMaxChildSum(treeNode<int> *root){
    if(root == NULL) return -1;
    int node = root->data;
    int sum = heightSum(root);
  
    for (int i = 0; i < root->children.size(); i++)
    {
        int val = nodeWithMaxChildSum(root->children[i]);  
        int childSum = heightSum(root->children[i]);
        if (childSum>sum)
        {
            sum = childSum;
            node = root->children[i]->data;
        }
        
    }
    return node;  
}

bool chekIdentical(treeNode<int>* root, treeNode<int>* node){
    if (root == NULL && node == NULL) return false;
    if (root->data != node->data) return false;
    if (root->children.size() != node->children.size()) return false;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool check = chekIdentical(root->children[i], node->children[i]);
        if (!check) return check;
    }
    return true;
}

int nextGreater(treeNode<int>* root,int val){
    if (root == NULL) return -1;
    int grt = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int child = nextGreater(root->children[i],val);
        if (val<child && grt>child)
        {
           grt = child;
        }
        
    }
    if (grt<val)
    {
        grt = -1;
    }
    return grt;
    
};

// todo
// int secLargestNode(treeNode<int>* root){
//     if (root == NULL) return NULL;
//     int grt = root->data;
//     int sec = NULL;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         int data = root->children[i]->data;
//         int temp;
//         if (data > grt)
//         {
//             temp = grt;
//             grt = data;
//             if (sec != NULL && sec<temp )
//             {
//                 sec = temp;
//             }
//         sec = temp;
//         } 
//     }
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         int child = secLargestNode(root->children[i]);

//     }
    
    
    
// };

void replaceWithDepth(treeNode<int>* root,int depth=0){
    if(root == NULL) return;
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i],depth+1);
    }
    
}

int main()
{
    treeNode<int>* root = treeTakeInput();
    // treeNode<int>* node = treeTakeInput();
    // bool value = checkValue(root,5);
    // cout<<"tree value"<<value<<endl;
    // int value = greaterNodes(root,5);
    // cout<<"greater values count"<<value<<endl;
    // printTreeLevel(root);
    // int value = nodeWithMaxChildSum(root);
    // cout<<"node with greater sum with thair all childs value : "<<value<<endl;
    // bool value = chekIdentical(root,root);
    // cout<<"two tree is indentical : "<<value<<endl;
    // int value = nextGreater(root,4);
    // cout<<"two tree is indentical : "<<value<<endl;
    replaceWithDepth(root);
    printTreeLevel(root);

    return 0;
}