# Ft_Printf
Implemeneted printf function from stdio (C standard library) and its behaviors.

The following conversions were made:
s = string;
S;
p = pointer address stored in pointer;
d = int signed integer;
D;
i;
o = unsigned octal value;
O;
u = unsigned decimal;
U;
x = int unsigned hex value;
X = int unsigned hex?;
c = character;
C;

Percision flags:
- left justified 
+ always display sign
0 pad with leading zeros
" " equals space

flags:
hh;
h: The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X);
l;
ll;
j;
z;

Typically printf usage includes the following parameters 1: specifier 2: flag 3: percision 
