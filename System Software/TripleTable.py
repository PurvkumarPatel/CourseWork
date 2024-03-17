code = """
i=1;
While(i<=num)
{
if (num%i == 0)
{ 
printf(“%d”,i);
}
++i;
}
"""

triples = []  # list 
symbol_table = {}  # dicnory

def new_temp():
    count = len(symbol_table) + 1
    temp = f"t{count}"
    symbol_table[temp] = None
    return temp

def add_triple(op, arg1, arg2, result):
    triple = (op, arg1, arg2, result)
    triples.append(triple)

lines = code.split("\n")

# Process each line
for line in lines:
    if not line.strip():
        continue
    words = line.strip().split()

    if words[0] == "i=1;":
        symbol_table["i"] = 1
        continue

    # Generate a new temporary variable for i++ and update the symbol table
    if words[0] == "++i;":
        i_value = symbol_table["i"]
        i_temp = new_temp()
        add_triple("+", "i", "1", i_temp)
        symbol_table["i"] = i_temp
        continue

    # start of the while loop 
    if words[0] == "While(i<=num)":
        while_start = len(triples)
        continue

    if words[0] == "{":
        while_end = len(triples)
        continue

    # Generate a modulo operation triple for the if condition
    if words[0] == "if":
        condition = words[1]
        op_index = condition.index("%")
        num_var = condition[:op_index]
        i_var = condition[op_index + 1:]
        i_temp = symbol_table["i"]
        add_triple("%", num_var, i_var, new_temp())
        continue

    # print operation 
    if words[0] == "printf":
        value = words[1][1:-2]
        add_triple("print", value, "", "")
        continue

print("Triple Table:")
print("-------------------------------------------------")
print("| Operator | Arg1 | Arg2 | Result |")
print("-------------------------------------------------")
for i, triple in enumerate(triples):
    print(f" {i+1}  {triple[0]}       {triple[1]}    {triple[2]}      {triple[3]} ")
print("-------------------------------------------------")