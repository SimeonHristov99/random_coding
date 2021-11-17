#include <iostream>
#include <queue>
#include <list>

typedef std::pair<int, int> Pair;

void populate(std::list<Pair> &balls, int colors[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (balls.empty() || balls.back().second != colors[i])
        {
            balls.push_back({1, colors[i]});
        }
        else if (balls.back().second == colors[i])
        {
            ++balls.back().first;
        }
    }
}

void shoot(Pair &request, std::list<Pair> &balls)
{
    if (balls.empty())
    {
        std::cout << "Game Over\n";
        return;
    }

    std::list<Pair> tmp;

    // Find where to insert element.
    while (!balls.empty() && request.first > balls.front().first)
    {
        tmp.push_front(balls.front());
        request.first -= balls.front().first;
        balls.pop_front();
    }

    int num_balls = 0;

    if (balls.empty())
    {
        if (request.first != 1)
        {
            std::cout << "Adding on an incorrect index!\n";
            return;
        }

        tmp.push_front(request);
    }
    else if (balls.front().second != request.second)
    {
        Pair front = balls.front();
        balls.pop_front();
        front.first -= request.first;
        //TODO: balls.push_front({  });

        balls.push_front(request);
    }
    else
    {

        if (balls.front().first + 1 > 2)
        {
            num_balls += balls.front().first + 1;
            balls.pop_front();

            while (!balls.empty() && !tmp.empty() && balls.front().second == tmp.front().second && balls.front().first + tmp.front().first > 2)
            {
                num_balls += balls.front().first + tmp.front().first;
                balls.pop_front();
                tmp.pop_front();
            }

            while (!tmp.empty())
            {
                balls.push_front(tmp.front());
                tmp.pop_front();
            }
        }
    }

    std::cout << num_balls << '\n';
}

void print(const std::list<Pair> &balls)
{
    while (!balls.empty())
    {
        Pair p = balls.back();

        for (int i = 0; i < p.first; ++i)
        {
            std::cout << p.second << ' ';
        }
    }
    std::cout << '\n';
}

void play(int n, int colors[], std::queue<Pair> &requests)
{
    std::list<Pair> balls;

    populate(balls, colors, n);

    while (!requests.empty())
    {
        shoot(requests.front(), balls);
        requests.pop();
    }

    if (balls.empty())
    {
        std::cout << -1 << '\n';
    }
    else
    {
        print(balls);
    }
}

void test1()
{
    int n = 15;
    int colors[] = {2, 2, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 1, 1, 2};

    std::queue<Pair> requests;
    requests.push({10, 3});
    requests.push({6, 2});
    requests.push({1, 1});
    requests.push({3, 2});

    play(n, colors, requests);
}

void test2()
{
    int n = 10;
    int colors[] = {1, 1, 1, 2, 2, 1, 1, 1, 3, 3};

    std::queue<Pair> requests;
    requests.push({1, 4});
    requests.push({9, 5});
    requests.push({9, 6});
    requests.push({3, 2});

    play(n, colors, requests);
}

int main(int argc, char const *argv[])
{
    test1();
    //test2();

    return 0;
}
