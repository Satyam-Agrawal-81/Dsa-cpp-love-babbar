#include<iostream>
// #include<algorithm>
using namespace std;

class heap{
public:
 int arr[100];
 int size=0;

 void insert(int val){ // Insertion TC: O(logn)
    size=size+1;//since zeroth index is left blank..for i/2 operation works smoothly..
    int index=size;
    arr[index]=val;

    while(index>1){
        int parent=index/2;

        if(arr[parent]<arr[index]){
        swap(arr[parent],arr[index]);
        index=parent; // taki ab iske parent se bhi compare kar paye next iteration me ...
        }    
      else 
      return;
    }

 }

 void deletion(){
//    deletion invloves root node deletion
//    This involves process to swap last node with  root node and then hence delete last node and  again perform heap sort..
if(size==0){
    cout<<"Nothimg to Delete\n";
    return ;

}
//Step1: put last element into first index
arr[1]=arr[size]; // root node  me last node  ki value dal di 
size--; // last node ko hata diya Step2: remove the last element.. 
// now performing heap sort again to determine correct root for max heap
// Step 3:  taking root node to its correct position
int i=1;
while(i<size){
  int leftIndex=2*i;
  int rightIndex=2*i+1;

  if(leftIndex<size && arr[i] < arr[leftIndex]){
  swap(arr[i],arr[leftIndex]);
  i=leftIndex;
  }

  else if(rightIndex<size && arr[i] < arr[rightIndex]){
  swap(arr[i],arr[rightIndex]);
  i=rightIndex;
}
else 
return ;
 }

 }
  void print(){
    for(int i=1;i<=size;i++){
     cout<<arr[i]<<" ";

    }
    cout<<endl;
  }

};


int main(){
 heap h;
 //insertion O(logn) as i/2 se compare
 h.insert(30);
 h.insert(50);
 h.insert(20);
 h.insert(60);
 h.insert(40);
 h.print();
 h.deletion();
 h.print();
return 0;
}