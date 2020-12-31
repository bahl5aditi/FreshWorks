#include<bits/stdc++.h>
#include<thread>
#include<time.h>
#include<map>
#include <tuple>
#include <vector>
#include <chrono>
#include <future>
#include "Code.h"
using namespace std;

int main(){
	create("aditi",25);
	//to create a key with key_name,value given and with no time-to-live property
	
    create("src",70,3600); 
    //to create a key with key_name,value given and with time-to-live property value given(number of seconds)
    
	read("aditi");
    //it returns the value of the respective key in Jasonobject format 'key_name:value'
    
	read("src");
    //it returns the value of the respective key in Jasonobject format if the TIME-TO-LIVE IS NOT EXPIRED else it returns an ERROR
    
	create("aditi",50);
    //it returns an ERROR since the key_name already exists in the database
    
	//To overcome this error 
    //either use modify operation to change the value of a key
    //or use delete operation and recreate it
    
	modify("aditi",55);
    //it replaces the initial value of the respective key with new value 
    
	del("aditi");
    //it deletes the respective key and its value from the data
    
	read("aditi");
    create("a33",90);
    create("t#yg",65);
    
    ///////////////////////threads as per the requirement/////////////////////////////////
    thread t1(create,"bahl",20,200); //as per the operation
    t1.join();
    thread t2(read,"bahl");         //as per the operation
    t2.join();
}
