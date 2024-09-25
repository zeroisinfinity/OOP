#include <iostream>

#include <fstream>

using namespace std;

class Train{//b1

	public:
		char type [10];
		int num;
		float ticket;
		void read_data(void);
		void write_data(void);

};//b1

void Train::read_data(void){//b2

	cin>>type;

	cin>>num;

	cin>>ticket;

}//b2

void Train::write_data(void){//b3

	cout<<type;

	cout<<num;

	cout<<ticket;

}//b3

int main(){//b4

	Train blocks[5];

	fstream file;

	file.open("train.dat", ios::in | ios::out | ios::binary);
	//ifstream infile("qbits.txt");
	//ofstream outfile("qbits.txt");


	for(int iter = 0; iter < 5; iter++){//b5

		blocks[iter].read_data();

		file.write((char*)&blocks[iter], sizeof(blocks[iter]));

}//b5

	file.seekg(0);
	//ofstream outfile("qbits.txt");


	for(int out = 0; out < 5; out++){//b6

		file.read((char*)&blocks[out], sizeof(blocks[out]));

		blocks[out].write_data();

}//b6
	file.close();
	//infile.close();
	//outfile.close();

return 0;

}//b4
