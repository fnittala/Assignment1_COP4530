#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class DisjointSet {
    private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    public:
    void makeSet(int item) {
        parent[item] = item;
        rank[item] = 0;
    }
    int findSet(int item) {
        if (parent[item] != item) {
            parent[item] = findSet(parent[item]);
        }
        return parent[item];
    }

    void unionSet(int item1, int item2){
        int root1 = findSet(item1);
        int root2 = findSet(item2);

        // if they are in the same set then return
        if (root1 == root2)
            return;
        
        if(rank[root1] < rank[root2])
            parent[root1] = root2;
        else if(rank[root1] > rank[root2])
            parent[root2] = root1;
        else{
            parent[root2] = root1;
            rank[root1]++;
        }
    }

    bool inSameSet(int item1, int item2){
        return findSet(item1) == findSet(item2);
    }
};

int main(){
    DisjointSet disjointSet;
    int num_sets, func;
    cout << "Enter the number of sets: \n";
    cin >> num_sets;
        
    for(int i = 0; i < num_sets; i++){
        disjointSet.makeSet(i);
    }
    
    while(func != -1){
        cout << "Enter 1 to find a set \n";
        cout << "Enter 2 to merge two sets \n";
        cout << "Enter -1 to exit \n";
        cin >> func;
        if( func == 1){
            int num;
            cout << "Enter the number you want to find: \n";
            cin >> num;
            cout << "This number is part of Set " << disjointSet.findSet(num) << "\n";
            if (disjointSet.findSet(num) == 0)
                cout << "This number is not part of a set \n";

        }

        else if (func == 2){
            int num1, num2;
            cout << "Enter two sets to merge: \n";
            cin >> num1 >> num2;
            disjointSet.unionSet(num1, num2);

        }

        else if (func != -1){
            cout << "Invalid number!" << endl;
        }
    }
    
    return 0;
}



