#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

string FILE_NAME = "../../data/VSD.Brain.XX.O.MR_Flair/Flair.csv";

int main()
{
	ifstream mhaReader;
 	mhaReader.open("../../data/VSD.Brain.XX.O.MR_Flair/Flair.csv");
 	if (mhaReader.is_open()) 
 	{
 		int SX=0, SY=0, SZ=0;
 		short val;
 		mhaReader >> SX;
 		mhaReader >> SY;
 		mhaReader >> SZ;

 		short *** imageMat = new short** [SX];
		for(int i = 0; i < SX; i++)
		{
			imageMat[i] = new short* [SY];
			for(int j = 0; j < SY; j++)
			{
				imageMat[i][j] = new short[SZ];
			}	
		}

		int max = 0;

 		for (int k = 0; k < SZ; k++)
    		{
    			for (int j = 0; j < SY; j++)
    			{
    				for (int i = 0; i < SX; i++)
    				{
 						mhaReader >> val;
						imageMat[i][j][k] = val;
    					if(val > max)
    					{
    						max = val;
    					}
    					if (i == 80 && j == 80 && k == 80) {
    						cout <<"HERE"<< val<<" "<<imageMat[i][j][k]<<" "<<endl;
    					}
    				}
    			}
		}
    	cout << imageMat[80][80][80] << " ";
    	cout << max << " ";
	}
}