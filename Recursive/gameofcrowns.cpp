#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<char>> &grid, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            cout << grid[i][j]; 
        cout << endl;
    }
}

bool canPlaceQueen(int r, int c, int rows, int cols, unordered_map<int, bool> &rowmap, unordered_map<int, bool> &colmap, unordered_map<char, bool> &colormap, vector<vector<char>> &ans, vector<string> &grid)
{
    if (r < 0 || c < 0 || r >= rows || c >= cols || rowmap[r] || colmap[c] || colormap[grid[r][c]] || ans[r][c] == 'Q')
        return false;
        
    bool top_left = true, top_right = true, bottom_left = true, bottom_right = true;
    
    //Look at diagonal elements
    if (r - 1 >= 0 && c - 1 >= 0)
        top_left = ans[r - 1][c - 1] != 'Q';
    if (r - 1 >= 0 && c + 1 < cols)
        top_right = ans[r - 1][c + 1] != 'Q';
    if (r + 1 < rows && c - 1 >= 0)
        bottom_left = ans[r + 1][c - 1] != 'Q';
    if (r + 1 < rows && c + 1 < cols)
        bottom_right = ans[r + 1][c + 1] != 'Q';
        
    return (top_right & bottom_right & top_left & bottom_left);
}

void placeQueens(int r, int rows, int cols, int queenCount, int totalQueens, unordered_map<int, bool> &rowmap, unordered_map<int, bool> &colmap, unordered_map<char, bool> &colormap, vector<vector<char>> &ans, vector<string> &grid)
{
    if(queenCount == totalQueens)
    {
        printGrid(ans, rows, cols);
        cout << "\n\n";
    }
    
    for(int j = 0; j < cols; j++)
    {
        if(canPlaceQueen(r, j, rows, cols, rowmap, colmap, colormap, ans, grid))
        {
            ans[r][j] = 'Q';
            rowmap[r] = true;
            colmap[j] = true;
            colormap[grid[r][j]] = true;
            
            
            placeQueens(r + 1, rows, cols, queenCount + 1, totalQueens, rowmap, colmap, colormap, ans, grid);
            
            
            ans[r][j] = '.';
            rowmap[r] = false;
            colmap[j] = false;
            colormap[grid[r][j]] = false;
        }
    }
    
    return;
}

int main() {
	// your code goes here
	vector<string> grid = {
        "OOGGGGGG",
        "OOPGGGGY",
        "OOPYYYYY",
        "OOPPPYYY",
        "OOPPPTTY",
        "OOXPTTRR",
        "OXXPPBBR",
        "OXXPPBBB"
    };
    
    vector<vector<vector<char>>> answers; 
    unordered_set<char> colours; 
    int rows = grid.size(), cols = grid[0].size();
    
    cout << rows << " " << cols << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            colours.insert(grid[i][j]);
    }
    
    if (rows != cols || rows != colours.size())
    {
	cout << "Solution cannot be formed\n";
	return 0;
    }
    
    vector<vector<char>> ans(rows, vector<char> (cols, '.'));
    unordered_map<int, bool> rowmap, colmap;
    unordered_map<char, bool> colormap;
    
    placeQueens(0, rows, cols, 0, colours.size(), rowmap, colmap, colormap, ans, grid);
    

    return 0;
}
