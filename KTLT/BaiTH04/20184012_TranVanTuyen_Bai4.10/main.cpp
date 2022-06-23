#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include<string>
#include <sstream>
#include<map>
using namespace std;
int  n,k;
vector<vector<string>> c;
vector<vector<string>> searchW;
vector<map<string,int>> d;// the count of word f(t,d)
int maxf[1001];//max of max f(t,d)
vector<map<string,int>> soVanBan;

vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;
    while (getline (ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}
map<string,int>split_map(const string &s, char delim) {
    map<string,int>  result;
    stringstream ss (s);
    string item;
    while (getline (ss, item, delim)) {
        if(result.count(item)==0) result.insert(pair<string,int>(item,1));
        else result[item]++;

    }

    return result;
}
void input(){
    string l;
	string segment;
    cin >> n;
    for (int i=1;i<=n+1;i++){
    	getline(cin, l);
		c.push_back(split(l,','));
		d.push_back(split_map(l,','));
	}

	cin >> k;

    for (int i=1;i<=k+1;i++){
    	getline(cin, l);
		searchW.push_back(split(l,','));
	}

	for (int i=1;i<=k;i++){
    	cout<<searchW[i].at(0);
	}
}
void maxF(){
    for (int i=1;i<n+1;i++){
        int max1=0;
        for (std::map<string,int>::iterator it=d[i].begin(); it!=d[i].end(); ++it){
             //cout << it->first << " => " << it->second << '\n';
             if (max1<= it->second) max1=it->second;
        }
        maxf[i]=max1;
    }
     for (int i=1;i<n+1;i++) cout<< maxf[i];//start by 1
}
void sovb(){
    for ()
}

int main()
{
    input();
    maxF();
    return 0;
}
