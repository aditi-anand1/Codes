/* Question-- to shift all the negative number to the left and all the positive numbers to right for a given array
* Input: 1,-3,2,-7,-6,5,0
* Expected Output: -3,-7,-6,1,2,5,0
*/

/* Algorithm:
    1. take 2 pointer itr and ptr in the starting of the index
    2. itr will iterate and stop when it finds the negative number it will swap that number with the number present at the position of ptr
    3. after swaping the ptr will increment
    4. itr will run till the end of the array

    Time Complexity: O(n)
    Space Complexity: O(1)        
*/

/*________code___________*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    /**
     * n: Total number of elements in the array.
     * i, j: Iterator.
     * v: Vector to store all the 'n' elements.
     */
    int n,i;
    vector<int>v;
    cout<<"enter the number of element you want in your array"<<endl;
    cin>>n;

    // Logic to input numbers in the vector.
    for(i=0;i<n;i++){
        cout<<"enter the elements in the array"<<endl;
        int num;
        cin>>num;    
        v.push_back(num);
    }

    // Logic to iterate and swap the negative numbers to the left.
    int j=0;
    for(i=0;i<n;i++){
        if(v[i]<0){
            int temp=v[j];
            v[j]=v[i];
            v[i]=temp;
            j++;
        }
        
    }

    // Logic to print the resultant vector.
    cout<<" so our resultant array look like"<<endl;
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
}
