#include<iostream>
using namespace std;
//By Queue
class Clinic{
 public:
	
  int front = -1, rear = -1, size = 5, Patientchecked;
  int PatientQueue[5];

  void Enqeue(int Patientid){
    	if (rear == size-1){
     	cout<< "TODAY'S LIMIT IS FULL "<<endl;
    	}
	   rear++;
	   PatientQueue[rear] = Patientid;
    	if (front == -1){
       front = 0;
    	}
    }
    
  void Deqeue(){
    if(front == -1){
      cout<<"CLINIC IS EMPTY! \n";
    	}
    else 
    Patientchecked = PatientQueue[front];
    cout<<"\nPatient having ID-"<<Patientchecked<<" is Checked"<<endl;
    PatientQueue[front] = 0;
    front++;
    }
    
  void display(){
    for(int i=0; i<size; i++){
    cout<<PatientQueue[i]<<"\n";
    	}
    }
    
};

int main(){
	
	Clinic c1;
	
	c1.Enqeue(1);
	c1.Enqeue(2);
	c1.Enqeue(3);
	c1.Enqeue(4);
	c1.Enqeue(5);
	
	cout<<"\n*** DOCTOR CLINIC TODAYS APPOIMENTS ARE ***"<<endl;
	c1.display();
	
	c1.Deqeue();
	cout<<"\nREMAIING PATIENT'S ARE :"<<endl;
	c1.display();
	
	c1.Deqeue();
	cout<<"\nREMAIING PATIENT'S ARE :"<<endl;
	c1.display();
	
	return 0;
}
