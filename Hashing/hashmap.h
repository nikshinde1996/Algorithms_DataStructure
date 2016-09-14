#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

template<class K,class V> class hashmap {
   public:
   	
   set< pair<K,V> > ht;
   	
   hashmap();
   void setvalue();
   void add(K key,V value);
   void remove();
   void getvalue();  	
};

template<class K,class V> hashmap::hashmap(){
	
}

hashmap::add(K key,V value){
	
}



