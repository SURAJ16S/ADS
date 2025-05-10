#include <iostream>
#include <iomanip>
using namespace std;

class OptimalBST {
    int totalKeys; // Number of items (keys)
    string itemNames[10]; // Array to store item names (keys)
    float p[10], q[11]; // p: Successful search probability, q: Unsuccessful search probability
    float w[11][11], c[11][11]; // w: Weight matrix, c: Cost matrix
    int rootMatrix[11][11]; // Stores optimal root positions

public:
    void acceptData(); // Accept user input
    void computeOptimalBST(); // Dynamic programming calculations
    void displayResults(); // Print matrices and tree structure
    void constructTree(int start, int end, string parentItem, string branchType); // Recursive function
};

// Function to accept input from user
void OptimalBST::acceptData() {
    cout << "Enter the number of items: ";
    cin >> totalKeys;

    // Input sorted item names
    cout << "Enter item names in sorted order:\n";
    for (int i = 0; i < totalKeys; i++) {
        cin >> itemNames[i];
    }

    // Input search probabilities
    cout << "Enter probabilities of successful searches (p):\n";
    for (int i = 0; i < totalKeys; i++) {
        cin >> p[i];
    }

    // Input probabilities for unsuccessful searches
    cout << "Enter probabilities of unsuccessful searches (q):\n";
    for (int i = 0; i <= totalKeys; i++) {
        cin >> q[i];
    }
}

// Function to compute the Optimal BST using dynamic programming
void OptimalBST::computeOptimalBST() {
    // Step 1: Initialize base cases (single-node trees)
    for (int i = 0; i <= totalKeys; i++) {
        w[i][i] = q[i]; // Initialize weight matrix
        c[i][i] = 0; // Zero cost for an empty subtree
        rootMatrix[i][i] = 0; // No root exists in an empty range
    }

    // Step 2: Compute matrices for increasing subtree sizes
    for (int gap = 1; gap <= totalKeys; gap++) { // 'gap' represents subtree length
        for (int i = 0; i <= totalKeys - gap; i++) {
            int j = i + gap; // End index of subtree
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

            float minimumCost = 9999; // Initialize minimum cost tracker
            int optimalRoot = 0; // Variable to store best root index

            // Step 3: Check every possible root between i & j and find the one with minimum cost
            for (int k = i + 1; k <= j; k++) {
                float currentCost = c[i][k - 1] + c[k][j];
                if (currentCost < minimumCost) {
                    minimumCost = currentCost;
                    optimalRoot = k; // Store optimal root index
                }
            }

            // Update matrices
            c[i][j] = w[i][j] + minimumCost;
            rootMatrix[i][j] = optimalRoot;
        }
    }
}

// Function to display matrices and tree structure
void OptimalBST::displayResults() {
    cout << fixed << setprecision(2);

    // Display weight matrix (Accumulated probabilities)
    cout << "\nWeight Matrix (W):\n";
    for (int gap = 0; gap <= totalKeys; gap++) {
        for (int i = 0; i <= totalKeys - gap; i++) {
            int j = i + gap;
            cout << "W[" << i << "][" << j << "] = " << w[i][j] << "\t";
        }
        cout << endl;
    }

    // Display cost matrix (Search costs)
    cout << "\nCost Matrix (C):\n";
    for (int gap = 0; gap <= totalKeys; gap++) {
        for (int i = 0; i <= totalKeys - gap; i++) {
            int j = i + gap;
            cout << "C[" << i << "][" << j << "] = " << c[i][j] << "\t";
        }
        cout << endl;
    }

    // Display root matrix (Optimal tree structure)
    cout << "\nRoot Matrix (R):\n";
    for (int gap = 0; gap <= totalKeys; gap++) {
        for (int i = 0; i <= totalKeys - gap; i++) {
            int j = i + gap;
            cout << "R[" << i << "][" << j << "] = " << rootMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMinimum cost of Optimal BST = " << c[0][totalKeys] << endl;
    
    // Display tree structure
    cout << "\nOptimal Binary Search Tree Structure:\n";
    constructTree(0, totalKeys, "None", "Root");
}

// Recursive function to construct the BST hierarchy
void OptimalBST::constructTree(int start, int end, string parentItem, string branchType) {
    int rootIndex = rootMatrix[start][end];

    // Base case: If no valid root exists, return
    if (rootIndex == 0 || rootIndex == -1) return;

    // Get the key corresponding to this root
    string currentItem = itemNames[rootIndex - 1];
    cout << currentItem << " is the " << branchType << " of " << parentItem << endl;

    // Recursively print left and right subtrees
    constructTree(start, rootIndex - 1, currentItem, "Left Child");
    constructTree(rootIndex, end, currentItem, "Right Child");
}

// Main function
int main() {
    OptimalBST obstObject; // Object creation
    int choice;
    do {
        cout << "1. Accept Data\t 2. Compute OBST\t 3. Display Result\t 0. Exit Program";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obstObject.acceptData();
                break;
            case 2:
                obstObject.computeOptimalBST();
                cout << "Computation completed successfully";
                break;
            case 3:
                obstObject.displayResults();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}
