# Engineering Drawing software
This repository contains the mathematical model, documentation, functional descriptions and source files of the Engineering Drawing as a part of COP290 Course at IIT Delhi. </br>
Team Members: Anubhav Palway (2016CS10368), Sunil Kumar (2016CS10314). 

 ## Aim
 Design and implement a software package for Engineering drawing with the following functionalities:</br>
*    We should be able to interactively input or read from a file either </br>
        i) an isometric drawing and a 3D object model or </br>
        ii) projections on to any cross section.</br>
*    Given the 3D model description we should be able to generate projections on to any cross section or 
     cutting plane.</br>
*    Given two or more projections we should be able to interactively recover the 3D description and
     produce an isometric drawing from any view direction. </br>
     
 ## How to use:
 Input Format:</br>
*    To Draw the 3d object:</br>
        - Press n.</br>
        - Press 'u' for positive x-axis and 'j' for negative x-axis.</br>
        - Press 'i' for positive y-axis and 'k' for negative y-axis.</br>
        - Press 'o' for positive z-axis and 'l' for negative z-axis.</br>
*    Using text file:</br>
        i) To generate projections from 3d object:</br>
            - First line gives type i.e, zero for 3d to 2d</br>
            - Next line gives n, number of shapes.</br>
            - Next n lines gives the points for basic shapes in the following format:</br>
                Basic shapes include point(1), line(2), triangle(3) and quadrilateral(4)</br>
                First the number of points according to the shape and then the x,y,z coordinates.</br>
                E.g.- 3 (1,1,0) (0,0,0) (0,1,0)     //This is for a triangle</br>
        ii) To generate 3d object from 2d projections:</br>
            - First line gives type i.e., one for 2d to 3d</br>
            - Next line gives n, number of points for top projections.</br>
            - Next n lines gives the points (x,y,z coordinates with spaces in between them)</br>
            - Next line contains e, number of the edges in top projection.</br>
            - Next e line should contain 2 integers, i, j, denoting an edge between vertex i and vertex j as per the order of input of vertices (order starting from 0)</br>
 *    Executing the code: </br>
        ```
        cd Cop290/codes/src/
        ```
        
        ```
        make
        ```
        
        Without any file</br>
        ```
        ./cadmake 
        ```
        
        With File</br>
        ```
        ./cadmake <input.txt>
        ```
        </br>
*       't' to save</br>
        'w' to zoom out </br>
        's' to zoom in </br>
        Arrow keys to rotate.</br>
        'x' and 'y' to reset x and y rotation respectively.
