#include<iostream>
#include<queue>
// #include<algorithm>
using namespace std;
// O(logn) heapify process
// O(n) heap building in heapify

// Inserting an item into a heap is O(log n), and the insert is repeated n/2 times (the remainder are leaves, and can't violate the heap property). So, this means the complexity should be O(n log n), I would think.

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


void heapify(int arr[],int n,int i){
   int largest=i;
   int left=2*i;
   int right=2*i+1;

   if(left<=n && arr[largest] < arr[left]){
    largest=left;

   }
   if(right<=n && arr[largest] < arr[right]){
    largest=right;
   }

   if(largest!=i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
   }
}


void heapsort(int arr[],int n){
    int size=n;

    while(size>1){
        //step1: swap
        swap(arr[size],arr[1]);

        size--;
//step2
        heapify(arr,size,1);


    }
}

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

 int arr[6]={-1,54,53,55,52,50};

  int n=5;

 cout<<"Printing  the array before:"<<endl;
 for(int i=1;i<=n;i++)
 cout<<arr[i]<<" ";
 cout<<endl;
//heapify now
 for(int i=n/2;i>0;i--){
  heapify(arr,n,i);
 }
 cout<<"Printing  the array now:"<<endl;
 for(int i=1;i<=n;i++)
 cout<<arr[i]<<" ";
 cout<<endl;

 //heapsort
 heapsort(arr,n);
 cout<<"Printing sorted array by maxheap:"<<endl;
 for(int i=1;i<=n;i++)
 cout<<arr[i]<<" ";
 cout<<endl;

cout<<"Using priority queue here:\n";
//maxheap
priority_queue<int>pq;
pq.push(5);
pq.push(10);
pq.push(7);
pq.push(4);

// priority queue always keep max element on the top
cout<<"Element at top: "<<pq.top()<<endl;
pq.pop();
cout<<"Element at top: "<<pq.top()<<endl;
cout<<"Size of the pq: "<<pq.size()<<endl;

if(pq.empty()){
  cout<<"PQ is  empty\n";
}
else{
  cout<<"PQ is empty\n";
}

//min heap
priority_queue<int ,vector<int>,greater<int>>p;
//top me min value;
p.push(5);
p.push(10);
p.push(7);
p.push(4);

// priority queue always keep max element on the top
cout<<"Element at top: "<<p.top()<<endl;
p.pop();
cout<<"Element at top: "<<p.top()<<endl;
cout<<"Size of the pq: "<<p.size()<<endl;

if(p.empty()){
  cout<<"P is  empty\n";
}
else{
  cout<<"P is not empty\n";
}

return 0;
}