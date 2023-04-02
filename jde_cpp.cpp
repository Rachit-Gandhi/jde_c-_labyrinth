#include<iostream>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;

int rows = 5;
int cols = 7;
int arr[rows][cols];
int visit[rows][cols];

int max1=-1;
int wasMax = 1;
int final[rows][cols];

int lastWrite = INT_MAX;     


bool safe(int x, int y, int rows, int cols){
   if (x < rows && y < cols && x >= 0 && y >= 0)
		return true;
  return false;
}

bool valid(int arr[][cols], int v[][cols], int x, int y, int rows, int cols){

    if(arr[x][y]=='#' || v[x][y])
         return false;
    return true;
}

int path(int arr[][cols],int v[][cols],int i, int j,int count, int rows, int cols){

   
    if( max1 < count ){                          // For limiting the recursion and finding largest path                       
    max1 = count;
    wasMax = 1;
    lastWrite = INT_MAX;
    for(int k=0;k<rows;k++){
        for(int l=0;l<cols;l++){
                final[k][l] = 0;              
        } 
    }
    }

 
    v[i][j]=1;                                    // Recursion for finding path

    if(safe(i+1,j) && valid(arr,v,i+1,j)){
    path(arr,v,i+1,j,count+1); 
    v[i+1][j] = 0;
    }

    if(safe(i,j+1) && valid(arr,v,i,j+1)){
    path(arr,v,i,j+1,count+1);
    v[i][j+1] = 0;
    }

    if(safe(i-1,j) && valid(arr,v,i-1,j)){
    path(arr,v,i-1,j,count+1);
    v[i-1][j] = 0;
    }

    if(safe(i,j-1) && valid(arr,v,i,j-1)){
        path(arr,v,i,j-1,count+1);  
        v[i][j-1] = 0;
    }
    

    if(wasMax && lastWrite > count){
         lastWrite = count;
         final[i][j]=count;
       }

    if(count == 1){
      wasMax = 0;
      lastWrite = INT_MAX;
    }

}


int main(){

freopen("Input.txt","r",stdin);  // Input File

freopen("Output.txt","w",stdout);  // Output File


int arr[r][c];                      // Input Array
int visit[r][c];                    // Visited Array

memset(visit,0,sizeof visit);
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        char ch;
        cin>>ch;
        arr[i][j] = ch;
    }
}

for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){

        if(arr[i][j]=='.'){
            path(arr,visit,i,j,1,rows,cols);
                visit[i][j] = 0;
        }        
    }     

}

        
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        if(final[i][j]==0 && arr[i][j]=='#')
            cout<<"#"<<" ";
        else if(final[i][j]==0 && arr[i][j=='.'])
            cout<<"."<<" ";
        else
            cout<<final[i][j]-1<<" ";
    }
    cout<<max1<<"\n";
    cout<<"\n";

}

}





// ##.##.#
// ##.#..#
// ####..#
// ##....#
// #######
