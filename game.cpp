#include <iostream>
#include <vector>

using namespace std;

int turn(int x){
    return (x+1)%2;
}

bool isValid(int r,int c){
    if(r>=0&&c>=0&&r<3&&c<3)return true;
    return false;
}

bool check(vector<vector<char>>&v,int r,int c){
    char sym=v[r][c];
    if(r==c){
        bool flag=true;
        for(int i=0;i<3;i++){
            if(v[i][i]!=sym)flag=false;
        }
        if(flag==true)return true;


    }
    
    if(r==0&&c==2||(r==1&&c==1)||(r==2&&c==0)){
        if((v[0][2]==v[1][1])&&(v[1][1]==v[2][0])&&(v[0][2]==sym))return true;
    }

    bool flag=true;
    for(int i=0;i<3;i++){
        if(v[i][c]!=sym)flag=false;
    }
    if(flag==true)return true;
    flag=true;
    for(int j=0;j<3;j++){
        if(v[r][j]!=sym)flag=false;
    }
    if(flag==true)return true;
    return false;
}

void printTable(vector<vector<char>>&v){
    int m=v.size();
    int n=v[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

int main(){

    vector<vector<char>>v(3,vector<char>(3,'_'));
    
    int flag=turn(1);
    int cnt=0;
    
    char symbolPlayer1;
    char symbolPlayer2;
    string p1,p2;
    cout<<"please select symbol for players1 and player2: "<<endl;


    cin>>symbolPlayer1>>symbolPlayer2;
    cout<<"please select player1 name and player2 name: "<<endl;
    cin>>p1>>p2;
    cout<<"initial table"<<endl;

    printTable(v);

    cout<<"game begins now!"<<endl;
    
    while(true){
        if(cnt==9)break;
        int r,c;
        if(flag==0)cout<<p1<<"'s turn\n please select the cell r and c (1th based indexing)"<<endl;
        else cout<<p2<<"'s turn\n please select the cell r and c (1th based indexing)"<<endl;
        
        cin>>r>>c;
        r--;
        c--;
        
        if(flag==0&&isValid(r,c)&&v[r][c]=='_'){
            v[r][c]=symbolPlayer1;
            if(check(v,r,c)){
                cout<<"player 1 wins";
                return 0;
            }         
            cnt++;
        }
        else if(flag==1&&isValid(r,c)&&v[r][c]=='_'){
            
                          //player 2 turn
            
            v[r][c]=symbolPlayer2;
            if(check(v,r,c)){
                cout<<"player 1 wins";
                return 0;
            }
            cnt++;
        }
        else if(!isValid(r,c))cout<<"please select a valid position"<<endl;
        else if(isValid(r,c)&&v[r][c]!='_')cout<<"the cell is already filled"<<endl;
        
        flag=turn(flag);

        printTable(v);
    }
    cout<<"final table"<<endl;
    printTable(v);
    cout<<"Nobody WON"<<endl;

    return 0;
}