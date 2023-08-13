// GFG Circular Tour
//Leetcode Gas Station
#include<bits/stdc++.h>
using namespace std;


//Leetcode Gas STation....
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // pair<int,int>p;
        // for(int i=0;i<n;i++){
        //     p[i].first=gas[i];
        //     p[i].second=cost[i];
        // }
        // int balance=0;
        int n=gas.size();
        int TotalGas=0,TotalCost=0;
        int currGas=0, start=0;
        for(int i=0;i<n;i++){
            TotalGas+=gas[i];
            TotalCost+=cost[i];

            currGas+=gas[i]-cost[i];
            if(currGas<0){
                start=i+1;
                currGas=0; //resetiing our fuel
            }
        }
        return (TotalGas<TotalCost) ? -1 : start;
    }
};
int main(){
    return 0;
}