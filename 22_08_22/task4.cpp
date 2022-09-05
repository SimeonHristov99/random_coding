class BankerPlan
{
public:
    static bool fortune(int f0, double p, int c0, int n, double i)
    {
        if (n == 1)
        {
            return f0 >= 0;
        }

        return fortune(f0 + int(p / 100 * f0) - c0, p, c0 + int(c0 * i / 100), n - 1, i);
    }
};