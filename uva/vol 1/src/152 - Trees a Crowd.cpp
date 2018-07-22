//
// 152 - Tree's a Crowd
//
//  Created by Ridhwanul Haque  on 2/24/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Tree{
public:
    float x, y, z;
    Tree(float a, float b, float c) {x = a, y = b, z = c;}
    float distance(Tree t);
};

float Tree::distance(Tree t) {
    return sqrt((x-t.x)*(x-t.x) + ((y-t.y)*(y-t.y)) + ((z-t.z)*(z-t.z)));
}

int main() {
    vi neighbours(10, 0);
    vector<Tree> trees;
    int x, y, z;
    while(cin >> x >> y >> z) {
        if (x == 0 && y == 0 && z == 0) break;
        Tree t((float) x, (float)y, (float) z);
        trees.push_back(t);
    }
    for (int i = 0; i < trees.size(); i++) {
        Tree t = trees[i];
        float minD = 10;
        for (int j = 0; j < trees.size(); j++) {
            if (j == i) continue;
            float d = t.distance(trees[j]);
            if (d < minD) minD = d;
        }
        neighbours[int(minD)] += 1;
    }
    for (int n : neighbours) {
        int space = 3;
        if (n >= 10) space = 2;
        if (n >= 100) space = 1;
        if (n >= 1000) space = 0;
        while(space > 0) {
            cout << " ";
            space--;
        }
        cout << n;
    }
    cout << endl;
}
