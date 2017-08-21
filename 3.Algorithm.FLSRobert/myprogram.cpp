// The following program was written by adamyi.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EAST 1
#define NORTH 0

#define CLEAR 0
#define ROUGH 1
#define SAMPLE 2

struct spot
{
    int type;				// the terrain type
    int chosenDirection;			// the direction moved from here
};

class terrain
{
    int xSize, ySize;
    spot *ground;

    public:

    void create(int x, int y)
    {
        xSize = x;
        ySize = y;
        ground = new spot[xSize * ySize];
    }

    void setGroundType(int x, int y, int type)
    {
        ground[xSize * (y - 1) + (x - 1)].type = type;
    }

    int getGroundType(int x, int y)
    {
        return ground[xSize * (y - 1) + (x - 1)].type;
    }  

    void setChosenDirection(int x, int y, int direction)
    {
        ground[xSize * (y - 1) + (x - 1)].chosenDirection = direction;
    }

    int getChosenDirection(int x, int y)
    {
        return ground[xSize * (y - 1) + (x - 1)].chosenDirection;
    }
};

int numberOfVehicles;
int xMax, yMax;
terrain land;

void readDataFile()//char *fileName)
{
    scanf(" %d", &numberOfVehicles);
    scanf(" %d %d", &xMax, &yMax);
    land.create(xMax, yMax);

    for (int y = 1; y <= yMax; y++)
    {  
        for (int x = 1; x <= xMax; x++)
        {
            int groundType;
            scanf(" %d", &groundType);
            land.setGroundType(x, y, groundType);
        }
    }  

}

int findBestPath(int x, int y)
{
    int thisSample;


    switch (land.getGroundType(x, y))
    {
        case CLEAR: 
            thisSample = 0;		// no sample here
            break;
        case ROUGH:
            return -1;		// no possible route
            break;
        case SAMPLE:
            thisSample = 1;		// sample here
            break;
    }

    if (x == xMax && y == yMax)
    {
        return thisSample;
    }  

    int northValue = -1;
    int eastValue = -1;

    if (y < yMax)
    {
        northValue = findBestPath(x, y + 1);
    }  

    if (x < xMax)
    {
        eastValue = findBestPath(x + 1, y);
    }  

    if (northValue == -1 && eastValue == -1)
    {
        return -1;
    }  

    if (eastValue > northValue)
    {
        land.setChosenDirection(x, y, EAST);
        return thisSample + eastValue;
    }
    else
    {
        land.setChosenDirection(x, y, NORTH);
        return thisSample + northValue;
    }
}    

void writeOutputFile()//char *fileName)
{
    int rover;

    for (rover = 1; rover <= numberOfVehicles; rover++)
    {

        if (findBestPath(1, 1) == -1)
        {
            break;
        }  

        int x = 1;
        int y = 1;	

        while (x != xMax || y != yMax)
        {

            land.setGroundType(x, y, CLEAR);


            if (land.getChosenDirection(x, y) == NORTH)
            {
                printf("%d 0 \n", rover);
                y++;
            }
            else
            {
                printf("%d 1 \n", rover);
                x++;
            }
        }


        land.setGroundType(x, y, CLEAR);
    }

}



int main(int argc, char **argv)
{

    readDataFile();//fileName);
    writeOutputFile();//"MARS.OUT");
    return 0;
}
