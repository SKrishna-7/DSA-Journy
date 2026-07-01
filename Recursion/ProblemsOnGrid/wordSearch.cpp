    #include <iostream>
    #include<vector>
    using namespace std;
    
    
    bool solve(vector<vector<char>> &words,string &target,int index,int i,int j,
     vector<vector<bool>> &visited){
        
        if(index == target.size()){
            return true ;
        }
        
        int rowSize = words.size();
        int colSize = words[0].size();
        
        if(
            i < 0 || i >= rowSize || j < 0 || j >= colSize || words[i][j] != target[index] || visited[i][j]
            ){
            return false;
        }
        
        visited[i][j] = true;
        bool found = solve(words,target,index+1,i-1,j,visited) || 
        solve(words,target,index+1,i+1,j,visited) || 
        solve(words,target,index+1,i,j-1,visited) || 
        solve(words,target,index+1,i,j+1,visited);
        
        visited[i][j] = false;
        return found;
       
    }
    int main() {
        
        vector<vector<char>> words = {
             {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        
       vector<vector<bool>> visited(words.size(), vector<bool>(words[0].size(), false));
       
        string target = "SEE";
        
        for(int r=0;r<words.size();r++){
            
            for(int c=0;c<words[0].size();c++){
                
               if(words[r][c] == target[0]){
                   
                   if(solve(words,target,0,r,c,visited)){
                       cout<<boolalpha << true;
                   }
               }
                
            }
        }
    
    
        return 0;
    }       