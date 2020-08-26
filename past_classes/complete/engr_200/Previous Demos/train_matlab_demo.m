%**************************************************************************
%MATLAB DEMO PROGRAM
%   
%PROGRAM DESCRIPTION:
%This program will calculate the centrifugal force of a train traveling
%around a level curved track.  The weight and radius are entered through
%the keyboard, and the matrix speed is loaded from the input file.  The
%computed results are printed to the command window and to an output file.
%The program will stop executing if an incorrect radius is entered.
%
%DESCRIPTION VARIABLES:
%NAME         | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%train_speeds | double | one-dimensional matrix of speeds in miles/hour
%weight       | double | weight of train in tons
%radius       | double | radius of track curve in feet
%force        | double | calculated centrifugal force in pounds
%gravity      | double | gravitation acceleration in ft/s^2
%outputfile   | char   | file location of printed output
%**************************************************************************

%Clear Command Window, memory, and plots
clc
clear
close all

%Load input file
load train_speeds.txt;

%Open output file
outputfile = fopen('train_report.txt','wt');

%Initialize gravity variable
gravity = 32;

%Print main heading
fprintf('**************************************');
fprintf('\n      CENTRIFUGAL FORCE PROGRAM\n\n');
fprintf(outputfile,'**************************************');
fprintf(outputfile,'\n      CENTRIFUGAL FORCE PROGRAM\n\n');
%Enter train weight and track radius
weight = input('Enter train weight in tons: ');
radius = input('Enter track radius in feet: ');

%Print column headings
fprintf('\nSpeed     Weight     Radius      Force');
fprintf('\n(mph)     (tons)      (ft)       (lbs)');
fprintf(outputfile,'\nSpeed     Weight     Radius      Force');
fprintf(outputfile,'\n(mph)     (tons)      (ft)       (lbs)');

%Verify radius of track curve
while radius < 2640 || radius > 7920
    clc;
    fprintf('\n\nRadius error occurred\n\n');
    radius = input('Enter track radius in feet: ');
end

%Compute centrifugal forces and print table
for k=1:1:length(train_speeds)
    force = (weight*2000/gravity)*(train_speeds(k)*1.4667^2)/radius;
    fprintf('\n %4.1f     %5.1f     %6.1f    %7.1f',train_speeds(k),...
           weight,radius,force);
    fprintf(outputfile,'\n %4.1f     %5.1f     %6.1f    %7.1f',...
           train_speeds(k),weight,radius,force); 
end

%Print end of report
fprintf('\n**************************************\n\n');
fprintf(outputfile,'\n**************************************\n\n');
%**************************************************************************