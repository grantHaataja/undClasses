--Author: Grant Haataja
--Email: grant.haataja@und.edu
--Program Description: Program takes in a list of integers from the user,
--sorts the list, gives average and largest value, and displays list to screen
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
procedure Prog6GEH is
    --declare data
    type Num is array (1 .. 100) of Integer;
    My_Array   : Num;
    My_Sorted_Array : Num;
    My_Length  : Integer := 0;
    My_Largest: Integer;
    My_Average : Float := 0.0;
    function Fill_Array return Num;
    function Find_Largest(Arr: in Num) return Integer;
    function Find_Average (Arr: in Num) return Float;
    procedure Me;
    procedure Print_Array (Arr : in Num);
    procedure Sort_Array (Arr : in Num; Sorted_Arr : out Num);

    --define procedures and functions
    procedure Me is
    begin
        My_Array := Fill_Array;
        My_Sorted_Array := My_Array;
        My_Largest := Find_Largest(My_Array);
        My_Average := Find_Average(My_Array);
    end Me;
    
    --function to populate array with user-entered integers
    function Fill_Array return Num is
        --temporary variable to get each integer entered by user
        temp : integer := 1;
        i    : integer := 1;
    begin
        Put("Please enter positive integers, one at a time, ");
        Put_Line("entering a 0 or negative number to stop.");

        loop
            --get next integer from input
            get(temp);
            -- --check to see if 0 or negative number was entered
            exit when temp <= 0;

            My_Array(i) := temp;
            My_Length := My_Length + 1;
            i := i + 1;
        end loop;
        --return populated array
        return My_Array;
    end Fill_Array;
    
    --function to find the largest value in an array
    function Find_Largest (Arr: in Num) return Integer is
        largest : integer := Arr(1);
    begin
        for i in 2..My_Length loop
            if Arr(i) > largest then
                largest := Arr(i);
            end if;
        end loop;
        --return largest value
        return largest;
    end Find_Largest;
    
    --function to find the average value of array
    function Find_Average (Arr: in Num) return Float is
        average : float := 0.0;
        total   : integer := 0;
    begin
        for i in 1..My_Length loop
            total := total + Arr(i);
        end loop;
        --calculate average
        average := Float (total) / Float (My_Length);
        --return average
        return average;
    end Find_Average;
    
    --procedure to print the contents of the array
    procedure Print_Array (Arr : in Num) is
    begin
        Put_Line("Array Contents:");
        for i in 1..My_Length loop
            Put_Line(Integer'Image(Arr(i)));
        end loop;
        new_line;
    end Print_Array;
    
    --procedure to sort the array
    procedure Sort_Array (Arr : in Num; Sorted_Arr : out Num) is 
        temp : integer := 0;
    begin
        Put_Line("Sorting the array...");
        for i in 1..My_Length-1 loop
            for j in 1..My_Length-i loop
                if Sorted_Arr(j) > Sorted_Arr(j+1) then
                    temp := Sorted_Arr(j);
                    Sorted_Arr(j) := Sorted_Arr(j+1);
                    Sorted_Arr(j+1) := temp;
                end if;
            end loop;
        end loop;
    end Sort_Array;

--run the program and call procedures
begin
    --call the functions to initialize the array, and find important values
    Me;
    --print the unsorted array
    Print_Array(My_Array);
    --sort the array
    Sort_Array(My_Array, My_Sorted_Array);
    --print the sorted array
    Print_Array(My_Sorted_Array);
    --print largest value
    Put("The largest integer in the array is:");
    Put_Line(Integer'Image(My_Largest));
    --print average value
    Put("The average value of the array is:");
    Put_Line(Float'Image(My_Average));
end Prog6GEH;