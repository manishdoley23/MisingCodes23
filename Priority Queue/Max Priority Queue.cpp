#include <vector>
using namespace std;
class PriorityQueue {
    vector<int> pq;
	
    void swap(vector<int>& arr, int x, int y){
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    
   public:
    PriorityQueue() {
    }

    void insert(int element) {
        pq.push_back(element);
        int childInd = pq.size() - 1;
        int parentInd = (childInd - 1)/2;
        while(pq[parentInd] < pq[childInd]){
            swap(pq, parentInd, childInd);
            childInd = parentInd;
            parentInd = (childInd - 1)/2;
            if(parentInd < 0) break;
        }
    }

    int getMax() {
        return pq[0];
    }

    int removeMax() {
        if(pq.empty()) return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentInd = 0;
        while(parentInd < pq.size()){
            int c1, c2;
            c1 = 2 * parentInd + 1;
            c2 = 2 * parentInd + 2;
            if(c1 > pq.size()) break;
            else if(c2 > pq.size()){
                if(pq[c1] > pq[parentInd]){
                    swap(pq, parentInd, c1);
                    break;
                }else break;
            }else{
                int mx;
                if(pq[c1] > pq[c2]){
                    mx = c1;
                }else{
                    mx = c2;
                }
                if(pq[mx] > pq[parentInd]){
                    swap(pq, mx, parentInd);
                }
                parentInd = mx;
            }
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.empty();
    }
};


















