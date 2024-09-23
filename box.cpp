#include <iostream>
using namespace std;
class Box{
	
	public:
	   double l;
	   double b;
	   double h;
	   double edges;
	   double faces;
	   

	

	   
	   double getlen(void);
	   //CAN ADD VOID IN FUNC DEF BUT NOT while calling it/
	   double getbre(void);
	   double gethei(void);
	   //double getlabel(void);
	   
	   
	   void setlen(double len);
	   void setbre(double bre);
	   void sethei(double hei);
	   //void setlabel(double leb);
	   
	   double getlabel(void){
	       secret_method_of_label();
	       return label;
	       }
	   
	 Box(void);
	 //Box(double len,double bre,double hei);
	 Box(double len,double bre, double hei):l(len),b(bre),h(hei){
		
		l2 = l*3;
		

		cout<<"Paramterized constructor is called."<<endl;
	 }/*NOW WHEN WE INNITIALIzED THE L2 IT WASN'T SET TO ----> 1)EITHER A GARABGE VALUE
	                                                     //   2)OR TO ZERO
	    INSTEAD IT GOT SET TO INTO 3
		THIS IS BECAUSE OF THE ORDER OF CONSTRUCTOR CALLS
		1)DEFAULT CONSTRUCTOR IS CALLED FIRST
		2)THEN PARAMETERIZED CONSTRUCTOR IS CALLED
		3)THEN THE INITIALIZER LIST IS EXECUTED
		*/
     Box(const Box& other){
		cout<<"COPY CONSTRUCTOR IS CALLED\n";

	 }
		
	   
	  
	   
   public: //public two times... all r initialize when obj created l2 initialize b4 l
       double l2 = l*3;
       
   private:
       int label;
       void secret_method_of_label(void){
           label = (l*3)+ (b*2) - h;
           }
	   double* ptr_l;
	   double* ptr_b;
	   double* ptr_h;
	   double* ptr_edges;
	   double* ptr_faces;
	   
	

           
           
       
       
		 };
		 
		 
	   double Box::getlen(void){
	       return l;
	       }
	   double Box::getbre(void){
	       return b;
	       }
	   double Box::gethei(void){
	       return h;
	       }

	   void Box::setlen(double len){
	       l = len;
	       }
	   void Box::setbre(double bre){
	       b = bre;
	       }
	   void Box::sethei(double hei){
	       h = hei;
	       }
	 Box::Box(void){
	       cout<<"----> box obj is created <----"<<endl;
	       
	       }// WE cant comment out default constructor once parametrized is declared
		   //so EXPLICITYLY DEFINING DFC WILL SHOW GARBAGE VALUES
		   //coz then only parameterized is called not the default ofc
		   //as a result we cant use obj which depended on default
		   //so we cant use default constructor
		   /*so either initialize value to some finite (i consider 0=inf) OR it stores a garbage value if not ini 
		   in paramterized const*/
		   //So if box12.faces is not ini then it stores garbage value
	 
	   
