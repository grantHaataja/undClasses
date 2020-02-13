%**************************************************************************
%ENGR 200-02                                                DATE:12/05/2017
% 
%ASSIGNMENT: #9                         Author: Grant Haataja
%**************************************************************************

%PROGRAM DESCRIPTION:
%This program will load input file of river data containing days data was
%collected, river heights in meters, and river velocitie in meters per
%second squared. It will then transpose and size the matrix, and compute
%average heights and velocities, maximum and minimum heights and
%velocities, matrix locations of maximums and minimums, river flow rate,
%and volume of water over a one-year period. Finally this program will
%develop a plot for flow rate versus time. The results will be printed to
%the Command Window.

%VARIABLE DESCRIPTIONS:
%NAME         | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%riv          | double  | transposed 2-dimensional matrix from input file
%flowrate     | double | one-dimensional matrix for flowrate in cubic m /s
%width        | double | channel width in meters
%volume       | double | volume of water in cubic meters for 1 year period
%avht         | double | average height
%avvel        | double | average velocity
%minht        | double | minimum height
%minvel       | double | minimum velocity
%maxht        | double | maximum height
%maxvel       | double | maximum velocity
%minhtrow     | double | row location for minimum height
%minhtcol     | double | column location for minimum height
%maxhtrow     | double | row location for maximum height
%maxhtcol     | double | column location for maximum height
%minvelrow    | double | row location for minimum velocity
%minvelcol    | double | column location for minimum velocity
%maxvelrow    | double | row location for maximum velocity
%maxvelcol    | double | column location for maximum velocity
%k            | int    | outer for loop control variable
%m            | int    | inner for loop control variable
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
load river.txt;

%Transpose matrix
riv = transpose(river);

%Size matrix
[nrows,ncols] = size(riv);

%Assign variables and compute averages, minimums, and maximums
width = 8;
avht = mean(riv(:,2));
avvel = mean(riv(:,3));
minht = min(riv(:,2));
minvel = min(riv(:,3));
maxht = max(riv(:,2));
maxvel = max(riv(:,3));

%Find matrix locations of maximums and minimums
[minhtrow,minhtcol] = find(riv(:,2) == minht);
[minvelrow,minvelcol] = find(riv(:,3) == minvel);
[maxhtrow,maxhtcol] = find(riv(:,2) == maxht);
[maxvelrow,maxvelcol] = find(riv(:,3) == maxvel);

%Compute flow rate matrix and volume
flowrate = riv(:,3).*width.*riv(:,2);
volume = 86400*trapz(riv(:,1),flowrate);

%Print main heading and column headings to Command Window
disp('*******************************************');
fprintf('          RIVER CHANNEL ANALYSIS\n\n');
disp('           Day   Height   Speed');
fprintf('                   (m)    (m/s)');

%Print array
for k=1:1:nrows
    fprintf('\n           %3i     %3.1f     %3.1f',riv(k,1),riv(k,2),...
            riv(k,3));
end

%Print computation results
fprintf('\n\nAverage height = %3.1f meters',avht);
fprintf('\nAverage speed  = %3.1f meters/sec',avvel);
fprintf('\nMinimum height = %3.1f meters on day %3i',minht,...
        riv(minhtrow,minhtcol));
fprintf('\nMinimum speed  = %3.1f meters/sec on day %3i',minvel,...
        riv(minvelrow,minvelcol));
fprintf('\nMaximum height = %3.1f meters on day %3i',maxht,...
        riv(maxhtrow,maxhtcol));
fprintf('\nMaximum speed  = %3.1f meters/sec on day %3i',maxvel,...
        riv(maxvelrow,maxvelcol));
fprintf('\n\nVolume per year = %12.6e cubic meters',volume);  

%Plot flow rate versus time
plot(riv(:,1),flowrate),title('Water Flow vs Time'),xlabel('Day'),...
     ylabel('Flow Rate (m^3/s)'),grid on, axis square 
    
%Print end of report
fprintf('\n*******************************************\n\n');
%**************************************************************************