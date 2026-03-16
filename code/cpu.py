import re

"""
This file defines a simple CPU simulator class that can store values in registers,
place instructions into memory, then fetch, decode, and execute those instructions.
"""

class CPU:
    """
    A basic CPU simulator with 32 registers, an instruction register, and a memory list.
    Includes methods to store values and instructions, then run them step by step.
    """

    def __init__(self):
        """
        Initializes the CPU with:
          - A program counter (PC) starting at 0.
          - 32 integer registers (all zero by default).
          - numbers_index for tracking where to store next value in a register.
          - An empty memory list for instructions.
          - An empty string for the instruction register.
        """
        self.program_counter = 0
        self.registers = [0] * 32
        self.numbers_index = 1
        self.memory = []  # list of instruction strings
        self.instruction_register = ''

    def store_value_in_register(self, value_to_store):
        """
        Stores a given integer value into one of the CPU registers.
        Increments numbers_index after each store.
        If numbers_index exceeds 31, it resets to 1.
        """
        if self.numbers_index > 31:
            self.numbers_index = 1
        # Place the value in the register array at numbers_index
        self.registers[self.numbers_index] = value_to_store
        print(f'{value_to_store} was stored in Register #{self.numbers_index}')
        self.numbers_index += 1

    def store_instruction_in_memory(self, instruction_string):
        """
        Appends a string representing an instruction (e.g., 'ADD,R1,R2,R3')
        onto the memory list. This simulates loading an instruction into memory.
        """
        self.memory.append(instruction_string)

    def fetch(self):
        """
        Fetches the next instruction string from memory using the program counter.
        Increments the PC by 1 afterward.
        """
        self.instruction_register = self.memory[self.program_counter]
        self.program_counter += 1
        return self.instruction_register

    @staticmethod
    def decode(instruction_string):
        """
        Splits an instruction string by commas or spaces into an opcode and operand list.
        Example: 'ADD,R3,R1,R2' -> opcode='ADD', operands=['R3','R1','R2'] -> [3,1,2].
        Returns: (opcode, [list_of_operand_indices])
        If there is only one token, returns (opcode, None).
        """
        split_instruction_string = re.split(r'[ ,]+', instruction_string)
        if len(split_instruction_string) > 1:
            # First token is the opcode (e.g. 'ADD')
            opcode = split_instruction_string.pop(0)
            # Remaining tokens are the operands (e.g. 'R3', 'R1', 'R2')
            operands = split_instruction_string
            for _ in operands:
                # Convert each operand to an integer by removing non-digit chars (e.g. "R3" -> 3)
                operands.append(int(re.sub(r'\D', '', operands.pop(0))))
            return opcode, operands
        # If only one token, it's presumably an opcode with no operands
        opcode = split_instruction_string[0]
        return opcode, None

    def execute(self, opcode, operands):
        """
        Executes the instruction based on the opcode and operands.
        - ADD, ADDI, SUB, MUL, DIV each perform arithmetic on the registers.
        - DIV checks for division by zero before computing the result.
        - Returns a string describing the result or an error message.
        """
        match opcode:
            case 'ADD':
                # registers[destination] = registers[src1] + registers[src2]
                self.registers[operands[0]] = self.registers[operands[1]] + self.registers[operands[2]]
                return f'The result is: {self.registers[operands[0]]}'
            case 'ADDI':
                # registers[destination] = registers[src] + immediate_value
                self.registers[operands[0]] = self.registers[operands[1]] + operands[2]
                return f'The result is: {self.registers[operands[0]]}'
            case 'SUB':
                # registers[destination] = registers[src1] - registers[src2]
                self.registers[operands[0]] = self.registers[operands[1]] - self.registers[operands[2]]
                return f'The result is: {self.registers[operands[0]]}'
            case 'MUL':
                # registers[destination] = registers[src1] * registers[src2]
                self.registers[operands[0]] = self.registers[operands[1]] * self.registers[operands[2]]
                return f'The result is: {self.registers[operands[0]]}'
            case 'DIV':
                # registers[destination] = registers[src1] / registers[src2], if src2 != 0
                if self.registers[operands[2]] != 0:
                    self.registers[operands[0]] = self.registers[operands[1]] / self.registers[operands[2]]
                else:
                    return f'Division by 0 error: {self.registers[operands[1]]} / {self.registers[operands[2]]}'
                return f'The result is: {self.registers[operands[0]]}'
            case _:
                print('Invalid opcode')

    def main(self, instruction, value_1=None, value_2=None):
        """
        Convenience method to:
          1. Optionally store value_1 and value_2 into consecutive registers.
          2. Store an instruction string into memory.
          3. Fetch, decode, and execute that instruction.
          4. Print the result or error message.
        """
        if value_1 is not None:
            self.store_value_in_register(value_1)

        if value_2 is not None:
            self.store_value_in_register(value_2)

        self.store_instruction_in_memory(instruction)

        instruction_register = self.fetch()

        opcode, operands = self.decode(instruction_register)

        print(self.execute(opcode,operands))


if __name__ == "__main__":
    """
    Demonstration of the CPU simulator using various instructions:
      - ADD
      - SUB
      - MUL
      - ADDI
      - DIV (valid and division by zero)
    """
    new_cpu = CPU()

    print('ADDITION')
    new_cpu.main("ADD,R11,R1,R2", 10, 20)

    print('SUBTRACTION')
    new_cpu.main("SUB,R8,R3,R4", 5, 10)

    print('MULTIPLICATION')
    new_cpu.main("MUL,R13,R5,R6", 3, 4)

    print('ADDITION WITH IMMEDIATE VALUE OF 7')
    new_cpu.main("ADDI,R20,R7,7", 5)

    print('DIVISION')
    new_cpu.main('DIV,R16,R8,R9', 30, 2)

    print('DIVISION BY 0')
    new_cpu.main("DIV,R21,R10,R11", 3, 0)
