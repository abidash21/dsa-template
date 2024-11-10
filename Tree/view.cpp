// Left View

    //1. DFS
    void solve(Node* root,int depth,vector<int>&res){
        if (root==NULL) return;
        if (depth==res.size()) res.push_back(root->data);
        solve(root->left,depth+1,res);
        solve(root->right,depth+1,res);
    }
    vector<int> leftView(Node *root) {
        vector<int>res;
        solve(root,0,res);
        return res;
    }

    //2.DFS
     vector<int> leftView(Node *root) {
        vector<int>res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int depth=q.front().second;
            Node* node=q.front().first;
            q.pop();
            if (res.size()==depth) res.push_back(node->data);
            if (node->left) q.push({node->left,depth+1});
            if (node->right) q.push({node->right,depth+1});
        }
        return res;
    }


// Right View

    //1.DFS
    void solve(Node* root,int depth,vector<int>&res){
        if (root==NULL) return;
        if (depth==res.size()) res.push_back(root->data);
        solve(root->right,depth+1,res);
        solve(root->left,depth+1,res);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>res;
        solve(root,0,res);
        return res;
    }

    //2.BFS
    vector<int> rightView(Node *root)
    {
        vector<int>res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int depth=q.front().second;
            Node* node=q.front().first;
            q.pop();
            if (res.size()==depth) res.push_back(node->data);
            if (node->right) q.push({node->right,depth+1});
            if (node->left) q.push({node->left,depth+1});
        }
        return res;
    }

// Bottom View
  
    //1.DFS
    void solve(Node* root,int hd,int depth,map<int,pair<int,int>>&mp){
        if (root==NULL) return;
        if (mp.find(hd)==mp.end() || depth>=mp[hd].first) mp[hd]={depth,root->data};
        solve(root->left,hd-1,depth+1,mp);
        solve(root->right,hd+1,depth+1,mp);
    }
    vector <int> bottomView(Node *root) {
        vector<int>res;
        map<int,pair<int,int>>mp; // hd,(depht,val)
        solve(root,0,0,mp);
        for (auto it:mp) res.push_back(it.second.second);
        return res;
    }

    //2.BFS
    vector <int> bottomView(Node *root) {
        vector<int>res;
        map<int,int>mp; // hd,(depht,val)
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* node=q.front().first;
            int hd=q.front().second;
            q.pop();
            mp[hd]=node->data;
            if (node->left) q.push({node->left,hd-1});
            if (node->right) q.push({node->right,hd+1});
        }
        for (auto it:mp) res.push_back(it.second);
        return res;
    }

    /*There is no need to track depth here because, bfs algorithm works in levelwise manner. Which means if the algo reaches
       a particular horizontal distance at last, then it is the highest depth */


// Top View
   

   //1.DFS
    void solve(Node* root,int hd,int depth,map<int,pair<int,int>>&mp){
        if (root==NULL) return;
        if (mp.find(hd)==mp.end() || depth<mp[hd].first) mp[hd]={depth,root->data};
        solve(root->left,hd-1,depth+1,mp);
        solve(root->right,hd+1,depth+1,mp);
    }
    vector<int> topView(Node *root)
    {
        vector<int>res;
        map<int,pair<int,int>>mp; // hd,(depht,val)
        solve(root,0,0,mp);
        for (auto it:mp) res.push_back(it.second.second);
        return res;
    }

    //2.BFS
    vector<int> topView(Node *root)
    {
        vector<int>res;
        map<int,int>mp; // hd,(depht,val)
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* node=q.front().first;
            int hd=q.front().second;
            q.pop();
            if (mp.find(hd)==mp.end()) mp[hd]=node->data;
            if (node->left) q.push({node->left,hd-1});
            if (node->right) q.push({node->right,hd+1});
        }
        for (auto it:mp) res.push_back(it.second);
        return res;
    }

    //as bfs work levelwise,hence the first one to get updated will be the top most view
