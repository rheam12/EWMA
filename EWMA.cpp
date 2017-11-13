#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
using namespace std;
int main(int argc, const char* const argv[])
{
	int i=3;
	int sample=1;
	float value=atof(argv[3]);
	float min=atof(argv[3]);
	float max=atof(argv[3]);
	float ewma=0;
	int age=atoi(argv[2]);
	int checkMax=0;
	int checkMin=0;
	
	if(argc<=3)
		cerr<<"Error: Unable to compute statistics over data set because of insufficient arguments."<<endl;
	if(atoi(argv[2])<1)
		cerr<<"Error: Invalid age value."<<endl;
	if(atof(argv[1])<0||atof(argv[1])>1)
		cerr<<"Error: Invalid 'a' value."<<endl;
	
	cout<<"Sample	Value	Minimum	EWMA	Maximum"<<endl;	

	while(i<=argc){
			if(i==3)
				ewma=atof(argv[3]);
			else
				ewma=atof(argv[1])*atof(argv[i])+(1-atof(argv[1]))*(ewma);
			
			if(atof(argv[i])>max||checkMax>=age){
				max=atof(argv[i]);
				checkMax=0;
			}
			if(atof(argv[i])<min||checkMin>=age){
				min=atof(argv[i]);
				checkMin=0;
			}	
			value=atof(argv[i]);
			cout<<sample<<"	"<<value<<"	"<<min<<"	"<<ewma<<"	"<<max<<endl;
			i++;
			sample++;
			checkMin++;
			checkMax++;
	}
		
	return 0;
}