#include <iostream>

using namespace std;

class Btree{
public:
    int val;
    Btree* left;
    Btree* right;
};

Btree* create()
{
    Btree* root = new Btree();
    int n;
    cout<<"Enter total number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers:  ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    root->val = arr[0];
    for(int i=1; i<n; i++)
    {
        Btree* node = new Btree();
        node->val = arr[i];
        Btree* temp = root;
        while(true){
            if(temp->val>node->val)
            {
                if(temp->left==NULL)
                {
                    temp->left = node;
                    break;
                }
                temp = temp->left;
            }
            else{
                if(temp->right==NULL)
                {
                    temp->right = node;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    
    return root;
}

void preorder(Btree* root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Btree* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

void inorder(Btree* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

int main()
{
    Btree* tree1 = create();
    cout<<"Preorder: ";
    preorder(tree1);
    cout<<endl;
    
    cout<<"Postorder: ";
    postorder(tree1);
    cout<<endl;
    
    cout<<"Inorder: ";
    inorder(tree1);
    cout<<endl;
}
