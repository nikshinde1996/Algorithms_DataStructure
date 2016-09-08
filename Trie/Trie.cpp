#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct trieNode {
	trieNode *children[26];
	bool isLeaf;
	bool isEOW;
	string currStr;
}

trieNode *getNode() {
	trieNode *newNode = new trieNode;
	if(newNode) {
		for(int i=0;i<26;i++) {
			newNode->children[i] = NULL;
		}
	}
	return newNode;
}

bool search(trieNode *root,string str) {
	trieNode *temp = root;
	for(auto it=str.begin();it!=str.end();it++) {
		if(!temp->children[*it-97]) {
			return false;
		}
		temp = temp->children[*it-97];
	}
    return (temp && temp->isLeaf);
}

void insert(trieNode *root,string str) {

    if(search(root,str)){
		cout<<"String allready present in Trie"<<endl;
		return;
	}

	trieNode *temp = root;
    for(auto it=str.begin();it!=str.end();it++) {
		if(!temp->children[*it-97]) {
			temp->children[*it-97] = getNode();
		}
		temp = temp->children[*it-97];
		if(temp->isLeaf) {
			temp->isLeaf = false;
		}
	}
	temp->isLeaf = true;
	temp->isEOW = true;
}


bool isFree(trieNode *temp) {
	for(int i=0;i<26;i++) {
		if(temp->children[i]) {
			return false;
		}
	}
	return true;
}


bool deleteString(trieNode *root,string str,int level) {
	if(root) {
		if(level == str.length()) {
			root->isLeaf = false;
			if(isFree(root)) {
				delete root;
				return true;
			}
			return false;
		}
		int key = str[level];
		if(deleteStr(root->children[key-97],str,level+1)) {
			if(!root->isLeaf) {
				delete root;
				return true;
			}else {
				return false;
			}
		}
	}
	return false;
}

bool deleteHelper(trieNode *root,string str) {
	if(!search(root,str)) {
		cout<<"Srting not present in Trie"<<endl;
		return;
	}
    deleteString(root,str,0);	
}

int main() {
	trieNode *root = getNode();
	string arr[3] = {"love","faith","unity","creative","nikhil"};
	for(string str:arr){
		insert(root,str);
	}
	
	/*Search for string*/
	cout<<"swapnil is present in Trie : "<<search("swapnil")<<endl;
	
	/*Delete Srtring*/
	deleteHelper(root,"nikhil");
}
