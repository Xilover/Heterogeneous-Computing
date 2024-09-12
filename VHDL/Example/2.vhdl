// signal
signal clk : std_logic;
signal reset : std_logic;
signal data_out : std_logic_vector(7 downto 0);

//variables:
variable temp : std_logic_vector(7 downto 0);
begin
    if rising_edge(clk) then
        temp := temp + 1;
    end if;
end process;

//Multiplexer (MUX)
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MUX4to1 is
    Port ( A, B, C, D : in STD_LOGIC;
        SEL : in STD_LOGIC_VECTOR(1 downto 0);
        Y : out STD_LOGIC);
end MUX4to1;

architecture Behavioral of MUX4to1 is
begin
    process(A, B, C, D, SEL)
    begin
        case SEL is
            when "00" => Y <= A;
            when "01" => Y <= B;
            when "10" => Y <= C;
            when "11" => Y <= D;
            when others => Y <= '0';
        end case;
    end process;
end Behavioral;
