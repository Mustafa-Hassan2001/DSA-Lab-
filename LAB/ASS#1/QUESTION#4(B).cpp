#include<iostream>
using namespace std;
const int size=5;
//Double stack queue
class Twostack{
	public:	
	
	int stack1[5];
	int stack2[5];
	int top=-1;
	int count=0;
	int top2=-1;
	
	void push(int ID){
		if(top==size-1)
			cout<<"TODAY'S LIMIT IS FULL ";
		
		else{
			top++;
			stack1[top]=ID;
			count++;
	
		}
	}

	void pop(){
		int num;
		if(top==-1&&top2==-1){
			cout<<"CLINIC IS EMPTY : ";
		}
		else{
			for(int i=0;i<count;i++){
				num=pop1();
				secpush(num);
			}
		}
	}
	
	int pop1(){
		return stack1[top--];
		cout<<"This patient checked : ";
	}

	void secpush(int ID){
		if(top2==size-1){
			cout<<"stack overflow : ";
		}
		else{
		top2++;
		stack2[top2]=ID;
		}
	}
	
	void display(){
		cout<<"\nTHE PATIANTS HAVEING THESE FOLLOWING ID:"<<endl;
		for(int i=0;i<count;i++)
		cout<<stack1[i]<<endl;
	}
	
	void secdisplay(){
		for(int i=0;i<=top2;i++)
		cout<<stack2[i]<<endl;
	}
	
	void secpop(){
		top2--;
	}

};

int main(){

	Twostack patient;
	
	patient.push(1);
	patient.push(2);
	patient.push(3);
	patient.push(4);
	patient.push(5);
	
	cout<<"\n*** DOCTOR CLINIC TODAYS APPOIMENTS ARE ***"<<endl;
	patient.display();
	patient.pop();
	cout<<endl;
	
	cout<<"\nPATIENT ID-1 WILL GO FIRST "<<endl;
	patient.secpop();
	patient.secdisplay();
	cout<<endl;
	
	cout<<"\nNOW PATIENT ID-2 WILL "<<endl;
	patient.secpop();
	patient.secdisplay();
	cout<<endl;
	
	cout<<"\nDOCTOR'S LUNCH TIME  "<<endl;
	cout<<"\nREMAINING PAIIENT'S ARE :"<<endl;
	patient.secdisplay();
	

	return 0;
}
