#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

template<class K,class V> class hashmap {
   public:   	
   		set< pair<K,V> > ht;
   		set< pair<K,V> >::iterator it;
		hashmap();
   		
   		void add(K k,V v){
   		   ht.insert(make_pair(k,v));	
		}
		
		void setvalue(K k,V v){
		    for(it=ht.begin();it.first != k;it++) {
		    	
			}
			*it.second = v;
		}
   		
   		void remove(K k){
   		   	
		}
   		
		V getvalue(K k){
//		  return  	
		}  	
};


int main() {
	
}

