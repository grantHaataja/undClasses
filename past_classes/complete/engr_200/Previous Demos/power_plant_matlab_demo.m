%**************************************************************************
%MATLAB DEMO USING A TWO-DIMENSIONAL MATRIX
   
%PROGRAM DESCRIPTION:
%This program will compute the average power output of a two-dimensional
%power matrix.  The program will determine the minimum power, the maximum
%power, the row and column location of the minimum power, and the row and
%column location of the maximum power.  The results are printed to the
%Command Window and to an output file.

%DESCRIPTION VARIABLES:
%NAME        | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%power_plant | double | two-dimensional matrix of power in megawatts
%nrows       | double | number of rows in the matrix
%ncols       | double | number of columns in the matrix
%minpow      | double | minimum power output
%maxpow      | double | maximum power output
%avepow      | double | calculated average power
%minrow      | double | row location of minimum power
%mincol      | double | column location of minimum power
%maxrow      | double | row location of maximum power
%maxcol      | double | column location of maximum power
%m           | double | outer loop control variable
%n           | double | inner loop control variable
%outputfile  | char   | file location of printed output
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
load power_plant_data.txt;

%Open outputfile
outputfile = fopen('power_plant_report.txt','wt');

%Size array
[nrows,ncols] = size(power_plant_data);

%Compute average power, find minimum and maximum power
minpow = min(power_plant_data(:));
maxpow = max(power_plant_data(:));
avepow = mean(power_plant_data(:));

%Find minimum and maximum power locations in array
[minrow,mincol] = find(power_plant_data == minpow);
[maxrow,maxcol] = find(power_plant_data == maxpow);

%Print to Command Window
disp('*********************************************');
disp('          POWER OUTPUT IN MEGAWATTS');
disp(' ');
disp('  Day1  Day2  Day3  Day4  Day5  Day6  Day7');
disp(power_plant_data);
fprintf('Minimum power = %3i megawatts at week %1i, day %1i', ...
        minpow,minrow,mincol);
fprintf('\nMaximum power = %3i megawatts at week %1i, day %1i', ...
        maxpow,maxrow,maxcol);
fprintf('\nAverage power = %5.1f megawatts\n',avepow);
disp('**********************************************');
disp(' ');
disp(' ');

%Print to output file
fprintf(outputfile,'***************************************************');
fprintf(outputfile,'\n             POWER OUTPUT IN MEGAWATTS');
fprintf(outputfile,'\n\n          Day1  Day2  Day3  Day4  Day5  Day6  Day7');

for m=1:1:nrows
    fprintf(outputfile,'\nWeek %1i ',m);
    for n=1:1:ncols
        fprintf(outputfile,'   %3i',power_plant_data(m,n));
    end
end

fprintf(outputfile,'\n\nMinimum power = %3i megawatts at week %1i, day %1i',...
        minpow,minrow,mincol);
fprintf(outputfile,'\nMaximum power = %3i megwatts at week %1i, day %1i',...
        maxpow,maxrow,maxcol);
fprintf(outputfile,'\nAverage power = %5.1f megawatts',avepow);
fprintf(outputfile,'\n***************************************************');