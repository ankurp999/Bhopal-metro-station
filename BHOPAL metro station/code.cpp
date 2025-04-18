#include<iostream>
#include<vector>
#include<utility>
#include<set>
using namespace std;
void dijikstras(int src,vector<vector<pair<int , int> > > &gh ,vector<string> &stationNames)
{
  int V = gh.size();  // Number of vertices
    vector<int> dist(V, INT_MAX);  // Distance from src to each node
    set<pair<int, int>> s;  // Set to store (distance, vertex)
    
    // Initialize source vertex distance and add to the set
    dist[src] = 0;
    s.insert({0, src});
    
    while (!s.empty()) {
        // Extract the vertex with the smallest distance
        pair<int, int> p = *(s.begin());
        s.erase(s.begin());
        int node = p.second;
        int nodeDist = p.first;
        
        // Relaxation step: Check neighbors of the current node
        for (auto &neighbor : gh[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;
            
            // If shorter path is found
            if (nodeDist + weight < dist[adjNode]) {
                // Remove if already in set
                if (dist[adjNode] != INT_MAX) {
                    s.erase({dist[adjNode], adjNode});
                }
                
                // Update distance and insert the new pair in the set
                dist[adjNode] = nodeDist + weight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    } 
    // Print the distances from the source
    cout << "Station Code\t\t\t\t\t\t\tDistance from "<<stationNames[src]<< endl;
    for (int i = 0; i < V; i++) {
        cout<<i<<". "<<stationNames[i]<<"\t\t\t\t\t\t\t"<<dist[i]<< endl;
    }
}
int main()
{ 
    vector<string> stationNames = {
        "Gandhi Nagar", "Karond", "Berasia", "Budhwar", "Jahangirabad", 
        "Roshanpura", "Kotra Sultanabad", "Nehru Nagar", "Shyamla Hills", 
        "Van Vihar", "Jawahar Chowk", "Rangmahal", "Vidhan Sabha", 
        "MP Nagar", "6 no. stop", "Shivaji Nagar", "Chaar Imli", "Bittan Market", 
        "Shahpura", "Gulmohar", "Aakriti Eco City", "Sadiya", "Chandbad", 
        "Ashoka Garden", "Govindpura", "Minal", "Piplani", 
        "Ayodhya Bypass", "Anand Nagar", "Awadhpuri", "Barkheda Pathani", 
        "Saket Nagar", "AIIMS", "Barkatullah University", "Misrod", "Ratanpur", 
        "Bairagarh", "Lalghati", "Tajul Masjid", "Hamidia Hospital", 
        "Kamla Park", "Polytechnic Square", "Roshanpura", "New Market", 
        "Mata Mandir", "MANIT Square", "Patrakar Colony", "Chuna Bhatti", 
        "Sarvadharm", "Bima Kunj", "Danish Kunj", "Nayapura", 
        "Bairagarh Chichli"};
    vector<vector<pair<int, int>>> graph(53); 
// We have 52 stations (0 to 52)

    // adding connections based on adjacency from the map (all with distance = 1)
    graph[0] = {{1, 1}};
    graph[1] = {{0, 1}, {2, 1}};
    graph[2] = {{1, 1}, {3, 1}};
    graph[3] = {{2, 1}, {4, 1}};
    graph[4] = {{3, 1}, {5,1}, {42, 1}};
    graph[5] = {{4, 1}, {41,1}, {42,1}, {43,1}};
    graph[6] = {{42, 1}, {5,1}, {7, 1}};
    graph[7] = {{6, 1}, {8, 1}};
    graph[8] = {{7, 1}};
    graph[9] = {{10, 1}};
    graph[10] = {{9, 1}, {11, 1}};
    graph[11] = {{10, 1}, {43, 1}};
    graph[12] = {{43, 1}, {13, 1}};
    graph[13] = {{12, 1}, {14, 1}, {23,1}, {24,1}};
    graph[14] = {{13, 1}, {15, 1}};
    graph[15] = {{14, 1}, {16, 1}};
    graph[16] = {{15, 1}, {17, 1}};
    graph[17] = {{16, 1}, {18, 1}};
    graph[18] = {{17, 1}, {19, 1}};
    graph[19] = {{18, 1}, {20, 1}};
    graph[20] = {{19, 1}, {21, 1}};
    graph[21] = {{20, 1}, {52, 1}};
    graph[22] = {{23, 1}};
    graph[23] = {{22, 1}, {13, 1}};
    graph[24] = {{13, 1}, {25, 1}};
    graph[25] = {{24, 1}, {26, 1}};
    graph[26] = {{25, 1}, {27, 1}};
    graph[27] = {{26, 1}, {28, 1}};
    graph[28] = {{27, 1}, {29, 1}};
    graph[29] = {{28, 1}, {30, 1}};
    graph[30] = {{29, 1}, {31, 1}};
    graph[31] = {{30, 1}, {32, 1}};
    graph[32] = {{31, 1}, {33, 1}};
    graph[33] = {{32, 1}, {34, 1}};
    graph[34] = {{33, 1}, {35, 1}};
    graph[35] = {{34, 1}};
    graph[36] = {{37, 1}};
    graph[37] = {{36, 1}, {38, 1}};
    graph[38] = {{37, 1}, {39, 1}};
    graph[39] = {{38, 1}, {40, 1}};
    graph[40] = {{39, 1}, {41,1}};
    graph[41] = {{40, 1}, {42,1}, {5,1}};
    graph[42] = {{41, 1}, {43,1}, {5,1}, {6,1}, {4,1}};
    graph[43] = {{11, 1}, {12, 1}, {42, 1}, {5,1}, {44, 1}};
    graph[44] = {{43, 1}, {45, 1}};
    graph[45] = {{44, 1}, {46, 1}};
    graph[46] = {{45, 1}, {47, 1}};
    graph[47] = {{46, 1}, {48, 1}};
    graph[48] = {{47, 1}, {49, 1}};
    graph[49] = {{48, 1}, {50, 1}};
    graph[50] = {{49, 1}, {51, 1}};
    graph[51] = {{50, 1}, {52, 1}};
    graph[52] = {{21, 1}, {51, 1}};
   int sn =0;
   cout<<"Enter the source Station Code"<<endl;
   for(int i=0; i<53; i++)
   {
      cout<<"["<<i<<"]"<<". "<<stationNames[i]<<endl;
   }
   cin>>sn;
   dijikstras(sn,graph,stationNames);
   
  return 0;
}