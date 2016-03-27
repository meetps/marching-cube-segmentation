#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

string FILE_NAME = "../../data/data/VSD.Brain.XX.O.MR_Flair/Flair.csv";

int str2int (const string &str) {
  stringstream ss(str);
  int num;
  ss >> num;
  return num;
}

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
						imageMat[i][j][k] = str2int(val);
    				}
    			}
    		}
		}
    	cout << imageMat[80][80][80] << " ";
	}
}