class Solution {
  public:
    void fun(vector<vector<int>>& max,vector<string>& res,string temp,int i,int j){
        int n=max.size();
        if(i==n-1 && j==n-1) {
            res.push_back(temp);
            return;
        }
        max[i][j]=0;
        if(i+1<n && max[i+1][j]==1) fun(max,res,temp+'D',i+1,j);
        if(j-1>=0 && max[i][j-1]==1) fun(max,res,temp+'L',i,j-1);
        if(j+1<n && max[i][j+1]==1) fun(max,res,temp+'R',i,j+1);
        if(i-1>=0 && max[i-1][j]==1) fun(max,res,temp+'U',i-1,j);
        max[i][j]=1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        fun(maze,res,"",0,0);
        return res;
    }
};