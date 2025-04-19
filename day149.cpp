#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(
    vector<vector<int>>& image, int sr, 
    int sc, int newColor) {

    // If the starting pixel already has the new color
    if (image[sr][sc] == newColor) {
        return image;
    }

    // Direction vectors for traversing 4 directions
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Initialize the queue for BFS
    queue<pair<int, int>> q;
    int oldColor = image[sr][sc];
    q.push({sr, sc});
    
    // Change the color of the starting pixel
    image[sr][sc] = newColor;

    // Perform BFS
    while (!q.empty()) {
        pair<int, int> front = q.front();
        int x = front.first, y = front.second;
        q.pop();
        
        // Traverse all 4 directions
        for (const pair<int, int>& direction : directions) {
            int nx = x + direction.first;
            int ny = y + direction.second;
            
            // Check boundary conditions and color match
            if (nx >= 0 && nx < image.size() && 
                ny >= 0 && ny < image[0].size() && 
                image[nx][ny] == oldColor) {
                
                // Change the color and enqueue
                image[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
    }

    return image;
}

int main() {
    
    // Define the input 2D image (grid of pixel colors)
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    // Starting pixel coordinates (row = 1, column = 2)
    int sr = 1, sc = 2;

    // New color to apply to the connected region
    int newColor = 2;

    // Call the floodFill function to perform DFS/BFS fill from the
    // starting pixel
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Print the updated image after flood fill
    for (auto& row : result) {
        for (auto& pixel : row) {
            
            // Print each pixel with a space
            cout << pixel << " ";  
        }
        
        // Move to the next line after printing each row
        cout << "\n";  
    }
    
    return 0; 
}