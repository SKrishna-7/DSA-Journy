#include<iostream>
#include<unordered_set>

using namespace std;


int countSubstrK_brute(string s,int k){

    // int distChar=0;
    int totalCount=0;
    
    int n=s.size();
    
    for(int i=0;i<n;i++){
        unordered_set<char> distChar;
        for(int j=i;j<n;j++){

            distChar.insert(s[j]);
            
            if(distChar.size() == k) totalCount++;
            
            else if(distChar.size() > k) break;
        }


    }


    return totalCount;
}

int countSubstrK_better(string s,int k){

    int totalCount=0;
    
    int n=s.size();
    
    
    for(int i=0;i<n;i++){

        int distChar=0;
        int freq[26]={0};
        
        for(int j=i;j<n;j++){
            
            if(freq[s[j] - 'a'] == 0) distChar++;
            freq[s[j] - 'a']++;
            
            if(distChar == k) totalCount++;
            
            else if(distChar > k) break;
        }


    }


    return totalCount;
}


int atMost(string s,int k,int n){


    int l=0;
    int freq[26]={0};
    int distinctCount=0;
    int total=0;


    for(int r=0;r<n;r++){

        if(freq[s[r]-'a'] ==0) distinctCount++;
        freq[s[r] - 'a']++;

        while(distinctCount>k){
            freq[s[l] - 'a']--;
            if(freq[s[l]-'a'] == 0) distinctCount--;
            l++;
        }

        total+=(r-l+1);

    }

    return total;
}

int countSubstrK_optimal(string s,int k){

    int n=s.size();

    return atMost(s,k,n) - atMost(s,k-1,n);
}


int main(){

    string s="abc";
    int k=2;

    // cout<<countSubstrK_brute(s,k);
    // cout<<countSubstrK_better(s,k);
    cout<<countSubstrK_optimal(s,k);

    return 0;
}