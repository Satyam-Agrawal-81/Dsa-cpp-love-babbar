#include <bits/stdc++.h> 

void sortedInsertion(stack<int>&s,int ele){
  if (s.empty() || ((!s.empty()) && ele > s.top())) {
    s.push(ele);

    return;
  }
  int num = s.top();
  s.pop();
  // recursion
  sortedInsertion(s, ele);
   s.push(num);
}

void sortStack(stack<int> &s)
{
	// Write your code here
	//base case
	if(s.empty()){
		return;
	}
	int num=s.top();
	s.pop();

   //recursion
   sortStack(s);


  sortedInsertion(s,num); 
}