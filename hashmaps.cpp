#include<iostream>
#include<map>  //O(logn)
#include<unordered_map>  //O(1)
using namespace std;

int main(){

//creation

// map<string,int>m;
unordered_map<string,int>m;

//insertion
//pair 1
pair<string,int>p = make_pair("satyam",20);
m.insert(p);
//pair 2 
pair<string,int>p2("minshi",20);
m.insert(p2);
m["satyam"]=19;
m["satyam"]=20;//this latest value will be there for key "satyam"  but there can't be two different satyam keys with different values , omly unique keys are allowed..

//search
cout<<m["satyam"]<<endl;
cout<<m.at("minshi")<<endl;
m["sai"]=19;
// cout<<m.at("unknown")<<endl; // no such key exists so it uncught exception key not found..
cout<<m["unknown"]<<endl; //output will be zero as we have made key here with no value so by default zero..
cout<<m.at("unknown")<<endl; // now answer would come and it will be zero
//size
cout<<m.size()<<endl;

// to check presence
cout<<m.count("satyam")<<endl; //if key present then will give 1 else if absent then give 0

m.erase("unknown");
cout<<m.size()<<endl;


cout<<"Printing map\n";
for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
}
cout<<"Printing by iterator - unordered map:\n";
// iterator k through print karna
unordered_map<string,int> :: iterator it=m.begin();

while(it!=m.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
}
// cout<<"Printing by iterator - ordered map:\n";
// map<string,int> :: iterator it=m.begin();

// while(it!=m.end()){
//     cout<<it->first<<" "<<it->second<<endl;
//     it++;
// }
return 0;
}