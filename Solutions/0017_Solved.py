from Euler.Solution import Solution
import Euler.Math as EM

AND      = 3
ONE      = 3
TWO      = 3
THREE    = 5
FOUR     = 4
FIVE     = 4
SIX      = 3
SEVEN    = 5
EIGHT    = 5
NINE     = 4
TEN      = 3
ELEVEN   = 6
TWELVE   = 6
THIRTEEN = 8
FIFTEEN  = 7
EIGHTEEN = 8
TEEN     = 4
TWENTY   = 6
THIRTY   = 6
FORTY    = 5
FIFTY    = 5
SIXTY    = 5
SEVENTY  = 7
EIGHTY   = 6
NINETY   = 6
HUNDRED  = 7
THOUSAND = 8

def logic():
    One_Nineteen = 0
    Twenty_NinetyNine = 0
    One_NinetyNine = 0
    sum = 0
    x = 0

    One_Nineteen += ONE + TWO + THREE + FOUR + FIVE + SIX + SEVEN + EIGHT + NINE + TEN
    One_Nineteen += ELEVEN + TWELVE + THIRTEEN + FOUR + TEEN + FIFTEEN + SIX + TEEN + SEVEN + TEEN + EIGHTEEN + NINE + TEEN

    for n in range(10): Twenty_NinetyNine += TWENTY + THIRTY + FORTY + FIFTY + SIXTY + SEVENTY + EIGHTY + NINETY
    for n in range(8):  Twenty_NinetyNine += ONE + TWO + THREE + FOUR + FIVE + SIX + SEVEN + EIGHT + NINE

    One_NinetyNine = One_Nineteen + Twenty_NinetyNine

    sum += One_NinetyNine

    sum += ONE + HUNDRED
    for n in range(99): sum += ONE+HUNDRED + AND
    sum += One_NinetyNine

    sum += TWO + HUNDRED
    for n in range(99): sum += TWO + HUNDRED + AND
    sum += One_NinetyNine

    sum += THREE + HUNDRED
    for n in range(99): sum += THREE + HUNDRED + AND
    sum += One_NinetyNine

    sum += FOUR+HUNDRED
    for n in range(99): sum += FOUR + HUNDRED + AND
    sum += One_NinetyNine

    sum += FIVE + HUNDRED
    for n in range(99): sum += FIVE + HUNDRED + AND
    sum += One_NinetyNine

    sum += SIX + HUNDRED
    for n in range(99): sum += SIX + HUNDRED + AND
    sum += One_NinetyNine

    sum += SEVEN + HUNDRED
    for n in range(99): sum += SEVEN + HUNDRED + AND
    sum += One_NinetyNine

    sum += EIGHT + HUNDRED
    for n in range(99): sum += EIGHT + HUNDRED + AND
    sum += One_NinetyNine

    sum += NINE + HUNDRED
    for n in range(99): sum += NINE + HUNDRED + AND
    sum += One_NinetyNine

    sum += ONE + THOUSAND
    return sum

solution = Solution(value = 21124, placement = None)
solution.logic = logic
solution.run()



"""
#define AND 3
#define ONE 3
#define TWO 3
#define THREE 5
#define FOUR 4
#define FIVE 4
#define SIX 3
#define SEVEN 5
#define EIGHT 5
#define NINE 4
#define TEN 3
#define ELEVEN 6
#define TWELVE 6
#define THIRTEEN 8
#define FIFTEEN 7
#define EIGHTEEN 8
#define TEEN 4
#define TWENTY 6
#define THIRTY 6
#define FORTY 5
#define FIFTY 5
#define SIXTY 5
#define SEVENTY 7
#define EIGHTY 6
#define NINETY 6
#define HUNDRED 7
#define THOUSAND 8

int One_Nineteen = 0, Twenty_NinetyNine = 0, One_NinetyNine = 0;
int sum = 0, x;

int _tmain(int argc, _TCHAR* argv[])
{
    One_Nineteen+=ONE+TWO+THREE+FOUR+FIVE+SIX+SEVEN+EIGHT+NINE+TEN;
    One_Nineteen+=ELEVEN+TWELVE+THIRTEEN+FOUR+TEEN+FIFTEEN+SIX+TEEN+SEVEN+TEEN+EIGHTEEN+NINE+TEEN;

    for(x=0;x<10;x++)
        Twenty_NinetyNine+=TWENTY+THIRTY+FORTY+FIFTY+SIXTY+SEVENTY+EIGHTY+NINETY;
    for(x=0;x<8;x++)
        Twenty_NinetyNine+=ONE+TWO+THREE+FOUR+FIVE+SIX+SEVEN+EIGHT+NINE;

    One_NinetyNine=One_Nineteen+Twenty_NinetyNine;

    sum+=One_NinetyNine;

    sum+=ONE+HUNDRED;
    for(x=0;x<99;x++)
        sum+=ONE+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=TWO+HUNDRED;
    for(x=0;x<99;x++)
        sum+=TWO+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=THREE+HUNDRED;
    for(x=0;x<99;x++)
        sum+=THREE+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=FOUR+HUNDRED;
    for(x=0;x<99;x++)
        sum+=FOUR+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=FIVE+HUNDRED;
    for(x=0;x<99;x++)
        sum+=FIVE+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=SIX+HUNDRED;
    for(x=0;x<99;x++)
        sum+=SIX+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=SEVEN+HUNDRED;
    for(x=0;x<99;x++)
        sum+=SEVEN+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=EIGHT+HUNDRED;
    for(x=0;x<99;x++)
        sum+=EIGHT+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=NINE+HUNDRED;
    for(x=0;x<99;x++)
        sum+=NINE+HUNDRED+AND;
    sum+=One_NinetyNine;

    sum+=ONE+THOUSAND;

    printf("Sum: %i\n", sum);
    getch();
    return 0;
}
"""