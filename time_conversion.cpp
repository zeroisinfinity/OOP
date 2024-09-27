#include <iostream>
#include <sstream>
using namespace std;

class Clock{

    public:
       int hours;
       int minutes;
       string input;
       string statinput;
       static bool flag;
       void static setflag(bool value);
       
       //Default constructor
       Clock() : hours(0),minutes(0),statinput(input){
        //cout<<"Explicit DEFAULT CONSTRUCTOR is called."<<endl;
       }
       Clock(int HH,int MM):hours(HH),minutes(MM){
        /*cout<<"PARAMETERIZED CONSTRUCTOR with a parameter list is called."<<endl;
        cout<<"hours is initialized to HH and minutes to MM."<<endl;*/
        statinput = input;
        }
       //Copy constructor
       Clock(const Clock& other){
        //cout<<"Copy constructor is called."<<endl;
        hours = other.hours;
        minutes = other.minutes;
        statinput = other.input;
        //cout<<"Contents are copied."<<endl;
       }
       //Move constructor 
       Clock(Clock&& other) noexcept : hours(other.hours),minutes(other.minutes){
        /*cout<<"MOVE CONSTRUCTOR was called.\n"
        <<"Source object is converted to 'rvalue'\n"
        <<"Onwership of resources of Source object is now transferred to Target object."<<endl;*/
        other.hours = 0;
        other.minutes = 0;
        statinput = other.input;
       }
       //Destructor
       ~Clock(){
        //cout<<"DESTRUCTOR called."<<endl;
       }
        //Dispalying function value of HH;MM in minutes
        void DisplayTimeInMins(void){
            if(Clock::flag==true){
            cout<<"Time in minutes is - "<<secret_conversion(hours)<<"mins"<<endl;
            }
            else{
                cout<<"Invalid format."<<endl;
            }
        }
        void Display_time(void);
        void set_hours_mins(void);
        

    private:
        int total_mins;
        int secret_conversion(int hh){
                total_mins = hh*60 + minutes;
                return total_mins;
        }
};
bool Clock::flag=true;
void Clock::setflag(bool value){
    flag=value;
}
void Clock::Display_time(void){
    if(Clock::flag){
        cout<<"Time in HH:MM is "<<statinput<<endl;
    }
    else{
        cout<<"Invalid input format."<<endl;
    }
}
void Clock::set_hours_mins(){
        char colon;
        cout<<"Enter time at your place in HH:MM"<<endl;
        getline(cin,input);
        stringstream ss(input);
        statinput = input;
        if(ss>>hours>>colon>>minutes and colon==':'){
            if(0<=hours and hours<=24){
                if(minutes>=0 and minutes<=60){
                    
                }
                else{
                    cout<<"Invalid value if MM pls enter within 00-60"<<endl;
                   Clock::setflag(false);
                }
            }
            else{
                cout<<"Invalid value if HH pls enter within 00-24."<<endl;
                Clock::setflag(false);
            }

        }
        else{
            cout<<"Invalid input."<<endl;
            Clock::setflag(false);
        }
}      
        
        

int main(){

    Clock England;
    cout<<"Place England"<<endl;
    England.set_hours_mins();
    England.Display_time();
    England.DisplayTimeInMins();

    //Clock India = Clock();
    Clock India(0,0);
    cout<<"Place India"<<endl;
    India.set_hours_mins();
    India.Display_time();
    India.DisplayTimeInMins();

    Clock Poland = move(England);
    cout<<"Place Poland"<<endl;
    Poland.Display_time();
    Poland.DisplayTimeInMins();

    Clock Nepal(India);
    cout<<"Place Nepal"<<endl;
    Nepal.Display_time();
    Nepal.DisplayTimeInMins();

}
