// This program will take in the Matlab values as a string, then create
// a vector of numbers that will be translated into an html file.
// The goal is to not have to manually plot the coordinates since the
// values will later be changed.


#include <stdio.h>
#include "string.h"
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){


FILE *2fp, *2fd;
int 2number_of_matlab_rows = 56;
float 2intake[2number_of_matlab_rows+1][2];
int i, h, j;

  2fp=fopen("data_2.c","r");

  if(2fp==NULL) {
     printf("\nFile does not exist in this directory.\n");
     exit(1);
  }
  
  // Extracts the desired information and puts the data into a matrix. Have to because cannot get multiple row information otherwise
  for(i=0;i<2number_of_matlab_rows;i++) {
     for(j=0;j<2;j++) {
        fscanf(2fp,"%f", &2intake[i][j]);
     }
     if(j!=0)
        j=0;
     else {
        fscanf(2fp,"%f", &2intake[i][j]);
     }
  }

  fclose(2fp);
  printf("\n\n\n\n");


  // Now that there is a matrix that contains the numbers, need to put into an html file for imaging.
  2fd=fopen("output.html","w");
  
  char 2begin_html_format[100] = "<!DOCTYPE html> \n <html> \n <style> \n img { \n position: absolute; \n } \n </style> \n <body>\n\n";
  char 2script_begin[100] = " <script> \n    function inputPanoramic(message) { \n\t   var myWindow = window.open(";
  char 2script_message[80] = "\"/home/ashley/matlab_imaging/test.html?msg=\" + message,";
  char 2script_width_height[50] = "width=1200, height=600";
  char 2end_script[50] = "); \n    } \n </script> \n\n ";
  char 2begin_html_format1[10] = "<img src=";
  char 2map_destination[50] = "/home/ashley/web/first-floor.jpg";
  char 2style[20] = "\n      style=";
  char 2map_info[50] = "z-index: -1;\n      left: 0px;\n      top: 0px;";
  char 2onclick[15] = "<a onclick=";
  char 2message[60] = "inputPanoramic('Panoramic/duc028.jpg')";
  char 2begin_img[20] = "\n <img src=";
  char 2file_destination[100] = "/home/ashley/web/index.jpg";
  char 2zindex_and_left[50] = "z-index: 1;\n      left: ";
  char 2top[20] = "\n      top: ";
  char 2width_height[50]  = "\n      width: 15px; \n      height: 15px;";
  char 2a[10] = "\n</a>\n ";
  char 2buffer[500] = {0}; 


  fputs(2begin_html_format,2fd);
  fputs(2script_begin,2fd);
  fputs(2script_message,2fd);
  fputs("\"\",\"",2fd);
  fputs(2script_width_height,2fd);
  fputs("\"",2fd);
  fputs(2end_script,2fd);
  fputs(2begin_html_format1,2fd);
  fputs("\"", 2fd); 
  fputs(2map_destination,2fd);
  fputs("\"",2fd);
  fputs(2style,2fd);
  fputs("\"",2fd);
  fputs(2map_info,2fd);
  fputs("\">",2fd);
  fputs("\n",2fd);
  i=4;j=0;
  j=1;

  for(i=0;i<(2number_of_matlab_rows-1);i++) {
     fputs("\n",2fd);
     for(j=0;j<1;j++) {
	fputs(2onclick,2fd);
	fputs("\"",2fd);

	//if statements that write the correct duc panoramic photo to each image. First floor: 1-27,67-91.





	if((2message[30]=='2') && (2message[31]=='8')) {
	    2message[31]='7';
	    2message[30]='6';
	    fputs(2message,2fd);
	    int j = (int)2message[31]+1;
	    2message[31]=(char)j;
	}
	else {
	   if((2message[31]=='9') && (2message[30]!='9')) {
		fputs(2message,2fd);
		2message[31]='0';
		int n = (int)2message[30]+1;
		2message[30]=(char)n;

	   }
	   else {
		if((2message[31]=='0') && (2message[30]=='0')) {
		     fputs(2message,2fd);
		     int h = (int)2message[31]+1;
		     2message[31]=(char)h;
		}
		else {
    		   if((2message[31]!='9') && (2message[30]!='9')) {
	                fputs(2message,2fd);
		        int m = (int)2message[31]+1;
		        2message[31]=(char)m;

		   }
		}
	   }
	}
	printf("2message[29]=%c\n",2message[29]);
	printf("2message[30]=%c\n",2message[30]);
	printf("2message[31]=%c\n\n",2message[31]);





	fputs("\">",2fd); 
        fputs(2begin_img,2fd);
        fputs("\"",2fd);
        fputs(2file_destination,2fd);
        fputs("\"",2fd);
        fputs(2style,2fd);
        fputs("\"",2fd);
        fputs(2zindex_and_left,2fd);
        sprintf(2buffer, "%f", 2intake[i][j]);
        fputs(2buffer, 2fd);
        fputs("px;",2fd);
        fputs(2top,2fd);
        j=j+1;
        sprintf(2buffer, "%f", 2intake[i][j]);
        fputs(2buffer, 2fd);    
        fputs("px;",2fd);
        fputs(2width_height,2fd);
        fputs("\">",2fd);
	fputs(2a,2fd);
     }
  }
  

  fclose(2fd);

  printf("\n\n\n\n");

  return 0;

}
