#include <bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    void swap(vector<int>& pq, int x, int y){
        int temp = pq[x];
        pq[x] = pq[y];
        pq[y] = temp;
    }

public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.empty();
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(pq.empty()) return 0;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int childInd = pq.size() - 1;
        int parentInd = (childInd - 1)/2;
        while(pq[parentInd] > pq[childInd]){
            swap(pq, parentInd, childInd);
            childInd = parentInd;
            parentInd = (childInd - 1)/2;
            if(parentInd < 0) break;
        }
    }

     int removeMin() {
        // Write your code here
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parentInd = 0;
        while(parentInd <= pq.size()){
            int c1, c2;
            c1 = 2 * parentInd + 1;
            c2 = 2 * parentInd + 2;
            if(c1 > pq.size() && c2 > pq.size()) break;
            // else if(c2 > pq.size()){
            //     if(pq[c1] < pq[parentInd]){
            //         swap(pq, c1, parentInd);
            //     }
            //     break;
            // }
            
            int mnInd;
            if(c2 > pq.size()) mnInd = c1;
            else if(pq[c1] < pq[c2]) mnInd = c1;
            else mnInd = c2;
            
            if(pq[parentInd] > pq[mnInd]){
                swap(pq, parentInd, mnInd);
            }
            parentInd = mnInd;
            // cout << "par ind:" << parentInd << " pq size:" << pq.size() << endl;
        }
        return ans;
    }

    void show(){
        for(int i=0; i<pq.size(); ++i) cout << pq[i] << " ";
        cout << endl;
    }
};

void solve(){
	PriorityQueue pq;
	cout << pq.isEmpty() << endl;
	pq.insert(2);
	pq.insert(3);
	pq.insert(4);
	pq.insert(5);
	pq.insert(6);
	// pq.insert(7);
	// pq.insert(10);
	cout << pq.isEmpty() << endl;
	pq.show();
	pq.removeMin();
	pq.show();
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--){
      solve();
    }
}


