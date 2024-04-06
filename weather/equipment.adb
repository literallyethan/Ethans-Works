with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Discrete_Random;

package body Equipment is
	Used_Equipment_Set : Weather_Set;
	
	-- Setter procedures	
	procedure Set_Temp(Set : in out Weather_Set; Temp : Integer) is
	begin
		Set.Temperature := Temp;
	end Set_Temp;

	procedure Set_Wind(Set : in out Weather_Set; Wind : Integer) is
	begin
		Set.Wind_Speed := Wind;
	end Set_Wind;

	procedure Set_Humid(Set : in out Weather_Set; Humid : Integer) is
	begin
		Set.Humidity := Humid;
	end Set_Humid;

	procedure Set_Atmos(Set : in out Weather_Set; Atmos : Integer) is
	begin
		Set.Atmospheric_Pressure := Atmos;
	end Set_Atmos;

	procedure Generate_Data is
		subtype Temperature_Range is Integer range -10 .. 130; -- F degrees range
		subtype Wind_Range is Integer range 5 .. 40; -- mph windspeed
		subtype Humidity_Range is Integer range 0 .. 100; -- Humidity percentage
		subtype Atmospheric_Range is Integer range 29 .. 31; -- Pressure in inHg
		package Temp_Gen_Pack is new Ada.Numerics.Discrete_Random(Temperature_Range);
		package Wind_Gen_Pack is new Ada.Numerics.Discrete_Random(Wind_Range);
		package Humid_Gen_Pack is new Ada.Numerics.Discrete_Random(Humidity_Range);
		package Atmos_Gen_Pack is new Ada.Numerics.Discrete_Random(Atmospheric_Range);
		Temperature_Generator : Temp_Gen_Pack.Generator;
		Wind_Generator : Wind_Gen_Pack.Generator;
		Humidity_Generator : Humid_Gen_Pack.Generator;
		Atmospheric_Generator : Atmos_Gen_Pack.Generator;
		Random_Temp : Temperature_Range;
		Random_Wind : Wind_Range;
		Random_Humid : Humidity_Range;
		Random_Atmos : Atmospheric_Range;
	begin
		-- Init Generators
		Temp_Gen_Pack.Reset(Temperature_Generator);
		Wind_Gen_Pack.Reset(Wind_Generator);
		Humid_Gen_Pack.Reset(Humidity_Generator);
		Atmos_Gen_Pack.Reset(Atmospheric_Generator);

		Random_Temp := Temp_Gen_Pack.Random(Temperature_Generator); -- Generates the random number
		Random_Wind := Wind_Gen_Pack.Random(Wind_Generator);
		Random_Humid := Humid_Gen_Pack.Random(Humidity_Generator);
		Random_Atmos := Atmos_Gen_Pack.Random(Atmospheric_Generator);

		-- Assign new values to Used_Equipment_set
		Set_Temp(Used_Equipment_Set, Random_Temp);
		Set_Wind(Used_Equipment_Set, Random_Wind);
		Set_Humid(Used_Equipment_Set, Random_Humid);
		Set_Atmos(Used_Equipment_Set, Random_Atmos);

		Put_Line("All said and done.");

	end Generate_Data;

	function Get_Temp return Integer is
	begin
		return Used_Equipment_Set.Temperature;
	end Get_Temp;

	function Get_Wind return Integer is
	begin
		return Used_Equipment_Set.Wind_Speed;
	end Get_Wind;

	function Get_Humid return Integer is
	begin
		return Used_Equipment_Set.Humidity;
	end Get_Humid;

	function Get_Atmos return Integer is
	begin
		return Used_Equipment_Set.Atmospheric_Pressure;
	end Get_Atmos;

end Equipment;
