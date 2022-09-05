// Better approach
// long long rowSumOddNumbers(unsigned n)
// {
//     // Well it's just n^3, 1^3 = 1,  2^3 = 8, 3^3 = 27 etc.
//     return n * n * n;
// }

long long rowSumOddNumbers(unsigned n)
{
    unsigned increment_step = 2;

    long long increment = 0;
    long long starting_number = 1;
    long long ending_number = 0;
    long long sum = 0;

    for (long long i = 1; i < n; ++i)
    {
        increment += increment_step;
        starting_number += increment;
    }

    increment += increment_step;
    ending_number = starting_number + increment;

    for (long long i = starting_number; i < ending_number; i += 2)
    {
        sum += i;
    }

    return sum;
}