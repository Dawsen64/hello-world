LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY CPU IS
	PORT(
		SW :IN STD_LOGIC_VECTOR(2 DOWNTO 0);
		CLR :IN STD_LOGIC;
		W1 :IN STD_LOGIC;
		W2 :IN STD_LOGIC;
		W3 :IN STD_LOGIC;
		IR :IN STD_LOGIC_VECTOR(7 DOWNTO 4);
		T3 :IN STD_LOGIC;
		C,Z :IN STD_LOGIC;
		S :OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		SEL :OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		SBUS,SELCTL,DRW,STOP,LAR,SHORT,MBUS,ARINC,MEMW,ABUS,LONG,M,PCADD,LPC,LIR,PCINC :OUT STD_LOGIC;
		CIN,LDZ,LDC:OUT STD_LOGIC
	);
END CPU;

ARCHITECTURE CPU1 OF CPU IS
	SIGNAL ST0,SST0:STD_LOGIC;
BEGIN
	PROCESS(ST0,SST0,W1,W2,W3,CLR,SW,IR,T3,C,Z)
	BEGIN
		SBUS <= '0';
		SELCTL <= '0';
		DRW <= '0';
		STOP <= '0';
		LAR <= '0';
		SHORT <= '0';
		MBUS <= '0';
		ARINC <= '0';
		MEMW <= '0';
		ABUS <= '0';
		LONG <= '0';
		M <= '0';
		PCADD <= '0';
		LPC <= '0';
		LIR <= '0';
		PCINC <= '0';
		CIN <= '0';
		LDZ <= '0';
		LDC <= '0';
		S <= "0000";
		SEL <= "0000";
		IF CLR = '0' THEN
			ST0 <= '0';
			SST0 <= '0';
		ELSE
			IF (T3'EVENT AND T3 = '0') THEN
				IF SST0 = '1' THEN 
					ST0 <= SST0;
				END IF;
			END IF;
			
			CASE SW IS
			WHEN "000" =>
				IF ST0 = '0' THEN
					SBUS <= W1;
					LPC <= W1;
					STOP <= W1;
					SST0 <= W1;
					SHORT <= W1;
					SELCTL <= W1;
				ELSE
					LIR <= W1;
					PCINC <= W1;
					
					CASE IR IS
					WHEN "0001" =>     --ADD
						S <= W2&'0'&'0'&W2;
						CIN <= W2;
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
						LDC <= W2;
					WHEN "0010" =>     --SUB
						S <= '0'&W2&W2&'0';
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
						LDC <= W2;
					WHEN "0011" =>     --AND
						M <= W2;
						S <= W2&'0'&W2&W2;
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
					WHEN "0100" =>     --INC
						S <= '0'&'0'&'0'&'0';
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
						LDC <= W2;
					WHEN "0101" =>     --LD
						M <= W2;
						S <= W2&'0'&W2&'0';
						ABUS <= W2;
						LAR <= W2;
						LONG <= W2;
						DRW <= W3;
						MBUS <= W3;
					WHEN "0110" =>     --ST
						M <= W2 OR W3;
						S <= (W2 OR W3)&W2&(W2 OR W3)&W2;
						ABUS <= W2 OR W3;
						LAR <= W2;
						LONG <= W2;
						MEMW <= W3;
					WHEN "0111" =>     --JC
						IF C = '1' THEN 
							PCADD <= W2;
						END IF;
					WHEN "1000" =>     --JZ
						IF Z = '1' THEN 
							PCADD <= W2;
						END IF;
					WHEN "1001" =>     --JMP
						M <= W2;
						S <= W2&W2&W2&W2;
						ABUS <= W2;
						LPC <= W2;
					WHEN "1110" =>      --STP
						STOP <= W2;
					WHEN "1010" =>   --OUT
						M <= W2;
						S <= W2&'0'&W2&'0';
						ABUS <= W2;
					WHEN "1011" =>        --OR
						M <= W2;
						S <= W2&W2&W2&'0';
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
					WHEN "1100" =>      --NOT
						M <= W2;
						S <= W2&W2&W2&W2;
						ABUS <= W2;
						DRW <= W2;
						LDZ <= W2;
					WHEN OTHERS =>  
						NULL;
					END CASE;
				END IF;
			
		  --写寄存器
		  when "100" =>	
				SBUS <= W1 or W2;
				SELCTL <= W1 or W1;
				DRW <= W1 or W2;
				STOP <= W1 or W2;
				SST0 <= not ST0 and W2;--W2时SSTO由0为1
				SEL(3) <= ST0;
				SEL(2) <= W2;
				if(ST0 = '0') then
					SEL(1) <= W1;
				else
					SEL(1) <= W2;
				end if;
				
				SEL(0) <= W1;
				
			--读寄存器
			when "011" =>
				SELCTL <= W1 or W2;
				STOP <= W1 or W2;
				SEL(3) <= W2;
				SEL(2) <= '0';
				SEL(1) <= W2;
				SEL(0) <= '1';
				
			--读存储器
			when "010" =>
			--写地址时STO为0，循环读数据为1
				 SBUS <= W1 and not ST0;
				 LAR <= W1 and not ST0;
				 STOP <= W1;
				 SST0 <= W1 and not ST0;
				 SHORT <= W1;
				 SELCTL <= W1;
				 
				 MBUS <= W1 and ST0;
				 ARINC <= W1 and ST0;
				
			--写存储器
			when "001" =>
				 SBUS <= W1;
				 LAR <= W1 and not ST0;
				 STOP <= W1;
				 SST0 <= W1 and not ST0;
				 SHORT <= W1;
				 SELCTL <= W1;
				 
				 ARINC <= W1 and ST0;
				 MEMW <= W1 and ST0;
			when others => NULL;
			END CASE;
		END IF;
	END PROCESS;
END CPU1;
