//https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

class Solution{
public:
    void search(Node* root, int l, int h, int& count){
        if(root == NULL) return;
        // cout << root-> data << endl;
        if(root-> data >= l && root-> data <= h) count++;
        
        if(root-> data > l){
            search(root-> left, l, h, count);
        }
        
        if(root-> data < h){
            search(root-> right, l, h, count);
        }
    }

    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
      if(root == NULL) return 0;
      int count = 0;
      search(root, l, h, count);
      return count;
    }
};
