#include <stdio.h>
#include <stdlib.h> 

void go_south_east(int lon,int lat)
{
    lon = lon + 1; 
    lat = lat - 1; 
}

int main()
{
    int longitude = 32;
    int latitude  = -64; 
    go_south_east(longitude,latitude);
    printf("now at:[%i longitude, %i latitude]\n",longitude,latitude);  
    return 0; 
}