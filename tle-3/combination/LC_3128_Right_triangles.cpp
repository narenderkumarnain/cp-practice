#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long rows = grid.size();
        long long columns = grid[0].size();
        // [row][column]
        vector<long long> rowCount(rows, 0);
        // for(long long i=0;i<rows;i++) {
        //     rowCount[i] += grid[i][columns-1];
        // }

        vector<long long> rowTotalCount(rows, 0), columnTotalCount(columns, 0);
        for(long long i=0;i<rows;i++) {
            for(long long j=0;j<columns;j++) {
                rowTotalCount[i] += grid[i][j];
                columnTotalCount[j] += grid[i][j];
            }
        }

        long long res = 0;

        for(long long j = columns-1;j>=0;j--) {
            long long columnCount = 0;

            // long long columnCntTotal = 0;
            // for(long long i=0;i<rows;i++) columnCntTotal += grid[i][j];
            
            for(long long i=0;i<rows;i++) {
                if(grid[i][j] == 1) {
                    // right - up
                    res += (columnCount * rowCount[i]);

                    // right down
                    res += ((columnTotalCount[j] - columnCount - 1) * rowCount[i]);

                    // left up
                    res += (columnCount * (rowTotalCount[i] - rowCount[i] - 1));

                    // left down
                    res += ((columnTotalCount[j] - columnCount - 1) * (rowTotalCount[i] - rowCount[i] - 1));
                }

                if(grid[i][j] == 1) {
                    columnCount++;
                    rowCount[i]++;
                }
            }
        }

        return res;
    }
};