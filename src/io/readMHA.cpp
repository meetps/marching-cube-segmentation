#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string FILE_NAME = "../../data/data/VSD.Brain.XX.O.MR_Flair/Flair.csv";

// void readMHA(FILE_NAME)
// {
// 	break;
// } 

int main()
{
	ifstream mhaReader;
 	mhaReader.open("../../data/VSD.Brain.XX.O.MR_Flair/Flair.csv");
 	if (mhaReader.is_open()) 
 	{
 		int n = 0, SX=0, SY=0, SZ=0;
 		string val;
 		mhaReader >> SX;
 		mhaReader >> SY;
 		mhaReader >> SZ;

 		short *** imageMat = new short** [(int)SX];
		for(int i = 0; i < SX; i++)
		{
			imageMat[i] = new short* [(int)SY];
			for(int j = 0; j < SY; j++)
			{
				imageMat[i][j] = new short[(int)SZ];
			}	
		}

 		while (!mhaReader.eof()) 
 		{
    		for (int k = 0; k < SZ; k++)
    		{
    			for (int j = 0; j < SY; j++)
    			{
    				for (int i = 0; i < SX; i++)
    				{
 						mhaReader >> val;
    					imageMat[i][j][k] = (short)val;
    				}
    			}
    		}
		}

		for (int i = 0; i < SX; i++)
    	{
    		for (int j = 0; j < SY; j++)
    		{
    			// cout << imageMat[0][i][j] << " ";
    			;
     		}
		}
    	cout << imageMat[80][80][80] << " ";
	}
}