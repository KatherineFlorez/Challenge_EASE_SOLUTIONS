# Challenge EASE Solutions
Repository with the solution of challenge in c++.
Developed in Visual Studio Community 2019.
The description of the challenge could be found in the file *Challenge.pdf*

# Proyect structure
The proyect is devided in 4 files

 1. Challende_EASE_SOLUTIONS.cpp: Contains main function of the project
    * Read the matrix information.
    * Calls the method to obtain the longest path information.
    * Prints the information.
 2. Methods.h: Header file with the declaration of class "Methods" with a default constructor and destructor and the definition of the methods.
    * Public methods:
      * PrintLongestPath: Print into the console the given path.
      * ReadFile: Read .txt file and save the information.
      * InfoLongestPath: Main method to calculate decreasing longest path into the matrix.
    * Private Methods:
      * DFS: Depth First Search algorithm for search the longest decreasing length starting of each of the elements of the matrix. 
      * GetPathInfo: Calculate the steep and save the path of a specific initial point and maximum length.
3. Methods.cpp: Contains the methods declared in Methods.h
4. InfoLongestPath.h: Header file that contains the declaration of the structure InfoLongestPath, that contains: 
   * The maximum Steepest. 
   * The maximum Longest.
   * The elements of the decreasing longest path.
 
# Test execution:
The project requests the location of the input .txt file through a message on the console: Enter file location:
```markdown
Enter file location: (Input/xxx.txt)
```
And returns the information with the output messages:

```markdown

  Length of calculated path: X
  Drop of calculated path: X
  Calculated path: X-X-X-X-X
```
# Dataset 
Directory Input contains different datasets saved in .txt file. 

File structure: First line that has the dimensions of the matrix M x N, the matrix of elevation.
```markdown
3 3 
1 2 3
4 5 6
7 8 9
```
* 4x4.txt: 4 x 4 matrix
  * Length of calculated path: 5
  * Drop of calculated path: 8
  * Calculated path: 8-5-3-2-1
  
* 5x10.txt:
  * Length of calculated path: 7
  * Drop of calculated path: 14
  * Calculated path: 15-14-12-9-7-2-1
  
* Spiral4x4.txt: 4 x 4 matrix spiral
  * Length of calculated path: 16
  * Drop of calculated path: 99
  * Calculated path: 100-95-83-80-70-60-54-50-47-41-32-30-23-12-1
  
* map.txt:
  * Length of calculated path: 15
  * Drop of calculated path: 1422
  * Calculated path: 1422-142-1316-1304-1207-1162-965-945-734-429-332-310-214-143-0
