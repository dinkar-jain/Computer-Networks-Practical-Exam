#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	int nf,N;
	int no_tr=0;
	
	srand(time(NULL));

	cout << "Enter no. of frames: ";
	cin >> nf;
	cout << "\nEnter the Window size: ";
	cin >> N;
	cout << "\n\n";
	
	int i=1, j;
	while(i<=nf)
	{
    	int x=0;
    	cout << "Sender" << endl;
    	for(j=i;j<i+N && j<=nf;j++,no_tr++)
			cout << "Sent frame " << j << "  ";
    
		cout << endl << endl << "Reciver" << endl;
		for(j=i;j<i+N && j<=nf;j++)
    	{
    	    int flag = rand() % 2;
    	    
			if(!flag)
    	        {
    	            cout << "Acknowledgment for Frame " << j << endl;
    	            x++;
    	        }
    	    else
    	        {   cout << "Frame " << j << " NOT Received\n";
    	            cout << endl << "Retransmitting Window\n";
    	            break;
    	        }
    	}
    	cout << endl;
    	i += x;
	}

	cout << "Total number of transmissions : "<< no_tr;
	
	return 0;
}
