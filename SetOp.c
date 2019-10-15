//
//  SetOp.c
//  CSE340P2
//
//  Created by hgupta15 on 10/15/19.
//  Copyright © 2019 Hardik Gupta. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <vector>
using namespace std;

struct addReturner{
    vector <string> result;
    bool change;
};

int  locationInVector(vector <string> input ,string key){
    int returner = -1;
    bool found = false;
    for (int i = 0; i < input.size(); i++)
        if (input[i] == key) {
            returner = i;
            found = true;
            break;
        }
    if (!found) {
        returner = -1;
    }
    return returner;
}
addReturner addition (vector<string> set1, vector<string> set2){
    //we add set2 in set1
    addReturner newElement;
    newElement.change = true;
    for(string h: set1){
        newElement.result.push_back(h);
    }
    for(string q: set2){
        if(locationInVector(set1, q) == -1){
            if(q != "#"){
                newElement.result.push_back(q);
            }
        }
    }
    
    if(set1 == newElement.result){
        newElement.change = false;
    }
    
    return newElement;
}

addReturner addEpsilon(vector<string>set1){
    addReturner newElement;
    newElement.change = false;
    newElement.result = set1;
    if(locationInVector(newElement.result, "#")== -1){
        newElement.result.push_back("#");
        newElement.change = true;
    }
    return newElement;
}


bool epsilonBelongs(vector <string> set1){
    bool exist = true;
    int i = locationInVector(set1, "#");
    if(i == -1){
        exist = false;
    }
    return exist;
}

void printOrder(vector <string> set1, vector<string> uni){
    vector <string> sorted;
    for(int q=0; q<uni.size();q++){
        int i = locationInVector(set1, uni[q]);
        if(i !=1){
            sorted.push_back(uni[q]);
        }
    }
    for (string sdf: sorted){
        cout << sdf <<" ";
    }
    cout << endl;
}

int main()
{
    vector <string> l ;
    l.push_back("a");
    l.push_back("b");
    l.push_back("c");
    l.push_back("d");
    vector <string> r;
    //   r.push_back("e");
    //   r.push_back("f");
    //   r.push_back("g");
    //   r.push_back("h");
    //   r.push_back("#");
    r.push_back("a");
    r.push_back("b");
    r.push_back("c");
    r.push_back("d");
    r.push_back("#");
    addReturner outcome;
    outcome = addition(l,r);
    for(string x: outcome.result){
        cout << x<< " ";
    }
    cout<< endl;
    cout << outcome.change << endl;
    
    bool ans = epsilonBelongs(l);
    cout << ans <<endl;
    addReturner outcome2;
    outcome2= addEpsilon(l);
    for(string xty : outcome2.result){
        cout << xty <<" ";
    }
    cout << endl;
    return 0;
}
