class DSU {
    vector<int>parent;
    vector<int>rank;
    int numberOfComponents;

    public:
        DSU(int n){
          parent.resize(n);
          rank.resize(n);
          numberOfComponents=n;
          for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
          }
        }

        int find(x){
          if (parent[x]==x) return x;
          return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
          int x_parent=find(x);
          int y_parent=find(y);

          if (x_parent==y_parent) return;

          if (rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
          } else if (rank[y_parent]>rank[x_parent]){
            parent [x_parent]=y_parent;
          } else {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
          }
          numberOfComponents--;
        }

        int maxSize(){
            return numberOfComponents;
        }
}