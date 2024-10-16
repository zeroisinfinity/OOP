#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Item{//b1
	public:
		string item_name;
		int item_code;
		float item_cost;
		float quantity;
		
		
		Item(){//b2
			item_name = "/0";
			item_code = 0;
			item_cost = 0.00;
			quantity = 0.00;
		}//b2
		
		Item(string item_name,int item_code, float item_cost, float quantity){//b3
			this -> item_name = item_name;
			this -> item_code = item_code;
			this -> item_cost = item_cost;
			this -> quantity = quantity;
		}//b3
		
};//b1


bool compare(const string& str1, const string& str2){//b5
		if((strcmp(str1,str2)!=0){//b6
			return 1;
		}//b6
		else{//b7
			return 0;
		}//b7
}//b5

void display(const vector<Item>&item/){//b8
		for(ptr = item}//b8	
int main(){//b4

		vector<Item> records;
		Item obj; 
		vector<Item>::iterator ptr; //at that instance that means scope resolution to bind with current vector
		ptr = records.begin();
		cout<<ptr -> item_name<<endl;
		return 0;
}//b4
