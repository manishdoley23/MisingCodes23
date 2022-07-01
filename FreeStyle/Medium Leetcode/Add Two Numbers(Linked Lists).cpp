//https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        int sum = l1-> val + l2-> val;
        int carry = 0;
        ListNode* root = new ListNode();
        if(sum >= 10){
            carry = 1;
            // cout << "18: " << sum << endl;
            int temp = sum%10;
            root-> val = temp;
        }else{
            root-> val = sum;
        }
        
        // cout << "root-> val: " << root-> val << endl;
        l1 = l1-> next;
        l2 = l2-> next;
        ListNode* tail = root;
        while(l1 != NULL && l2 != NULL){
            sum = l1-> val + l2-> val + carry;
            // cout << "sum: " << sum << endl;
            if(sum >= 10){
                carry = 1;
                int temp = sum%10;
                ListNode* newNode = new ListNode(temp);
                tail-> next = newNode;
                tail = newNode;
            }else{
                carry = 0;
                ListNode* newNode = new ListNode(sum);
                tail-> next = newNode;
                tail = newNode;
            }
            l1 = l1-> next;
            l2 = l2-> next;
        }
        
        // if(sum >= 10){
        //     sum %= 10;
        //     carry = 1;
        // }
        
        while(l1 != NULL){
            sum = l1-> val + carry;
            cout << "1: " << carry << endl;
            cout << "0: " << sum << endl;
            if(sum >= 10){
                carry = 1;
                int temp = sum%10;
                ListNode* newNode = new ListNode(temp);
                tail-> next = newNode;
                tail = newNode;
            }else{
                carry = 0;
                ListNode* newNode = new ListNode(sum);
                tail-> next = newNode;
                tail = newNode;
            }            
            l1 = l1-> next;
        }
        
        while(l2 != NULL){
            sum = l2-> val + carry;
            // cout << "1: " << carry << endl;
            // cout << "0: " << sum << endl;
            if(sum >= 10){
                carry = 1;
                int temp = sum%10;
                ListNode* newNode = new ListNode(temp);
                tail-> next = newNode;
                tail = newNode;
            }else{
                carry = 0;
                ListNode* newNode = new ListNode(sum);
                tail-> next = newNode;
                tail = newNode;
            }            
            l2 = l2-> next;
        }
        
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            tail-> next = newNode;
            tail = newNode;
        }
        return root;
    }
};
