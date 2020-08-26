%**************************************************************************
%MATLAB DEMO USING A TWO-DIMENSIONAL MATRIX AND PLOTTING
%   
%PROGRAM DESCRIPTION:
%This program will load experimental time and temperature data into a two-
%dimensional matrix.  It will compute the summations of time, temperature,
%time squared, and time x temperature values.  The program will compute the
%slope and y-intercept of a linear equation and plot the experimental data 
%and the linear equation to a graph.  The results are printed to the
%Command Window and an x-y plot is generated.
%
%DESCRIPTION VARIABLES:
%NAME        | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%concrete    | double | two-dimensional array of time and temperature
%sumtime     | double | summation of all time values
%sumtemp     | double | summation of all temperature values
%sumtimesq   | double | summation of all time squared values
%sumtimetemp | double | summation of all time x temperature values
%slope       | double | computed slope
%yint        | double | computed y-intercept
%computed    | double | one-dimensional array linear equation
%nrows       | double | number of rows in the input file
%ncols       | double | number of columns in the input file
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
load concrete.txt;

%Size matrix
[nrows,ncols] = size(concrete);

%Compute summations
sumtime = sum(concrete(:,1));
sumtemp = sum(concrete(:,2));
sumtimesq = sum(concrete(:,1).^2);
sumtimetemp = sum(concrete(:,1).*concrete(:,2));

%Compute slope and y-intercept
slope = (sumtime*sumtemp - nrows*sumtimetemp)/...
        (sumtime^2 - nrows*sumtimesq);
yint = (sumtemp - slope*sumtime)/nrows;

%Compute linear data
computed = slope*concrete(:,1)+yint;

%Print headings to the Command Window
disp('************************************************');
disp('    EXPERIMENTAL PROCESS TEMPERATURE CONTROL');
disp(' ');
disp('         Time     Temp     Computed');

%Print results to Command Window
for k=1:1:nrows
    fprintf('        %5.1f    %5.1f        %5.1f\n',concrete(k,1),...
            concrete(k,2), computed(k));
end

disp(' ');
disp('************************************************');
disp(' ');
disp(' ');

%Plot time, temperature, and computed values
plot(concrete(:,1),concrete(:,2),concrete(:,1),computed),...
    title({'Time vs Temperature','Concrete Sample'}),xlabel('Time'),...
    ylabel('Temperature'),grid on,legend('Experimental','Computed')









