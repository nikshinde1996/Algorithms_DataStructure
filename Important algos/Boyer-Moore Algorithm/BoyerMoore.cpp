#include<bits/stdc++.h>
#define NO_OF_CHAR 256
/**
 *   The Boyer Moore algorithm is most efficient algorithms to find the presence of pattern in the text.
 *   It has the time complexity of O(n/m) where n is length of text and m is length of pattern to be searched.
 */

using namespace std;

void makeCharTable(string str,int charTable[NO_OF_CHAR]);
void BMsearch(string txt,string pat);

int main(){
    string txt,pat;
    cout<<"......Boyer-Moore Algorithm......"<<endl<<endl;
    cout<<"Enter Text String :> "<<endl;
    getline(cin,txt);
    cout<<"Enter Pattern String :>"<<endl;
    getline(cin,pat);

    BMsearch(txt,pat);
}

void makeCharTable(string pat,int charTable[NO_OF_CHAR]) {
    for(int i=0;i<NO_OF_CHAR;i++)
        charTable[i]=-1;
    for(int i=0;i<pat.length();i++)
        charTable[(int)pat[i]]=i;
}

void BMsearch(string txt,string pat) {
    int n = txt.length();
    int m = pat.length();

    int charTable[NO_OF_CHAR];

    // Create the charTable and fill the last occuring index of all chars in string
    makeCharTable(pat,charTable);

    int s = 0;  // s is shift of the pattern with respect to txt...
    while(s<=(n-m)) {
        int j=m-1;

        // If chars match keep decrementing j
        while(j>=0 && pat[j]==txt[s+j])
            j--;

        if(j<0) {   // The string matches
            cout<<"The pattern occurs at index : "<<s<<endl;
            // continue searching in remaining txt
            s += (s+m<n)?m-charTable[txt[s+m]]:1;
        }else{
            s += max(1,j-charTable[txt[s+j]]);
        }

    }
}