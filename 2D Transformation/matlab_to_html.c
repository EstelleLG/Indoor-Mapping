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


FILE *fp, *fd;
int number_of_matlab_rows = 53;
float intake[number_of_matlab_rows+1][2];
int i, h, j;

  fp=fopen("data_1.c","r");

  if(fp==NULL) {
     printf("\nFile does not exist in this directory.\n");
     exit(1);
  }
  
  // Extracts the desired information and puts the data into a matrix. Have to because cannot get multiple row information otherwise
  for(i=0;i<number_of_matlab_rows;i++) {
     for(j=0;j<2;j++) {
        fscanf(fp,"%f", &intake[i][j]);
     
     if(j!=0)
        j=0;
     else {
        fscanf(fp,"%f", &intake[i][j]);
     }
  }

  fclose(fp);
  printf("\n\n\n\n");


  // Now that there is a matrix that contains the numbers, need to put into an html file for imaging.
  fd=fopen("output.html","w");
  
  char begin_html_format[100] = "<!DOCTYPE html> \n <html> \n <style> \n img { \n position: absolute; \n } \n </style> \n <body>\n\n";
  char script_begin[100] = " <script> \n    function inputPanoramic(message) { \n\t   var myWindow = window.open(";
  char script_message[80] = "\"/home/ashley/matlab_imaging/test.html?msg=\" + message,";
  char script_width_height[50] = "width=1200, height=600";
  char end_script[50] = "); \n    } \n </script> \n\n ";
  char begin_html_format1[10] = "<img src=";
  char map_destination[50] = "/home/ashley/web/first-floor.jpg";
  char style[20] = "\n      style=";
  char map_info[50] = "z-index: -1;\n      left: 0px;\n      top: 0px;";
  char onclick[15] = "<a onclick=";
  char message[60] = "inputPanoramic('Panoramic/duc000.jpg')";
  char begin_img[20] = "\n <img src=";
  char file_destination[100] = "/home/ashley/web/index.jpg";
  char zindex_and_left[50] = "z-index: 1;\n      left: ";
  char top[20] = "\n      top: ";
  char width_height[50]  = "\n      width: 15px; \n      height: 15px;";
  char a[10] = "\n</a>\n ";
  char buffer[500] = {0}; 


  fputs(begin_html_format,fd);
  fputs(script_begin,fd);
  fputs(script_message,fd);
  fputs("\"\",\"",fd);
  fputs(script_width_height,fd);
  fputs("\"",fd);
  fputs(end_script,fd);
  fputs(begin_html_format1,fd);
  fputs("\"", fd); 
  fputs(map_destination,fd);
  fputs("\"",fd);
  fputs(style,fd);
  fputs("\"",fd);
  fputs(map_info,fd);
  fputs("\">",fd);
  fputs("\n",fd);
  i=4;j=0;
  j=1;

  for(i=0;i<(number_of_matlab_rows-1);i++) {
     fputs("\n",fd);
     for(j=0;j<1;j++) {
	fputs(onclick,fd);
	fputs("\"",fd);

	//if statements that write the correct duc panoramic photo to each image. First floor: 1-27,67-91.
	if((message[30]=='2') && (message[31]=='8')) {
	    message[31]='7';
	    message[30]='6';
	    fputs(message,fd);
	    int j = (int)message[31]+1;
	    message[31]=(char)j;
	}
	else {
	   if((message[31]=='9') && (message[30]!='9')) {
		fputs(message,fd);
		message[31]='0';
		int n = (int)message[30]+1;
		message[30]=(char)n;

	   }
	   else {
		if((message[31]=='0') && (message[30]=='0')) {
		     fputs(message,fd);
		     int h = (int)message[31]+1;
		     message[31]=(char)h;
		}
		else {
    		   if((message[31]!='9') && (message[30]!='9')) {
	                fputs(message,fd);
		        int m = (int)message[31]+1;
		        message[31]=(char)m;

		   }
		}
	   }
	}
	printf("message[29]=%c\n",message[29]);
	printf("message[30]=%c\n",message[30]);
	printf("message[31]=%c\n\n",message[31]);

	fputs("\">",fd); 
        fputs(begin_img,fd);
        fputs("\"",fd);
        fputs(file_destination,fd);
        fputs("\"",fd);
        fputs(style,fd);
        fputs("\"",fd);
        fputs(zindex_and_left,fd);
        sprintf(buffer, "%f", intake[i][j]);
        fputs(buffer, fd);
        fputs("px;",fd);
        fputs(top,fd);
        j=j+1;
        sprintf(buffer, "%f", intake[i][j]);
        fputs(buffer, fd);    
        fputs("px;",fd);
        fputs(width_height,fd);
        fputs("\">",fd);
	fputs(a,fd);
     }
  }
  

  fclose(fd);

  printf("\n\n\n\n");

  return 0;

}


