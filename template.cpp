#include <iostream>
using namespace std;

template <typename Gen>

void selection_sort(Gen arr[] , int records){//b1

        
        Gen temp; 
        int min;
        for(int iter = 0 ; iter < records - 1 ; iter++){//b2
            min = iter;
            for(int cf = iter + 1 ; cf < records ; cf++){//b3
            
                if(arr[min] > arr[cf]){//b4
                    min = cf;
                   
                   }//b4
                   
           }//b3
                if(min!=iter){//b6
                    temp = arr[iter];
                    arr[iter] = arr[min];
                    arr[min] = temp;
                    }//b6
                 
         }//b2
         
         for(int show = 0 ; show  < records ; show++){//b5
                cout<<arr[show]<<" ";
         }//b5
         cout<<endl;
         
}//b1

int main(){//b1
           
         int choice;
         int size;
         float* inp_arr_fl = new float[size];
         int* inp_arr_it = new int[size];
         int assign;
         
         do{//b2
           
            cout<<"Welcome to the Program!!"<<endl;
            cout<<"You can Enter either a float or int array"<<endl;
            cout<<"Enter 1 for Float Array."<<endl;
            cout<<"Enter 2 for Integer Arrayy."<<endl;
            cout<<"Enter 3 to Exit."<<endl;
            cin>>choice;
            while(choice > 3 or choice < 1){
                cout<<"Please Enter the correct choice - ";
                cin>>choice;
                }
            
            switch(choice){//b3
                case 1:
                    
                     cout<<"Enter no.of records in Float Array - ";
                     cin>>size; 

                     cout<<"Enter the elements into array"<<endl;
                     for(assign = 0 ; assign < size ; assign++){//b4
                            cout<<"Enter the "<<assign+1<<" number element -----> ";
                            cin>>inp_arr_fl[assign];
                            cout<<endl;
                         }//b4
                     selection_sort(inp_arr_fl,size);
                     delete[] inp_arr_fl;
                     break;
                     
                case 2:
                    
                     cout<<"Enter no.of records in Integer Array - ";
                     cin>>size; 
                   
                     cout<<"Enter the elements into array"<<endl;
                     for(assign = 0 ; assign < size ; assign++){//b5
                            cout<<"Enter the "<<assign+1<<" number element -----> ";
                            cin>>inp_arr_it[assign];
                            cout<<endl;
                         }//b5
                     selection_sort(inp_arr_it,size);
                     delete[] inp_arr_it;
                     break;
                default:
                     cout<<"Thank You!! For using our Program"<<endl;
                     return 0;
              
                   }//b3
            }//b2
         while(choice!=3);
         return 0;
 
}//b1
