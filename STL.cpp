#include<bits/stdc++.h>
using namespace std;

/*
STL
1.Containers
2.Iterators
3.Algorithm
4.Functions
*/

//Pair 
void pairExplain(){
    pair<int,int> p={1,3};
    cout<<p.first<<endl;;

    pair<int,pair<int,int>> p2={1,{4,7}};
    cout<<p2.second.second<<endl;

    pair<int,int> arr[]={{2,4},{6,8},{7,5}};
    cout<<"Array "<<arr[0].second<<endl;
}

//Vector
void explainVector(){
    vector<int>v={1,2,3,4,5,6,7,8,9};//--->Syntax
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(3,4);//Assumes it as set

    vector<int> v1(5,100);//5 elements,all are 100;
    vector<int> v2(5);//Length is 5 but empty/garbage value/0

    vector<int>::iterator it=v.begin();
    it++;
    cout<<*(it)<<endl;;
    
    it+=2;

    vector<int>::iterator it1=v.end();
    // vector<int>::iterator it2=v.rend();//Not often used
    // vector<int>::iterator it3=v.rbegin();//Not often used

    //Print
    cout<<v[0]<<" or "<<v.at(1)<<endl;;
    cout<<v.back()<<endl;;//Last element

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    //Erase
    v.erase(v.begin()+1);
    v.erase(v.begin()+2,v.begin()+5);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";//To check result of erase
    }
    cout<<endl;

    //Insert function
    vector<int> v3(2,100);
    v3.insert(v.begin()+1,10);//Position,element to be inserted
    v3.insert(v.begin()+1,3,10);//Position,no. of times to insert,element to be inserted

    vector<int> v4(2,20);
    v3.insert(v3.begin(),v4.begin(),v4.end());

    cout<<v.size()<<endl;//Size of vector

    v3.swap(v4);//Swap v2 & v3

    vec.clear();
    cout<<"vector is:"<<vec.empty()<<endl;
}

//List
void explainList(){
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    
    ls.push_front(3);
    ls.emplace_front(4);
    //Rest functions are same as vector
}

//Deque
void explainDeque(){
    deque<int> dq;
     dq.push_back(1);
    dq.emplace_back(2);
    
    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
    //Rest functions are same as vector

}

//Stack
void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);

    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;

    stack<int>st1,st2;

    st1.swap(st2);
}

//Queue
void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back()+=5;
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;

    q.pop();

    cout<<q.front();
    //size swap empty same as stack
}

//Priority Queue
//Maximum Heap
void explainPQ(){
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.emplace(3);

    cout<<pq.top()<<endl;

    pq.pop();
    cout<<pq.top()<<endl;

    //Minimum Heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.emplace(4);

    cout<<pq.top()<<endl;
}


//Set
void explainSet(){
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(3);
    st.emplace(4);

    auto it=st.find(3);

    auto if=st.find(5);//If 5 is not found then it will give the last addresss of the i.e, the address after the last element


    st.erase(4);

    int cnt=st.count(2);

    auto it1=st.find(1);
    st.erase(it1);

    auto it2=find(1);
    auto it3=find(3);
    st.erase(it2,it3);

    auto it4=st.lower_bound(2);
    auto it5=st.lower_bound(3);
}

//Multi Set
void explainMultiset(){
    multiset<int> ms;
    //Everything same as set
    //But can also store duplicate elements unlike set
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.emplace(2);

    ms.erase(1);//All 1's are erased

    int cnt=ms.count(2);

    ms.erase(ms.find(1));//Only single 1 is erased

    ms.erase(ms.find(1),ms.find(2));

}

//Unordered Set
void explainUnorderedSet(){
    unordered_set<int> ut;
    //Lower_bound & upper_bound does not work. It is not sorted,stores in random order,better T.C than set except when collision happens

}


//Map
void explainMap(){
    map<int,int> mp;
    map<int,pair<int,int>> mp1;
    map<pair<int,int>,int> mp2;

    mp[1]=2;//{1,2}
    mp.emplace({3,1});//{{1,2},{3,1}}
    mp.insert({2,1});//{{1,2},{2,1},{3,1}}
    mp2.[{1,2}]=3;


    for(auto it:mp){
        cout<<*(it).first<<*(it).second<<endl;
    }

    cout<<mp[1]<<endl;
    cout<<mp[2]<<endl;

    auto it=mp.find(3);
    cout<<*(it).second<<endl;

    auto it5=mp.lower_bound(2);
    auto it6=mp.upper_bound(3);

}


//Multi Map
void explainMultiMap(){
    //everything is same, it can store multiple same keys,only mp[key] cannot be used
    
}

//Unordered mapp
void explainUnorderedMap(){
    //everything is same as unordered set
}


//Extras

bool comp(pair<int,int> p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first>p2.firse) return true;
    return false;
}

void explainExtra(){
    //For arrays,vectors,maps etc
    sort(a,a+4);//Increasing order
    sort(v.begin(),v.end());

    sort(a,a+n,greater<int>);//Decreasing order

    //To sort in my own way
    sort(a,a+n,comp);

    int num=7;
    int cnt=__builtin_popcount();

    long long num1=14739473483749348;
    int cnt=__builtin_popcountll();

    string s="123";
    sort(s.begin(),s.end());

    do{
        cout<<s<<endl;
    }while (next_permutation(s.begin()),s.end());

    int maxi=*max_element(a,a+n);

}
int main(){
    // pairExplain();
    // explainVector();
    // explainStack();
    explainQueue();

    return 0;
}




