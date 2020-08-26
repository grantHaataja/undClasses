%**************************************************************************
%MATLAB DEMO USING MATRIX MULTIPLICATION, MATRIX WITHIN MATRIX, AND
%MULTI-VARIABLE PLOTTING
%   
%PROGRAM DESCRIPTION:
%This program will compute distance, velocity, and acceleration of a rocket
%as time varies from 0 to 25 seconds in one second intervals.  The program
%will plot the curves of distance, velocity, and acceleration vs time.  The
%results are printed to the Command Window and to an output file.
%
%DESCRIPTION VARIABLES:
%NAME        | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%outputfile  | char   | file location of printed output
%time        | double | one-dimensional matrix of time in seconds
%accl        | double | one-dimensional matrix of acceleration in ft/sec^2
%velo        | double | one-dimensional matrix of velocity in ft/sec
%dist        | double | one-dimensional matrix of distance in ft
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Open output file
outputfile = fopen('rocket_output.txt','wt');

%Print headings to Command Window
disp('****************************************************************');
disp('                    ROCKET FLIGHT SIMULATION');
disp(' ');
disp('          TIME   ACCELERATION   VELOCITY     DISTANCE');
disp('          (sec)   (ft/sec^2)    (ft/sec)       (ft)');

%Print headings to output file
fprintf(outputfile,'**************************************************');
fprintf(outputfile,'**************\n');
fprintf(outputfile,'%44s\r\n\n%53s\r\n%51s','ROCKET FLIGHT SIMULATION',...
        'TIME    ACCELERATION     VELOCITY      DISTANCE',...
        '(sec)   (ft/sec*sec)     (ft/sec)        (ft)');

%Compute distance, velocity, acceleration, and print results
time = 0:1:25;
dist = 90.0+2.125*time.^2-0.00125*time.^4;
velo = 4.25*time-0.005*time.^3;
accel = 4.25-0.015*time.^2;
disp([time',accel',velo',dist']);
flight = [time;accel;velo;dist];
fprintf(outputfile,'\r\n %2i       %6.2f          %6.2f        %6.2f',...
        flight);
fprintf(outputfile,'\n*************************************************');
fprintf(outputfile,'***************');
disp('****************************************************************');
disp(' ');
disp(' ');

%Plot distance, velocity, and acceleration vs time
plot(time,dist,time,accel,'--',time,velo,'-.'),...
    title('Rocket Flight'),xlabel('Time'),...
    ylabel('Distance, Acceleration, Velocity'),...
    legend('Distance','Acceleration','Velocity'),...
    grid on,axis square







