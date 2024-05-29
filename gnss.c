
#include <stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    //   printf("GNGGA Detected!\r\n");

   uint8_t *p = "$GNGGA,114116.00,1714.38276,N,07828.48321,E,1,06,1.38,617.0,M,-74.7,M,,*67";

   printf("Received String: %s\r\n",p);
   
   double timef;
   int time1,hour,minute,seconds;
   char degreebuff[10];
   long degree, degree1;
   float minutes1, minutes2;
int LongDir= 0, LatDir = 0;
float latitude , longitude, speed, angle;
uint32_t Latitude, Longitude;

   //Time parsing
   	p = strchr(p , ',')+1;
   	timef = atof(p);
   	time1 = timef;
   	hour = time1/10000;
   	minute = (time1 % 10000)/100;
   	seconds = (time1 % 100);
   	printf("hh:mm:ss %d: %d: %d\r\n" , hour,minute,seconds);

   	p = strchr(p , ',')+1;

//   	printf("%s\r\n lat str",p);
   		    if (',' != *p)
   		    {
   		      strncpy(degreebuff, p, 2);
   		      p += 2;
   		      degreebuff[2] = '\0';
   		      degree = atol(degreebuff);
//   			print("degree =%d\r\n ",degree);
   		      char data[9];
   		      strncpy(data, p , 8);
//   			print("data = %s\r\n",data);
   		      p=p+8;
//   		      printf("p = %s\r\n",p);
   		      data[8] = '\0';
//   			print("data %s\r\n",data);
   		      minutes1 = atof(data);
//   		      print("minutes = %f\r\n",minutes1);
   		      latitude = (degree + ((float)(minutes1)/60));
   		      Latitude = latitude * 1000000;			// for simplicity make it float at ttn
   			printf("latitude = %f\r\n",latitude);
   		    }

//   		  /*    // Latitude Direction South or North
   		    p = strchr(p , ',')+1;
//   		    printf("parsed str = %s\r\n" , p);
   		 	if(',' != *p)
   		 	{
   		 		LatDir = p[0];

   		 		if(p[0]=='N')
   		 			printf("North..\r\n" , p[0]);
   		 		else if(p[0]=='S')
   		 			printf("South..\r\n",p[0]);
   		  	}

   		 p = strchr(p , ',')+1;
   		if(',' != *p)
   		{

//   			print("p = %s\r\n",p);
   			strncpy(degreebuff , p ,3);
   															// taking the longitude degree and seconds
   			p += 3;
   			degreebuff[3] = '\0';
//   			print("degreebuff %s\r\n",degreebuff);
   			degree1 = atol(degreebuff);
   			char data1[9];											// Parse the only degree
   			strncpy(data1, p, 8);
   			p = p+6;
   			data1[8] = '\0';
//   			print("data1 %s\r\n",data1);
   			minutes2 = atof(data1);
//   			printf("minutes2 %f\r\n",minutes2);
   			longitude = (degree1 + ((float)(minutes2)/60));							// final longitude coordinates
   			Longitude = longitude * 1000000;						// for simplicity
   			printf("longitude %f\r\n",longitude);
   		}
   		p = strchr(p , ',')+1;
//   		printf("parsed string %s\r\n",p);
             if(',' != *p)
             {
            	 LatDir = p[0];

            	 if(p[0]=='E')
            		 printf("East..\r\n" , p[0]);
            	 else if(p[0]=='W')
            		 printf("West..\r\n",p[0]);
             }
         p = strchr(p , ',')+1;
         p = strchr(p , ',')+1;
         p = strchr(p , ',')+1;
         p = strchr(p , ',')+1;

//   		print("p = %s\r\n",p);
   		if(',' != *p)
        {
         char alti[6];
   		strncpy(alti , p , 5);
   		 printf("altt  %s\r\n",alti);
   			   p = p+6;
   			  alti[5] = '\0';
//   			print("alti %s\r\n",alti);
   			float altitude =atof(alti);
   			printf("altitude = %f\r\n",altitude);
   			}

// }
}

