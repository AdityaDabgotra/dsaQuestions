#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];
    if (initial == color)
        return image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.second + 1 < image[0].size() && image[curr.first][curr.second + 1] == initial)
        {
            q.push({curr.first, curr.second + 1});
            image[curr.first][curr.second + 1] = color;
        }
        if (curr.second - 1 >= 0 && image[curr.first][curr.second - 1] == initial)
        {
            q.push({curr.first, curr.second - 1});
            image[curr.first][curr.second - 1] = color;
        }
        if (curr.first - 1 >= 0 && image[curr.first - 1][curr.second] == initial)
        {
            q.push({curr.first - 1, curr.second});
            image[curr.first - 1][curr.second] = color;
        }
        if (curr.first + 1 < image.size() && image[curr.first + 1][curr.second] == initial)
        {
            q.push({curr.first + 1, curr.second});
            image[curr.first + 1][curr.second] = color;
        }
    }
    return image;
}
int main(){
    int rows, cols;
    cout << "Enter the row Size :\t";
    cin >> rows;
    cout << "Enter the cols Size :\t";
    cin >> cols;
    vector<vector<int>> adj(rows, vector<int>(cols));
    cout << "Enter the Elements:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> adj[i][j];
        }
    }

    vector<vector<int>>result = floodFill(adj,1,1,1);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}