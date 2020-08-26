%**************************************************************************
%ENGR 200-02                                                DATE:12/05/2017
% 
%ASSIGNMENT: #9                         Author: Grant Haataja
%**************************************************************************

%PROGRAM DESCRIPTION:
%This program will 

%VARIABLE DESCRIPTIONS:
%NAME         | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%density      | double | density of air in kg/m^3 at sea level and 15°C
%power10      | double | power in watts for 10% power
%power20      | double | power in watts for 20% power
%power40      | double | power in watts for 40% power
%power59      | double | power in watts for 59% power
%area         | double | swept area of rotating blades in square meters
%speed        | double | wind speed in meters per second
%blade_radii  | double | one-dimensional matrix for blade radii in cm
%wind_speeds  | double | one-dimensional matrix for wind speed in mph
%k            | int    | outer for loop control variable
%m            | int    | inner for loop control variable
%ofile        | char   | file location of printed output
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input files
load blade_radii.txt;
load wind_speeds.txt;

%Open output file
ofile = fopen('power_results.txt','wt');

%Assign air density value to a variable
density = 1.225;

%Print main heading and column headings to Command Window and output file
fprintf('**************************************************');
fprintf('\n      ELECTRICAL POWER CALCULATIONS IN WATTS');
fprintf('\n\nWind(m/h)     10pct     20pct     40pct     59pct\n\n');
fprintf(ofile,'**************************************************');
fprintf(ofile,'\n      ELECTRICAL POWER CALCULATIONS IN WATTS');
fprintf(ofile,'\n\nWind(m/h)     10pct     20pct     40pct     59pct\n\n');

%Compute and print power output to Command Window and output file
for k=1:1:length(blade_radii)
    fprintf('Blade radius #%1i = %3i centimeters',k,blade_radii(k));
    fprintf(ofile,'Blade radius #%1i = %3i centimeters',k,blade_radii(k));
    area = pi*(blade_radii(k)*0.01)^2;
    
    for m=1:1:length(wind_speeds)
        speed = (wind_speeds(m))*1609/3600;
        power10 = .1*1/2*density*area*speed^3;
        power20 = .2*1/2*density*area*speed^3;
        power40 = .4*1/2*density*area*speed^3;
        power59 = .59*1/2*density*area*speed^3;
        
        if wind_speeds(m) == 0
            fprintf('\nNO ELECTRICAL OUTPUT');
            fprintf(ofile,'\nNO ELECTRICAL OUTPUT');
        else
            fprintf('\n    %2i        %5.1f     %5.1f     %5.1f     %5.1f',...
                   wind_speeds(m), power10, power20, power40, power59);
            fprintf(ofile,'\n    %2i        %5.1f     %5.1f     %5.1f     %5.1f',...
                   wind_speeds(m), power10, power20, power40, power59);
        end        
    end
    if k==1
        fprintf('\n==================================================\n\n');
        fprintf(ofile,'\n==================================================\n\n');
    end    
end

%Print end of report
fprintf('\n***************************************************\n\n');
fprintf(ofile,'\n***************************************************\n\n');
%**************************************************************************