#include <iostream>
using namespace std;

template <typename Gen>

void selection_sort(Gen arr[] , int records){//b1

        
        Gen current_min; 
        
        for(int iter = 0 ; iter < records ; iter++){//b2
        
            for(int cf = 1 ; cf < records ; cf++){//b3
            
                if(arr[iter] > arr[cf]){//b4
                    current_min = arr[cf];
                    arr[cf] = arr[iter];
                    arr[iter] = current_min;
                   }//b4
                   
            }//b3
            
         }//b2
         
         for(int show = 0 ; show  < records ; show++){//b5
                cout<<arr[show];
         }//b5
         
}//b1

int main(){//b1
           
         int choice;
         int size;
         float inp_arr_fl[size];
         int inp_arr_it[size];
         
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
                     for(int assign = 0 ; assign < size ; assign++){//b4
                            cout<<"Enter the "<<assign+1<<" number element -----> ";
                            cin>>inp_arr_fl[assign];
                            cout<<endl;
                         }//b4
                     selection_sort<float>(inp_arr_fl,size);
                     break;
                     
                case 2:
                    
                     cout<<"Enter no.of records in Integer Array - ";
                     cin>>size; 
                     cout<<"Enter the elements into array"<<endl;
                     for(int assign = 0 ; assign < size ; assign++){//b5
                            cout<<"Enter the "<<assign+1<<" number element -----> ";
                            cin>>inp_arr_it[assign];
                            cout<<endl;
                         }//b5
                     selection_sort<int>(inp_arr_it,size);
                     break;
                default:
                     cout<<"Thank You!! For using our Program"<<endl;
                     exit(0);
              
                   }//b3
            }//b2
         while(choice!=3);
         return 0;
 
}//b1
