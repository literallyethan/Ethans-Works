
package Equipment is
	-- Set of equipment that provides randomly generated readouts
	type Weather_Set is limited private;
	
	-- Procedure that generates all of the random data
	procedure Generate_Data;
	
	-- Setter Procedures
	procedure Set_Temp(Set : in out Weather_Set; Temp : Integer);
	procedure Set_Wind(Set : in out Weather_Set; Wind : Integer);
	procedure Set_Humid(Set : in out Weather_Set; Humid : Integer);
	procedure Set_Atmos(Set : in out Weather_Set; Atmos : Integer);

	-- Functions to get the weather conditions from Weather_Set
	function Get_Temp return Integer;
	function Get_Wind return Integer;
	function Get_Humid return Integer;
	function Get_Atmos return Integer;

private
	type Weather_Set is
	record
		Temperature : Integer;
		Wind_Speed : Integer;
		Humidity : Integer;
		Atmospheric_Pressure : Integer;
	end record;

end Equipment;
