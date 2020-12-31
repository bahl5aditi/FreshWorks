#include<bits/stdc++.h>
#include<thread>
#include<time.h>
#include<map>
#include <tuple>
#include <vector>

using namespace std;

using k = std::pair<int,time_t>;
using ValueType = std::vector<k>;

map<string,k>m;

void create(string key,int value,time_t timeout=0){
	pair<int,time_t>k;
	if ( m.find(key) == m.end() ) {
		int i=0;
		int isalp=0;
		while(key[i]!='\0'){
			if(!isalpha(key[i])){
				isalp++;
				break;
			}
			i++;
		}
		if(isalp==0)
            if(m.size()<(1024*1020*1024) and value<=(16*1024*1024)){   //constraints for file size less than 1GB and Jasonobject value less than 16KB 
                if(timeout==0){
                	//geek = make_tuple('a', 10, 15.5)
                	
                	k=make_pair(value,timeout);
                    //k l=[value,timeout];
                    //l.append(value);
                    //l.append(timeout);
                    //m[key]=l;
                }
                else
                    k=make_pair(value,time(NULL)+timeout);
                    //k l=[value,time.time()+timeout];
                if (key.length()<=32){    //constraints for input key_name capped at 32chars
                    m[key]=(k);
                    cout<<"key Created"<<endl;
                }
            }
            else
                cout<<"error: Memory limit exceeded!! "<<endl;    //error message1
        else
            cout<<"error: Invalind key_name!! key_name must contain only alphabets and no special characters or numbers"<<endl;    //error message2
	}
    else {
    	cout<<"error: this key already exists"<<endl;  //error message3
   }
}

void read(string key){
	pair<int,time_t>k;
	if ( m.find(key) != m.end() ){
		k=make_pair(m[key].first,m[key].second);
		//cout<<key<<k.first<<k.second<<endl;
        if (k.second!=0){
            if (time(NULL)<k.second){   //comparing the present time with expiry time
                string stri=key+":"+(to_string)(k.first); //to return the value in the format of JasonObject i.e.,"key_name:value"
                cout<<stri<<endl;
            }
            else{
                string error="error: the given key's time-to-live of has expired"; //error message4
                cout<<error<<endl;
            }
        }
        else{
            string stri=key+":"+to_string(k.first);
            cout<<stri<<endl;
        }
	}
	else{
		string error="error: given key does not exist in database. Please enter a valid key";
		cout<<error<<endl;
	    //error message5
	}
}

void del(string key){
	pair<int,time_t>k;
    if(m.find(key) != m.end() ){
        k=make_pair(m[key].first,m[key].second);
        if(k.second!=0){
            if(time(NULL)<k.first){ //comparing the current time with expiry time
                m.erase(key);
                cout<<"key is successfully deleted"<<endl;
            }
            else
                cout<<"error: time-to-live of"<<key<<"has expired"<<endl; //error message6
        }
        else{
            m.erase(key);
            cout<<"key is successfully deleted"<<endl;
        }
    }
    else{
    	cout<<"error: given key does not exist in database. Please enter a valid key"<<endl; //error message7
	}
}

void modify(string key,int value){
	pair<int,time_t>k;
	pair<int,time_t>t;
	k=make_pair(m[key].first,m[key].second);
	if(k.second!=0){
		if(time(NULL)<k.second){
            if (m.find(key) == m.end() )
                cout<<"error: given key does not exist in database. Please enter a valid key"<<endl; //error message6
            else{
            	t=make_pair(value,k.second);
                m[key]=t;
                cout<<" Key modified"<<endl;
            }
        }
        else
            cout<<"error: time-to-live of"<<key<<"has expired"<<endl; //error message5
    }
    else{
    	if(m.find(key) == m.end())
            cout<<"error: given key does not exist in database. Please enter a valid key"<<endl; //error message6
        else{
            t=make_pair(value,k.second);
            m[key]=t;
            cout<<"Key modified"<<endl;
        }
	}
}

