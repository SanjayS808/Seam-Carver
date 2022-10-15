#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // delete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
  int* A = new int[length];
  for (int i = 0;i<length;i++){
     A[i] = 0;
  }
  return A;
}

void deleteSeam(int* seam) {
  delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {

  string fileType;


  

  //open up file
  ifstream inFS;     
  inFS.open(filename);
  if (!inFS.is_open()) {
      cout << "Error: failed to open input file - "<< filename ;
      return false;
   }
  
  //check file type
  inFS >> fileType;
  if (fileType != "P3"){
    cout << "Error: type is " << fileType <<" instead of P3";
    return false;
  }
  //check width and height
  int checkW;
  int checkH;
  inFS >> checkW;
  if (inFS.fail()&& !inFS.eof()){
        cout << "Error: read non-integer value";
       return false;
     }
  inFS >> checkH;
  if (inFS.fail()&& !inFS.eof()){
        cout << "Error: read non-integer value";
       return false;
     }
//check if height and width match function param
  if (checkW != width){
    cout << "Error: input width ("<< width<<") does not match value in file (" <<checkW <<")";
    return false;
  }
  if (checkH != height){
    cout << "Error: input height ("<< height <<") does not match value in file (" <<checkH <<")";
    return false;
  }

//check max color val
  int maxColor;
  inFS >> maxColor;
  if (inFS.fail()&& !inFS.eof()){
        cout << "Error: read non-integer value";
       return false;
  }
// while loop that loads values into structures and then loads structures into array
  for (int h =0;h< height;h++){
    for (int w = 0;w< width;w++){
      //load three values into structure
      Pixel temp;
      int temp1;
      int temp2;
      int temp3;
      if (inFS.eof()){
        cout << "Error: not enough color values";
        return false;
      }
      inFS >> temp1;
      if (inFS.fail()&& !inFS.eof()){
       cout << "Error: read non-integer value";
       return false;
      }
      if (inFS.eof()){
        cout << "Error: not enough color values";

        return false;
      }
      inFS >> temp2;
      if (inFS.fail()&& !inFS.eof()){
        cout << "Error: read non-integer value";
       return false;
     }
      if (inFS.eof()){
        cout << "Error: not enough color values";
        return false;
      }
      inFS >> temp3;
      if (inFS.fail()&& !inFS.eof()){
        cout << "Error: read non-integer value";
       return false;
     }
      // check for invalid value
      if (temp1 < 0 || temp1 > maxColor){
        cout << "Error: invalid color value " << temp1 << endl;
        return false;
      }
      if (temp2 < 0 || temp2 > maxColor){
        cout << "Error: invalid color value " << temp2<< endl;
        return false;
      }
      if (temp3 < 0 || temp3 > maxColor){
        cout << "Error: invalid color value " << temp3 << endl;
        return false;
      }
      temp.r = temp1;
      temp.g = temp2;
      temp.b = temp3;
      //append structure to array at index [w][h]
      image[w][h] = temp;
    }
  }
  //check if there are extras
  string var;
  inFS >> var;
  if (!inFS.fail()){
    cout << "Error: too many color values";
    return false;
  }
  

  inFS.close();
 
  return true;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  //open file for output,
  ofstream outFS;
  outFS.open(filename);
  if (!outFS.is_open()) {
   cout << "Error: failed to open output file - " << filename;
   return false;
  }

  //write p3
  outFS << "P3" << endl;
  //write the width x height
  outFS << width << " "<< height << endl;
  //write max color
  outFS << "255" << endl;

  //nested loops to write the file
  for (int h =0;h< height;h++){
    for (int w = 0;w< width;w++){
      Pixel temp;
      temp = image[w][h];
      outFS << temp.r << " " << temp.g << " " << temp.b << endl;
    }
  }
  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) { 
//top edge
if (y-1 < 0){
  //top left
  if(x-1 < 0){
    
  }
  //top right
  if (x+1 > width){

  }

}
//bottom edge
if (y+1 > height){
  //bottom left
  if(x-1 < 0){

  }
  //bottom right
  if (x+1 > width){

  }

}
//left edge
if (x-1 < 0){

}
//right edge 
if (x+1 > width){

}














/*
width --;
height --;

int Rx1;
int Rx2;
int Gx1;
int Gx2;
int Bx1;
int Bx2;

int Ry1;
int Ry2;
int Gy1;
int Gy2;
int By1;
int By2;


int xgrad;
int ygrad;

//top left corner
if( x == 0 && y == 0){
  Pixel temp;
  //store x1 values
  (temp) = image[width][0] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[1][0];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[0][height];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[0][1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
}
//top right corner
else if( x == width && y == 0){
  Pixel temp;
  //store x1 values
  (temp) = image[width-1][0] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[0][0];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[width][height];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[width][1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
  
}
//bottom left corner
else if( x == 0 && y == height){
  Pixel temp;
  //store x1 values
  (temp) = image[width][height] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[1][height];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[0][height-1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[0][0];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
}
//bottom right corner
else if( x == width && y == height){
  Pixel temp;
  //store x1 values
  (temp) = image[width-1][height] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[0][height];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[width][height-1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[width][0];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
  
}
//top edge
else if( y == 0 ){
  Pixel temp;
  //store x1 values
  (temp) = image[x-1][0] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[x+1][0];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[x][height];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[x][1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;

  
}
//bottom edge
else if( y == height ){
  Pixel temp;
  //store x1 values
  (temp) = image[x-1][height] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[x+1][height];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[x][height -1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[x][0];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
}
// left edge
if( x == 0 ){
  Pixel temp;
  //store x1 values
  (temp) = image[width][y] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[1][y];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[0][y-1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[0][y+1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
  
}
//right edge
if( x == width ){
  Pixel temp;
  //store x1 values
  (temp) = image[width-1][y] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[0][y];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[width][y-1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[width][y+1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;
  
}
  Pixel temp;
  //store x1 values
  (temp) = image[x-1][y] ;
  Rx1 = temp.r;
  Gx1 = temp.g;
  Bx1 = temp.b;
  //store x2 values
  temp = image[x+1][y];
  Rx2 = temp.r;
  Gx2 = temp.g;
  Bx2 = temp.b;
  //store y1 values
  temp = image[x][y-1];
  Ry1 = temp.r;
  Gy1 = temp.g;
  By1 = temp.b;
  //store x2 values
  temp = image[x][y+1];
  Ry2 = temp.r;
  Gy2 = temp.g;
  By2 = temp.b;
  // calculate energy and return
  xgrad = pow((Rx1 - Rx2),2) + pow((Gx1 - Gx2),2) + pow((Bx1 - Bx2),2);
  ygrad = pow((Ry1 - Ry2),2) + pow((Gy1 - Gy2),2) + pow((By1 - By2),2);
  int energy = xgrad + ygrad;


  return energy;

*/

}

// implement for part 2

// uncomment for part 2
/* 

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  return 0;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
}
*/
