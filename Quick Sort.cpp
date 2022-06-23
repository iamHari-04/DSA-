#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    } 
};
void preorder(Node* root){
    stack<Node*>s;
    Node* curr = root;
    while(!s.empty() or root){
        if(curr){
            cout<<curr->data;
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }
    
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void QuickSort(int arr[], int low, int high){
    if(low<high){
        int p = partition(arr, low, high);
        QuickSort(arr, low, p-1);
        QuickSort(arr, p+1, high);
    }
}
int main(){
    
    int arr[8] = {1,5,7,3,6,10,5,8};
    QuickSort(arr, 0, 7);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
