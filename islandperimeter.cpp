#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int maxX = width - 1;
        int maxY = height - 1;
        int perimeter = 0;
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++) {
                if (grid[y][x] == 1) {
                    if ((y == 0) || (grid[y-1][x] == 0))
                        perimeter++;
                    if ((y == maxY) || (grid[y+1][x] == 0))
                        perimeter++;
                    if ((x == 0) || (grid[y][x-1] == 0))
                        perimeter++;
                    if ((x == maxX) || (grid[y][x+1] == 0))
                        perimeter++;
                }
            }
        }
        return perimeter;        
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    vector<vector<int>> grid({
        {0,1,0,0}, 
        {1,1,1,0}, 
        {0,1,0,0}, 
        {1,1,0,0}
    });
    auto r = sol.islandPerimeter(grid);
    REQUIRE(r == 16);
}


