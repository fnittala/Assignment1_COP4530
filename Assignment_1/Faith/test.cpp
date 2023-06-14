#include "BinaryTree.h"
#include "PDF.h" 

using namespace std;

void func( const int& src )
  // A test function for the function-based 
{
  cout << src << " ";
}

void user_prompt(BinaryTree<int>& tree){
    string command = "\n"
                     "----------------------------------------\n"
                     "Choose the operation you want to perform: \n"
                     "1. Enter a series of numbers to make a binary tree \n"
                     "2. Choose the traversal method\n"
                     "3. Add a new node\n"
                     "4. Remove a node\n"
                     "5. Print the tree\n"
                     "6. Exit\n";
    
    int prompt = 0;
    while (prompt != 6){
        cout << command << endl;
        cout << "Enter a command: ";
        cin >> prompt;
        if (prompt == 1){
            int max_num = 255, count = 0;
            int num, num_nodes;
            cout << "Enter number of nodes: " ;
            cin >> num_nodes;
            int array_num[num_nodes];
            cout << "Enter numbers you want to add: " ;
            for (int i = 0; i < num_nodes; i++) {
                cin >> array_num[i];
                tree.add(array_num[i]);
            }
            cout << "Enter any character key to finish" << endl;

        }

        else if (prompt == 2)
        {
            cout << "Choose the traversal method: " << endl;
            cout << "1. Preorder" << endl;
            cout << "2. Inorder" << endl;
            cout << "3. Postorder" << endl;
            int num;
            cout << "Enter a method you want to traverse: " << endl;
            cin >> num;
            cout << "The tree is: " << endl;
            if (num == 1){
                tree.preorder(func);
                cout << "Enter any number to finish command" << endl;
            }
            else if (num == 2){
                tree.inorder(func);
                cout << "Enter any number to finish command" << endl;
            } 
            else if (num == 3){
                tree.postorder(func);
                cout << "Enter any number to finish command" << endl;
            }
            else{
                cout << "Invalid input" << endl;
            }
            
            
        }
        if (prompt == 3){
            int num;
            cout << "Enter a number you want to add: " ;
            cin >> num;
            tree.add(num);
            cout << "Added " << num << " to the tree" << endl;
        }
        else if (prompt == 4)
        {
            int num;
            cout << "Enter a number you want to remove: ";
            cin >> num;
            tree.remove(num);
            if (tree.remove(num) == false){
                cout << "The tree does not contain " << num << endl;
            }
            else{
                cout << "Removed " << num << " from the tree" << endl;
            }
        }
        else if (prompt == 5){
          PDF *pdf = new PDF("trees.pdf");

          ostringstream ostring;
          ostring << "Complete tree having " << tree.node_count() << " nodes";
          tree.display(pdf, ostring.str());
          pdf->finish();
          delete pdf;
          cout << "Printed the tree. Check the pdf file" << endl;
        }
       
        else if (prompt == 6)
        {
            cout << "Exiting..." << endl;
        }
        else if (!(cin >> prompt)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
        {
          cout << " " << endl;
        }
    }
}

/********/
/* Main */
/********/

int main( int argc, char *argv[] )
{
    int max_nodes = 255;
    int elements[max_nodes + 1];
    // for (int k = 1; k <= max_nodes; k++)
    //     elements[k] = k;
    elements[0] = 0;

    // Create a new binary tree, having 'n' elements
    int n = 0;  // <-- try changing the value of 'n'
    

    PDF *pdf = new PDF("trees.pdf");

    BinaryTree<int> tree(elements, n);
    user_prompt(tree);
}

