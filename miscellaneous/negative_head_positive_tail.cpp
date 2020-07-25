/* Question-- to shift all the negative number to the left and all the positive numbers to right for a given array*/

/* Algorithm-- take 2 pointer itr and ptr in the starting of the index
            --itr will iterate and stop when it finds the negative number it will swap that number with 
                    the number present at the position of ptr
            -- after swaping the ptr will increment
            -- itr will till the end of the array*/

/*________code___________*/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i;
    vector<int>v;
    cout<<"enter the number of element you want in your array"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"enter the elements in the array"<<endl;
        int num;
        cin>>num;
        
        v.push_back(num);
    }
    int j=0;
    for(i=0;i<n;i++){
        if(v[i]<0){
            int temp=v[j];
            v[j]=v[i];
            v[i]=temp;
            j++;
        }
        
    }
    cout<<" so our resultant array look like"<<endl;
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    
}
