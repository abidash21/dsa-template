class DSU{
    vector<int>parent;
    vector<int>size;
    int numberOfComponents=n;

    public:
      DSU(int n){
        parent.resize(n);
        size.resize(n);
        numberOfComponents;
        for (int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
      }

      int find(int x){
        if (x==parent[x]) return x;
        return parent[x]=find(parent[x]);
      }

      void Union(int x,int y){
        int x_parent=parent[x];
        int y_parent=parent[y];
        if (x_parent==y_parent) return;

        if (size[x_parent]>size[y_parent]){
            parent[y_parent]=x_parent;
            size[x_parent]+=parent[y_parent];
        } else if (size[y_parent]>size[x_parent]){
            parent[x_parent]=y_parent;
            size[y_parent]+=parent[x_parent];
        }  else {
            parent[x_parent]=y_parent;
            size[y_parent]+=parent[x_parent];
        }
        numberOfComponents--;
      }

      int maxSize(){
        return numberOfComponents;
      }
};
