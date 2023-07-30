#include<iostream>
#include<queue>
using namespace std;


int main(){

queue<int>q;
q.push(11);
q.push(22);
q.push(33);
cout<<"Size: "<<q.size()<<endl;
q.pop();
if(q.empty()){
    cout<<"queue empty"<<endl;

}
else
cout<<"queue is not empty"<<endl;
cout<<q.front()<<endl;
cout<<q.back()<<endl;
return 0;
}