#include <iostream>
#include <stack>
#include <tuple>

using namespace std;


void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: If there is only one disk, move it from source to destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Recursive steps:
    // 1. Move n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // 2. Move the nth disk from source to destination peg
    towerOfHanoi(n - 1,  source, auxiliary, destination);

    // 3. Move the n-1 disks from auxiliary to destination peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}



void iterativeTowerOfHanoi(int numDisks, char source, char auxiliary, char destination) {

    // Initialize an empty stack to store tuples (n, src, aux, dest)
    stack<tuple<int, char, char, char>> stack;  

    // Push the initial state onto the stack
    stack.push(make_tuple(numDisks, source, auxiliary, destination));  

    // While the stack is not empty
    while (!stack.empty()) {  

        // Get the top tuple from the stack
        tuple<int, char, char, char> current = stack.top();  

        // Remove the top element from the stack
        stack.pop();  

        // Extract the number of disks (n) from the tuple
        int n = get<0>(current);  

        // Extract the source peg (src) from the tuple
        char src = get<1>(current); 

        // Extract the auxiliary peg (aux) from the tuple
        char aux = get<2>(current);  

        // Extract the destination peg (dest) from the tuple
        char dest = get<3>(current);  

        if (n == 1) {
            // Base case: Move disk 1 from source to destination
            cout << "Move disk 1 from " << src << " to " << dest << endl;
        }
        else {
            // Recursive steps:
            // 
            // 1. Move n-1 disks from source to auxiliary peg
            stack.push(make_tuple(n - 1, src, dest, aux));

            // 2. Move the nth disk from source to destination peg
            stack.push(make_tuple(1, src, aux, dest));
                                                                        
            // 3. Move the n-1 disks from auxiliary to destination peg
            stack.push(make_tuple(n - 1, aux, src, dest));
        }
    }
}



int main() {
    int numDisks = 8; 
    // You can change this to the desired number of disks
    //iterativeTowerOfHanoi(numDisks, 'A', 'B', 'C');

    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}


