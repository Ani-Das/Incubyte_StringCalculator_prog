//Incubyte test
//Aniesh Das 32204 anieshpictmun@gmail.com
#include <iostream>
#include <conio.h>     //for getch()
#include <windows.h>   //for clear screen
using namespace std;

class StringCalculator{
	private:
		string str;      //private string variable
	
	public:
		StringCalculator(string s){     //Parameterised constructor to initialise private variable
			str = s;
		}	
		
		int addString(){          //addString class method to carry out string addition program
			
			int len = str.length();   //find length of string
			int sumcount = 0;
			int i=0;
			
			while(i<len){   //loop through string elements
				if(str[i]==','){      // ignore commas
					i++;
					continue;
				}
				
				else if(str[i]=='-'){
					int snum =0;
					i++;
					    while(isdigit(str[i])){                    //convert characters to number
					    	snum=(str[i]-'0') + snum*10;
					    	i++;
						}

						i = i-1;           // iterator reduces by one since it is incremented at the end;
					
					try{                     //exception handling in case of negatives
						    throw(snum);
						}
						
					catch(int n){
						return -n;
						break;
					}
				}
				
				
				else{
					
					if(isdigit(str[i])){   //if integer found
					int dnum =0;
					    while(isdigit(str[i])){                    //convert characters to number
					    	dnum=(str[i]-'0') + dnum*10;
					    	i++;
						}

						i = i-1;           // iterator reduces by one since it is incremented at the end;
						
						if(dnum>=0 && dnum<1000){
							sumcount+=dnum;	
						}
						
						else if(dnum>1000){    //continue iteration if greater than 1000
						    i++;
							continue;
						}
					}
					
					else if(isalpha(str[i])){
						sumcount+=(str[i]-'a') + 1;
					}
					
				}
				
				i++;   // increments i
			}
			
			return sumcount;
			
		}
	
	~StringCalculator(){
	     //calling destructor
	    }
	};

int main(){
	
	string ans = "no";
	
	do{
		
		string input = "";
		cout<<"Enter string: ";
		getline(cin,input);
	
		StringCalculator obj(input);
	
		if(obj.addString()<0){
			cout<<"Negatives not allowed: "<<obj.addString();     //if negative found
		}
		else{
			cout<<"String sum is: "<<obj.addString();
		}
	
		getch();
		system("cls");
	
		cout<<"Do you wish to continue?(yes/no)";    //user can choose to repeat program
		cin>>ans;        
		                        
	}
	while(ans=="yes");

	if(ans=="no"){
		exit(0);      //if user doesnt continue end program
	}
	
	return 0;
	
}
