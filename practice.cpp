#include<iostream>
using namespace std;

class prims {
public:
    int totaledges, totalcities;
    string cities[100];
    int distance[100][100];

    void accept();
    void primsalg();
    void display();
};

void prims::accept() {
    cout << "Enter total cities: ";
    cin >> totalcities;

    for (int i = 0; i < totalcities; i++) {
        cout << "Enter city name: ";
        cin >> cities[i];   
    }

    // Initialize the distance matrix
    for (int k = 0; k < totalcities; k++) {
        for (int f = 0; f < totalcities; f++) {
            if (cities[k] == cities[f]) {
                distance[k][f] = 0;
            }
            else {
                distance[k][f] = 999;
            }
        }
    }

    string city1, city2;
    int weight;
    cout << "Enter total edges: ";
    cin >> totaledges;

    // Process each edge, fixing the issue - move assignment inside the loop
    for (int j = 0; j < totaledges; j++) {
        cout << "Enter city 1, city 2 and weight: ";
        cin >> city1 >> city2 >> weight;
        
        // Reset indices for each edge input
        int index1 = -1, index2 = -1;  // Moved inside the loop
        
        // Find indices of the given cities
        for (int z = 0; z < totalcities; z++) {
            if (cities[z] == city1) {
                index1 = z;
            }
            if (cities[z] == city2) {
                index2 = z;
            }
        }
        
        // Only update if both cities were found
        if (index1 != -1 && index2 != -1) {
            distance[index1][index2] = weight;
            distance[index2][index1] = weight;
        } else {
            cout << "Invalid cities entered. Try again.\n";
            j--; // Retry this edge input if invalid
        }
    }
}

void prims::primsalg() {
    bool visited[10] = {false}; // Note: This assumes a maximum of 10 cities.
    int weight[10];
    int parent[10];
    int min, u;
    int mstvalue = 0;
    
    for (int i = 0; i < totalcities; i++) {
        weight[i] = 999;
        parent[i] = -1;
    }
    weight[0] = 0;

    for (int count = 0; count < totalcities - 1; count++) {
        min = 999;
        for (int v = 0; v < totalcities; v++) {
            if (!visited[v] && weight[v] < min) {
                min = weight[v];
                u = v;
            }
        }
        visited[u] = true;

        for (int v = 0; v < totalcities; v++) {
            if (!visited[v] && distance[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = distance[u][v];
            }
        }
    }
    
    // Start printing from i = 1 to skip the first node's undefined parent (-1)
    for (int i = 1; i < totalcities; i++) {
        cout << "Calculated MST: ";
        cout << cities[parent[i]] << " -> " << cities[i] << " = " << distance[i][parent[i]] << endl;
        mstvalue = mstvalue + distance[i][parent[i]];
    }
    cout << "Total MST Distance: " << mstvalue << endl;
}

void prims::display() {
    cout << "Distance matrix:" << endl;
    for (int i = 0; i < totalcities; i++) {
        for (int j = 0; j < totalcities; j++) {
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    prims obj;
    obj.accept();
    obj.primsalg();
    obj.display();
    return 0;
}
