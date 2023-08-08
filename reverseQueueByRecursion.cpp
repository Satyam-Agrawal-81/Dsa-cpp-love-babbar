#include<bits/stdc++.h>
using namespace std;

// PSEUDO CODE
queue reverseFunction(queue)
{
    if (queue is empty)
       return queue;
    else {
       data = queue.front()
       queue.pop()
       queue = reverseFunction(queue);
       q.push(data);
       return queue;
    }
}


void reverseQueue(queue<long long int>& q)
{
    // Base case
    if (q.empty())
        return;
 
    // Dequeue current item (from front) 
    long long int data = q.front();
    q.pop();
 
    // Reverse remaining queue 
    reverseQueue(q);
 
    // Enqueue current item (to rear) 
    q.push(data);
}

int main(){
 
return 0;
}