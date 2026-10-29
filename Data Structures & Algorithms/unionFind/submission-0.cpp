class UnionFind {
    vector<int> parents;
    int components;
public:
    UnionFind(int n) : components(n) {
        parents.resize(n);
        for(int i = 0; i<n; i++){
            parents[i] = i;
        }
    }

    int find(int x) {
        if(parents[x] == x){
            return x;
        }

        return parents[x] = find(parents[x]);
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        if(isSameComponent(x,y)) return false;

        int p_x = find(x);
        int p_y = find(y);

        parents[p_y] = p_x;
        components--;

        return true;
    }

    int getNumComponents() {
        return components;
    }
};
