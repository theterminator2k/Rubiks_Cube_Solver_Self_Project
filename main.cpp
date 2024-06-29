


#include "bits/stdc++.h"
#include <chrono>
using namespace std;



class RubiksCube1dArray {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };
    int getIndex(int ind, int row, int col) {
        return (ind * 9) + (row * 3) + col;
    }
    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }
    char cube[54]{};
    RubiksCube1dArray() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i * 9 + j * 3 + k] = getColorLetter(COLOR(i));
                }
            }
        }
    }
    
    COLOR getColor(FACE face, unsigned row, unsigned col) {
    char color = cube[getIndex((int)face, (int)row, (int)col)];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }
    char getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
        }
    }
    void print()  {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
            }
        cout << "\n";
        }
    cout << "\n";
    }

    bool isSolved(){
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[getIndex(i, j, k)] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }
    string getMove(MOVE ind){
        switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
        }
    }
    vector<MOVE> randomShuffleCube(unsigned int times){
        
        vector<MOVE> moves_performed;
        srand(time(0));
        for (unsigned int i = 0; i < times; i++) {
            unsigned int selectMove = (rand() % 18);
            moves_performed.push_back(static_cast<MOVE>(selectMove));
            this->move(static_cast<MOVE>(selectMove));
        }
        return moves_performed;
    }
    RubiksCube1dArray &move(MOVE ind){
        switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
        }
    }
    RubiksCube1dArray &l(){
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &lPrime(){
        this->l();
        this->l();
        this->l();

        return *this;
    }
    RubiksCube1dArray &l2(){
        this->l();
        this->l();

        return *this;
    }
    RubiksCube1dArray &r(){
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &rPrime(){
        this->r();
        this->r();
        this->r();

        return *this;
    }
    RubiksCube1dArray &r2(){
        this->r();
        this->r();

        return *this;
    }
    RubiksCube1dArray &u(){
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &uPrime(){
        this->u();
        this->u();
        this->u();

        return *this;
    }
    RubiksCube1dArray &u2(){
        this->u();
        this->u();

        return *this;
    }
    RubiksCube1dArray &d(){
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &dPrime(){
        this->d();
        this->d();
        this->d();

        return *this;
    }
    RubiksCube1dArray &d2(){
        this->d();
        this->d();

        return *this;
    }
    RubiksCube1dArray &f(){
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &fPrime(){
        this->f();
        this->f();
        this->f();

        return *this;
    }
    RubiksCube1dArray &f2(){
        this->f();
        this->f();

        return *this;
    }
    
    RubiksCube1dArray &b(){
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube1dArray &bPrime(){
        this->b();
        this->b();
        this->b();

        return *this;
    }
    RubiksCube1dArray &b2(){
        this->b();
        this->b();

        return *this;
    }
    RubiksCube1dArray &invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
        }
    }
    bool operator==(const RubiksCube1dArray &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    RubiksCube1dArray &operator=(const RubiksCube1dArray &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
    
    
};
struct Hash1d {
    size_t operator()(const RubiksCube1dArray &r1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += r1.cube[i];
        return hash<string>()(str);
    }
};

class BFSSolver {
public:
    vector<RubiksCube1dArray::MOVE> moves;
    unordered_map<RubiksCube1dArray, bool, Hash1d> visited;
    unordered_map<RubiksCube1dArray, RubiksCube1dArray::MOVE, Hash1d> move_done;

    RubiksCube1dArray bfs() {
        queue<RubiksCube1dArray> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            RubiksCube1dArray node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube1dArray::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
        return rubiksCube;
    }
    RubiksCube1dArray rubiksCube;

    BFSSolver(RubiksCube1dArray _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

//    Performs BFS and returns the vector of moves done to solve the cube
    vector<RubiksCube1dArray::MOVE> solve() {
        RubiksCube1dArray solved_cube = bfs();
        assert(solved_cube.isSolved());
        RubiksCube1dArray curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            RubiksCube1dArray::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
}; 

class DFSSolver {
public:

    vector<RubiksCube1dArray::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(RubiksCube1dArray::MOVE(i));
            moves.push_back(RubiksCube1dArray::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube1dArray::MOVE(i));
        }
        return false;
    }

    RubiksCube1dArray rubiksCube;

    DFSSolver(RubiksCube1dArray _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube1dArray::MOVE> solve() {
        dfs(1);
        return moves;
    }

};
class IDDFSSolver {
public:
    int max_search_depth;
    vector<RubiksCube1dArray::MOVE> moves;


    RubiksCube1dArray rubiksCube;

    IDDFSSolver(RubiksCube1dArray _rubiksCube, int _max_search_depth) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

//    Used DFSSolver with increasing max_search_depth
    vector<RubiksCube1dArray::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }


};

int main()
{
    int algo;
    cout << "Enter 1 for BFS Solver, 2 for DFS Solver and 3 for IDDFS Solver \n";
    cin >> algo;
    auto start = std::chrono::high_resolution_clock::now();


    int shuffle_num = 8;
    RubiksCube1dArray object1;
    cout << "Rubik's Cube initialized to solved state\n";
    object1.print();
    //if(object1.isSolved()){cout << "SOLVED\n";}
    auto shuffleMoves = object1.randomShuffleCube(shuffle_num);
    cout << "The cube is being shuffled " << shuffle_num << " times\n";
    cout << "Shuffle Moves : ";
    for(auto move: shuffleMoves) cout << object1.getMove(move) << " ";
    cout << "\n";
    object1.print();

    if(algo==1)
    {
        cout << "Cube is being solved by BFS\n";
        BFSSolver bfsSolver(object1);
        vector<RubiksCube1dArray::MOVE> solve_moves = bfsSolver.solve();
        cout << "Solution Moves : ";
        for(auto move: solve_moves) cout << object1.getMove(move) << " ";
        cout << "\n";
        bfsSolver.rubiksCube.print();
    }
    if(algo==2)
    {
        cout << "Cube is being solved by DFS\n";
        DFSSolver dfsSolver(object1, shuffle_num+1);
        vector<RubiksCube1dArray::MOVE> solve_moves = dfsSolver.solve();
        cout << "Solution Moves : ";
        for(auto move: solve_moves) cout << object1.getMove(move) << " ";
        cout << "\n";
        dfsSolver.rubiksCube.print();
    }
    if(algo==3)
    {
        cout << "Cube is being solved by IDDFS\n";
        IDDFSSolver iddfsSolver(object1, shuffle_num+1);
        vector<RubiksCube1dArray::MOVE> solve_moves = iddfsSolver.solve();
        cout << "Solution Moves : ";
        for(auto move: solve_moves) cout << object1.getMove(move) << " ";
        cout << "\n";
        iddfsSolver.rubiksCube.print();
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Execution time: " << duration/1000 << " s" << std::endl;

    return 0;
}
