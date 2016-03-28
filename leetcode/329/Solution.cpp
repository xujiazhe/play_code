//
// Created by xujiazhe on 16/3/28.
// 排序广搜  内存超了
// 另外一种方法 就是 Dijkstra's algorithm 完美的变形
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class Solution {

#define MATRIX_MAX_SIZE 500
#define NOT_PASSED -1

    size_t matrixSizeN; //height of matrix
    size_t matrixSizeM; //width  of matrix
    vector<vector<int> > maxPath, maxPath_init;
    vector<int> tmp;
    vector< pair<int, int> > ordered_pos, ordered_pos_init;
    vector<pair<int, int> > directions = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0, -1}
    };

public:
    void t1(vector<vector<int> > & nums){
        auto MaxPath = longestIncreasingPath(nums);
        cout << " MaxPath = " << MaxPath << endl;
    }

    void test(){
        vector<vector<int> > nums1 {
            vector<int>{9, 9, 4},
            vector<int>{6, 6, 8},
            vector<int>{2, 1, 1}
        };

        vector<vector<int> > nums2{
            vector<int>{3, 4, 5},
            vector<int>{3, 2, 6},
            vector<int>{2, 2, 1}
        };

        vector<vector<int> > nums3{
            vector<int>{5, 6, 7},
            vector<int>{4, 9, 8},
            vector<int>{3, 2, 1}
        };
        vector<vector<int> > nums4{
            vector<int>{1,2}
        };

#include "data.txt"

        t1(nums0);
        t1(nums1);
        t1(nums2);
        t1(nums3);
        t1(nums4);

        return ;
    }

    void outputMatrix(vector<vector<int> >& matrix){

        cout << endl;
        for( auto p : matrix){
            for(auto m : p){
                cout << m << ' ';
            }
            cout << endl;
        }
    }

    void printOrderedValue(const vector<vector<int>> &matrix, vector< pair<int, int> >& ordered_pos) const {
        for(auto a : ordered_pos ){
            cout << matrix[a.first][a.second] << ' ' ;
        }
        cout << endl;
    }

    bool couldWalkFromTo( pair<int,int> curPos, pair<int,int> nextPos, const vector<vector<int> >& matrix){
        return matrix[nextPos.first][nextPos.second] > matrix[curPos.first][curPos.second];
    }

    void initVar(vector<vector<int> >& matrix){
//        tmp.capacity();

        matrixSizeN = matrix.size();
        matrixSizeM = matrix[0].size();

        tmp.resize(matrixSizeM, NOT_PASSED);

        maxPath = maxPath_init;
        maxPath.resize(matrixSizeN, tmp);

        ordered_pos = ordered_pos_init;

        for(int i = 0;i<matrixSizeN;i++){
            for(int j = 0;j<matrixSizeM;j++){
                ordered_pos.push_back( pair<int,int>(i,j) );
            }
        }

        sort(ordered_pos.begin(), ordered_pos.end(),
             [&matrix](const pair<int, int> &a, const pair<int, int> &b) -> int {
                 return matrix[a.first][a.second] < matrix[b.first][b.second];
             }
        );

        return ;
    }

    int&pathStatus(const pair<int, int> &pos){
        return maxPath[pos.first][pos.second];
    }

    bool hasPassed(pair<int, int> &pos) {
        return pathStatus(pos) != NOT_PASSED;
    }

    bool outOfMatrixBorder(pair<int, int>& pos){
        if( pos.first >= matrixSizeN || pos.first < 0 ){
            return true;
        }
        if( pos.second >= matrixSizeM || pos.second < 0 ){
            return true;
        }

        return false;
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1)
            return 0;
        //内存抄了 日了狗了


        // 初始化该点的路径最大值, 把所有位置的点,按照大小排序
        initVar(matrix);

//        从最小的点开始近邻往上走的广搜, 更新大小,如果不能比新加的点距离大,就不进队列

        for(auto pos : ordered_pos){

            if(hasPassed(pos)){
                continue;
            }
            vector< pair<int, int> > breadthPath(1, pos);
            pathStatus(pos) = 1;

            // 四个方向不过界,matrix比它大 路径比它小
                // 更新并且加入队列
            for(auto i = 0;i<breadthPath.size();i++){

                auto curPos = breadthPath[i]; //fuck bug

                for(auto j = 0;j<directions.size();j++){
                    pair<int, int> nextPos ( directions[j].first + curPos.first, directions[j].second + curPos.second );

                    if( outOfMatrixBorder(nextPos) ){
                        continue;
                    }

                    if( !couldWalkFromTo(curPos, nextPos, matrix)  ){
                        continue;
                    }

                    if(pathStatus(nextPos) >= pathStatus(curPos) + 1 ){
                        continue;
                    }

                    pathStatus(nextPos) = pathStatus(curPos) + 1;

                    breadthPath.push_back(nextPos);
                }
            }

//            cout << "hello world" << endl;
        }


//      找到最大的路径点
        int MaxPath = 0;
        for(auto i = 0 ; i<matrixSizeN; i++){
            for(auto j = 0;j<matrixSizeM;j++){
                MaxPath = max(maxPath[i][j], MaxPath);
            }
        }

        return MaxPath;
    }


};


int main(){
    Solution a;
    a.test();
}