int main(){
	   
	   Box box1;

     //Box box3;
	 /*cout<<box1.l<<endl; 
	   cout<<box1.l2<<endl; OUTPUT 0,0 COZ INITIALIZE TO ZERO ALREADY BOTH.... L2 = 0 EVEN BEFORE L = 3.999 AND INSTANTLY WHEN OBJ WAS CREATED*/
	   
	   box1.l = 67.999; //initializing l but l2 = garbage value
	   box1.b = 45.78786;
	   box1.h = 77.88;
	 //box1.label = 78.421105 ERROR... LABEL IS PRIVATE
	 /*box1.l2 = box1.l*3;  initializing l2
	   cout<<box1.l2<<endl; correct*/
	   box1.l2;
	   cout<<"Label is - "<<box1.getlabel()<<endl;
	 //cout<<box1.l2<<endl; //garbage
	  
	 /*Box box2(56.676,77.675,67.999); ERROR - MOVE 
	 										  COPY 
	 										  DEFAULT 
	 			no constructor applicable
	 			MOVE - 1 ARG (ANOTHER OBJ) with move keyword
	 			COPY - 1 ARG (another OBJ)
	 			DEFAULT - 0 ARG (Nothing needed)*/
	 
	 						           
	 /*Box box2;
	   box2.l = 56.676;
	   box2.b = 77.675;
	   box2.h = 67.999;*/
	 //Box box2(&&&&box1); //vol 14260.3000
	 //Box box2(box1); //vol 14260.3000
	   Box box2 = move(box1); 
	   //CASTS LVALUE box2 to rvalue so now move constructor            can operate/
	   //vol 14260.3000
	 //cout<<box1.l;
	 
	   
	   
	   cout<<box1.getlen()<<endl;
	   //cout<<box1.getbre(void)<<endl; ERROR OF TYPE CAST 
	   //compiler either set of args Or empty set only
	   cout<<box1.getbre()<<endl;
	   cout<<box1.gethei()<<endl;
	   
	   
	   double vol = box2.l*box2.b*box2.h;
	   cout<<"Volume of box2 is : "<<vol<<endl;
	   
	   box1.setlen(5.999);
	   box1.setbre(6.78);
	   box1.sethei(89.111);
	   
	   cout<<"L is - "<<box1.getlen()<<endl;
	   cout<<"B is - "<<box1.getbre()<<endl;
	   cout<<"H is - "<<box1.gethei()<<endl;
	   
	   box2 = move(box1);
	   
	   double vol2 = box2.l*box2.b*box2.h;
	   //Same coz no moved yet
	   cout<<"Volume of box2 is : "<<vol2<<endl;
	 //cout<<box1.l<<endl;STILL WORTHY (STILL CAN ANCESS COZ                             INT IS SIMPLE DATA STRUCT)
	 //Box Box1();//No () operator provider
	 //Box Box1;//WORKS 
	 //Box box3 = Box1(); //ERROR COZ BOX DOESN'T PROVIDE A ()                             OPERATOR
	 //Box box3 = Box1;//box3 STORING REFERENCE PC BOX1 SO                             box3 IS POINTING AT BOX1 SO IT CAN                             CHANGE IT'S MEMBERS N CALL FUNC
	   Box box3 = Box();//Works because constructor passed                               here 
	 //cout<<"Box().l is - "<<Box().l<<endl;//Works
	   Box Box2;
	 //Box box4 = Box2; //copied early so box4.l is 0
	   box3.l = 69.99;
	 //box4.l = 7000.00;
	   Box2.l = 5.099;
	   Box box4 = Box2; //Now box4.l is 5.099
	                    //same as Box box4(Box2);
	   cout<<"box4.l is "<<box4.l<<endl;
	   cout<<"box3.l is "<<box3.l<<endl;
	   cout<<"Box2.l is "<<Box2.l<<endl;
	   cout<<"Box().l is \n"<<Box().l<<endl;
     //cout<<Box1().l; 
	   cout<<"box3.l is "<<box3.l<<endl;
	 //cout<<Box1.l<<endl;
	   Box box5((Box())); //Box() interpreted as func call
	   cout<<"box5.l is "<<box5.l<<endl; 
	   /*Box box5(Box());
	   OR Box box5 = Box();
	   is for initializing values by default constructor
	   BUT Box box5(Box()); is CONSIDERED AS A FUNCTION CALL
	   
	   rather add outer parentheses too like 👇🏻
	                                   Box box5((Box()));
	                                   cout<<box5.l<<endl;
	                                   now will be Zero.*/
	                                   
	                                   
	   Box box6(Box{});
	   box6.l = 0;
	   cout<<"box6.l is "<<box6.l<<endl; 
	   //OUTPUT 2M6935E-233 is garbage values located at the          memory of box6.l.. as constructor doesn't initialize so        garbage is showed 
	  
	   Box box7{Box()};
	 //box7.l=8;
	   cout<<"box7.l is "<<box7.l<<endl;
	   
	   
	   /*Box box5((Box())); --> Interpreted as a Func call             with return type Box so returns a Box obj and then             parameter is unnamed pointer to the func returning             Box();
	    Box box5{Box()} Correct way of initializing creates a          temporary Box() obj n move it to box5.. BRACE                  INITIALIZIATION
	    Box box5(Box{]) similar to above but more explicit in          manner*/
	    
	    
	  //Box box8((box1())); BOX DOESN'T PROVIDE A CALL                 OPERATOR
	    Box box9;
	    Box box8{box9};
	    Box box10((box9));
	    Box box11(box9);
	    //if Box box12(Box{}) HERE BOX() is a rvalue so it can           operate move constructor otherwise copy is called              until u cast lvalue to rvalue using std::move();
	    Box box12(39.9989,57.999,12.98);
		
		box12.edges = 18;
		//box12.faces = 8;
		cout<<"box12.l is - "<<box12.l<<endl;
		cout<<"box12.b is - "<<box12.b<<endl;
		cout<<"box12.h is - "<<box12.h<<endl;
		box12.setlen(00.01);
		box12.setbre(00.555);
		box12.sethei(00.001);
		cout<<"box12 lable is - "<<box12.getlabel()<<endl;
		double vol12 = box12.l*box12.b*box12.h;
		cout<<"box12.vol is - "<<vol12<<endl;
		Box box13 = move(box12);
		cout<<"box13.edges is - "<<box13.edges<<endl;
		cout<<"box12.faces is - "<<box12.faces<<endl;/*garbage coz no mention in ini list and thus no self reference
		stored*/
	    /*char a = 68.9999999999999999999999;
	    int b = 676.99;
	    float j = 'y';
	    float k= "string"[3];
	    int o = 'j';
	    cout<<k<<endl;
	    cout<<j<<"\n"<<o<<endl;
	    char c[]={67, 87,56,60,66};
	    char* h = c;
	    cout<<*(h+4);
	    char* p;*/
	  /**p = 67;
	    cout<<p<<endl;*/
	    //ANY DATATYPE can CONTAIN NUMBER;
return 0;
          }