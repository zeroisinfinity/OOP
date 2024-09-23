#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

class Publication{

    public:
            string entry_title;
            float entry_price;
            string entry_owner;
            char shelf_section;
            string entry_address;
            Publication(){}
            
            void GetEntryData(void);
            void DisplayEntryData(void);
            
    private:
            string EntryDeletionID;
            string benificiary_id;
            int BenificiaryTeleNO;
            
    protected:
            string TransactionID;
            bool IRL_certified;
            bool best_seller;
            
           };
class Book:public Publication{
        public:
                int page_count;
                //void GetBookDetails(void);
                void GetPageCount(void);
                void DisplayPageCount(void);
                };
                
class Tape:public Publication{
        public:
            int tape_duration;
            //void GetTapeDetails(void);
            void GetTapeDuration(void);
            void DisplayTapeDuration(void);
                };
          
                
void Publication::GetEntryData(void){
            
            cout<<"Enter the title of the entry - ";
            getline(cin,entry_title);
            cout<<endl;
            cout<<"Enter the entry price - ";
            cin>>entry_price;
            cout<<endl;
            cout<<"Enter the entry address - ";
            cin>>entry_address;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }   
            
void Publication::DisplayEntryData(void){
            cout<<"Entry title is - "<<entry_title<<endl;
            cout<<"Entry price is - "<<entry_price<<endl;
            cout<<"Entry address is - "<<entry_address<<endl;
            }
/*void Book::GetBookDetails(void){
                GetEntryData();
                
}           */         
void Book::GetPageCount(void){
                
                cout<<"Enter the page count - ";
                cin>>page_count;
                cout<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                
void Book::DisplayPageCount(void){
                cout<<"Page count of "<<entry_title<<" is - "<<page_count<<endl;
                }  
                              
                
/*void Tape::GetTapeDetails(void){
                GetEntryData();
                
}     */        
void Tape::GetTapeDuration(void){
            cout<<"Enter the tape duration - ";
            cin>>tape_duration;
            cout<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            
void Tape::DisplayTapeDuration(void){
            cout<<"Tape duration of "<<entry_title<<" is - "<<tape_duration<<endl;
                }                
                
                
                
int main(){
            
            Book book_alpha;
            book_alpha.GetEntryData();
            book_alpha.GetPageCount();
            book_alpha.DisplayPageCount();
            book_alpha.DisplayEntryData();
            Tape tape_alpha;
            tape_alpha.GetEntryData();
            tape_alpha.GetTapeDuration();
            tape_alpha.DisplayEntryData();
            tape_alpha.DisplayTapeDuration();
            return 0;
            }               
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
