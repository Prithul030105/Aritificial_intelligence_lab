#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;

const int N = 3; 


int goal[N][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};


string toStr(int state[N][N]) {
    string s="";
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            s += to_string(state[i][j]);
    return s;
}


bool isGoal(int state[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(state[i][j] != goal[i][j])
                return false;
    return true;
}


void printState(int state[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout << state[i][j] << " ";
        cout << endl;
    }
    cout << "-----\n";
}


void copyState(int src[N][N], int dest[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dest[i][j] = src[i][j];
}

// DFS
bool DFS(int start[N][N]) {
    stack<string> st;
    set<string> visited;

    st.push(toStr(start));

    while(!st.empty()) {
        string current = st.top();
        st.pop();

        // Convert string back to matrix
        int state[N][N], k=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                state[i][j] = current[k++] - '0';

        if(isGoal(state)) {
            cout << "Goal Reached (DFS)\n";
            printState(state);
            return true;
        }

        visited.insert(current);

        // Find blank (0)
        int x,y;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(state[i][j]==0) { x=i; y=j; }

        // Moves: up, down, left, right
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int m=0;m<4;m++) {
            int nx=x+dx[m], ny=y+dy[m];
            if(nx>=0 && nx<N && ny>=0 && ny<N) {
                int newState[N][N];
                copyState(state,newState);
                swap(newState[x][y], newState[nx][ny]);
                string s = toStr(newState);
                if(!visited.count(s)) st.push(s);
            }
        }
    }
    return false;
}

int main() {
    int start[N][N] = {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    cout << "Initial State:\n";
    printState(start);

    DFS(start);

    return 0;
}
